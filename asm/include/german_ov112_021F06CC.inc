	thumb_func_start ov112_021F06CC
ov112_021F06CC:
	push {r4, r5, r6, r7, lr}
	sub sp, #20
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	add r0, #40
	ldrb r7, [r0, #0]
	ldrh r0, [r4, #38]
	add r1, #10
	str r0, [sp, #16]
	ldr r0, [r5, #112]
	bl CopyU16ArrayToString
	add r0, r5, #0
	add r0, #56
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021F08E4
	add r3, r1, #0
	str r0, [sp, #8]
	str r1, [sp, #12]
	add r0, r5, #0
	ldr r2, [r5, #112]
	add r0, #56
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #56
	bl CopyWindowToVram
	ldrh r0, [r4, #4]
	ldr r1, [r5, #0]
	bl GetSpeciesName
	add r6, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r5, #108]
	mov r1, #0
	add r2, r6, #0
	mov r3, #2
	bl BufferString
	add r0, r6, #0
	bl String_Delete
	ldr r0, [r5, #108]
	ldr r1, [r5, #104]
	ldr r3, [r5, #0]
	mov r2, #0
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021F08E4
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #8
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #8
	bl CopyWindowToVram
	add r0, r6, #0
	bl String_Delete
	mov r0, #1
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, [r5, #108]
	mov r1, #0
	add r2, r7, #0
	mov r3, #3
	bl BufferIntegerAsString
	ldr r0, [r5, #108]
	ldr r1, [r5, #104]
	ldr r3, [r5, #0]
	mov r2, #3
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
	add r0, r5, #0
	add r0, #24
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #24
	bl GetWindowWidth
	add r7, r0, #0
	mov r0, #0
	add r1, r6, #0
	add r2, r0, #0
	bl FontID_String_GetWidth
	lsl r1, r7, #3
	sub r3, r1, r0
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021F08E4
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #24
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #24
	bl CopyWindowToVram
	add r0, r6, #0
	bl String_Delete
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _DE_021F0802
	ldr r0, [r5, #104]
	mov r1, #1
	bl NewString_ReadMsgData
	add r4, r0, #0
	add r0, r5, #0
	add r0, #72
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021F08E8
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #72
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #72
	bl CopyWindowToVram
	add r0, r4, #0
	bl String_Delete
	b _DE_021F0858
_DE_021F0802:
	cmp r0, #1
	bne _DE_021F0846
	ldr r0, [r5, #104]
	mov r1, #2
	bl NewString_ReadMsgData
	add r4, r0, #0
	add r0, r5, #0
	add r0, #72
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	mov r0, #193
	lsl r0, r0, #10
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #72
	add r2, r4, #0
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #72
	bl CopyWindowToVram
	add r0, r4, #0
	bl String_Delete
	b _DE_021F0858
_DE_021F0846:
	add r0, r5, #0
	add r0, #72
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #72
	bl CopyWindowToVram
_DE_021F0858:
	ldr r0, [r5, #104]
	mov r1, #4
	bl NewString_ReadMsgData
	add r4, r0, #0
	add r0, r5, #0
	add r0, #40
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021F08E4
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #40
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #40
	bl CopyWindowToVram
	add r0, r4, #0
	bl String_Delete
	ldr r0, [r5, #108]
	ldr r2, [sp, #16]
	mov r1, #0
	bl BufferItemName
	ldr r0, [r5, #108]
	ldr r1, [r5, #104]
	ldr r3, [r5, #0]
	mov r2, #5
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	add r0, r5, #0
	add r0, #88
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021F08E4
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #88
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r5, #88
	add r0, r5, #0
	bl CopyWindowToVram
	add r0, r4, #0
	bl String_Delete
	add sp, #20
	pop {r4, r5, r6, r7, pc}
	nop
_DE_021F08E4:
	.word 0x00010200
_DE_021F08E8:
	.word 0x00070800
	thumb_func_end ov112_021F06CC
