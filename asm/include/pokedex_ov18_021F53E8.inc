	thumb_func_start ov18_021F53E8
ov18_021F53E8:
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4, #11]
	cmp r0, #0
	beq _DE_021F5050
	cmp r0, #1
	beq _DE_021F506C
	b _DE_021F509C
_DE_021F5050:
	ldr r0, _DE_021F50A0
	bl PlaySE
	mov r1, #7
	mov r2, #63
	ldr r3, _DE_021F50A4
	add r0, r4, #0
	lsl r1, r1, #6
	mvn r2, r2
	bl ov18_021F5198
	ldrb r0, [r4, #11]
	add r0, r0, #1
	strb r0, [r4, #11]
_DE_021F506C:
	ldr r1, [r4, #0]
	ldr r0, _DE_021F50A8
	ldr r0, [r1, r0]
	ldr r1, [r4, #12]
	bl ManagedSprite_OffsetAffineZRotation
	ldr r1, [r4, #0]
	ldr r0, _DE_021F50A8
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
	bne _DE_021F509C
	mov r0, #0
	pop {r4, pc}
_DE_021F509C:
	mov r0, #1
	pop {r4, pc}
_DE_021F50A0:
	.word 0x000008EB
_DE_021F50A4:
	.word 0xFFFFFEC0
_DE_021F50A8:
	.word 0x0000068C
	thumb_func_end ov18_021F53E8
