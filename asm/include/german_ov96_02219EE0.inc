	thumb_func_start ov96_02219EE0
ov96_02219EE0:
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	add r0, r1, #1
	mov r1, #3
	blx _s32_div_f
	lsl r2, r1, #24
	mov r0, #1
	lsr r2, r2, #22
	str r0, [sp, #0]
	mov r0, #5
	add r2, r4, r2
	str r0, [sp, #4]
	add r2, #176
	ldr r0, [r4, #28]
	ldr r2, [r2, #0]
	mov r1, #0
	mov r3, #2
	bl BufferString
	ldr r0, [r4, #4]
	mov r3, #154
	str r0, [sp, #0]
	add r0, r4, #0
	ldr r1, [r4, #28]
	ldr r2, [r4, #24]
	add r0, #64
	bl ov96_02219BC4
	add sp, #8
	pop {r4, pc}
	thumb_func_end ov96_02219EE0
