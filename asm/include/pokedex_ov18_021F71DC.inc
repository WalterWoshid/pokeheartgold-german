	thumb_func_start ov18_021F71DC
ov18_021F71DC:
	push {r4, r5, r6, lr}
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	cmp r6, #18
	bne _DE_021F6EDC
	cmp r4, #0
	bne _DE_021F6E96
	ldr r0, _DE_021F6F88
	ldr r1, [r5, r0]
	cmp r1, #16
	blt _DE_021F6E78
	cmp r1, #17
	bgt _DE_021F6E78
	lsr r3, r1, #31
	lsl r2, r1, #30
	sub r2, r2, r3
	mov r1, #30
	ror r2, r1
	add r4, r3, r2
	sub r0, #56
	lsl r1, r4, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #18
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6E78:
	cmp r1, #0
	blt _DE_021F6F72
	cmp r1, #1
	bgt _DE_021F6F72
	ldr r0, _DE_021F6F8C
	add r4, r1, #0
	lsl r1, r1, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #18
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6E96:
	cmp r4, #16
	bne _DE_021F6F72
	ldr r0, _DE_021F6F88
	ldr r1, [r5, r0]
	cmp r1, #0
	blt _DE_021F6EBE
	cmp r1, #1
	bgt _DE_021F6EBE
	add r4, r1, #0
	add r4, #16
	sub r0, #56
	lsl r1, r4, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #18
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6EBE:
	cmp r1, #16
	blt _DE_021F6F72
	cmp r1, #17
	bgt _DE_021F6F72
	ldr r0, _DE_021F6F8C
	add r4, r1, #0
	lsl r1, r1, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #18
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6EDC:
	cmp r6, #19
	bne _DE_021F6F72
	cmp r4, #3
	bne _DE_021F6F2E
	ldr r0, _DE_021F6F88
	ldr r1, [r5, r0]
	cmp r1, #14
	blt _DE_021F6F10
	cmp r1, #15
	bgt _DE_021F6F10
	lsr r3, r1, #31
	lsl r2, r1, #30
	sub r2, r2, r3
	mov r1, #30
	ror r2, r1
	add r4, r3, r2
	sub r0, #56
	lsl r1, r4, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #19
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6F10:
	cmp r1, #2
	blt _DE_021F6F72
	cmp r1, #3
	bgt _DE_021F6F72
	ldr r0, _DE_021F6F8C
	add r4, r1, #0
	lsl r1, r1, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #19
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6F2E:
	cmp r4, #15
	bne _DE_021F6F72
	ldr r0, _DE_021F6F88
	ldr r1, [r5, r0]
	cmp r1, #2
	blt _DE_021F6F56
	cmp r1, #3
	bgt _DE_021F6F56
	add r4, r1, #0
	add r4, #12
	sub r0, #56
	lsl r1, r4, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #19
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F6F72
_DE_021F6F56:
	cmp r1, #14
	blt _DE_021F6F72
	cmp r1, #15
	bgt _DE_021F6F72
	ldr r0, _DE_021F6F8C
	add r4, r1, #0
	lsl r1, r1, #24
	lsl r2, r6, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #19
	bl GridInputHandler_SetNextLastUnk0FInputs
_DE_021F6F72:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F719C
	ldr r0, _DE_021F6F88
	str r6, [r5, r0]
	ldr r0, _DE_021F6F90
	bl PlaySE
	pop {r4, r5, r6, pc}
	nop
_DE_021F6F88:
	.word 0x00001894
_DE_021F6F8C:
	.word 0x0000185C
_DE_021F6F90:
	.word 0x000008E8
	thumb_func_end ov18_021F71DC
