	thumb_func_start ov18_021EE8B8
ov18_021EE8B8:
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r0, #204
	add r4, r1, #0
	add r6, r2, #0
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #0
	add r0, #236
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #0
	add r0, #188
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #0
	add r0, #220
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #0
	add r0, #252
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #67
	lsl r0, r0, #2
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #71
	lsl r0, r0, #2
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #75
	lsl r0, r0, #2
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	mov r0, #79
	lsl r0, r0, #2
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	cmp r4, #0
	beq _DE_021EE920
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #11
	bl ov18_021EE984
	ldr r0, _DE_021EE924
	ldrb r0, [r5, r0]
	cmp r0, #5
	bne _DE_021EE8F4
	add r0, r5, #0
	mov r1, #12
	bl ov18_021EE9FC
	add r0, r5, #0
	mov r1, #14
	bl ov18_021EEA40
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #13
	bl ov18_021EEAE4
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #15
	bl ov18_021EEB94
	pop {r4, r5, r6, pc}
_DE_021EE8F4:
	add r0, r5, #0
	mov r1, #16
	bl ov18_021EEBE4
	ldr r3, _DE_021EE924
	add r0, r5, #0
	ldrb r3, [r5, r3]
	add r1, r4, #0
	mov r2, #17
	bl ov18_021EEC34
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #18
	bl ov18_021EECB0
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #19
	bl ov18_021EED00
_DE_021EE920:
	pop {r4, r5, r6, pc}
	nop
_DE_021EE924:
	.word 0x00001854
	thumb_func_end ov18_021EE8B8
