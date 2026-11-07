	thumb_func_start ov18_021F3B60
ov18_021F3B60:
	push {r4, r5, r6, lr}
	add r5, r0, #0
	cmp r1, #1
	bne _DE_021F37E0
	mov r4, #42
	mov r6, #1
_DE_021F37C4:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F11C0
	add r4, r4, #1
	cmp r4, #56
	bls _DE_021F37C4
	add r0, r5, #0
	mov r1, #41
	mov r2, #0
	bl ov18_021F11C0
	pop {r4, r5, r6, pc}
_DE_021F37E0:
	mov r4, #42
	mov r6, #0
_DE_021F37E4:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F11C0
	add r4, r4, #1
	cmp r4, #56
	bls _DE_021F37E4
	add r0, r5, #0
	bl ov18_021F3BA4
	pop {r4, r5, r6, pc}
	thumb_func_end ov18_021F3B60
