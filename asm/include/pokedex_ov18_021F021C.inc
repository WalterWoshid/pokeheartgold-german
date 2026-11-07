	thumb_func_start ov18_021F021C
ov18_021F021C:
	push {r3, r4, r5, lr}
	sub sp, #16
	ldr r1, _DE_021F0268
	add r5, r0, #0
	mov r2, #14
	bl ov18_021EE35C
	add r0, r5, #0
	add r0, #12
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #44
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #76
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F026C
	ldr r1, _DE_021F0270
	str r0, [sp, #8]
	str r3, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #12
	mov r2, #142
	bl ov18_021F9648
	ldr r0, _DE_021F0274
	mov r1, #5
	ldrh r0, [r5, r0]
	mov r2, #37
	bl ov18_021E590C
	add r4, r0, #0
	mov r3, #0
	ldr r0, _DE_021F026C
	str r3, [sp, #0]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #44
	add r1, r4, #0
	mov r2, #36
	bl ov18_021F95FC
	add r0, r4, #0
	bl String_Delete
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F0278
	ldr r1, _DE_021F0270
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #76
	mov r2, #132
	mov r3, #24
	bl ov18_021F9648
	add r0, r5, #0
	add r0, #12
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #44
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #76
	bl ScheduleWindowCopyToVram
	ldr r0, _DE_021F027C
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _DE_021F01F8
	add r0, r5, #0
	add r0, #92
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #124
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F0280
	ldr r1, _DE_021F0270
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #92
	mov r2, #65
	mov r3, #28
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F0280
	ldr r1, _DE_021F0270
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #124
	mov r2, #66
	mov r3, #28
	bl ov18_021F9648
	add r0, r5, #0
	add r0, #92
	bl ScheduleWindowCopyToVram
	add r0, r5, #0
	add r0, #124
	bl ScheduleWindowCopyToVram
	b _DE_021F0228
_DE_021F01F8:
	add r0, r5, #0
	add r0, #108
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F0278
	ldr r1, _DE_021F0270
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #108
	mov r2, #65
	mov r3, #28
	bl ov18_021F9648
	add r0, r5, #0
	add r0, #108
	bl ScheduleWindowCopyToVram
_DE_021F0228:
	add r0, r5, #0
	add r0, #60
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F026C
	ldr r1, _DE_021F0270
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #60
	mov r2, #128
	mov r3, #56
	bl ov18_021F9648
	add r0, r5, #0
	add r0, #60
	bl CopyWindowPixelsToVram_TextMode
	add r0, r5, #0
	bl ov18_021F03E0
	add r0, r5, #0
	bl ov18_021F0428
	add sp, #16
	pop {r3, r4, r5, pc}
_DE_021F0268:
	.word ov18_021F9E4C
_DE_021F026C:
	.word 0x00020100
_DE_021F0270:
	.word 0x0000065C
_DE_021F0274:
	.word 0x0000189A
_DE_021F0278:
	.word 0x00050900
_DE_021F027C:
	.word 0x00001858
_DE_021F0280:
	.word 0x000F0C00
	thumb_func_end ov18_021F021C
