	thumb_func_start ov18_021F1314
ov18_021F1314:
	mov r1, #133
	lsl r1, r1, #4
	ldr r3, _DE_021F11EC
	ldr r0, [r0, r1]
	bx r3
	nop
_DE_021F11EC:
	.word NARC_Delete
	thumb_func_end ov18_021F1314
