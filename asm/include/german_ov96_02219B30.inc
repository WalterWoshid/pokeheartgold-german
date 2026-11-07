	thumb_func_start ov96_02219B30
ov96_02219B30:
	push {r3, r4, r5, lr}
	sub sp, #16
	add r5, r0, #0
	add r0, #48
	mov r1, #0
	bl FillWindowPixelBuffer
	add r1, r5, #0
	add r1, #34
	ldrb r1, [r1, #0]
	ldr r0, [r5, #0]
	bl PokeathlonCourse_GetPlayerProfileFromData
	ldr r1, [r5, #4]
	bl PlayerProfile_GetPlayerName_NewString
	mov r1, #0
	add r4, r0, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_02219BB0
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	str r1, [sp, #12]
	add r0, #48
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [r5, #4]
	mov r3, #19
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	ldr r1, [r5, #28]
	ldr r2, [r5, #24]
	add r0, #80
	lsl r3, r3, #4
	bl ov96_02219BDC
	add r0, r4, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #48
	bl CopyWindowToVram
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	add r2, r5, #0
	str r0, [sp, #4]
	add r2, #180
	ldr r0, [r5, #28]
	ldr r2, [r2, #0]
	mov r1, #0
	mov r3, #2
	bl BufferString
	ldr r0, [r5, #4]
	mov r3, #154
	str r0, [sp, #0]
	add r0, r5, #0
	ldr r1, [r5, #28]
	ldr r2, [r5, #24]
	add r0, #64
	bl ov96_02219BC4
	add sp, #16
	pop {r3, r4, r5, pc}
	nop
_DE_02219BB0:
	.word 0x000F0E00
	thumb_func_end ov96_02219B30
