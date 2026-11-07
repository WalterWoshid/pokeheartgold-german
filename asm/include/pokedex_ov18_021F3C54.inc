	thumb_func_start ov18_021F3C54
ov18_021F3C54:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _DE_021F38DC
	add r4, r1, #0
	add r1, sp, #0
	ldr r0, [r5, r0]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	ldr r0, _DE_021F38DC
	add r3, sp, #0
	mov r2, #0
	ldrsh r2, [r3, r2]
	mov r1, #2
	ldrsh r1, [r3, r1]
	add r2, r2, r4
	lsl r2, r2, #16
	ldr r0, [r5, r0]
	asr r2, r2, #16
	bl ManagedSprite_SetPositionXY
	pop {r3, r4, r5, pc}
	nop
_DE_021F38DC:
	.word 0x000006CC
	thumb_func_end ov18_021F3C54
