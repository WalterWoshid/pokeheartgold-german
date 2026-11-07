	thumb_func_start ov18_021F3618
ov18_021F3618:
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #3
	bhi _DE_021F3530
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #16
	asr r1, r1, #16
	add pc, r1
_DE_021F34C8:
	.short _DE_021F34D0 - _DE_021F34C8 - 2
	.short _DE_021F34E0 - _DE_021F34C8 - 2
	.short _DE_021F34F0 - _DE_021F34C8 - 2
	.short _DE_021F3510 - _DE_021F34C8 - 2
_DE_021F34D0:
	mov r1, #1
	bl ov18_021F34EC
	add r0, r4, #0
	mov r1, #0
	bl ov18_021F3544
	pop {r4, pc}
_DE_021F34E0:
	mov r1, #0
	bl ov18_021F34EC
	add r0, r4, #0
	mov r1, #0
	bl ov18_021F3544
	pop {r4, pc}
_DE_021F34F0:
	mov r1, #1
	bl ov18_021F34C4
	add r0, r4, #0
	mov r1, #1
	bl ov18_021F3544
	ldr r2, _DE_021F3544
	add r0, r4, #0
	ldr r1, [r4, r2]
	add r2, r2, #4
	ldr r2, [r4, r2]
	mov r3, #0
	bl ov18_021F3560
	pop {r4, pc}
_DE_021F3510:
	mov r1, #1
	bl ov18_021F34C4
	add r0, r4, #0
	mov r1, #1
	bl ov18_021F3544
	ldr r2, _DE_021F3548
	add r0, r4, #0
	ldr r1, [r4, r2]
	add r2, r2, #4
	ldr r2, [r4, r2]
	mov r3, #1
	bl ov18_021F3560
	pop {r4, pc}
_DE_021F3530:
	add r0, r4, #0
	mov r1, #1
	bl ov18_021F34C4
	add r0, r4, #0
	mov r1, #0
	bl ov18_021F3544
	pop {r4, pc}
	nop
_DE_021F3544:
	.word 0x00001870
_DE_021F3548:
	.word 0x00001878
	thumb_func_end ov18_021F3618
