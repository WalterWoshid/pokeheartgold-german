	thumb_func_start ov18_021F0C50
ov18_021F0C50:
	push {r4, r5, lr}
	sub sp, #20
	add r5, r0, #0
	add r0, #12
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #76
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #28
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F0BE4
	ldr r1, _DE_021F0BE8
	str r0, [sp, #8]
	str r3, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #12
	mov r2, #170
	bl ov18_021F9648
	ldr r0, _DE_021F0BEC
	ldrsb r0, [r5, r0]
	cmp r0, #1
	beq _DE_021F0B7E
	mov r3, #0
	str r3, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F0BF0
	ldr r1, _DE_021F0BE8
	str r0, [sp, #8]
	str r3, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #76
	mov r2, #168
	bl ov18_021F9648
_DE_021F0B7E:
	ldr r0, _DE_021F0BF4
	mov r1, #5
	ldrh r0, [r5, r0]
	mov r2, #37
	bl ov18_021E590C
	add r4, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #102
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	add r2, r4, #0
	mov r3, #2
	bl BufferString
	add r0, r4, #0
	bl String_Delete
	mov r0, #72
	str r0, [sp, #0]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, _DE_021F0BE4
	mov r2, #1
	str r0, [sp, #12]
	ldr r1, _DE_021F0BE8
	str r2, [sp, #16]
	ldr r1, [r5, r1]
	add r0, r5, #0
	mov r3, #167
	bl ov18_021EE3AC
	add r0, r5, #0
	add r0, #12
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #76
	bl ScheduleWindowCopyToVram
	add r5, #28
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #20
	pop {r4, r5, pc}
_DE_021F0BE4:
	.word 0x00020100
_DE_021F0BE8:
	.word 0x0000065C
_DE_021F0BEC:
	.word 0x000018BC
_DE_021F0BF0:
	.word 0x000F0C00
_DE_021F0BF4:
	.word 0x0000189A
	thumb_func_end ov18_021F0C50
