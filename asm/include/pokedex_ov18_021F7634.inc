	thumb_func_start ov18_021F7634
ov18_021F7634:
	push {r3, lr}
	bl ov18_021F75C8
	ldr r0, _DE_021F72A4
	bl PlaySE
	pop {r3, pc}
	nop
_DE_021F72A4:
	.word 0x000008E8
	thumb_func_end ov18_021F7634
