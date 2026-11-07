#!/usr/bin/env python3
"""Inspect, extract, and compare the supplied retail ROMs using only Python."""

import argparse
import hashlib
import json
from pathlib import Path
import struct


GERMAN_SHA1 = {
    "IPKD": "13b6853aa93121069df1d17446d3ecb36872aecf",
    "IPGD": "576cdb7eec728c49aed85b9dd7e1e084ba1f08f9",
}


def sha1(data):
    return hashlib.sha1(data).hexdigest()


def decompress_blz(data):
    """Decode the backwards LZ compression used by ARM9 and its overlays."""
    if len(data) < 8:
        raise ValueError("Truncated BLZ data")
    trailer, extra = struct.unpack_from("<II", data, len(data) - 8)
    if extra == 0:
        return data
    header_length = trailer >> 24
    compressed_length = trailer & 0xFFFFFF
    if not 8 <= header_length <= compressed_length <= len(data):
        raise ValueError("Invalid BLZ footer")
    output = bytearray(data) + bytearray(extra)
    source = len(data) - header_length
    stop = len(data) - compressed_length
    destination = len(output)
    while source > stop:
        source -= 1
        flags = data[source]
        for bit in range(7, -1, -1):
            if source <= stop:
                break
            if flags & (1 << bit):
                if source - stop < 2:
                    raise ValueError("Truncated BLZ backreference")
                source -= 2
                pair = (data[source + 1] << 8) | data[source]
                length = (pair >> 12) + 3
                distance = (pair & 0xFFF) + 3
                for _ in range(length):
                    destination -= 1
                    if destination < stop or destination + distance >= len(output):
                        raise ValueError("Invalid BLZ backreference")
                    output[destination] = output[destination + distance]
            else:
                source -= 1
                destination -= 1
                if destination < stop:
                    raise ValueError("Invalid BLZ literal")
                output[destination] = data[source]
    if destination != stop:
        raise ValueError("BLZ output length does not match its footer")
    return bytes(output)


class Rom:
    def __init__(self, path):
        self.path = Path(path)
        self.data = self.path.read_bytes()
        if len(self.data) < 0x200:
            raise ValueError("Truncated Nintendo DS header")
        self.code = self.data[12:16].decode("ascii")
        self.revision = self.data[30]
        self.digest = sha1(self.data)
        self.arm9_offset, self.arm9_entry, self.arm9_address, self.arm9_size = self.words(0x20, 4)
        self.arm7_offset, self.arm7_entry, self.arm7_address, self.arm7_size = self.words(0x30, 4)
        self.fnt_offset, self.fnt_size, self.fat_offset, self.fat_size = self.words(0x40, 4)
        self.ov9_offset, self.ov9_size, self.ov7_offset, self.ov7_size = self.words(0x50, 4)
        self.banner_offset = self.words(0x68)[0]
        if self.fat_size % 8 or self.ov9_size % 32:
            raise ValueError("Invalid allocation or overlay table length")
        self.fat = [self.words(self.fat_offset + index, 2) for index in range(0, self.fat_size, 8)]
        for start, end in self.fat:
            if not 0 <= start <= end <= len(self.data):
                raise ValueError("File allocation extends outside ROM")
        self.files = {}
        self._walk_directory(0xF000, "", set())
        self.overlays = []
        for offset in range(self.ov9_offset, self.ov9_offset + self.ov9_size, 32):
            values = self.words(offset, 8)
            self.overlays.append(dict(zip(
                ("id", "address", "size", "bss_size", "init_start", "init_end", "file_id", "flags"),
                values,
            )))

    def words(self, offset, count=1):
        return struct.unpack_from("<" + "I" * count, self.data, offset)

    def _walk_directory(self, directory, prefix, visited):
        if directory in visited:
            raise ValueError("Cycle in filename table")
        visited.add(directory)
        table = self.fnt_offset + 8 * (directory & 0xFFF)
        subtable, file_id, _ = struct.unpack_from("<IHH", self.data, table)
        position = self.fnt_offset + subtable
        end = self.fnt_offset + self.fnt_size
        while position < end:
            length = self.data[position]
            position += 1
            if length == 0:
                return
            name_length = length & 0x7F
            name = self.data[position:position + name_length].decode("ascii")
            position += name_length
            if name in (".", "..") or "/" in name or "\\" in name:
                raise ValueError("Unsafe ROM filename")
            path = prefix + name
            if length & 0x80:
                child = struct.unpack_from("<H", self.data, position)[0]
                position += 2
                self._walk_directory(child, path + "/", visited)
            else:
                if file_id >= len(self.fat) or path in self.files:
                    raise ValueError("Invalid filename table entry")
                self.files[path] = file_id
                file_id += 1
        raise ValueError("Unterminated filename subtable")

    def file(self, file_id):
        start, end = self.fat[file_id]
        return self.data[start:end]

    def arm9(self, decompress=False):
        data = self.data[self.arm9_offset:self.arm9_offset + self.arm9_size]
        if decompress:
            return decompress_blz(data)
        return data

    def overlay(self, overlay, decompress=False):
        data = self.file(overlay["file_id"])
        if decompress and overlay["flags"] & 0x1000000:
            data = decompress_blz(data)
        if decompress and len(data) != overlay["size"]:
            raise ValueError(f"Overlay {overlay['id']} has an unexpected decoded size")
        return data

    def manifest(self):
        return {
            "source": self.path.name,
            "sha1": self.digest,
            "game_code": self.code,
            "revision": self.revision,
            "size": len(self.data),
            "verified_german": self.digest == GERMAN_SHA1.get(self.code),
            "arm9": {"offset": self.arm9_offset, "size": self.arm9_size,
                     "sha1": sha1(self.arm9()), "decoded_size": len(self.arm9(True))},
            "arm7": {"offset": self.arm7_offset, "size": self.arm7_size,
                     "sha1": sha1(self.data[self.arm7_offset:self.arm7_offset + self.arm7_size])},
            "overlays": [{**ov, "sha1": sha1(self.overlay(ov)),
                          "decoded_sha1": sha1(self.overlay(ov, True))} for ov in self.overlays],
            "files": {path: {"id": index, "offset": self.fat[index][0],
                             "size": self.fat[index][1] - self.fat[index][0],
                             "sha1": sha1(self.file(index))}
                      for path, index in self.files.items()},
        }

    def extract(self, destination):
        destination = Path(destination)
        destination.mkdir(parents=True, exist_ok=True)
        for name, data in {
            "header.bin": self.data[:0x200],
            "banner.bin": self.data[self.banner_offset:self.banner_offset + 0x840],
            "arm9.bin": self.arm9(),
            "arm9.dec.bin": self.arm9(True),
            "arm7.bin": self.data[self.arm7_offset:self.arm7_offset + self.arm7_size],
            "arm9_overlays.bin": self.data[self.ov9_offset:self.ov9_offset + self.ov9_size],
        }.items():
            (destination / name).write_bytes(data)
        for ov in self.overlays:
            path = destination / "overlays" / f"overlay_{ov['id']:03}.bin"
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(self.overlay(ov, True))
        for name, index in self.files.items():
            path = destination / "files" / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(self.file(index))
        (destination / "manifest.json").write_text(json.dumps(self.manifest(), indent=2) + "\n")


