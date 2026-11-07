	thumb_func_start ov18_021F36D4
ov18_021F36D4:
	thumb_func_start ov18_021F37D4
ov18_021F37D4:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	lsl r6, r2, #2
	mov r0, #103
	add r4, r1, #0
	add r1, r5, r6
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	add r1, sp, #4
	add r1, #2
	add r2, sp, #4
	str r3, [sp, #0]
	bl ManagedSprite_GetPositionXY
	cmp r4, #0
	bne _DE_021F3576
	add r1, sp, #4
	mov r0, #2
	ldrsh r4, [r1, r0]
	b _DE_021F3584
_DE_021F3576:
	cmp r4, #52
	bhs _DE_021F357E
	mov r4, #52
	b _DE_021F3584
_DE_021F357E:
	cmp r4, #204
	bls _DE_021F3584
	mov r4, #204
_DE_021F3584:
	mov r0, #103
	lsl r0, r0, #4
	add r7, r5, r0
	add r1, sp, #4
	ldr r0, [r7, r6]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	lsl r1, r4, #16
	add r3, sp, #4
	mov r2, #0
	ldrsh r2, [r3, r2]
	ldr r0, [r7, r6]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	ldr r0, _DE_021F3640
	add r1, sp, #4
	add r7, r5, r0
	ldr r0, [r7, r6]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	add r1, r4, #0
	sub r1, #16
	lsl r1, r1, #16
	add r3, sp, #4
	mov r2, #0
	ldrsh r2, [r3, r2]
	ldr r0, [r7, r6]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	ldr r0, _DE_021F3644
	add r1, r5, r6
	ldr r0, [r1, r0]
	add r1, r4, #0
	sub r1, #8
	lsl r1, r1, #16
	add r3, sp, #4
	mov r2, #0
	ldrsh r2, [r3, r2]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	ldr r0, _DE_021F3648
	add r1, r5, r6
	ldr r0, [r1, r0]
	lsl r1, r4, #16
	add r3, sp, #4
	mov r2, #0
	ldrsh r2, [r3, r2]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	mov r0, #26
	add r1, r5, r6
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	add r1, r4, #0
	add r1, #16
	lsl r1, r1, #16
	add r3, sp, #4
	mov r2, #0
	ldrsh r2, [r3, r2]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	ldr r0, [sp, #0]
	cmp r0, #1
	bne _DE_021F363A
	mov r0, #103
	lsl r0, r0, #4
	add r1, sp, #4
	ldr r0, [r5, r0]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	mov r0, #103
	lsl r0, r0, #4
	lsl r1, r4, #16
	add r3, sp, #4
	mov r2, #0
	ldrsh r2, [r3, r2]
	ldr r0, [r5, r0]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
_DE_021F363A:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F3640:
	.word 0x00000674
_DE_021F3644:
	.word 0x00000678
_DE_021F3648:
	.word 0x0000067C
	thumb_func_end ov18_021F36D4
