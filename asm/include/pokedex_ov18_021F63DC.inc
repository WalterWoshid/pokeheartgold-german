	thumb_func_start ov18_021F63DC
ov18_021F63DC:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, _DE_021F60F0
	add r1, sp, #4
	add r6, r2, #0
	ldr r0, [r5, r0]
	add r1, #2
	add r2, sp, #4
	bl ManagedSprite_GetPositionXY
	mov r0, #86
	str r0, [sp, #0]
	ldr r2, _DE_021F60F4
	add r0, r5, #0
	mov r1, #5
	mov r3, #96
	bl ov18_021F6230
	cmp r6, r0
	bhs _DE_021F6060
	add r6, r0, #0
_DE_021F6060:
	mov r0, #86
	str r0, [sp, #0]
	ldr r2, _DE_021F60F4
	add r0, r5, #0
	mov r1, #5
	mov r3, #96
	bl ov18_021F6244
	cmp r6, r0
	bls _DE_021F6076
	add r6, r0, #0
_DE_021F6076:
	ldr r0, _DE_021F60F0
	add r2, sp, #4
	mov r1, #2
	ldrsh r1, [r2, r1]
	lsl r2, r6, #16
	ldr r0, [r5, r0]
	asr r2, r2, #16
	bl ManagedSprite_SetPositionXY
	mov r0, #86
	str r0, [sp, #0]
	ldr r2, _DE_021F60F4
	add r0, r5, #0
	mov r1, #5
	mov r3, #96
	bl ov18_021F6230
	add r7, r0, #0
	mov r0, #86
	str r0, [sp, #0]
	ldr r2, _DE_021F60F4
	add r0, r5, #0
	mov r1, #5
	mov r3, #96
	bl ov18_021F6244
	sub r1, r0, r7
	ldr r0, _DE_021F60F8
	ldr r0, [r5, r0]
	sub r4, r0, #1
	lsl r0, r1, #8
	add r1, r4, #0
	blx _u32_div_f
	sub r1, r6, r7
	mov r3, #0
	lsl r2, r1, #8
	add r6, r3, #0
	add r7, r3, #0
_DE_021F60C4:
	cmp r2, r6
	blo _DE_021F60DE
	add r1, r7, r0
	cmp r2, r1
	bhs _DE_021F60DE
	ldr r0, _DE_021F60FC
	ldrsb r1, [r5, r0]
	cmp r1, r3
	beq _DE_021F60E8
	add sp, #8
	strb r3, [r5, r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F60DE:
	add r3, r3, #1
	add r6, r6, r0
	add r7, r7, r0
	cmp r3, r4
	bls _DE_021F60C4
_DE_021F60E8:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F60F0:
	.word 0x00000684
_DE_021F60F4:
	.word ov18_021FA304
_DE_021F60F8:
	.word 0x000018F8
_DE_021F60FC:
	.word 0x000018C2
	thumb_func_end ov18_021F63DC
