	thumb_func_start ov18_021F4384
ov18_021F4384:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	mov r1, #0
	add r3, sp, #12
	str r1, [sp, #4]
	mov r1, #2
	add r2, sp, #16
	add r3, #2
	add r5, r0, #0
	str r1, [sp, #0]
	bl ov18_021F12C8
	mov r0, #0
	str r0, [sp, #20]
	ldr r0, _DE_021F4260
	ldrsb r1, [r5, r0]
	cmp r1, #0
	bne _DE_021F40FA
	add r0, #54
	ldr r0, [r5, r0]
	mov r4, #1
	cmp r0, #1
	ble _DE_021F40CA
	add r6, sp, #8
_DE_021F4008:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021E8AB0
	cmp r0, #0
	add r0, sp, #8
	bne _DE_021F402E
	ldr r1, _DE_021F4264
	str r0, [sp, #0]
	ldr r2, [r5, r1]
	lsl r1, r4, #2
	ldr r1, [r2, r1]
	add r3, sp, #8
	add r0, r5, #0
	add r2, sp, #12
	add r3, #2
	bl ov18_021F41C4
	b _DE_021F4054
_DE_021F402E:
	ldr r1, _DE_021F4264
	str r0, [sp, #0]
	ldr r1, [r5, r1]
	lsl r7, r4, #2
	add r3, sp, #8
	ldr r1, [r1, r7]
	add r0, r5, #0
	add r2, sp, #12
	add r3, #2
	bl ov18_021F42E4
	ldr r0, _DE_021F4264
	ldr r0, [r5, r0]
	ldr r0, [r0, r7]
	bl ov18_021E8B18
	add r1, sp, #20
	bl ov18_021F47C0
_DE_021F4054:
	mov r0, #2
	str r0, [sp, #0]
	mov r2, #4
	mov r3, #2
	add r7, r4, #0
	add r7, #8
	ldrsh r2, [r6, r2]
	ldrsh r3, [r6, r3]
	add r0, r5, #0
	add r1, r7, #0
	bl ov18_021F1294
	ldrb r2, [r6, #0]
	add r0, r5, #0
	add r1, r7, #0
	bl ov18_021F118C
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #1
	bl ov18_021F11C0
	ldrb r0, [r6, #0]
	lsl r1, r0, #1
	ldr r0, _DE_021F4268
	add r3, r0, r1
	ldrb r0, [r0, r1]
	lsr r2, r0, #1
	mov r0, #4
	ldrsh r1, [r6, r0]
	mov r0, #8
	ldrsh r7, [r6, r0]
	sub r0, r1, r2
	cmp r7, r0
	blt _DE_021F40BC
	add r0, r1, r2
	cmp r7, r0
	bge _DE_021F40BC
	ldrb r0, [r3, #1]
	lsr r2, r0, #1
	mov r0, #2
	ldrsh r1, [r6, r0]
	mov r0, #6
	ldrsh r0, [r6, r0]
	sub r3, r1, r2
	cmp r0, r3
	blt _DE_021F40BC
	add r1, r1, r2
	cmp r0, r1
	bge _DE_021F40BC
	mov r0, #1
	str r0, [sp, #4]
_DE_021F40BC:
	add r0, r4, #1
	lsl r0, r0, #16
	lsr r4, r0, #16
	ldr r0, _DE_021F426C
	ldr r0, [r5, r0]
	cmp r4, r0
	blt _DE_021F4008
_DE_021F40CA:
	add r4, #8
	ldr r1, [sp, #20]
	add r0, r5, #0
	add r2, r4, #0
	bl ov18_021F47F8
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _DE_021F40E2
	ldr r0, [sp, #20]
	cmp r0, #0
	bne _DE_021F40E4
_DE_021F40E2:
	b _DE_021F4254
_DE_021F40E4:
	add r1, r4, #0
	add r4, sp, #8
	mov r2, #8
	mov r3, #6
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	add r0, r5, #0
	bl ov18_021F4974
	str r0, [sp, #4]
	b _DE_021F4254
_DE_021F40FA:
	add r0, r5, #0
	bl ov18_021F4620
	ldr r1, _DE_021F4260
	add r0, r5, #0
	ldrsb r1, [r5, r1]
	bl ov18_021E8AB0
	cmp r0, #0
	add r0, sp, #8
	ldr r1, _DE_021F4264
	bne _DE_021F4194
	str r0, [sp, #0]
	ldr r2, [r5, r1]
	sub r1, #50
	ldrsb r1, [r5, r1]
	add r3, sp, #8
	add r0, r5, #0
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	add r2, sp, #12
	add r3, #2
	bl ov18_021F41C4
	mov r4, #2
	str r4, [sp, #0]
	add r3, sp, #8
	mov r2, #4
	ldrsh r2, [r3, r2]
	ldrsh r3, [r3, r4]
	add r0, r5, #0
	mov r1, #9
	bl ov18_021F1294
	add r2, sp, #8
	ldrb r2, [r2, #0]
	add r0, r5, #0
	mov r1, #9
	bl ov18_021F118C
	add r0, r5, #0
	mov r1, #9
	mov r2, #1
	bl ov18_021F11C0
	add r0, sp, #8
	ldrb r1, [r0, #0]
	lsl r4, r1, #1
	ldr r1, _DE_021F4268
	ldrb r1, [r1, r4]
	lsr r3, r1, #1
	mov r1, #4
	ldrsh r2, [r0, r1]
	mov r1, #8
	ldrsh r1, [r0, r1]
	sub r6, r2, r3
	cmp r1, r6
	blt _DE_021F4254
	add r2, r2, r3
	cmp r1, r2
	bge _DE_021F4254
	ldr r1, _DE_021F4270
	mov r2, #2
	ldrb r1, [r1, r4]
	ldrsh r3, [r0, r2]
	mov r2, #6
	ldrsh r2, [r0, r2]
	lsr r1, r1, #1
	sub r0, r3, r1
	cmp r2, r0
	blt _DE_021F4254
	add r0, r3, r1
	cmp r2, r0
	bge _DE_021F4254
	mov r0, #1
	str r0, [sp, #4]
	b _DE_021F4254
_DE_021F4194:
	str r0, [sp, #0]
	ldr r2, [r5, r1]
	sub r1, #50
	ldrsb r1, [r5, r1]
	add r3, sp, #8
	add r0, r5, #0
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	add r2, sp, #12
	add r3, #2
	bl ov18_021F42E4
	ldr r0, _DE_021F4264
	ldr r1, [r5, r0]
	sub r0, #50
	ldrsb r0, [r5, r0]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl ov18_021E8B18
	add r1, sp, #20
	bl ov18_021F47C0
	mov r4, #2
	str r4, [sp, #0]
	add r3, sp, #8
	mov r2, #4
	ldrsh r2, [r3, r2]
	ldrsh r3, [r3, r4]
	add r0, r5, #0
	mov r1, #9
	bl ov18_021F1294
	add r2, sp, #8
	ldrb r2, [r2, #0]
	add r0, r5, #0
	mov r1, #9
	bl ov18_021F118C
	add r0, r5, #0
	mov r1, #9
	mov r2, #1
	bl ov18_021F11C0
	add r0, sp, #8
	ldrb r1, [r0, #0]
	lsl r4, r1, #1
	ldr r1, _DE_021F4268
	ldrb r1, [r1, r4]
	lsr r3, r1, #1
	mov r1, #4
	ldrsh r2, [r0, r1]
	mov r1, #8
	ldrsh r1, [r0, r1]
	sub r6, r2, r3
	cmp r1, r6
	blt _DE_021F422A
	add r2, r2, r3
	cmp r1, r2
	bge _DE_021F422A
	ldr r1, _DE_021F4270
	mov r2, #2
	ldrb r1, [r1, r4]
	ldrsh r3, [r0, r2]
	mov r2, #6
	ldrsh r2, [r0, r2]
	lsr r1, r1, #1
	sub r0, r3, r1
	cmp r2, r0
	blt _DE_021F422A
	add r0, r3, r1
	cmp r2, r0
	bge _DE_021F422A
	mov r0, #1
	str r0, [sp, #4]
_DE_021F422A:
	ldr r1, [sp, #20]
	add r0, r5, #0
	mov r2, #10
	bl ov18_021F47F8
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _DE_021F4254
	ldr r0, [sp, #20]
	cmp r0, #0
	beq _DE_021F4254
	add r4, sp, #8
	mov r2, #8
	mov r3, #6
	ldrsh r2, [r4, r2]
	ldrsh r3, [r4, r3]
	add r0, r5, #0
	mov r1, #10
	bl ov18_021F4974
	str r0, [sp, #4]
_DE_021F4254:
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ov18_021F69C0
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F4260:
	.word 0x000018C2
_DE_021F4264:
	.word 0x000018F4
_DE_021F4268:
	.word ov18_021FA3B0
_DE_021F426C:
	.word 0x000018F8
_DE_021F4270:
	.word ov18_021FA3B0 + 1
	thumb_func_end ov18_021F4384
