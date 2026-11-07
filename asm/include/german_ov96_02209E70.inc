	thumb_func_start ov96_02209E70
ov96_02209E70:
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	bne _DE_02209E64
	bl GF_AssertFail
_DE_02209E64:
	ldr r0, [r5, #76]
	cmp r0, #0
	bne _DE_02209E6E
	bl GF_AssertFail
_DE_02209E6E:
	mov r0, #38
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #30
	blx _s32_div_f
	cmp r0, #0
	bge _DE_02209E80
	mov r0, #0
_DE_02209E80:
	mov r1, #100
	blx _s32_div_f
	lsl r0, r1, #24
	lsr r4, r0, #24
	add r0, r4, #0
	mov r1, #10
	blx _s32_div_f
	add r1, r0, #0
	lsl r1, r1, #24
	lsr r1, r1, #24
	ldr r0, [r5, #56]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #10
	blx _s32_div_f
	lsl r1, r1, #24
	lsr r1, r1, #24
	ldr r0, [r5, #60]
	add r1, r1, #1
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r5, #76]
	bl ov96_0220B7B4
	add r0, r0, #1
	mov r1, #3
	blx _s32_div_f
	lsl r2, r1, #24
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #151
	lsr r2, r2, #22
	lsl r0, r0, #2
	add r2, r5, r2
	ldr r0, [r5, r0]
	ldr r2, [r2, #24]
	mov r1, #0
	mov r3, #2
	bl BufferString
	mov r2, #146
	ldr r0, [r5, #0]
	lsl r2, r2, #2
	add r1, r2, #0
	str r0, [sp, #0]
	add r0, r5, r2
	add r1, #20
	add r2, #16
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	mov r3, #154
	bl ov96_02209F40
	add sp, #8
	pop {r3, r4, r5, pc}
	thumb_func_end ov96_02209E70
