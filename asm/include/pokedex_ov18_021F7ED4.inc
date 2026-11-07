	thumb_func_start ov18_021F7ED4
ov18_021F7ED4:
	push {r4, r5, r6, r7, lr}
	sub sp, #36
	str r2, [sp, #16]
	mov r2, #135
	add r5, r0, #0
	lsl r2, r2, #4
	add r7, r1, #0
	add r1, r5, r2
	mov r0, #0
	sub r2, #184
	str r3, [sp, #20]
	blx MIi_CpuClear32
	ldr r1, _DE_021F7DC0
	mov r0, #37
	bl Heap_AllocAtEnd
	add r6, r0, #0
	bne _DE_021F7B5E
	bl GF_AssertFail
_DE_021F7B5E:
	ldr r2, _DE_021F7DC0
	add r0, r6, #0
	mov r1, #0
	blx memset
	mov r0, #0
	str r0, [sp, #28]
	ldr r1, _DE_021F7DC0
	mov r0, #37
	bl Heap_AllocAtEnd
	add r4, r0, #0
	bne _DE_021F7B7C
	bl GF_AssertFail
_DE_021F7B7C:
	ldr r2, _DE_021F7DC0
	add r0, r4, #0
	mov r1, #0
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	cmp r7, #0
	add r1, sp, #32
	bne _DE_021F7B98
	mov r0, #1
	bl ov18_021F8168
	b _DE_021F7B9C
_DE_021F7B98:
	bl ov18_021F8168
_DE_021F7B9C:
	add r7, r0, #0
	ldr r0, [sp, #32]
	add r1, sp, #28
	str r0, [sp, #0]
	ldr r2, [r5, #0]
	add r0, r6, #0
	ldr r2, [r2, #0]
	add r3, r7, #0
	bl ov18_021F8198
	ldr r0, [sp, #28]
	add r1, r4, #0
	str r0, [sp, #0]
	ldr r0, [r5, #0]
	add r2, sp, #24
	ldr r0, [r0, #0]
	add r3, r6, #0
	str r0, [sp, #4]
	ldr r0, [sp, #16]
	bl ov18_021F822C
	ldr r2, [sp, #24]
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	ldr r0, [sp, #28]
	add r1, r4, #0
	str r0, [sp, #0]
	ldr r0, [r5, #0]
	add r2, sp, #24
	ldr r0, [r0, #0]
	add r3, r6, #0
	str r0, [sp, #4]
	ldr r0, [sp, #20]
	bl ov18_021F82CC
	ldr r2, [sp, #24]
	cmp r2, #0
	beq _DE_021F7CF2
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	ldr r0, [sp, #28]
	add r1, r4, #0
	str r0, [sp, #0]
	ldr r0, [r5, #0]
	add r2, sp, #24
	ldr r0, [r0, #0]
	add r3, r6, #0
	str r0, [sp, #4]
	ldr r0, [sp, #56]
	bl ov18_021F831C
	ldr r2, [sp, #24]
	cmp r2, #0
	beq _DE_021F7CF2
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	ldr r0, [sp, #28]
	add r1, r4, #0
	str r0, [sp, #0]
	ldr r0, [r5, #0]
	add r2, sp, #24
	ldr r0, [r0, #0]
	add r3, r6, #0
	str r0, [sp, #4]
	ldr r0, [sp, #60]
	bl ov18_021F831C
	ldr r2, [sp, #24]
	cmp r2, #0
	beq _DE_021F7CF2
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	ldr r0, [sp, #28]
	add r1, r4, #0
	str r0, [sp, #0]
	ldr r0, [r5, #0]
	add r2, sp, #24
	ldr r0, [r0, #0]
	add r3, r6, #0
	str r0, [sp, #4]
	ldr r0, [sp, #84]
	bl ov18_021F8468
	ldr r2, [sp, #24]
	cmp r2, #0
	beq _DE_021F7DA6
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	ldr r0, _DE_021F7DC4
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _DE_021F7CF4
	ldr r1, [sp, #80]
	mov r0, #4
	tst r0, r1
	beq _DE_021F7CF4
	str r6, [sp, #0]
	ldr r0, [sp, #28]
	mov r1, #6
	str r0, [sp, #4]
	ldr r0, [r5, #0]
	add r2, r4, #0
	ldr r0, [r0, #0]
	add r3, sp, #24
	str r0, [sp, #8]
	add r0, r5, #0
	bl ov18_021F8584
	ldr r2, [sp, #24]
	cmp r2, #0
	bne _DE_021F7D12
_DE_021F7CF2:
	b _DE_021F7DA6
_DE_021F7CF4:
	str r6, [sp, #0]
	ldr r0, [sp, #28]
	ldr r1, [sp, #80]
	str r0, [sp, #4]
	ldr r0, [r5, #0]
	add r2, r4, #0
	ldr r0, [r0, #0]
	add r3, sp, #24
	str r0, [sp, #8]
	add r0, r5, #0
	bl ov18_021F8584
	ldr r2, [sp, #24]
	cmp r2, #0
	beq _DE_021F7DA6
_DE_021F7D12:
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	add r0, sp, #24
	str r0, [sp, #0]
	str r6, [sp, #4]
	ldr r0, [sp, #28]
	ldr r1, [sp, #64]
	str r0, [sp, #8]
	ldr r0, [r5, #0]
	ldr r2, [sp, #68]
	ldr r0, [r0, #0]
	lsl r1, r1, #16
	lsl r2, r2, #16
	str r0, [sp, #12]
	add r0, r5, #0
	lsr r1, r1, #16
	lsr r2, r2, #16
	add r3, r4, #0
	bl ov18_021F8640
	ldr r2, [sp, #24]
	add r0, r6, #0
	add r1, r4, #0
	lsl r2, r2, #1
	blx memcpy
	ldr r2, [sp, #24]
	add r0, r4, #0
	str r2, [sp, #28]
	mov r1, #0
	lsl r2, r2, #1
	blx memset
	mov r0, #0
	str r0, [sp, #24]
	add r0, sp, #24
	str r0, [sp, #0]
	str r6, [sp, #4]
	ldr r0, [sp, #28]
	ldr r1, [sp, #72]
	str r0, [sp, #8]
	ldr r0, [r5, #0]
	ldr r2, [sp, #76]
	ldr r0, [r0, #0]
	lsl r1, r1, #16
	lsl r2, r2, #16
	str r0, [sp, #12]
	add r0, r5, #0
	lsr r1, r1, #16
	lsr r2, r2, #16
	add r3, r4, #0
	bl ov18_021F86D0
	ldr r1, [r5, #0]
	mov r0, #135
	lsl r0, r0, #4
	ldr r1, [r1, #0]
	ldr r3, [sp, #24]
	add r0, r5, r0
	add r2, r4, #0
	bl ov18_021F81D8
_DE_021F7DA6:
	add r0, r7, #0
	bl Heap_Free
	add r0, r4, #0
	bl Heap_Free
	add r0, r6, #0
	bl Heap_Free
	mov r0, #1
	add sp, #36
	pop {r4, r5, r6, r7, pc}
	nop
_DE_021F7DC0:
	.word 0x000003DA
_DE_021F7DC4:
	.word 0x00001858
	thumb_func_end ov18_021F7ED4
