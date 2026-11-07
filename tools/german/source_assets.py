#!/usr/bin/env python3
"""Convert localized archive members to editable sources and rebuild them."""

import argparse
import csv
import itertools
import json
from pathlib import Path
import shlex
import struct
import subprocess
import tempfile
import re

from bitmap import pack_pixels, read_png, unpack_pixels, write_png


TRADE_FIELDS = ("give_species hpIv atkIv defIv speedIv spAtkIv spDefIv ability otId cool beauty cute smart tough "
                "pid heldItem gender sheen language ask_species unk_50").split()


def texture_entries(data):
    base = data.index(b"TEX0")
    dictionary = base + struct.unpack_from("<H", data, base + 14)[0]
    entries = dictionary + struct.unpack_from("<H", data, dictionary + 6)[0]
    unit, names = struct.unpack_from("<HH", data, entries)
    pixels = base + struct.unpack_from("<I", data, base + 20)[0]
    result = {}
    for i in range(data[dictionary + 1]):
        parameter = struct.unpack_from("<I", data, entries + 4 + unit*i)[0]
        name = data[entries+names+i*16:entries+names+(i+1)*16].rstrip(b"\0").decode("ascii")
        result[name] = {"format": parameter >> 26 & 7, "width": 8 << (parameter >> 20 & 7),
                        "height": 8 << (parameter >> 23 & 7), "offset": pixels + (parameter & 65535)*8}
    return result


def write_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")


def run(program, source, target, options=()):
    result = subprocess.run([str(program), str(source), str(target), *map(str, options)],
                            capture_output=True, text=True)
    if result.returncode:
        raise ValueError(result.stderr.strip() or result.stdout.strip())
    return result.stdout


def unpack(data, directory, nitrogfx):
    if data[0] in (0x10, 0x11) and int.from_bytes(data[1:4], "little"):
        source, target = directory / "original.lz", directory / "decoded.raw"
        source.write_bytes(data)
        run(nitrogfx, source, target)
        return target.read_bytes(), True
    return data, False


def compression_options(original, data, directory, nitrogfx):
    source, target = directory / "decoded.raw", directory / "encoded.lz"
    source.write_bytes(data)
    extension = ["-extfmt"] if original[0] == 0x11 else []
    for distance, reverse, pad in itertools.product((2, 1), (False, True), (False, True)):
        options = extension + ["-search", str(distance)]
        if reverse:
            options += ["-reverse"]
        if not pad:
            options += ["-nopad"]
        run(nitrogfx, source, target, options)
        if target.read_bytes() == original:
            return options
    raise ValueError("No matching LZ compression settings")


