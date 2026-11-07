	thumb_func_start ov40_02242E4C
ov40_02242E4C:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #48
	add r4, r0, #0
	mov r0, #109
	add r5, r1, #0
	bl ov40_0222DAB0
	add r6, r0, #0
	mov r0, #75
	lsl r0, r0, #4
	ldr r7, [r4, r0]
	add r0, r0, #4
	ldr r4, [r4, r0]
	mov r0, #255
	mov r1, #109
	str r4, [sp, #20]
	bl String_New
	str r0, [sp, #24]
	mov r0, #255
	mov r1, #109
	bl String_New
	str r0, [sp, #28]
	mov r0, #255
	mov r1, #109
	bl String_New
	str r0, [sp, #32]
	ldr r2, _DE_02242F7C
	add r0, r7, #0
	add r1, r4, #0
	mov r3, #0
	blx _ull_div
	str r0, [sp, #36]
	add r4, r1, #0
	ldr r0, [r5, #72]
	ldr r1, _DE_02242F80
	bl NewString_ReadMsgData
	str r0, [sp, #40]
	mov r0, #255
	mov r1, #109
	bl String_New
	str r0, [sp, #44]
	ldr r1, [sp, #20]
	ldr r2, _DE_02242F7C
	add r0, r7, #0
	mov r3, #0
	blx _ull_mod
	add r1, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, [sp, #24]
	mov r2, #5
	mov r3, #2
	bl String16_FormatInteger
	ldr r0, [sp, #36]
	ldr r2, _DE_02242F7C
	add r1, r4, #0
	mov r3, #0
	blx _ull_mod
	add r1, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, [sp, #28]
	mov r2, #5
	mov r3, #2
	bl String16_FormatInteger
	ldr r0, [sp, #36]
	ldr r2, _DE_02242F7C
	add r1, r4, #0
	mov r3, #0
	blx _ull_div
	add r1, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r2, #2
	ldr r0, [sp, #32]
	add r3, r2, #0
	bl String16_FormatInteger
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r2, [sp, #24]
	add r0, r6, #0
	mov r1, #2
	mov r3, #0
	bl BufferString
	mov r1, #1
	str r1, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r2, [sp, #28]
	add r0, r6, #0
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	mov r1, #0
	str r0, [sp, #4]
	ldr r2, [sp, #32]
	add r0, r6, #0
	add r3, r1, #0
	bl BufferString
	ldr r1, [sp, #44]
	ldr r2, [sp, #40]
	add r0, r6, #0
	bl StringExpandPlaceholders
	ldr r0, _DE_02242F84
	mov r1, #204
	add r0, r5, r0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02242F88
	ldr r2, [sp, #44]
	str r0, [sp, #8]
	ldr r0, _DE_02242F84
	add r3, r1, #0
	add r0, r5, r0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _DE_02242F84
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #24]
	bl String_Delete
	ldr r0, [sp, #28]
	bl String_Delete
	ldr r0, [sp, #32]
	bl String_Delete
	ldr r0, [sp, #40]
	bl String_Delete
	ldr r0, [sp, #44]
	bl String_Delete
	add r0, r6, #0
	bl MessageFormat_ResetBuffers
	add r0, r6, #0
	bl MessageFormat_Delete
	add sp, #48
	pop {r3, r4, r5, r6, r7, pc}
_DE_02242F7C:
	.word 0x000186A0
_DE_02242F80:
	.word 0x00000127
_DE_02242F84:
	.word 0x000008A4
_DE_02242F88:
	.word 0x000F0D00
	thumb_func_end ov40_02242E4C