def compare(first, second):
    left, right = first.manifest(), second.manifest()
    changed_files = []
    for name in sorted(left["files"].keys() | right["files"].keys()):
        a, b = left["files"].get(name), right["files"].get(name)
        if a is None or b is None or a["sha1"] != b["sha1"]:
            changed_files.append({"path": name, "left": a, "right": b})
    overlays_a = {ov["id"]: ov for ov in left["overlays"]}
    overlays_b = {ov["id"]: ov for ov in right["overlays"]}
    changed_overlays = []
    for index in sorted(overlays_a.keys() | overlays_b.keys()):
        a, b = overlays_a.get(index), overlays_b.get(index)
        if a is None or b is None or a["decoded_sha1"] != b["decoded_sha1"]:
            changed_overlays.append({"id": index, "left": a, "right": b})
    return {"left": str(first.path), "right": str(second.path),
            "arm9_equal": first.arm9(True) == second.arm9(True),
            "arm7_equal": left["arm7"]["sha1"] == right["arm7"]["sha1"],
            "changed_files": changed_files, "changed_overlays": changed_overlays}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    subparsers = parser.add_subparsers(dest="command", required=True)
    inspect = subparsers.add_parser("inspect")
    inspect.add_argument("rom", type=Path)
    extract = subparsers.add_parser("extract")
    extract.add_argument("rom", type=Path)
    extract.add_argument("destination", type=Path)
    diff = subparsers.add_parser("compare")
    diff.add_argument("first", type=Path)
    diff.add_argument("second", type=Path)
    diff.add_argument("--output", type=Path)
    arguments = parser.parse_args()
    if arguments.command == "extract":
        rom = Rom(arguments.rom)
        rom.extract(arguments.destination)
        print(f"Extracted {len(rom.files)} files and {len(rom.overlays)} overlays: {rom.code}")
    else:
        result = (Rom(arguments.rom).manifest() if arguments.command == "inspect"
                  else compare(Rom(arguments.first), Rom(arguments.second)))
        output = json.dumps(result, indent=2) + "\n"
        if getattr(arguments, "output", None):
            arguments.output.parent.mkdir(parents=True, exist_ok=True)
            arguments.output.write_text(output)
        else:
            print(output, end="")


if __name__ == "__main__":
    main()
