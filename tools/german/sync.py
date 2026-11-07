#!/usr/bin/env python3
"""Synchronize source files inside WSL without a network filesystem per file."""

import json
from pathlib import Path
import sys


def main():
    source, destination = (Path(value) for value in sys.argv[1:3])
    request = json.load(sys.stdin)
    state_file = destination / ".german-source-sync.json"
    previous = json.loads(state_file.read_text()) if state_file.exists() else {}
    text_extensions = {".c", ".cpp", ".cc", ".h", ".hpp", ".s", ".inc", ".py", ".sh", ".txt",
                       ".json", ".ini", ".csv", ".build", ".wrap", ".md", ".rsf", ".in", ".options", ".sha1"}
    changed = 0
    for name, stamp in request.items():
        if previous.get(name) == stamp:
            continue
        path = source / name
        data = path.read_bytes()
        preserve_rom_asset = name.startswith("files/") and path.suffix.lower() in (".txt", ".inc")
        if not preserve_rom_asset and (path.suffix.lower() in text_extensions or path.name in ("Makefile", ".gitignore")):
            data = data.replace(b"\r\n", b"\n")
        target = destination / name
        target.parent.mkdir(parents=True, exist_ok=True)
        if not target.exists() or target.read_bytes() != data:
            target.write_bytes(data)
            changed += 1
        if path.suffix == ".sh":
            target.chmod(target.stat().st_mode | 0o111)
    for name in previous.keys() - request.keys():
        (destination / name).unlink(missing_ok=True)
    state_file.write_text(json.dumps(request) + "\n")
    print(f"Synchronized {changed} changed files", flush=True)


if __name__ == "__main__":
    main()
