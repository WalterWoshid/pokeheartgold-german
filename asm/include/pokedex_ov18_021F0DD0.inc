	thumb_func_start ov18_021F0DD0
ov18_021F0DD0:
	push {r4, r5, lr}
	sub sp, #20
	add r5, r0, #0
	bl ov18_021F0D7C
	add r0, r5, #0
	add r0, #12
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #60
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #92
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #140
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #156
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F0DE0
	ldr r1, _DE_021F0DE4
	str r0, [sp, #8]
	str r3, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #12
	mov r2, #170
	bl ov18_021F9648
	ldr r0, _DE_021F0DE8
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
	ldr r0, _DE_021F0DE0
	ldr r1, _DE_021F0DE4
	str r0, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r1, [r5, r1]
	add r0, r5, #0
	mov r2, #3
	mov r3, #169
	bl ov18_021EE3AC
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F0DEC
	ldr r1, _DE_021F0DE4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #92
	mov r2, #170
	mov r3, #24
	bl ov18_021F9648
	mov r0, #4
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F0DF0
	ldr r1, _DE_021F0DE4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #140
	mov r2, #171
	mov r3, #48
	bl ov18_021F9648
	mov r0, #4
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F0DF0
	ldr r1, _DE_021F0DE4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #156
	mov r2, #172
	mov r3, #48
	bl ov18_021F9648
	add r0, r5, #0
	add r0, #12
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #60
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #92
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #140
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #156
	bl ScheduleWindowCopyToVram
	ldr r2, _DE_021F0DF4
	add r0, r5, #0
	ldrsb r2, [r5, r2]
	mov r1, #6
	bl ov18_021F0F68
	ldr r2, _DE_021F0DF8
	add r0, r5, #0
	ldrsb r2, [r5, r2]
	mov r1, #7
	bl ov18_021F0F68
	add sp, #20
	pop {r4, r5, pc}
	nop
_DE_021F0DE0:
	.word 0x00020100
_DE_021F0DE4:
	.word 0x0000065C
_DE_021F0DE8:
	.word 0x0000189A
_DE_021F0DEC:
	.word 0x00050900
_DE_021F0DF0:
	.word 0x000F0C00
_DE_021F0DF4:
	.word 0x000018BD
_DE_021F0DF8:
	.word 0x000018BE
	thumb_func_end ov18_021F0DD0
