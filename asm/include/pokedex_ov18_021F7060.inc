	thumb_func_start ov18_021F7060
ov18_021F7060:
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r0, r6, #0
	sub r0, #27
	add r4, r1, #0
	cmp r0, #1
	bhi _DE_021F6D3A
	ldr r0, _DE_021F6D50
	ldr r0, [r5, r0]
	lsl r1, r0, #3
	ldr r0, _DE_021F6D54
	cmp r4, #0
	ldrb r0, [r0, r1]
	beq _DE_021F6CE2
	cmp r4, #6
	bne _DE_021F6D0C
_DE_021F6CE2:
	ldr r3, _DE_021F6D54
	mov r1, #0
_DE_021F6CE6:
	ldrb r2, [r3, #0]
	cmp r0, r2
	bne _DE_021F6D02
	ldr r0, _DE_021F6D58
	lsl r2, r6, #24
	add r4, r1, #0
	lsl r1, r1, #24
	lsr r2, r2, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	add r3, r2, #0
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6D3A
_DE_021F6D02:
	add r1, r1, #1
	add r3, #8
	cmp r1, #26
	ble _DE_021F6CE6
	b _DE_021F6D3A
_DE_021F6D0C:
	cmp r4, #21
	beq _DE_021F6D14
	cmp r4, #26
	bne _DE_021F6D3A
_DE_021F6D14:
	ldr r3, _DE_021F6D5C
	mov r1, #26
_DE_021F6D18:
	ldrb r2, [r3, #0]
	cmp r0, r2
	bne _DE_021F6D34
	ldr r0, _DE_021F6D58
	lsl r2, r6, #24
	add r4, r1, #0
	lsl r1, r1, #24
	lsr r2, r2, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	add r3, r2, #0
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6D3A
_DE_021F6D34:
	sub r3, #8
	sub r1, r1, #1
	bpl _DE_021F6D18
_DE_021F6D3A:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F7018
	ldr r0, _DE_021F6D50
	str r6, [r5, r0]
	ldr r0, _DE_021F6D60
	bl PlaySE
	pop {r4, r5, r6, pc}
	nop
_DE_021F6D50:
	.word 0x00001894
_DE_021F6D54:
	.word ov18_021FBC34
_DE_021F6D58:
	.word 0x0000185C
_DE_021F6D5C:
	.word ov18_021FBC34 + 0xD0
_DE_021F6D60:
	.word 0x000008E8
	thumb_func_end ov18_021F7060
