	thumb_func_start ov112_021F1488
ov112_021F1488:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #16
	add r5, r0, #0
	mov r0, #1
	str r2, [sp, #8]
	add r6, r1, #0
	add r4, r3, #0
	str r0, [sp, #12]
	ldr r1, [r5, #4]
	add r0, r4, #0
	bl String_New
	add r7, r0, #0
	ldrh r0, [r6, #0]
	cmp r0, #0
	beq _DE_021F14AA
	mov r2, #0
	cmp r4, #0
	ble _DE_021F14AA
	ldr r0, _DE_021F14E0
	add r3, r6, #0
_DE_021F1496:
	ldrh r1, [r3, #0]
	cmp r1, r0
	bne _DE_021F14A2
	mov r0, #0
	str r0, [sp, #12]
	b _DE_021F14AA
_DE_021F14A2:
	add r2, r2, #1
	add r3, r3, #2
	cmp r2, r4
	blt _DE_021F1496
_DE_021F14AA:
	ldr r0, [sp, #12]
	cmp r0, #0
	beq _DE_021F14BA
	ldr r1, _DE_021F14E4
	add r0, r7, #0
	bl CopyU16ArrayToString
	b _DE_021F14C2
_DE_021F14BA:
	add r0, r7, #0
	add r1, r6, #0
	bl CopyU16ArrayToString
_DE_021F14C2:
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r5, #88]
	ldr r1, [sp, #8]
	add r2, r7, #0
	mov r3, #2
	bl BufferString
	add r0, r7, #0
	bl String_Delete
	add sp, #16
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F14E0:
	.word 0x0000FFFF
_DE_021F14E4:
	.word ov112_021FF2EC
	thumb_func_end ov112_021F1488
