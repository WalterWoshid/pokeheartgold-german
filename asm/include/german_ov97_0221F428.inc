	thumb_func_start ov97_0221F428
ov97_0221F428:
	push {r4, r5, r6, lr}
	sub sp, #16
	add r5, r0, #0
	ldr r0, [r5, #116]
	add r4, r1, #0
	add r1, #10
	bl CopyU16ArrayToString
	add r0, r5, #0
	add r0, #40
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_0221F568
	add r3, r1, #0
	str r0, [sp, #8]
	str r1, [sp, #12]
	add r0, r5, #0
	ldr r2, [r5, #116]
	add r0, #40
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #40
	bl CopyWindowToVram
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _DE_0221F4A8
	ldr r0, [r5, #108]
	mov r1, #2
	bl NewString_ReadMsgData
	add r6, r0, #0
	add r0, r5, #0
	add r0, #56
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_0221F56C
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #56
	mov r3, #4
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #56
	bl CopyWindowToVram
	add r0, r6, #0
	bl String_Delete
	b _DE_0221F4FE
_DE_0221F4A8:
	cmp r0, #1
	bne _DE_0221F4EC
	ldr r0, [r5, #108]
	mov r1, #3
	bl NewString_ReadMsgData
	add r6, r0, #0
	add r0, r5, #0
	add r0, #56
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
	add r0, #56
	add r2, r6, #0
	mov r3, #4
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #56
	bl CopyWindowToVram
	add r0, r6, #0
	bl String_Delete
	b _DE_0221F4FE
_DE_0221F4EC:
	add r0, r5, #0
	add r0, #56
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #56
	bl CopyWindowToVram
_DE_0221F4FE:
	ldrh r0, [r4, #4]
	ldr r1, [r5, #0]
	bl GetSpeciesName
	add r4, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r5, #112]
	mov r1, #0
	add r2, r4, #0
	mov r3, #2
	bl BufferString
	add r0, r4, #0
	bl String_Delete
	ldr r0, [r5, #112]
	ldr r1, [r5, #108]
	ldr r3, [r5, #0]
	mov r2, #9
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
	ldr r0, _DE_0221F568
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
	add sp, #16
	pop {r4, r5, r6, pc}
	nop
_DE_0221F568:
	.word 0x00010200
_DE_0221F56C:
	.word 0x00070800
	thumb_func_end ov97_0221F428
