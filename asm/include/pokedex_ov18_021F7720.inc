	thumb_func_start ov18_021F7720
ov18_021F7720:
	push {r3, lr}
	bl ov18_021F76E0
	ldr r0, _DE_021F7390
	bl PlaySE
	pop {r3, pc}
	nop
_DE_021F7390:
	.word 0x000008E8
	thumb_func_end ov18_021F7720
