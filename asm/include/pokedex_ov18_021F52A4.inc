	thumb_func_start ov18_021F52A4
ov18_021F52A4:
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4, #11]
	cmp r0, #0
	beq _DE_021F4F0C
	cmp r0, #1
	beq _DE_021F4F28
	b _DE_021F4F58
_DE_021F4F0C:
	ldr r0, _DE_021F4F5C
	bl PlaySE
	mov r1, #5
	mov r2, #31
	ldr r3, _DE_021F4F60
	add r0, r4, #0
	lsl r1, r1, #6
	mvn r2, r2
	bl ov18_021F5198
	ldrb r0, [r4, #11]
	add r0, r0, #1
	strb r0, [r4, #11]
_DE_021F4F28:
	ldr r1, [r4, #0]
	ldr r0, _DE_021F4F64
	ldr r0, [r1, r0]
	ldr r1, [r4, #12]
	bl ManagedSprite_OffsetAffineZRotation
	ldr r1, [r4, #0]
	ldr r0, _DE_021F4F64
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
	bne _DE_021F4F58
	mov r0, #0
	pop {r4, pc}
_DE_021F4F58:
	mov r0, #1
	pop {r4, pc}
_DE_021F4F5C:
	.word 0x000008EB
_DE_021F4F60:
	.word 0xFFFFFEE0
_DE_021F4F64:
	.word 0x0000068C
	thumb_func_end ov18_021F52A4
