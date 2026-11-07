	thumb_func_start ov18_021F64F4
ov18_021F64F4:
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r1, #0
	mov r1, #86
	str r1, [sp, #0]
	ldr r2, _DE_021F6198
	mov r1, #5
	mov r3, #96
	add r6, r0, #0
	bl ov18_021F6230
	add r4, r0, #0
	mov r0, #86
	str r0, [sp, #0]
	ldr r2, _DE_021F6198
	add r0, r6, #0
	mov r1, #5
	mov r3, #96
	bl ov18_021F6244
	ldr r1, _DE_021F619C
	ldr r1, [r6, r1]
	sub r1, r1, #1
	cmp r5, r1
	beq _DE_021F6192
	sub r0, r0, r4
	lsl r0, r0, #8
	blx _u32_div_f
	add r1, r0, #0
	mul r1, r5
	lsr r0, r1, #8
	add r0, r4, r0
_DE_021F6192:
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_DE_021F6198:
	.word ov18_021FA304
_DE_021F619C:
	.word 0x000018F8
	thumb_func_end ov18_021F64F4
