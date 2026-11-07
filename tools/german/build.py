#!/usr/bin/env python3
"""Build this checkout in Ubuntu WSL, keeping generated files in a Linux cache."""

import argparse
import json
import os
from pathlib import Path
import shlex
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--version", choices=["heartgold", "soulsilver"], default="heartgold")
    parser.add_argument("--language", choices=["german", "english"], default="german")
    parser.add_argument("--jobs", type=int, default=8)
    parser.add_argument("--sync-only", action="store_true")
    parser.add_argument("--target", help="Build a specific Ninja target instead of the ROM and checksum tests")
    arguments = parser.parse_args()
    if os.name != "nt":
        parser.error("This helper is for Windows. On Linux, run make GAME_LANGUAGE=GERMAN.")
    source = Path(__file__).resolve().parents[2]
    # Resolve the configured WSL user's home instead of assuming a Windows username.
    user_home = subprocess.check_output(["wsl", "-d", "Ubuntu", "--", "printenv", "HOME"], text=True).strip()
    cache = f"{user_home}/.cache/pokeheartgold-german/source"
    subprocess.run(["wsl", "-d", "Ubuntu", "--", "mkdir", "-p", cache], check=True)
    files = subprocess.check_output(["git", "ls-files", "-co", "--exclude-standard", "-z"], cwd=source).decode().split("\0")
    state = {}
    for name in files:
        if not name:
            continue
        path = source / name
        if not path.is_file():
            continue
        info = path.stat()
        stamp = [info.st_mtime_ns, info.st_size]
        state[name] = stamp
    linux_source = subprocess.check_output(["wsl", "-d", "Ubuntu", "--", "wslpath", "-a", str(source)], text=True).strip()
    subprocess.run(["wsl", "-d", "Ubuntu", "--", "python3", linux_source + "/tools/german/sync.py", linux_source, cache],
                   input=json.dumps(state), text=True, check=True)
    print(f"Linux source cache: {cache}", flush=True)
    if arguments.sync_only:
        return
    region = "de" if arguments.language == "german" else "us"
    build = f"build/{arguments.version}.{region}"
    command = (f"cd {shlex.quote(cache)} && find tools scripts -type f -name '*.sh' -exec chmod +x {{}} + && "
               f"make GAME_VERSION={arguments.version.upper()} GAME_LANGUAGE={arguments.language.upper()} "
               f"-j{arguments.jobs}")
    if arguments.target:
        command = (f"cd {shlex.quote(cache)} && ninja -C {build} -j{arguments.jobs} "
                   + shlex.quote(arguments.target))
    result = subprocess.run(["wsl", "-d", "Ubuntu", "--", "bash", "-lc", command])
    if arguments.target or result.returncode:
        raise SystemExit(result.returncode)
    rom_name = f"poke{arguments.version}.{region}.nds"
    target = source / build / rom_name
    target.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(["wsl", "-d", "Ubuntu", "--", "cp", cache + "/" + build + "/" + rom_name,
                    linux_source + "/" + build + "/" + rom_name], check=True)
    print(f"ROM: {target}", flush=True)
    raise SystemExit(result.returncode)


if __name__ == "__main__":
    main()