def build(recipe, root, directory, nitrogfx, original=None):
    source = root / recipe["source"]
    target = directory / ("converted." + recipe["target"])
    if recipe["kind"] == "nitrogfx":
        options = list(recipe.get("options", []))
        if "metadata" in recipe:
            options += ["-metadata", str(root / recipe["metadata"])]
        run(nitrogfx, source, target, options)
        data = target.read_bytes()
    elif recipe["kind"] == "screen":
        value = json.loads(source.read_text(encoding="utf-8"))
        entries = []
        for row in value["tiles"]:
            for tile in row:
                entries.append(tile["index"] | tile["flip_x"] << 10 | tile["flip_y"] << 11 | tile["palette"] << 12)
        payload = struct.pack("<" + "H" * len(entries), *entries)
        header = struct.pack("<4sHHIHH", b"RCSN", value["byte_order"], value["version"], 36 + len(payload), 16, 1)
        data = header + struct.pack("<4sIHHHHI", b"NRCS", 20 + len(payload), value["width"],
                                    value["height"], value["color_mode"], value["screen_format"], len(payload)) + payload
    elif recipe["kind"] == "npc_trade":
        constants = {"LANGUAGE_JAPANESE": 1, "LANGUAGE_ENGLISH": 2, "LANGUAGE_FRENCH": 3, "LANGUAGE_ITALIAN": 4,
                     "LANGUAGE_GERMAN": 5, "LANGUAGE_SPANISH": 7, "LANGUAGE_KOREAN": 8}
        for header in ("species", "items"):
            text = (root.parent / "include/constants" / (header + ".h")).read_text()
            constants.update({key: int(value) for key, value in re.findall(r"#define\s+(\w+)\s+(\d+)\b", text)})
        value = json.loads(source.read_text())
        values = [constants[v] if isinstance(v, str) else v for v in (value[field] for field in TRADE_FIELDS)]
        data = struct.pack("<21I", *values)
    elif recipe["kind"] == "textures":
        data = bytearray(original)
        entries = texture_entries(data)
        for texture in json.loads(source.read_text())["textures"]:
            entry = entries[texture["name"]]
            if entry["format"] != 2:
                raise ValueError("Unsupported texture pixel format")
            width, height, pixels = read_png(root / texture["source"])
            if (width, height) != (entry["width"], entry["height"]):
                raise ValueError("Texture dimensions differ from its model")
            payload = pack_pixels(pixels, 2)
            data[entry["offset"]:entry["offset"] + len(payload)] = payload
        data = bytes(data)
    elif recipe["kind"] == "land_model":
        permissions, props, model_size, collision = struct.unpack_from("<4I", original)
        offset = 20 + permissions + props
        model = source.read_bytes()
        data = struct.pack("<4I", permissions, props, len(model), collision) + original[16:offset] + model + original[offset+model_size:]
    else:
        raise ValueError("Unknown source kind: " + recipe["kind"])
    if "compression" in recipe:
        source, target = directory / "compress.raw", directory / "compress.lz"
        source.write_bytes(data)
        run(nitrogfx, source, target, recipe["compression"])
        data = target.read_bytes()
    return data


