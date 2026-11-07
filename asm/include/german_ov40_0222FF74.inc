	thumb_func_start ov40_0222FF74
ov40_0222FF74:
	push {r4, r5, r6, r7, lr}
	sub sp, #156
	ldr r3, _DE_02230280
	add r7, r1, #0
	str r0, [sp, #20]
	add r2, sp, #116
	mov r1, #20
_DE_0222FF62:
	ldrh r0, [r3, #0]
	add r3, r3, #2
	strh r0, [r2, #0]
	add r2, r2, #2
	sub r1, r1, #1
	bne _DE_0222FF62
	ldr r3, _DE_02230284
	add r2, sp, #92
	str r2, [sp, #32]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r0, #1
	ldr r5, [sp, #20]
	str r0, [sp, #60]
	mov r0, #0
	str r0, [sp, #64]
	add r4, sp, #116
	add r5, #60
_DE_0222FF8E:
	mov r0, #0
	ldrsh r0, [r4, r0]
	cmp r0, #255
	beq _DE_02230042
	ldr r1, [sp, #32]
	ldr r0, [r7, #72]
	ldr r1, [r1, #0]
	bl NewString_ReadMsgData
	add r6, r0, #0
	add r0, r5, #0
	bl InitWindow
	mov r0, #2
	ldrsh r0, [r4, r0]
	mov r3, #0
	add r1, r5, #0
	lsl r0, r0, #24
	lsr r0, r0, #24
	str r0, [sp, #0]
	mov r0, #4
	ldrsh r0, [r4, r0]
	mov r2, #2
	lsl r0, r0, #24
	lsr r0, r0, #24
	str r0, [sp, #4]
	mov r0, #6
	ldrsh r0, [r4, r0]
	lsl r0, r0, #24
	lsr r0, r0, #24
	str r0, [sp, #8]
	mov r0, #14
	str r0, [sp, #12]
	ldr r0, [sp, #60]
	lsl r0, r0, #16
	lsr r0, r0, #16
	str r0, [sp, #16]
	ldrsh r3, [r4, r3]
	ldr r0, [r7, #36]
	lsl r3, r3, #24
	lsr r3, r3, #24
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r1, r6, #0
	bl ov40_022306C0
	add r3, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02230288
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #12]
	add r0, r5, #0
	add r2, r6, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	mov r0, #4
	ldrsh r1, [r4, r0]
	mov r0, #6
	ldrsh r0, [r4, r0]
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #60]
	add r0, r0, r2
	str r0, [sp, #60]
	add r0, r6, #0
	bl String_Delete
	ldr r0, [sp, #32]
	add r4, #8
	add r0, r0, #4
	str r0, [sp, #32]
	ldr r0, [sp, #64]
	add r5, #16
	add r0, r0, #1
	str r0, [sp, #64]
	cmp r0, #5
	blt _DE_0222FF8E
_DE_02230042:
	ldr r0, [sp, #20]
	ldr r6, [r0, #0]
	mov r0, #109
	bl ov40_0222DAB0
	ldr r5, [sp, #20]
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #109
	add r5, #60
	bl sub_020315B8
	str r0, [sp, #68]
	ldr r1, [sp, #68]
	add r0, r7, #0
	bl ov40_02230DCC
	ldr r0, [r7, #72]
	mov r1, #7
	bl NewString_ReadMsgData
	str r0, [sp, #72]
	mov r0, #255
	mov r1, #109
	bl String_New
	add r6, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	mov r1, #0
	str r0, [sp, #4]
	ldr r2, [sp, #68]
	add r0, r4, #0
	add r3, r1, #0
	bl BufferString
	ldr r2, [sp, #72]
	add r0, r4, #0
	add r1, r6, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r1, r6, #0
	bl ov40_022306C0
	mov r1, #0
	add r3, r0, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02230288
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #68]
	bl String_Delete
	ldr r0, [sp, #72]
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_ResetBuffers
	ldr r0, [sp, #20]
	mov r1, #3
	ldr r0, [r0, #4]
	mov r2, #0
	bl sub_0203088C
	add r1, r0, #0
	ldr r5, [sp, #20]
	ldr r0, [r7, #72]
	add r1, #132
	add r5, #76
	bl NewString_ReadMsgData
	add r6, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02230288
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_ResetBuffers
	ldr r0, [sp, #20]
	mov r1, #2
	ldr r0, [r0, #4]
	mov r2, #0
	bl sub_0203088C
	str r0, [sp, #76]
	cmp r0, #0
	beq _DE_022301D4
	ldr r5, [sp, #20]
	mov r0, #255
	mov r1, #109
	add r5, #92
	bl String_New
	str r0, [sp, #80]
	ldr r0, [r7, #72]
	mov r1, #9
	bl NewString_ReadMsgData
	str r0, [sp, #84]
	mov r0, #255
	mov r1, #109
	bl String_New
	add r6, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, [sp, #80]
	ldr r1, [sp, #76]
	mov r2, #4
	mov r3, #0
	bl String16_FormatInteger
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	mov r1, #0
	str r0, [sp, #4]
	ldr r2, [sp, #80]
	add r0, r4, #0
	add r3, r1, #0
	bl BufferString
	ldr r2, [sp, #84]
	add r0, r4, #0
	add r1, r6, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r1, r6, #0
	bl ov40_022306C0
	mov r1, #0
	add r3, r0, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02230288
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #80]
	bl String_Delete
	ldr r0, [sp, #84]
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_ResetBuffers
	b _DE_022301E6
_DE_022301D4:
	ldr r5, [sp, #20]
	mov r1, #0
	add r5, #108
	add r0, r5, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
_DE_022301E6:
	ldr r0, [sp, #20]
	mov r1, #4
	ldr r0, [r0, #4]
	mov r2, #0
	bl sub_0203088C
	add r5, r0, #0
	str r1, [sp, #28]
	add r6, r1, #0
	mov r0, #255
	mov r1, #109
	bl String_New
	str r0, [sp, #56]
	mov r0, #255
	mov r1, #109
	bl String_New
	str r0, [sp, #52]
	mov r0, #255
	mov r1, #109
	bl String_New
	str r0, [sp, #48]
	ldr r0, [sp, #20]
	ldr r1, [sp, #28]
	add r0, #124
	str r0, [sp, #20]
	ldr r2, _DE_0223028C
	add r0, r5, #0
	mov r3, #0
	blx _ull_mod
	str r0, [sp, #44]
	ldr r2, _DE_0223028C
	add r0, r5, #0
	add r1, r6, #0
	mov r3, #0
	blx _ull_div
	ldr r2, _DE_0223028C
	str r0, [sp, #88]
	mov r3, #0
	add r6, r1, #0
	blx _ull_mod
	str r0, [sp, #40]
	ldr r0, [sp, #88]
	ldr r2, _DE_0223028C
	add r1, r6, #0
	mov r3, #0
	blx _ull_div
	mov r1, #10
	str r0, [sp, #36]
	blx _u32_div_f
	mov r1, #10
	blx _u32_div_f
	cmp r1, #0
	bne _DE_02230290
	ldr r0, [sp, #28]
	mov r1, #0
	eor r1, r0
	mov r2, #0
	add r0, r5, #0
	eor r0, r2
	orr r0, r1
	beq _DE_02230290
	ldr r0, [r7, #72]
	mov r1, #12
	bl NewString_ReadMsgData
	add r6, r0, #0
	b _DE_0223029A
	nop
_DE_02230280:
	.word ov40_02244EE8
_DE_02230284:
	.word ov40_02244E28
_DE_02230288:
	.word 0x000F0D00
_DE_0223028C:
	.word 0x000186A0
_DE_02230290:
	ldr r0, [r7, #72]
	mov r1, #11
	bl NewString_ReadMsgData
	add r6, r0, #0
_DE_0223029A:
	mov r0, #255
	mov r1, #109
	bl String_New
	add r5, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, [sp, #56]
	ldr r1, [sp, #44]
	mov r2, #5
	mov r3, #2
	bl String16_FormatInteger
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, [sp, #52]
	ldr r1, [sp, #40]
	mov r2, #5
	mov r3, #2
	bl String16_FormatInteger
	mov r0, #1
	str r0, [sp, #0]
	mov r2, #2
	ldr r0, [sp, #48]
	ldr r1, [sp, #36]
	add r3, r2, #0
	bl String16_FormatInteger
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r2, [sp, #56]
	add r0, r4, #0
	mov r1, #2
	mov r3, #0
	bl BufferString
	mov r1, #1
	str r1, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r2, [sp, #52]
	add r0, r4, #0
	mov r3, #0
	bl BufferString
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	mov r1, #0
	str r0, [sp, #4]
	ldr r2, [sp, #48]
	add r0, r4, #0
	add r3, r1, #0
	bl BufferString
	add r0, r4, #0
	add r1, r5, #0
	add r2, r6, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #20]
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #20]
	add r1, r5, #0
	bl ov40_022306C0
	mov r1, #0
	add r3, r0, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02230374
	add r2, r5, #0
	str r0, [sp, #8]
	ldr r0, [sp, #20]
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #20]
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #56]
	bl String_Delete
	ldr r0, [sp, #52]
	bl String_Delete
	ldr r0, [sp, #48]
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_ResetBuffers
	add r0, r4, #0
	bl MessageFormat_Delete
	add sp, #156
	pop {r4, r5, r6, r7, pc}
_DE_02230374:
	.word 0x000F0D00
	thumb_func_end ov40_0222FF74
