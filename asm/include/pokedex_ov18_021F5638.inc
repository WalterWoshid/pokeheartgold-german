	thumb_func_start ov18_021F5638
ov18_021F5638:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldrb r0, [r5, #11]
	cmp r0, #0
	beq _DE_021F52A0
	cmp r0, #1
	beq _DE_021F52B8
	b _DE_021F5326
_DE_021F52A0:
	ldr r0, _DE_021F532C
	bl PlaySE
	mov r1, #3
	add r0, r5, #0
	lsl r1, r1, #8
	mov r2, #0
	bl ov18_021F5180
	ldrb r0, [r5, #11]
	add r0, r0, #1
	strb r0, [r5, #11]
_DE_021F52B8:
	ldr r1, [r5, #0]
	ldr r0, _DE_021F5330
	ldr r0, [r1, r0]
	ldr r1, [r5, #12]
	bl ManagedSprite_OffsetAffineZRotation
	ldr r1, [r5, #0]
	ldr r0, _DE_021F5330
	ldr r0, [r1, r0]
	bl ManagedSprite_GetRotation
	add r4, r0, #0
	ldr r0, [r5, #0]
	add r1, r4, #0
	bl ov18_021F5000
	ldr r1, [r5, #12]
	ldr r0, [r5, #16]
	add r0, r1, r0
	str r0, [r5, #12]
	ldrb r0, [r5, #10]
	cmp r0, #0
	bne _DE_021F5306
	mov r1, #246
	lsl r1, r1, #8
	cmp r4, r1
	bhi _DE_021F5326
	ldr r2, [r5, #0]
	ldr r0, _DE_021F5330
	ldr r0, [r2, r0]
	bl ManagedSprite_SetAffineZRotation
	mov r1, #246
	ldr r0, [r5, #0]
	lsl r1, r1, #8
	bl ov18_021F5000
	mov r0, #0
	pop {r3, r4, r5, pc}
_DE_021F5306:
	mov r1, #10
	lsl r1, r1, #8
	cmp r4, r1
	blo _DE_021F5326
	ldr r2, [r5, #0]
	ldr r0, _DE_021F5330
	ldr r0, [r2, r0]
	bl ManagedSprite_SetAffineZRotation
	mov r1, #10
	ldr r0, [r5, #0]
	lsl r1, r1, #8
	bl ov18_021F5000
	mov r0, #0
	pop {r3, r4, r5, pc}
_DE_021F5326:
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_DE_021F532C:
	.word 0x000008EB
_DE_021F5330:
	.word 0x0000068C
	thumb_func_end ov18_021F5638
