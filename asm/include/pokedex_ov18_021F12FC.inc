	thumb_func_start ov18_021F12FC
ov18_021F12FC:
	push {r4, lr}
	add r4, r0, #0
	mov r0, #20
	mov r1, #37
	bl NARC_New
	mov r1, #133
	lsl r1, r1, #4
	str r0, [r4, r1]
	pop {r4, pc}
	thumb_func_end ov18_021F12FC
