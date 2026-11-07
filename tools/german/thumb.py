#!/usr/bin/env python3
"""Render a reference Thumb routine as symbolic Metrowerks assembly for review."""

import argparse
import json
from pathlib import Path
import re
import struct
import subprocess

from compare import elf_symbols


def discover_jump_tables(data,base,start,end):
    result={}
    for address in range(start+12,end-2,2):
        offset=address-base
        if data[offset-10:offset+2] != bytes.fromhex('00187844c088000400148744'):continue
        for earlier in range(address-12,max(start-2,address-32),-2):
            value=struct.unpack_from('<H',data,earlier-base)[0]
            if value&0xFF00==0x2800:
                result[address+2]=(value&255)+1
                break
    return result


def render(binary, base, start, end, names, aliases, jump_tables=None):
    data = binary.read_bytes()
    if jump_tables is None:
        jump_tables = discover_jump_tables(data,base,start,end)
    result = subprocess.check_output([
        "arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "arm", "-M", "force-thumb",
        f"--adjust-vma={base}", f"--start-address={start}", f"--stop-address={end}", str(binary),
    ], text=True)
    instructions = {}
    pools = set()
    targets = set()
    table_entries = {}
    for table, count in (jump_tables or {}).items():
        targets.add(table)
        for index in range(count):
            offset = table + index * 2
            relative = struct.unpack_from('<h', data, offset - base)[0]
            target = table + 2 + relative
            targets.add(target)
            table_entries[offset] = (table, target)
    for line in result.splitlines():
        match = re.match(r"\s*([0-9a-f]+):\s+(?:[0-9a-f]{4}\s+){1,2}\s*([a-z][a-z0-9.]*)\s*(.*)", line)
        if not match:
            continue
        address, mnemonic, operands = int(match[1], 16), match[2], match[3]
        if address in pools or address - 2 in pools or address in table_entries:
            instructions[address] = ""
            continue
        if mnemonic == "ldr" and "[pc," in operands:
            target = re.search(r"; \(0x([0-9a-f]+)\)", operands)
            if not target:
                raise ValueError(line)
            target = int(target[1], 16)
            if not start <= target <= end - 4:
                raise ValueError(f"Literal pool outside routine: {line}")
            pools.add(target)
            operands = operands.split(",", 1)[0] + f", _DE_{target:08X}"
        else:
            operands = operands.split(";", 1)[0].strip()
            direct = re.fullmatch(r"0x([0-9a-f]+)", operands)
            if direct:
                target = int(direct[1], 16)
                if start <= target < end:
                    targets.add(target)
                    operands = f"_DE_{target:08X}"
                elif target in names:
                    operands = names[target]
                else:
                    raise ValueError(f"Unresolved code reference 0x{target:08X}: {line}")
        mnemonic = mnemonic.removesuffix(".n").removesuffix(".w")
        mnemonic = {"adds": "add", "subs": "sub", "movs": "mov", "lsls": "lsl", "lsrs": "lsr",
                    "asrs": "asr", "ands": "and", "orrs": "orr", "eors": "eor", "muls": "mul",
                    "bics": "bic", "negs": "neg", "mvns": "mvn", "rors": "ror", "adcs": "adc",
                    "sbcs": "sbc", "bcc": "blo", "bcs": "bhs"}.get(mnemonic, mnemonic)
        instructions[address] = "\t" + mnemonic + (" " + operands if operands else "")
    for address in pools:
        instructions.setdefault(address, "")
    output = []
    for name in aliases:
        output.extend(["\tthumb_func_start " + name, name + ":"])
    for address in sorted(instructions):
        if address in table_entries:
            table, target = table_entries[address]
            if address in targets:
                output.append(f"_DE_{address:08X}:")
            output.append(f"\t.short _DE_{target:08X} - _DE_{table:08X} - 2")
        elif address in pools:
            value = struct.unpack_from("<I", data, address - base)[0]
            if 0x02000000 <= value < 0x02400000:
                if value & ~1 not in names:
                    raise ValueError(f"Unresolved data reference 0x{value:08X}")
                value = names.get(value, names[value & ~1])
            else:
                value = f"0x{value:08X}"
            output.extend([f"_DE_{address:08X}:", "\t.word " + value])
        elif address - 2 in pools:
            continue
        else:
            if address in targets:
                output.append(f"_DE_{address:08X}:")
            output.append(instructions[address])
    output.append("\tthumb_func_end " + aliases[0])
    return "\n".join(output) + "\n"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("binary", type=Path)
    parser.add_argument("--elf", type=Path, required=True)
    parser.add_argument("--map", type=Path, required=True)
    parser.add_argument("--base", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--start", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--end", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--names", nargs="+", required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--jump-table", action="append", default=[], help="ADDRESS:COUNT")
    args = parser.parse_args()
    symbols = elf_symbols(args.elf, include_empty=True)
    names = {}
    for module in ("main", "ITCM", "DTCM"):
        for symbol in symbols.get(module, []):
            if not symbol["name"].startswith((".", "$", "SDK_")):
                names.setdefault(symbol["address"] & ~1, symbol["name"])
    names.update({int(address, 0): name for address, name in json.loads(args.map.read_text()).items()})
    tables = {int(address, 0): int(count, 0) for address, count in (item.split(':') for item in args.jump_table)}
    args.output.write_text(render(args.binary, args.base, args.start, args.end, names, args.names, tables or None))


if __name__ == "__main__":
    main()
