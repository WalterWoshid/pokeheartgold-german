	thumb_func_start ov18_021F1104
ov18_021F1104:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r4, #0
_DE_021F0FDA:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F10E8
	add r4, r4, #1
	cmp r4, #118
	blo _DE_021F0FDA
	pop {r3, r4, r5, pc}
	thumb_func_end ov18_021F1104
