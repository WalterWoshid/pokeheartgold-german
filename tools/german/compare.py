#!/usr/bin/env python3
"""Compare source-built ARM9 modules with the verified German retail modules."""

import argparse
import json
from pathlib import Path
import struct

from rom import Rom


def elf_symbols(path, include_empty=False):
    data = path.read_bytes()
    if data[:6] != b"\x7fELF\x01\x01":
        raise ValueError("Expected a little-endian ELF32 file")
    offset = struct.unpack_from("<I", data, 32)[0]
    size, count, strings_index = struct.unpack_from("<HHH", data, 46)
    sections = [struct.unpack_from("<10I", data, offset + size * index) for index in range(count)]
    names = sections[strings_index]
    names = data[names[4]:names[4] + names[5]]

    def cstring(blob, start):
        return blob[start:blob.index(b"\0", start)].decode("ascii", errors="replace")

    modules = {}
    for section in sections:
        if section[1] != 2:
            continue
        strings = sections[section[6]]
        strings = data[strings[4]:strings[4] + strings[5]]
        owner = ""
        for position in range(section[4], section[4] + section[5], section[9]):
            name, address, length, info, other, index = struct.unpack_from("<IIIBBH", data, position)
            name = cstring(strings, name)
            if info & 15 == 4:
                owner = name
                continue
            if 0 < index < len(sections) and name and (length or include_empty):
                module = cstring(names, sections[index][0])
                modules.setdefault(module, []).append({"name": name, "address": address,
                                                       "size": length, "owner": owner, "type": info & 15})
    return modules


def compare(build, rom):
    symbols = elf_symbols(build / "main.nef")
    module_names = [line.split("*", 1)[1].strip() for line in (build / "../../" / ("heartgold.de" if rom.code == "IPKD" else "soulsilver.de") / "main.sha1").read_text().splitlines()]
    arm9 = bytearray(rom.arm9(True))
    footer = rom.data[rom.arm9_offset + rom.arm9_size:rom.arm9_offset + rom.arm9_size + 12]
    parameters = struct.unpack_from("<I", footer, 4)[0]
    struct.pack_into("<I", arm9, parameters + 20, 0)
    references = [("main", 0x02000000, bytes(arm9) + footer)]
    references.extend((module_names[index + 1].removesuffix(".sbin"), ov["address"], rom.overlay(ov, True))
                      for index, ov in enumerate(rom.overlays))
    result = []
    for (module, address, expected), filename in zip(references, module_names):
        actual = (build / filename).read_bytes()
        if actual == expected:
            continue
        groups = []
        for index, (a, b) in enumerate(zip(actual, expected)):
            if a == b:
                continue
            if groups and index - groups[-1][-1] < 8:
                groups[-1].append(index)
            else:
                groups.append([index])
        differences = []
        for group in groups:
            start, end = group[0] & ~1, (group[-1] + 2) & ~1
            covering = [s for s in symbols.get(module, [])
                        if s["address"] <= address + start < s["address"] + s["size"]]
            covering.sort(key=lambda s: s["size"])
            differences.append({"address": f"0x{address + start:08X}", "offset": start,
                                "actual": actual[start:end].hex(), "expected": expected[start:end].hex(),
                                "symbols": covering[:2]})
        result.append({"module": module, "file": filename, "actual_size": len(actual),
                       "expected_size": len(expected), "changed_bytes": sum(len(g) for g in groups),
                       "differences": differences})
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("build", type=Path)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--output", type=Path)
    arguments = parser.parse_args()
    result = compare(arguments.build, Rom(arguments.rom))
    if arguments.output:
        arguments.output.write_text(json.dumps(result, indent=2) + "\n")
    for module in result:
        print(f"{module['module']}: {module['actual_size']} / {module['expected_size']} bytes; "
              f"{module['changed_bytes']} differing bytes in {len(module['differences'])} ranges")
    print(f"{130 - len(result)}/130 modules match")


if __name__ == "__main__":
    main()
