	thumb_func_start ov18_021F38F0
ov18_021F38F0:
	thumb_func_start ov18_021F39C4
ov18_021F39C4:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	mov r0, #0
	mov r5, #250
	add r6, r1, #0
	str r2, [sp, #0]
	str r0, [sp, #4]
	lsl r5, r5, #2
	add r4, r0, #0
_DE_021F3660:
	ldr r0, [sp, #0]
	add r1, r5, #0
	blx _u32_div_f
	add r2, r0, #0
	bne _DE_021F3672
	ldr r0, [sp, #4]
	cmp r0, #1
	bne _DE_021F368C
_DE_021F3672:
	mov r0, #1
	str r0, [sp, #4]
	add r0, r7, #0
	add r1, r6, r4
	add r2, #43
	bl ov18_021F118C
	add r0, r7, #0
	add r1, r6, r4
	mov r2, #1
	bl ov18_021F11C0
	b _DE_021F3696
_DE_021F368C:
	add r0, r7, #0
	add r1, r6, r4
	mov r2, #0
	bl ov18_021F11C0
_DE_021F3696:
	ldr r0, [sp, #0]
	add r1, r5, #0
	blx _u32_div_f
	str r1, [sp, #0]
	add r0, r5, #0
	mov r1, #10
	blx _u32_div_f
	add r5, r0, #0
	cmp r4, #1
	bne _DE_021F36B2
	mov r0, #1
	str r0, [sp, #4]
_DE_021F36B2:
	add r4, r4, #1
	cmp r4, #4
	blo _DE_021F3660
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov18_021F38F0
