	thumb_func_start ov18_021F6F78
ov18_021F6F78:
	push {r3, lr}
	bl ov18_021F6F38
	ldr r0, _DE_021F6BE8
	bl PlaySE
	pop {r3, pc}
	nop
_DE_021F6BE8:
	.word 0x000008E8
	thumb_func_end ov18_021F6F78
