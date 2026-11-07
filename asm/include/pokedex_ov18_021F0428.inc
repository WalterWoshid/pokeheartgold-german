	thumb_func_start ov18_021F0428
ov18_021F0428:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	add r5, r0, #0
	add r6, r5, #0
	mov r4, #0
	add r6, #12
_DE_021F02F8:
	add r0, r4, #0
	add r0, #8
	lsl r7, r0, #4
	add r0, r6, r7
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, _DE_021F0378
	ldrsb r0, [r5, r0]
	add r0, r0, r4
	sub r1, r0, #2
	bmi _DE_021F0342
	ldr r0, _DE_021F037C
	ldr r0, [r5, r0]
	cmp r1, r0
	bge _DE_021F0342
	add r0, r5, #0
	bl ov18_021F04C0
	add r3, r0, #0
	mov r0, #72
	str r0, [sp, #0]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r0, _DE_021F0380
	add r2, r4, #0
	str r0, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r1, _DE_021F0384
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r2, #8
	bl ov18_021EE3AC
_DE_021F0342:
	add r0, r6, r7
	bl CopyWindowPixelsToVram_TextMode
	add r0, r6, r7
	bl GetWindowX
	str r0, [sp, #20]
	add r0, r6, r7
	bl GetWindowY
	add r3, r0, #0
	ldr r2, [sp, #20]
	add r1, r4, #0
	lsl r2, r2, #24
	lsl r3, r3, #24
	ldr r0, [r5, #8]
	add r1, #17
	asr r2, r2, #24
	asr r3, r3, #24
	bl sub_020196E8
	add r4, r4, #1
	cmp r4, #6
	blo _DE_021F02F8
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F0378:
	.word 0x000018C2
_DE_021F037C:
	.word 0x000018F8
_DE_021F0380:
	.word 0x000F0C00
_DE_021F0384:
	.word 0x0000065C
	thumb_func_end ov18_021F0428
