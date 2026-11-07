	thumb_func_start ov18_021EFD00
ov18_021EFD00:
	thumb_func_start ov18_021EFDB4
ov18_021EFDB4:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	add r5, r0, #0
	add r4, r5, #0
	add r0, r2, #0
	add r7, r1, #0
	add r4, #12
	lsl r6, r0, #4
	add r0, r4, r6
	mov r1, #0
	str r2, [sp, #20]
	bl FillWindowPixelBuffer
	add r0, r7, #0
	mov r1, #10
	blx _u32_div_f
	mov r1, #0
	add r2, r0, #0
	str r1, [sp, #0]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #102
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r3, #3
	bl BufferIntegerAsString
	add r0, r7, #0
	mov r1, #10
	blx _u32_div_f
	mov r0, #2
	add r2, r1, #0
	str r0, [sp, #0]
	mov r1, #1
	mov r0, #102
	str r1, [sp, #4]
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r3, r1, #0
	bl BufferIntegerAsString
	add r0, r4, r6
	bl GetWindowWidth
	lsl r1, r0, #3
	lsr r0, r1, #31
	add r0, r1, r0
	asr r0, r0, #1
	str r0, [sp, #0]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r0, _DE_021EFD2C
	ldr r1, _DE_021EFD30
	str r0, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r1, [r5, r1]
	ldr r2, [sp, #20]
	add r0, r5, #0
	mov r3, #38
	bl ov18_021EE3AC
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021EFD2C:
	.word 0x00020100
_DE_021EFD30:
	.word 0x0000065C
	thumb_func_end ov18_021EFD00
