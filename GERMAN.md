# German HeartGold and SoulSilver

The German targets rebuild the original revision 0 releases. English remains the default.

| Output | Game code | SHA-1 |
| --- | --- | --- |
| `pokeheartgold.de.nds` | IPKD | `13b6853aa93121069df1d17446d3ecb36872aecf` |
| `pokesoulsilver.de.nds` | IPGD | `576cdb7eec728c49aed85b9dd7e1e084ba1f08f9` |

## Build

Follow [INSTALL.md](INSTALL.md) to install the build dependencies. From a Linux checkout:

```sh
make GAME_VERSION=HEARTGOLD GAME_LANGUAGE=GERMAN -j8
make GAME_VERSION=SOULSILVER GAME_LANGUAGE=GERMAN -j8
```

Each command builds the ROM and checks ARM9, ARM7, the filesystem, and the complete ROM against the reference SHA-1 hashes. Outputs are under `build/heartgold.de/` and `build/soulsilver.de/`.

On this Windows checkout, use Ubuntu WSL through the supplied helper:

```powershell
python tools/german/build.py
python tools/german/build.py --version soulsilver
```

The helper synchronizes source files to `~/.cache/pokeheartgold-german/source` inside Ubuntu, builds there, and copies a successfully verified ROM back into this checkout. This avoids Windows path and line-ending problems. Use `--sync-only` to update the Linux source cache, or `--language english` to build the original English target.

## Source layout

- `heartgold.de/` and `soulsilver.de/` contain regional ROM metadata and expected checksums.
- `german/msgdata/` and `german/pbr/` contain editable German message banks using the `de_DE` key.
- `german/files/` follows the original filesystem/source paths. Graphics use indexed PNGs, palettes use JASC `.pal` files, and sprite cells, animations, tilemaps, fonts, and NPC trades use structured JSON.
- The German Pokédex sorting data, phonebook, and wallpaper password words use the original project's JSON or assembly schemas and native build rules.
- `german/images/` contains PNGs for the Wi-Fi Plaza graphics and battle HP-bar components formerly embedded as hexadecimal arrays.
- `german/ui/pokedex.json` contains named `WindowTemplate`, `ManagedSpriteTemplate`, `BgTemplate`, hitbox, callback, and numeric ID records. The build generates assembly from these records.
- `german/heartgold.json` and `german/soulsilver.json` select localized archive members and their build recipes. Unchanged archive members are built from the English project sources; localized members are encoded from the editable sources above.
- German code, metric units, alphabetical order, UI layouts, credits, and secure-area routines are selected with `GERMAN`. Regional assembly uses named routines and pointers.

There are no generic German `.bin` source dumps. Four localized 3D map models remain native `.nsbmd` resources, and three embedded programs remain `.dat` files, matching the English project's binary resource boundary. The texture changes in the three shared 3D texture containers are rebuilt from 18 named PNGs using the unchanged English containers as templates.

The build consumes checked-in source assets and does not require an original ROM. Reference ROMs and generated outputs stay ignored by Git.

## Editing assets

Keep pixel art in indexed PNG mode. Palette indices carry the Nintendo pixel values; changing the PNG's display palette alone does not recolor the in-game palette. Edit the associated `.pal` source to change in-game colors. Font width tables and sprite animation properties are in their JSON sidecars.

Embedded UI images retain their original byte size. Resizing these images requires changing their layout and `german/embedded.json` together. The build rejects accidental size changes. The Pokédex record fields follow the structures in `bg_window.h` and `sprite_system.h`.

```sh
python3 tools/german/test_sources.py
```

Run this from the Linux checkout after building `nitrogfx`; it checks tile coordinates, editing round trips, and the 271/272/273-byte LZ11 compression boundary. `NITROGFX` can point to another native tool build.

## Reference tools

The tools use Python's standard library. Assembly inspection also uses `arm-none-eabi-objdump`; message import uses the project's `msgenc`.

```sh
python3 tools/german/rom.py inspect /path/to/game.nds
python3 tools/german/rom.py extract /path/to/game.nds build/reference/game
python3 tools/german/rom.py compare /path/to/first.nds /path/to/second.nds
python3 tools/german/compare.py build/heartgold.de /path/to/heartgold-german.nds
```

`compare.py` checks the uncompressed main ARM9 module and all 129 overlays, and identifies differences by ELF symbol. `align.py` proposes corresponding routine locations across regional binaries; inferred locations need review. Pass `--reference-base` if the reference overlay loads at a different address. `thumb.py` renders bounded Thumb routines with symbolic calls and literal pools, while `data.py` renders named data tables. These are inspection and porting tools, separate from the normal build.

`assets.py prepare` encodes the localized source recipes and packs the archives during normal builds. `source_assets.py` contains the image, font, texture, and structured-data conversion logic; `bitmap.py`, `embedded.py`, and `ui_tables.py` handle the executable-embedded assets.

The original `assets.py import` command is a reference-ROM extraction tool. Re-running it replaces localization manifests with raw extraction results; it is not part of the normal source-editing workflow.
