	thumb_func_start ov112_021F1624
ov112_021F1624:
	push {r4, r5, r6, r7, lr}
	sub sp, #20
	add r5, r0, #0
	ldr r0, _DE_021F1760
	str r1, [sp, #4]
	ldrb r1, [r5, r0]
	str r2, [sp, #8]
	lsl r1, r1, #2
	add r1, r5, r1
	add r1, #192
	ldr r4, [r1, #0]
	add r1, r0, #0
	sub r1, #25
	ldr r1, [r5, r1]
	str r1, [sp, #16]
	add r1, r0, #0
	sub r1, #21
	sub r0, #13
	ldr r1, [r5, r1]
	ldr r7, [r5, r0]
	str r1, [sp, #12]
	cmp r7, #12
	bge _DE_021F163A
	mov r6, #87
	b _DE_021F163C
_DE_021F163A:
	mov r6, #88
_DE_021F163C:
	ldr r1, [r5, #8]
	add r0, r5, #0
	mov r2, #0
	mov r3, #9
	bl ov112_021F1488
	add r1, r4, #0
	ldrh r3, [r4, #10]
	add r0, r5, #0
	add r1, #32
	mov r2, #1
	bl ov112_021F1584
	add r1, r4, #0
	add r0, r5, #0
	add r1, #16
	mov r2, #2
	mov r3, #9
	bl ov112_021F1488
	add r1, r4, #0
	ldrh r3, [r4, #12]
	add r0, r5, #0
	add r1, #54
	mov r2, #3
	bl ov112_021F1584
	ldrh r1, [r4, #14]
	add r0, r5, #0
	bl ov112_021F1504
	add r1, r4, #0
	ldrh r3, [r4, #12]
	add r0, r5, #0
	add r1, #54
	mov r2, #5
	bl ov112_021F1584
	mov r0, #0
	str r0, [sp, #0]
	add r0, r5, #0
	mov r1, #6
	add r2, r7, #0
	mov r3, #2
	bl ov112_021F15CC
	mov r0, #0
	add r2, r4, #0
	str r0, [sp, #0]
	add r2, #120
	ldrh r2, [r2, #0]
	add r0, r5, #0
	mov r1, #7
	mov r3, #5
	bl ov112_021F15CC
	add r4, #76
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #8
	mov r3, #21
	bl ov112_021F1488
	mov r0, #0
	str r0, [sp, #0]
	ldr r2, [sp, #16]
	add r0, r5, #0
	mov r1, #9
	mov r3, #2
	bl ov112_021F15CC
	mov r0, #0
	str r0, [sp, #0]
	ldr r2, [sp, #12]
	add r0, r5, #0
	mov r1, #10
	mov r3, #2
	bl ov112_021F15CC
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	add r0, r5, #0
	bl ov112_021F13CC
	mov r0, #1
	str r0, [sp, #0]
	ldr r2, [sp, #16]
	add r0, r5, #0
	mov r1, #9
	mov r3, #2
	bl ov112_021F15CC
	mov r0, #1
	str r0, [sp, #0]
	ldr r2, [sp, #12]
	add r0, r5, #0
	mov r1, #10
	mov r3, #2
	bl ov112_021F15CC
	mov r1, #0
	add r0, r5, #0
	mov r2, #86
	add r3, r1, #0
	bl ov112_021F13BC
	mov r0, #1
	str r0, [sp, #0]
	add r0, r5, #0
	mov r1, #6
	add r2, r7, #0
	mov r3, #2
	bl ov112_021F15CC
	ldr r0, [r5, #88]
	ldr r1, [r5, #92]
	ldr r3, [r5, #4]
	add r2, r6, #0
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	add r0, r5, #0
	add r0, #40
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #1
	add r1, r4, #0
	mov r2, #0
	lsl r3, r3, #3
	bl FontID_String_GetCenterAlignmentX
	add r7, r0, #0
	add r0, r4, #0
	bl String_Delete
	lsl r3, r7, #24
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	lsr r3, r3, #24
	bl ov112_021F13BC
	add sp, #20
	pop {r4, r5, r6, r7, pc}
	nop
_DE_021F1760:
	.word 0x0000013D
	thumb_func_end ov112_021F1624
