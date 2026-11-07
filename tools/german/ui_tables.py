#!/usr/bin/env python3
"""Serialize named Pokédex UI records into assembly for the matching build."""

import argparse
import json
from pathlib import Path


WINDOW_FIELDS = "bgId left top width height palette baseTile".split()
BG_FIELDS = "x y bufferSize baseTile size colorMode screenBase charBase bgExtPltt priority areaOver dummy mosaic".split()


def build(source, output):
    tables = json.loads(source.read_text(encoding="utf-8"))
    lines = ["// Generated from German Pokedex UI records. Do not edit."]
    for name, table in tables.items():
        lines.extend(["\t.global " + name, name + ":"])
        kind, entries = table["type"], table["entries"]
        for entry in entries:
            if kind == "WindowTemplate":
                lines.append("\t.byte " + ", ".join(str(entry[field]) for field in WINDOW_FIELDS[:6]))
                lines.append("\t.short " + str(entry["baseTile"]))
            elif kind == "ManagedSpriteTemplate":
                lines.append("\t.short " + ", ".join(str(entry[field]) for field in ("x", "y", "z", "animation")))
                lines.append("\t.word " + ", ".join(str(entry[field]) for field in ("drawPriority", "pal", "vram")))
                lines.append("\t.word " + ", ".join(map(str, entry["resources"])))
                lines.append("\t.word " + str(entry["bgPriority"]) + ", " + str(entry["vramTransfer"]))
            elif kind == "BgTemplate":
                lines.append("\t.word " + ", ".join(str(entry[field]) for field in BG_FIELDS[:4]))
                lines.append("\t.byte " + ", ".join(str(entry[field]) for field in BG_FIELDS[4:12]))
                lines.append("\t.word " + str(entry["mosaic"]))
            elif kind == "TouchscreenHitbox":
                lines.append("\t.byte " + ", ".join(str(entry[field]) for field in ("top", "bottom", "left", "right")))
            elif kind in ("callbacks", "u32"):
                lines.append("\t.word " + str(entry))
            elif kind == "u16":
                lines.append("\t.short " + str(entry))
            elif kind == "u8":
                lines.append("\t.byte " + str(entry))
            else:
                raise ValueError("Unknown UI table type: " + kind)
        lines.extend(["\t.size " + name + ",.-" + name, ""])
    output.write_text("\n".join(lines), encoding="utf-8")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    build(args.source, args.output)
