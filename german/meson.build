regional_sources = files(fs.read('inputs.txt').strip().splitlines())
regional_manifest = files(game_version.to_lower() + '.json')
original_csv = game_version == 'HEARTGOLD' ? files('../heartgold.us/filesystem.csv') : files('../soulsilver.us/filesystem.csv')
python3 = find_program('python3', native: true)

localized_files = custom_target('german_filesystem',
    input: nitrofs_files + regional_sources + files('../tools/german/assets.py', '../tools/german/rom.py', '../tools/german/source_assets.py', '../tools/german/bitmap.py'),
    output: 'filesystem.stamp',
    command: [
        python3, files('../tools/german/assets.py'), 'prepare',
        '--manifest', regional_manifest,
        '--filesystem', original_csv,
        '--build', meson.project_build_root(),
        '--output', meson.project_build_root() / 'localized',
        '--msgenc', msgenc_exe,
        '--nitrogfx', nitrogfx_exe,
        '--charmap', charmap_txt,
        '--stamp', '@OUTPUT@',
    ],
)

german_embedded = custom_target('german_embedded',
    input: files(fs.read('embedded.inputs').strip().splitlines()) + files('../tools/german/embedded.py', '../tools/german/bitmap.py'),
    output: 'embedded.h',
    command: [python3, files('../tools/german/embedded.py'), files('embedded.json'), '@OUTPUT@'],
)

german_pokedex_data = custom_target('german_pokedex_data',
    input: files('ui/pokedex.json', '../tools/german/ui_tables.py'),
    output: 'pokedex_data.h',
    command: [python3, files('../tools/german/ui_tables.py'), '@INPUT0@', '@OUTPUT@'],
)
