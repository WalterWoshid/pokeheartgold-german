#!/usr/bin/env python3
"""Build executable-embedded UI graphics from indexed PNG source images."""

import argparse
import json
from pathlib import Path

from bitmap import png_to_tiles


def build(manifest, output):
    root = manifest.parent
    records = json.loads(manifest.read_text())
    lines = ["// Generated from German UI source images. Do not edit.", "#pragma once", "#ifdef PM_ASM"]
    for name, entry in records["assembly"].items():
        data = png_to_tiles(root / entry["source"], entry["bit_depth"])
        if len(data) != entry["size"]:
            raise ValueError(f"{name}: resizing requires updating its layout and size")
        lines.append("\t.macro GERMAN_BITMAP_" + name)
        for i in range(0, len(data), 16):
            lines.append("\t.byte " + ", ".join(f"0x{x:02X}" for x in data[i:i+16]))
        lines.append("\t.endm")
    lines.append("#else")
    for name, entry in records["c"].items():
        data = png_to_tiles(root / entry["source"], entry["bit_depth"])
        if len(data) != entry["size"]:
            raise ValueError(f"{name}: unexpected image size")
        lines.append("#define " + name + " \\")
        for i in range(0, len(data), 16):
            lines.append("    " + ", ".join(f"0x{x:02X}" for x in data[i:i+16]) + "," + (" " + chr(92) if i+16 < len(data) else ""))
    lines.append("#endif")
    output.write_text("\n".join(lines) + "\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    build(args.manifest, args.output)
