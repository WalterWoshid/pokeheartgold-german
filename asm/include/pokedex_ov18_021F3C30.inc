	thumb_func_start ov18_021F3C30
ov18_021F3C30:
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _DE_021F38A8
	mov r1, #48
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #144
	bl ManagedSprite_SetPositionXY
	add r0, r4, #0
	mov r1, #23
	mov r2, #1
	bl ov18_021F11C0
	pop {r4, pc}
	nop
_DE_021F38A8:
	.word 0x000006CC
	thumb_func_end ov18_021F3C30
