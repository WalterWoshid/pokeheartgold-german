	thumb_func_start ov18_021F3B2C
ov18_021F3B2C:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _DE_021F37B4
	add r4, r1, #0
	add r1, sp, #0
	ldr r0, [r5, r0]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	ldr r0, _DE_021F37B4
	add r3, sp, #0
	mov r1, #2
	ldrsh r1, [r3, r1]
	mov r2, #0
	ldrsh r2, [r3, r2]
	add r1, r1, r4
	lsl r1, r1, #16
	ldr r0, [r5, r0]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	pop {r3, r4, r5, pc}
	nop
_DE_021F37B4:
	.word 0x000006AC
	thumb_func_end ov18_021F3B2C
