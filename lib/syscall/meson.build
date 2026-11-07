
libsyscall_link_args = [
    '-library',
    '-nodead',
    '-w', 'off',
    '-proc', 'v5te'
]

if game_language == 'GERMAN'
    if game_version == 'HEARTGOLD'
        libsyscall_asm = files('asm/_secure_IPKD.s')
    else
        libsyscall_asm = files('asm/_secure_IPGD.s')
    endif
elif game_version == 'HEARTGOLD'
    libsyscall_asm = files(
        'asm/_secure_IPKE.s'
    )
elif game_version == 'SOULSILVER'
    libsyscall_asm = files(
        'asm/_secure_IPGE.s'
    )
endif

libsyscall_public_includes = include_directories('.')

libsyscall = static_library('syscall',
    sources : libsyscall_asm,
    link_args : libsyscall_link_args,
    include_directories : libsyscall_public_includes,
    pic : false
)
