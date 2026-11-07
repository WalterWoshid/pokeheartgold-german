#!/usr/bin/env python3
"""Import German asset differences and rebuild localized NitroFS files."""

import argparse
import csv
import json
from pathlib import Path
import struct
import subprocess
import tempfile

from rom import GERMAN_SHA1, Rom, sha1
from source_assets import build as build_source


class Narc:
    def __init__(self, data):
        if data[:4] != b"NARC":
            raise ValueError("Not a NARC archive")
        self.header = data[:16]
        self.blocks = []
        offset = struct.unpack_from("<H", data, 12)[0]
        self.entries = None
        for _ in range(struct.unpack_from("<H", data, 14)[0]):
            magic, size = struct.unpack_from("<4sI", data, offset)
            block = data[offset:offset + size]
            if len(block) != size or size < 8:
                raise ValueError("Truncated NARC block")
            self.blocks.append((magic, block))
            if magic == b"BTAF":
                count = struct.unpack_from("<H", block, 8)[0]
                allocations = [struct.unpack_from("<II", block, 12 + i * 8) for i in range(count)]
            elif magic == b"GMIF":
                payload = block[8:]
                self.entries = [payload[start:end] for start, end in allocations]
            offset += size
        if self.entries is None or offset != len(data):
            raise ValueError("Invalid NARC layout")

    def pack(self):
        payload = bytearray()
        allocations = bytearray()
        for entry in self.entries:
            start = len(payload)
            payload.extend(entry)
            allocations.extend(struct.pack("<II", start, len(payload)))
            payload.extend(b"\xFF" * (-len(payload) % 4))
        blocks = []
        for magic, original in self.blocks:
            if magic == b"BTAF":
                block = original[:12] + allocations
                block = block[:4] + struct.pack("<I", len(block)) + block[8:]
            elif magic == b"GMIF":
                block = magic + struct.pack("<I", 8 + len(payload)) + payload
            else:
                block = original
            blocks.append(block)
        result = b"".join(blocks)
        return self.header[:8] + struct.pack("<I", len(result) + 16) + self.header[12:] + result


def run_msgenc(program, charmap, mode, text, binary):
    subprocess.run([str(program), mode, "--json", "-c", str(charmap), str(text), str(binary)],
                   check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)


