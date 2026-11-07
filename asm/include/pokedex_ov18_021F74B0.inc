	thumb_func_start ov18_021F74B0
ov18_021F74B0:
	push {r3, lr}
	bl ov18_021F7444
	ldr r0, _DE_021F7120
	bl PlaySE
	pop {r3, pc}
	nop
_DE_021F7120:
	.word 0x000008E8
	thumb_func_end ov18_021F74B0
