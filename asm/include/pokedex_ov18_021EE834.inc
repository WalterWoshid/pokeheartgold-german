	thumb_func_start ov18_021EE834
ov18_021EE834:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #16
	add r6, r0, #0
	add r4, r6, #0
	lsl r5, r3, #4
	add r4, #12
	add r7, r1, #0
	add r0, r4, r5
	mov r1, #0
	str r2, [sp, #12]
	bl FillWindowPixelBuffer
	cmp r7, #0
	beq _DE_021EE84A
	ldr r0, [sp, #12]
	lsl r0, r0, #2
	add r1, r6, r0
	ldr r0, _DE_021EE854
	ldrh r0, [r1, r0]
	cmp r0, #2
	bne _DE_021EE80E
	add r0, r7, #0
	mov r1, #5
	mov r2, #37
	bl ov18_021E595C
	b _DE_021EE818
_DE_021EE80E:
	mov r0, #0
	mov r1, #5
	mov r2, #37
	bl ov18_021E595C
_DE_021EE818:
	add r6, r0, #0
	add r0, r4, r5
	bl GetWindowWidth
	lsl r0, r0, #3
	sub r2, r0, #4
	mov r0, #4
	str r0, [sp, #0]
	ldr r0, _DE_021EE858
	add r1, r6, #0
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	add r0, r4, r5
	mov r3, #0
	bl ov18_021F95FC
	add r0, r6, #0
	bl String_Delete
	add r0, r4, r5
	bl ScheduleWindowCopyToVram
	add sp, #16
	pop {r3, r4, r5, r6, r7, pc}
_DE_021EE84A:
	add r0, r4, r5
	bl ClearWindowTilemapAndScheduleTransfer
	add sp, #16
	pop {r3, r4, r5, r6, r7, pc}
_DE_021EE854:
	.word 0x0000102A
_DE_021EE858:
	.word 0x00020100
	thumb_func_end ov18_021EE834
