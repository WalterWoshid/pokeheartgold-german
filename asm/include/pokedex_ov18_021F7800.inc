	thumb_func_start ov18_021F7800
ov18_021F7800:
	push {r4, r5, r6, lr}
	add r4, r2, #0
	add r5, r0, #0
	add r6, r1, #0
	cmp r4, #15
	bne _DE_021F74FE
	cmp r6, #0
	bne _DE_021F74B8
	ldr r0, _DE_021F75A8
	ldr r1, [r5, r0]
	cmp r1, #0
	blt _DE_021F7492
	cmp r1, #2
	bgt _DE_021F7492
	sub r0, #56
	add r6, r1, #0
	lsl r1, r1, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #15
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F7492:
	cmp r1, #10
	blt _DE_021F7592
	cmp r1, #12
	bgt _DE_021F7592
	add r0, r1, #0
	mov r1, #5
	blx _s32_div_f
	ldr r0, _DE_021F75AC
	add r6, r1, #0
	lsl r1, r6, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #15
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F74B8:
	cmp r6, #10
	bne _DE_021F7592
	ldr r0, _DE_021F75A8
	ldr r1, [r5, r0]
	cmp r1, #0
	blt _DE_021F74E0
	cmp r1, #2
	bgt _DE_021F74E0
	add r6, r1, #0
	add r6, #10
	sub r0, #56
	lsl r1, r6, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #15
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F74E0:
	cmp r1, #10
	blt _DE_021F7592
	cmp r1, #12
	bgt _DE_021F7592
	ldr r0, _DE_021F75AC
	add r6, r1, #0
	lsl r1, r1, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #15
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F74FE:
	cmp r4, #16
	bne _DE_021F7592
	cmp r6, #4
	bne _DE_021F754E
	ldr r0, _DE_021F75A8
	ldr r1, [r5, r0]
	cmp r1, #3
	blt _DE_021F7528
	cmp r1, #4
	bgt _DE_021F7528
	sub r0, #56
	add r6, r1, #0
	lsl r1, r1, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #16
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F7528:
	cmp r1, #13
	blt _DE_021F7592
	cmp r1, #14
	bgt _DE_021F7592
	add r0, r1, #0
	mov r1, #5
	blx _s32_div_f
	ldr r0, _DE_021F75AC
	add r6, r1, #0
	lsl r1, r6, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #16
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F754E:
	cmp r6, #14
	bne _DE_021F7592
	ldr r0, _DE_021F75A8
	ldr r1, [r5, r0]
	cmp r1, #3
	blt _DE_021F7576
	cmp r1, #4
	bgt _DE_021F7576
	add r6, r1, #0
	add r6, #10
	sub r0, #56
	lsl r1, r6, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #16
	bl GridInputHandler_SetNextLastUnk0FInputs
	b _DE_021F7592
_DE_021F7576:
	cmp r1, #13
	blt _DE_021F7592
	cmp r1, #14
	bgt _DE_021F7592
	ldr r0, _DE_021F75AC
	add r6, r1, #0
	lsl r1, r1, #24
	lsl r2, r4, #24
	ldr r0, [r5, r0]
	lsr r1, r1, #24
	lsr r2, r2, #24
	mov r3, #16
	bl GridInputHandler_SetNextLastUnk0FInputs
_DE_021F7592:
	add r0, r5, #0
	add r1, r6, #0
	bl ov18_021F77C0
	ldr r0, _DE_021F75A8
	str r4, [r5, r0]
	ldr r0, _DE_021F75B0
	bl PlaySE
	pop {r4, r5, r6, pc}
	nop
_DE_021F75A8:
	.word 0x00001894
_DE_021F75AC:
	.word 0x0000185C
_DE_021F75B0:
	.word 0x000008E8
	thumb_func_end ov18_021F7800
