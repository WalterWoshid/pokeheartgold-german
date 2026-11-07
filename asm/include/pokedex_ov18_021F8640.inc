	thumb_func_start ov18_021F8640
ov18_021F8640:
	push {r4, r5, r6, r7, lr}
	sub sp, #12
	add r6, r0, #0
	ldr r0, [sp, #40]
	str r3, [sp, #0]
	str r0, [sp, #40]
	ldr r0, [sp, #44]
	ldr r5, [sp, #32]
	str r0, [sp, #44]
	cmp r1, #0
	bne _DE_021F82CE
	cmp r2, #152
	bne _DE_021F82CE
	ldr r2, [sp, #40]
	ldr r1, [sp, #36]
	add r0, r3, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r0, [sp, #40]
	add sp, #12
	str r0, [r5, #0]
	pop {r4, r5, r6, r7, pc}
_DE_021F82CE:
	ldr r0, [sp, #40]
	mov r7, #0
	cmp r0, #0
	bls _DE_021F8326
	lsl r0, r1, #2
	str r0, [sp, #8]
	lsl r0, r2, #2
	ldr r4, [sp, #36]
	str r0, [sp, #4]
_DE_021F82E0:
	mov r0, #97
	lsl r0, r0, #6
	ldrh r2, [r4, #0]
	ldr r1, [r6, r0]
	ldr r3, [sp, #8]
	lsl r0, r2, #2
	ldr r1, [r1, r0]
	ldr r0, _DE_021F832C
	ldr r0, [r6, r0]
	ldrh r3, [r3, r0]
	cmp r1, r3
	blt _DE_021F831C
	ldr r3, [sp, #4]
	ldrh r0, [r3, r0]
	cmp r1, r0
	bgt _DE_021F831C
	ldr r0, [sp, #44]
	add r1, r2, #0
	bl Pokedex_CheckMonCaughtFlag
	cmp r0, #0
	beq _DE_021F831C
	ldr r1, [r5, #0]
	ldrh r0, [r4, #0]
	lsl r2, r1, #1
	ldr r1, [sp, #0]
	strh r0, [r1, r2]
	ldr r0, [r5, #0]
	add r0, r0, #1
	str r0, [r5, #0]
_DE_021F831C:
	ldr r0, [sp, #40]
	add r7, r7, #1
	add r4, r4, #2
	cmp r7, r0
	blo _DE_021F82E0
_DE_021F8326:
	add sp, #12
	pop {r4, r5, r6, r7, pc}
	nop
_DE_021F832C:
	.word 0x00001848
	thumb_func_end ov18_021F8640
