	thumb_func_start ov18_021F6E98
ov18_021F6E98:
	push {r3, lr}
	bl ov18_021F6E58
	ldr r0, _DE_021F6B08
	bl PlaySE
	pop {r3, pc}
	nop
_DE_021F6B08:
	.word 0x000008E8
	thumb_func_end ov18_021F6E98
