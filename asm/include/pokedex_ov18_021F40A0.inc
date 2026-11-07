	thumb_func_start ov18_021F40A0
ov18_021F40A0:
	push {r3, r4, lr}
	sub sp, #4
	mov r1, #9
	str r1, [sp, #0]
	ldr r2, _DE_021F3D30
	add r4, r0, #0
	ldr r2, [r4, r2]
	ldr r3, _DE_021F3D34
	lsl r2, r2, #24
	mov r1, #5
	asr r2, r2, #24
	bl ov18_021F61DC
	add r0, r4, #0
	bl ov18_021F65EC
	ldr r2, _DE_021F3D38
	add r0, r4, #0
	ldrsb r1, [r4, r2]
	add r2, #54
	ldr r2, [r4, r2]
	mov r3, #6
	lsl r2, r2, #24
	asr r2, r2, #24
	bl ov18_021F619C
	add sp, #4
	pop {r3, r4, pc}
_DE_021F3D30:
	.word 0x000018F8
_DE_021F3D34:
	.word ov18_021FA35A
_DE_021F3D38:
	.word 0x000018C2
	thumb_func_end ov18_021F40A0
