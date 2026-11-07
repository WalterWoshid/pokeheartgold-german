	thumb_func_start ov18_021F3494
ov18_021F3494:
	push {r4, lr}
	ldr r1, _DE_021F3384
	add r4, r0, #0
	ldr r1, [r4, r1]
	cmp r1, #14
	bne _DE_021F336E
	mov r1, #26
	mov r2, #0
	bl ov18_021F11C0
	pop {r4, pc}
_DE_021F336E:
	mov r1, #26
	mov r2, #1
	bl ov18_021F11C0
	ldr r2, _DE_021F3384
	add r0, r4, #0
	ldr r2, [r4, r2]
	mov r1, #26
	bl ov18_021F118C
	pop {r4, pc}
_DE_021F3384:
	.word 0x00001884
	thumb_func_end ov18_021F3494
