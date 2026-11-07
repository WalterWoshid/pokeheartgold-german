	thumb_func_start ov18_021F1004
ov18_021F1004:
	push {r4, r5, r6, lr}
	mov r6, #103
	add r5, r0, #0
	mov r4, #0
	lsl r6, r6, #4
_DE_021F0EDE:
	ldr r0, [r5, r6]
	cmp r0, #0
	beq _DE_021F0EE8
	bl ManagedSprite_TickFrame
_DE_021F0EE8:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #118
	blo _DE_021F0EDE
	pop {r4, r5, r6, pc}
	thumb_func_end ov18_021F1004
