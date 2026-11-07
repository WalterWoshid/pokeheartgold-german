	thumb_func_start ov18_021F51CC
ov18_021F51CC:
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4, #11]
	cmp r0, #0
	beq _DE_021F4E34
	cmp r0, #1
	beq _DE_021F4E52
	b _DE_021F4E82
_DE_021F4E34:
	ldr r0, _DE_021F4E88
	bl PlaySE
	mov r2, #31
	mvn r2, r2
	mov r1, #1
	add r3, r2, #0
	add r0, r4, #0
	lsl r1, r1, #8
	sub r3, #192
	bl ov18_021F5198
	ldrb r0, [r4, #11]
	add r0, r0, #1
	strb r0, [r4, #11]
_DE_021F4E52:
	ldr r1, [r4, #0]
	ldr r0, _DE_021F4E8C
	ldr r0, [r1, r0]
	ldr r1, [r4, #12]
	bl ManagedSprite_OffsetAffineZRotation
	ldr r1, [r4, #0]
	ldr r0, _DE_021F4E8C
	ldr r0, [r1, r0]
	bl ManagedSprite_GetRotation
	add r1, r0, #0
	ldr r0, [r4, #0]
	bl ov18_021F5000
	ldr r1, [r4, #12]
	ldr r0, [r4, #16]
	add r1, r1, r0
	str r1, [r4, #12]
	ldr r0, [r4, #20]
	cmp r1, r0
	bne _DE_021F4E82
	mov r0, #0
	pop {r4, pc}
_DE_021F4E82:
	mov r0, #1
	pop {r4, pc}
	nop
_DE_021F4E88:
	.word 0x000008EB
_DE_021F4E8C:
	.word 0x0000068C
	thumb_func_end ov18_021F51CC
