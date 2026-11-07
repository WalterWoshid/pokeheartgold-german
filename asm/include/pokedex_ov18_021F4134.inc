	thumb_func_start ov18_021F4134
ov18_021F4134:
	push {r3, lr}
	mov r1, #99
	lsl r1, r1, #6
	ldrsb r1, [r0, r1]
	cmp r1, #0
	ldr r1, [r0, #0]
	bne _DE_021F3DBC
	ldr r2, [r1, #16]
	asr r1, r2, #4
	lsr r1, r1, #27
	add r1, r2, r1
	asr r1, r1, #5
	cmp r1, #23
	blt _DE_021F3DB2
	mov r1, #2
	mov r2, #0
	bl ov18_021F11C0
	pop {r3, pc}
_DE_021F3DB2:
	mov r1, #2
	mov r2, #1
	bl ov18_021F11C0
	pop {r3, pc}
_DE_021F3DBC:
	ldr r2, [r1, #16]
	asr r1, r2, #4
	lsr r1, r1, #27
	add r1, r2, r1
	asr r1, r1, #5
	cmp r1, #23
	blt _DE_021F3DD4
	mov r1, #2
	mov r2, #1
	bl ov18_021F11C0
	pop {r3, pc}
_DE_021F3DD4:
	mov r1, #2
	mov r2, #0
	bl ov18_021F11C0
	pop {r3, pc}
	thumb_func_end ov18_021F4134
