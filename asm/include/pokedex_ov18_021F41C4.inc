	thumb_func_start ov18_021F41C4
ov18_021F41C4:
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r6, r0, #0
	add r0, r5, #0
	add r7, r2, #0
	str r3, [sp, #0]
	ldr r4, [sp, #24]
	bl ov18_021E8B24
	cmp r0, #1
	bne _DE_021F3E3C
	mov r0, #32
	mov r1, #4
	mov r2, #1
	mov r3, #3
	b _DE_021F3E84
_DE_021F3E3C:
	add r0, r5, #0
	bl ov18_021E8B0C
	cmp r0, #18
	bne _DE_021F3E5C
	mov r0, #36
	add r1, r5, #0
	mul r1, r0
	ldr r0, _DE_021F3F34
	mov r3, #2
	ldr r2, [r6, r0]
	ldrb r0, [r2, r1]
	add r1, r2, r1
	ldrb r1, [r1, #1]
	mov r2, #1
	b _DE_021F3E84
_DE_021F3E5C:
	add r0, r5, #0
	bl ov18_021E8B5C
	cmp r0, #1
	bne _DE_021F3E70
	mov r0, #35
	mov r1, #8
	mov r2, #2
	mov r3, #1
	b _DE_021F3E84
_DE_021F3E70:
	mov r0, #36
	add r1, r5, #0
	mul r1, r0
	ldr r0, _DE_021F3F34
	ldr r2, [r6, r0]
	add r3, r2, r1
	ldrb r0, [r2, r1]
	ldrb r1, [r3, #1]
	ldrb r2, [r3, #2]
	ldrb r3, [r3, #3]
_DE_021F3E84:
	cmp r2, #1
	bne _DE_021F3EBA
	cmp r3, #1
	bne _DE_021F3E92
	mov r5, #0
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3E92:
	cmp r3, #2
	bne _DE_021F3E9C
	mov r5, #6
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3E9C:
	cmp r3, #3
	bne _DE_021F3EA6
	mov r5, #7
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EA6:
	cmp r3, #4
	bne _DE_021F3EB0
	mov r5, #8
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EB0:
	cmp r3, #5
	bne _DE_021F3F04
	mov r5, #9
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EBA:
	cmp r2, #2
	bne _DE_021F3ECE
	cmp r3, #1
	bne _DE_021F3EC8
	mov r5, #1
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EC8:
	mov r5, #10
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3ECE:
	cmp r2, #3
	bne _DE_021F3EE2
	cmp r3, #1
	bne _DE_021F3EDC
	mov r5, #2
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EDC:
	mov r5, #11
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EE2:
	cmp r2, #4
	bne _DE_021F3EEC
	mov r5, #3
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EEC:
	cmp r2, #5
	bne _DE_021F3EF6
	mov r5, #4
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3EF6:
	cmp r2, #6
	bne _DE_021F3F00
	mov r5, #5
	strb r5, [r4, #0]
	b _DE_021F3F04
_DE_021F3F00:
	mov r5, #0
	strb r5, [r4, #0]
_DE_021F3F04:
	lsl r4, r2, #3
	lsr r2, r4, #31
	add r2, r4, r2
	mov r4, #99
	lsl r4, r4, #6
	ldrsb r5, [r6, r4]
	mov r4, #22
	asr r2, r2, #1
	mul r4, r5
	sub r0, r0, r4
	lsl r0, r0, #3
	add r0, r2, r0
	add r0, #64
	lsl r2, r1, #3
	lsl r1, r3, #3
	strh r0, [r7, #0]
	lsr r0, r1, #31
	add r0, r1, r0
	asr r0, r0, #1
	add r1, r2, r0
	ldr r0, [sp, #0]
	add r1, #40
	strh r1, [r0, #0]
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F3F34:
	.word 0x00001904
	thumb_func_end ov18_021F41C4