def convert(data, stem, root, directory, nitrogfx, original=None):
    decoded, compressed = unpack(data, directory, nitrogfx)
    magic = decoded[:4]
    if magic == b"BTX0":
        textures = []
        for name, entry in texture_entries(data).items():
            if entry["format"] != 2:
                continue
            start = entry["offset"]
            size = entry["width"] * entry["height"] // 4
            if data[start:start+size] == original[start:start+size]:
                continue
            relative = stem.with_name(stem.name + "." + name).with_suffix("." + name + ".png")
            write_png(root / relative, entry["width"], entry["height"], unpack_pixels(data[start:start+size], 2), 4)
            textures.append({"name": name, "source": relative.as_posix()})
        relative = stem.with_suffix(".textures.json")
        write_json(root / relative, {"textures": textures})
        recipe = {"kind": "textures", "source": relative.as_posix(), "target": "nsbtx"}
        if build(recipe, root, directory, nitrogfx, original) != data:
            raise ValueError("Texture container has changes outside the edited images")
        return recipe
    kind = {b"RGCN": "NCGR", b"RLCN": "NCLR", b"RECN": "NCER", b"RNAN": "NANR", b"RCSN": "NSCR"}.get(magic)
    if kind is None and len(decoded) > 16 and decoded[:4] == b"\x10\0\0\0":
        kind = "NFGR"
    if kind is None:
        return None
    source = directory / ("original." + kind)
    source.write_bytes(decoded)
    extension = {"NCGR": ".png", "NCLR": ".pal", "NCER": ".cell.json", "NANR": ".anim.json",
                 "NSCR": ".screen.json", "NFGR": ".png"}[kind]
    relative = stem.with_suffix(extension)
    destination = root / relative
    destination.parent.mkdir(parents=True, exist_ok=True)
    recipe = {"kind": "nitrogfx", "source": relative.as_posix(), "target": kind}
    if kind == "NCGR":
        flags = ["-verbose"]
        height, width = struct.unpack_from("<HH", decoded, 24)
        if width == 65535:
            flags += ["-width", "16"]
        output = run(nitrogfx, source, destination, flags)
        suggested = next(line.split(":", 1)[1] for line in output.splitlines() if line.startswith("Suggested NCGR options:"))
        options = shlex.split(suggested)
        if "-width" in options and int(options[options.index("-width") + 1]) < 1:
            index = options.index("-width")
            del options[index:index+2]
        bitdepth = 4 if struct.unpack_from("<I", decoded, 28)[0] == 3 else 8
        options += ["-num_tiles", str(struct.unpack_from("<I", decoded, 40)[0] // (bitdepth * 8))]
        recipe["options"] = options
    elif kind == "NFGR":
        metadata = stem.with_suffix(".font.json")
        run(nitrogfx, source, destination, ["-metadata", root / metadata])
        recipe["metadata"] = metadata.as_posix()
    elif kind == "NSCR":
        width, height, mode, screen_format, size = struct.unpack_from("<HHHHI", decoded, 24)
        entries = struct.unpack_from("<" + "H" * (size // 2), decoded, 36)
        columns = width // 8
        tiles = [{"index": v & 1023, "flip_x": bool(v & 1024), "flip_y": bool(v & 2048), "palette": v >> 12} for v in entries]
        write_json(destination, {"byte_order": struct.unpack_from("<H", decoded, 4)[0], "version": struct.unpack_from("<H", decoded, 6)[0],
                                 "width": width, "height": height, "color_mode": mode, "screen_format": screen_format,
                                 "tiles": [tiles[i:i+columns] for i in range(0, len(tiles), columns)]})
        recipe["kind"] = "screen"
    else:
        run(nitrogfx, source, destination)
        if kind == "NCLR":
            recipe["options"] = ["-bitdepth", "8" if struct.unpack_from("<I", decoded, 24)[0] == 4 else "4"]
    if compressed:
        recipe["compression"] = compression_options(data, decoded, directory, nitrogfx)
    rebuilt = build(recipe, root, directory, nitrogfx)
    if rebuilt != data:
        positions = [i for i, (a, b) in enumerate(zip(decoded, unpack(rebuilt, directory, nitrogfx)[0])) if a != b]
        raise ValueError(f"{kind} round trip failed: {len(rebuilt)}/{len(data)} bytes; offsets {positions[:12]}")
    return recipe


def import_sources(root, build_dir):
    from assets import Narc
    nitrogfx = build_dir / "tools/nitrogfx/nitrogfx"
    with (root.parent / "heartgold.us/filesystem.csv").open(newline="") as stream:
        paths = {target.lstrip("/"): source for source, target in list(csv.reader(stream))[1:]}
    converted, failures = {}, {}
    manifests = []
    with tempfile.TemporaryDirectory() as temporary:
        directory = Path(temporary)
        for game in ("heartgold", "soulsilver"):
            path = root / (game + ".json")
            manifest = json.loads(path.read_text())
            manifests.append((path, manifest))
            for name, item in manifest["files"].items():
                members = item.get("members", {"file": item.get("source")})
                for index, relative in list(members.items()):
                    if not isinstance(relative, str) or not relative.endswith(".bin"):
                        continue
                    if relative in converted:
                        recipe = converted[relative]
                    elif relative in failures:
                        continue
                    else:
                        source = Path(paths[name])
                        stem = Path("files") / source.relative_to("files").with_suffix("") / index
                        try:
                            original = None
                            if name == "a/0/4/4":
                                original = Narc((root.parent / paths[name]).read_bytes()).entries[int(index)]
                            recipe = convert((root / relative).read_bytes(), stem, root, directory, nitrogfx, original)
                        except (ValueError, subprocess.SubprocessError) as error:
                            failures[relative] = str(error)
                            print(relative, error, flush=True)
                            continue
                        if recipe is None:
                            failures[relative] = "Format needs a dedicated converter"
                            continue
                        converted[relative] = recipe
                    if "members" in item:
                        item["members"][index] = recipe
                    else:
                        item["source"] = recipe
        for path, manifest in manifests:
            write_json(path, manifest)
    write_json(root.parent / "build/reference/source-asset-import.json", {"converted": len(converted), "remaining": failures})
    print(f"Converted {len(converted)} assets; {len(failures)} remaining", flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path("german"))
    parser.add_argument("--build", type=Path, default=Path("build/heartgold.de"))
    args = parser.parse_args()
    import_sources(args.root.resolve(), args.build.resolve())


if __name__ == "__main__":
    main()
