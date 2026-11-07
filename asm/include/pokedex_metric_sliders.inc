	thumb_func_start ov18_021F3560
ov18_021F3560:
	push {r3, r4, r5, r6, r7, lr}
	add r6, r2, #0
	add r4, r1, #0
	add r5, r0, #0
	add r1, r6, #0
	add r7, r3, #0
	bl ov18_021F3AD0
	add r1, r0, #0
	add r0, r5, #0
	mov r2, #5
	mov r3, #1
	bl ov18_021F36D4
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F3AD0
	add r1, r0, #0
	add r0, r5, #0
	mov r2, #10
	mov r3, #0
	bl ov18_021F36D4
	cmp r7, #0
	ldr r2, _DE_021F34B0
	bne _DE_021F3476
	ldr r3, [r5, r2]
	lsl r2, r6, #2
	ldrh r2, [r3, r2]
	add r0, r5, #0
	mov r1, #6
	bl ov18_021F38F0
	ldr r2, _DE_021F34B0
	add r0, r5, #0
	ldr r3, [r5, r2]
	lsl r2, r4, #2
	ldrh r2, [r3, r2]
	mov r1, #11
	bl ov18_021F38F0
	b _DE_021F3498
_DE_021F3476:
	ldr r3, [r5, r2]
	lsl r2, r6, #2
	add r2, r3, r2
	ldrh r2, [r2, #2]
	add r0, r5, #0
	mov r1, #6
	bl ov18_021F38F0
	ldr r2, _DE_021F34B0
	add r0, r5, #0
	ldr r3, [r5, r2]
	lsl r2, r4, #2
	add r2, r3, r2
	ldrh r2, [r2, #2]
	mov r1, #11
	bl ov18_021F38F0
_DE_021F3498:
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #1
	bl ov18_021F3A64
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #3
	bl ov18_021F3A64
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F34B0:
	.word 0x00001848
	thumb_func_end ov18_021F3560
