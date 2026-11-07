	thumb_func_start ov18_021EFE70
ov18_021EFE70:
	push {r4, r5, r6, lr}
	sub sp, #16
	add r6, r0, #0
	add r5, r6, #0
	lsl r4, r1, #4
	add r5, #12
	add r0, r5, r4
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, r4
	bl GetWindowWidth
	add r3, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021EFD80
	mov r2, #98
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, r4
	ldr r1, _DE_021EFD84
	lsl r2, r2, #6
	lsl r4, r3, #3
	ldr r2, [r6, r2]
	lsr r3, r4, #31
	add r3, r4, r3
	ldr r1, [r6, r1]
	add r2, #65
	asr r3, r3, #1
	bl ov18_021F9648
	add sp, #16
	pop {r4, r5, r6, pc}
	nop
_DE_021EFD80:
	.word 0x00020100
_DE_021EFD84:
	.word 0x0000065C
	thumb_func_end ov18_021EFE70
