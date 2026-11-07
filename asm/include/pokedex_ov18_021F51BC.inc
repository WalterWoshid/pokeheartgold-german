	thumb_func_start ov18_021F51BC
ov18_021F51BC:
	push {r3, lr}
	ldr r0, _DE_021F4E20
	bl PlaySE
	mov r0, #0
	pop {r3, pc}
_DE_021F4E20:
	.word 0x000008EB
	thumb_func_end ov18_021F51BC
