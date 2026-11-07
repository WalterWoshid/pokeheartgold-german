	thumb_func_start ov18_021F3BD4
ov18_021F3BD4:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _DE_021F3880
	add r4, r1, #0
	add r1, sp, #0
	ldr r0, [r5, r0]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	ldr r0, _DE_021F3880
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
	ldr r0, _DE_021F3884
	add r1, sp, #0
	ldr r0, [r5, r0]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	ldr r0, _DE_021F3884
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
_DE_021F3880:
	.word 0x000006D8
_DE_021F3884:
	.word 0x00000714
	thumb_func_end ov18_021F3BD4
