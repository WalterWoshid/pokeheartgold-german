	thumb_func_start ov18_021F34C4
ov18_021F34C4:
	push {r4, r5, r6, lr}
	add r5, r0, #0
	cmp r1, #1
	bne _DE_021F3398
	mov r1, #26
	mov r2, #0
	bl ov18_021F11C0
_DE_021F3398:
	mov r4, #27
	mov r6, #0
_DE_021F339C:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F11C0
	add r4, r4, #1
	cmp r4, #40
	bls _DE_021F339C
	pop {r4, r5, r6, pc}
	thumb_func_end ov18_021F34C4
