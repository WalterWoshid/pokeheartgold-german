	thumb_func_start ov18_021F209C
ov18_021F209C:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r1, #0
	ldr r1, _DE_021F20A8
	add r5, r0, #0
	ldrb r0, [r5, r1]
	add r4, r3, #0
	cmp r0, #5
	bne _DE_021F1F82
	cmp r6, #0
	beq _DE_021F1F82
	lsl r0, r2, #2
	add r2, r5, r0
	ldr r0, _DE_021F20AC
	ldrh r0, [r2, r0]
	cmp r0, #1
	bne _DE_021F1FBA
_DE_021F1F82:
	lsl r4, r4, #2
	mov r0, #103
	add r1, r5, r4
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, _DE_021F20B0
	add r1, r5, r4
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, _DE_021F20B4
	add r1, r5, r4
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, _DE_021F20B8
	add r1, r5, r4
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F1FBA:
	add r0, r1, #3
	ldrb r0, [r5, r0]
	lsl r0, r0, #24
	lsr r0, r0, #28
	bne _DE_021F1FE4
	lsl r7, r4, #2
	mov r0, #103
	add r1, r5, r7
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, _DE_021F20B0
	add r1, r5, r7
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #2
	b _DE_021F1FFE
_DE_021F1FE4:
	lsl r7, r4, #2
	ldr r0, _DE_021F20B4
	add r1, r5, r7
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, _DE_021F20B8
	add r1, r5, r7
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_DE_021F1FFE:
	ldr r0, _DE_021F20BC
	mov r2, #240
	ldrb r3, [r5, r0]
	add r1, r3, #0
	bic r1, r2
	lsl r2, r3, #24
	lsr r3, r2, #28
	mov r2, #1
	eor r2, r3
	lsl r2, r2, #24
	lsr r2, r2, #24
	lsl r2, r2, #28
	lsr r2, r2, #24
	orr r1, r2
	strb r1, [r5, r0]
	ldr r0, [r5, #0]
	add r1, r6, #0
	ldr r0, [r0, #0]
	mov r2, #0
	bl Pokedex_GetSeenFormByIdx
	add r7, r0, #0
	cmp r6, #172
	bne _DE_021F2038
	cmp r7, #2
	bne _DE_021F2036
	mov r7, #1
	b _DE_021F2038
_DE_021F2036:
	mov r7, #0
_DE_021F2038:
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #6
	bl GetMonBaseStat_HandleAlternateForm
	lsl r0, r0, #16
	lsr r0, r0, #16
	str r0, [sp, #4]
	ldr r2, [sp, #4]
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F21FC
	lsl r0, r4, #2
	str r0, [sp, #0]
	add r1, r5, r0
	mov r0, #103
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r6, #0
	add r1, r7, #0
	mov r2, #7
	bl GetMonBaseStat_HandleAlternateForm
	lsl r0, r0, #16
	lsr r2, r0, #16
	beq _DE_021F207A
	ldr r0, [sp, #4]
	cmp r0, r2
	bne _DE_021F208C
_DE_021F207A:
	ldr r0, [sp, #0]
	add r1, r5, r0
	ldr r0, _DE_021F20B0
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F208C:
	add r0, r5, #0
	add r1, r4, #1
	bl ov18_021F21FC
	ldr r0, [sp, #0]
	add r1, r5, r0
	ldr r0, _DE_021F20B0
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F20A8:
	.word 0x00001854
_DE_021F20AC:
	.word 0x0000102A
_DE_021F20B0:
	.word 0x00000674
_DE_021F20B4:
	.word 0x00000678
_DE_021F20B8:
	.word 0x0000067C
_DE_021F20BC:
	.word 0x00001857
	thumb_func_end ov18_021F209C
