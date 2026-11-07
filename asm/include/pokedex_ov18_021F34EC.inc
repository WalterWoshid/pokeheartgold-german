	thumb_func_start ov18_021F34EC
ov18_021F34EC:
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov18_021F3494
	cmp r4, #1
	ldr r0, _DE_021F3400
	bne _DE_021F33E0
	ldr r0, [r5, r0]
	mov r1, #224
	mov r2, #72
	bl ManagedSprite_SetPositionXY
	mov r4, #27
	mov r6, #0
_DE_021F33CE:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F11C0
	add r4, r4, #1
	cmp r4, #40
	bls _DE_021F33CE
	pop {r4, r5, r6, pc}
_DE_021F33E0:
	ldr r0, [r5, r0]
	mov r1, #152
	mov r2, #20
	bl ManagedSprite_SetPositionXY
	mov r4, #27
	mov r6, #1
_DE_021F33EE:
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F11C0
	add r4, r4, #1
	cmp r4, #40
	bls _DE_021F33EE
	pop {r4, r5, r6, pc}
_DE_021F3400:
	.word 0x000006D8
	thumb_func_end ov18_021F34EC
