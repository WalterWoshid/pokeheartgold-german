	thumb_func_start ov96_022088AC
ov96_022088AC:
	push {r3, r4, r5, lr}
	sub sp, #16
	add r4, r0, #0
	add r5, r1, #0
	add r0, #12
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #1
	lsl r2, r5, #2
	str r0, [sp, #0]
	mov r0, #5
	add r3, r4, r2
	mov r2, #106
	str r0, [sp, #4]
	lsl r2, r2, #2
	ldr r2, [r3, r2]
	ldr r0, [r4, #32]
	mov r1, #0
	mov r3, #2
	bl BufferString
	ldr r0, [r4, #32]
	ldr r1, [r4, #28]
	ldr r3, [r4, #0]
	mov r2, #154
	bl ReadMsgData_ExpandPlaceholders
	mov r1, #0
	add r5, r0, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_022088F8
	add r2, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r0, #12
	add r3, r1, #0
	str r1, [sp, #12]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	add r4, #12
	add r0, r4, #0
	bl CopyWindowToVram
	add sp, #16
	pop {r3, r4, r5, pc}
	nop
_DE_022088F8:
	.word 0x000F0E00
	thumb_func_end ov96_022088AC
