	thumb_func_start ov18_021F3544
ov18_021F3544:
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r4, #1
_DE_021F340C:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F11C0
	add r4, r4, #1
	cmp r4, #14
	bls _DE_021F340C
	pop {r4, r5, r6, pc}
	thumb_func_end ov18_021F3544
