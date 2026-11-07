	thumb_func_start ov102_021EC13C
ov102_021EC13C:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	add r5, r0, #0
	add r4, r2, #0
	ldr r0, [r5, #4]
	ldr r2, [r5, #60]
	add r7, r1, #0
	bl ov102_021E8FFC
	cmp r4, #240
	bhi _DE_021EC15A
	str r4, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021EC1E8
	mov r1, #0
	str r0, [sp, #8]
	str r1, [sp, #12]
	add r0, r5, #0
	mov r3, #1
	add r4, r7, #0
	and r4, r3
	mov r3, #112
	mul r3, r4
	ldr r2, [r5, #60]
	add r0, #16
	add r3, r3, #5
	bl AddTextPrinterParameterizedWithColor
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021EC15A:
	mov r0, #1
	lsl r0, r0, #8
	sub r6, r0, r4
	add r0, r5, #0
	add r0, #32
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021EC1E8
	add r3, r1, #0
	str r0, [sp, #8]
	str r1, [sp, #12]
	add r0, r5, #0
	ldr r2, [r5, #60]
	add r0, #32
	bl AddTextPrinterParameterizedWithColor
	mov r2, #0
	mov r0, #1
	add r1, r7, #0
	and r1, r0
	mov r0, #112
	mul r0, r1
	add r7, r0, #5
	mov r0, #96
	str r0, [sp, #0]
	mov r1, #16
	str r1, [sp, #4]
	lsl r1, r7, #16
	lsr r1, r1, #16
	str r1, [sp, #8]
	lsl r1, r4, #16
	lsr r1, r1, #16
	str r1, [sp, #12]
	str r0, [sp, #16]
	lsl r0, r6, #16
	lsr r0, r0, #16
	str r0, [sp, #20]
	add r0, r5, #0
	ldr r1, [r5, #44]
	add r0, #16
	add r3, r2, #0
	bl BlitBitmapRectToWindow
	mov r1, #96
	lsl r2, r7, #16
	lsl r3, r6, #16
	str r1, [sp, #0]
	mov r0, #16
	str r0, [sp, #4]
	lsr r2, r2, #16
	str r2, [sp, #8]
	mov r2, #0
	sub r0, r0, r6
	str r2, [sp, #12]
	lsl r0, r0, #16
	str r1, [sp, #16]
	lsr r0, r0, #16
	str r0, [sp, #20]
	add r0, r5, #0
	ldr r1, [r5, #44]
	add r0, #16
	lsr r3, r3, #16
	bl BlitBitmapRectToWindow
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021EC1E8:
	.word 0x00010200
	thumb_func_end ov102_021EC13C