def import_assets(arguments):
    us, de = Rom(arguments.us), Rom(arguments.german)
    if de.digest != GERMAN_SHA1.get(de.code):
        raise ValueError("German ROM does not match the verified retail hash")
    expected_code = "IPKD" if arguments.version == "heartgold" else "IPGD"
    if de.code != expected_code:
        raise ValueError("German ROM does not match the selected version")
    destination = arguments.destination
    destination.mkdir(parents=True, exist_ok=True)
    manifest = {"game_code": de.code, "reference_sha1": de.digest, "files": {}}
    charmap = arguments.source / "tools/msgenc/charmap.txt"
    counts = {"archives": 0, "members": 0, "json_messages": 0, "binary_messages": 0, "raw_files": 0}
    with tempfile.TemporaryDirectory() as temporary:
        temporary = Path(temporary)
        for name, index in de.files.items():
            original = us.file(us.files[name])
            localized = de.file(index)
            if original == localized:
                continue
            item = {"sha1": sha1(localized)}
            if localized.startswith(b"NARC") and original.startswith(b"NARC"):
                before, after = Narc(original), Narc(localized)
                if after.pack() != localized:
                    raise ValueError(f"NARC round trip failed: {name}")
                if len(before.entries) != len(after.entries):
                    raise ValueError(f"Archive member count changed: {name}")
                item["members"] = {}
                counts["archives"] += 1
                for member, (a, b) in enumerate(zip(before.entries, after.entries)):
                    if a == b:
                        continue
                    counts["members"] += 1
                    relative = Path("assets") / name / f"{member:04}.bin"
                    if arguments.msgenc and name in ("a/0/2/7", "pbr/msg.narc"):
                        binary = temporary / "message.bin"
                        binary.write_bytes(b)
                        text = temporary / f"msg_{member:04}.json"
                        run_msgenc(arguments.msgenc, charmap, "-d", text, binary)
                        messages = json.loads(text.read_text())
                        english = arguments.source / "files/msgdata/msg" / text.name
                        original_messages = json.loads(english.read_text())["messages"] if english.exists() and name == "a/0/2/7" else []
                        for i, message in enumerate(messages["messages"]):
                            if i < len(original_messages):
                                message["id"] = original_messages[i]["id"]
                            if "en_US" in message:
                                message["de_DE"] = message.pop("en_US")
                        text.write_text(json.dumps(messages, ensure_ascii=False, indent=2) + "\n")
                        roundtrip = temporary / "roundtrip.bin"
                        run_msgenc(arguments.msgenc, charmap, "-e", text, roundtrip)
                        if roundtrip.read_bytes() == b:
                            relative = Path("msgdata" if name == "a/0/2/7" else "pbr") / text.name
                            b = text.read_bytes()
                            counts["json_messages"] += 1
                        else:
                            counts["binary_messages"] += 1
                    target = destination / relative
                    target.parent.mkdir(parents=True, exist_ok=True)
                    if target.exists() and target.read_bytes() != b:
                        # Most localization assets are shared between HG and SS.
                        relative = Path(arguments.version) / relative
                        target = destination / relative
                        target.parent.mkdir(parents=True, exist_ok=True)
                    target.write_bytes(b)
                    item["members"][str(member)] = relative.as_posix()
            else:
                counts["raw_files"] += 1
                relative = Path("assets") / (name + ".bin")
                target = destination / relative
                target.parent.mkdir(parents=True, exist_ok=True)
                if target.exists() and target.read_bytes() != localized:
                    relative = Path(arguments.version) / relative
                    target = destination / relative
                    target.parent.mkdir(parents=True, exist_ok=True)
                target.write_bytes(localized)
                item["source"] = relative.as_posix()
            manifest["files"][name] = item
    (destination / f"{arguments.version}.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(json.dumps(counts))


def prepare(arguments):
    manifest = json.loads(arguments.manifest.read_text())
    assets = arguments.manifest.parent
    arguments.output.mkdir(parents=True, exist_ok=True)
    temporary = arguments.output / "messages"
    temporary.mkdir(exist_ok=True)
    with arguments.filesystem.open(newline="") as stream:
        rows = list(csv.reader(stream))
    for source, name in rows[1:]:
        name = name.lstrip("/")
        localized = manifest["files"].get(name)
        original = arguments.build / source
        data = original.read_bytes()
        if localized:
            if "source" in localized:
                source = localized["source"]
                data = (build_source(source, assets, temporary, arguments.nitrogfx, data)
                        if isinstance(source, dict) else (assets / source).read_bytes())
            else:
                archive = Narc(data)
                for index, relative in localized["members"].items():
                    if isinstance(relative, dict):
                        archive.entries[int(index)] = build_source(relative, assets, temporary, arguments.nitrogfx,
                                                                   archive.entries[int(index)])
                        continue
                    path = assets / relative
                    if path.suffix == ".json":
                        binary = temporary / (name.replace("/", "_") + "_" + index + ".bin")
                        run_msgenc(arguments.msgenc, arguments.charmap, "-e", path, binary)
                        archive.entries[int(index)] = binary.read_bytes()
                    else:
                        archive.entries[int(index)] = path.read_bytes()
                data = archive.pack()
        destination = arguments.output / "files" / name
        destination.parent.mkdir(parents=True, exist_ok=True)
        if not destination.exists() or destination.read_bytes() != data:
            destination.write_bytes(data)
    arguments.stamp.write_text("German filesystem prepared\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    importer = commands.add_parser("import")
    importer.add_argument("--us", type=Path, required=True)
    importer.add_argument("--german", type=Path, required=True)
    importer.add_argument("--version", choices=["heartgold", "soulsilver"], required=True)
    importer.add_argument("--destination", type=Path, default=Path("german"))
    importer.add_argument("--source", type=Path, default=Path("."))
    importer.add_argument("--msgenc", type=Path)
    builder = commands.add_parser("prepare")
    builder.add_argument("--manifest", type=Path, required=True)
    builder.add_argument("--filesystem", type=Path, required=True)
    builder.add_argument("--build", type=Path, required=True)
    builder.add_argument("--output", type=Path, required=True)
    builder.add_argument("--msgenc", type=Path, required=True)
    builder.add_argument("--nitrogfx", type=Path, required=True)
    builder.add_argument("--charmap", type=Path, required=True)
    builder.add_argument("--stamp", type=Path, required=True)
    arguments = parser.parse_args()
    if arguments.command == "import":
        import_assets(arguments)
    else:
        prepare(arguments)


if __name__ == "__main__":
    main()
