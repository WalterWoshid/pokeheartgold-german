	thumb_func_start ov18_021EE7DC
ov18_021EE7DC:
	push {r3, r4, r5, r6, lr}
	sub sp, #12
	add r4, r0, #0
	lsl r5, r2, #4
	add r4, #12
	add r6, r1, #0
	add r0, r4, r5
	mov r1, #0
	bl FillWindowPixelBuffer
	cmp r6, #0
	beq _DE_021EE7CA
	add r0, r6, #0
	mov r1, #5
	mov r2, #37
	bl ov18_021E590C
	add r6, r0, #0
	mov r0, #4
	str r0, [sp, #0]
	ldr r0, _DE_021EE7D4
	mov r2, #0
	str r0, [sp, #4]
	add r0, r4, r5
	add r1, r6, #0
	add r3, r2, #0
	str r2, [sp, #8]
	bl ov18_021F95FC
	add r0, r6, #0
	bl String_Delete
	add r0, r4, r5
	bl ScheduleWindowCopyToVram
	add sp, #12
	pop {r3, r4, r5, r6, pc}
_DE_021EE7CA:
	add r0, r4, r5
	bl ClearWindowTilemapAndScheduleTransfer
	add sp, #12
	pop {r3, r4, r5, r6, pc}
_DE_021EE7D4:
	.word 0x00020100
	thumb_func_end ov18_021EE7DC
