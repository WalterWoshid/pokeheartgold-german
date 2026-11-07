	thumb_func_start ov109_021E7248
ov109_021E7248:
	push {r3, r4, r5, lr}
	sub sp, #16
	add r5, r0, #0
	ldr r0, [r5, #20]
	add r4, r1, #0
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, [r5, #20]
	mov r1, #7
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	add r0, #112
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5, #20]
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #20]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	cmp r4, #0
	bne _DE_021E726A
	add r5, #112
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add sp, #16
	pop {r3, r4, r5, pc}
_DE_021E726A:
	ldr r0, [r5, #16]
	ldr r0, [r0, #12]
	bl Save_PlayerData_GetProfile
	add r2, r0, #0
	ldr r0, [r5, #40]
	mov r1, #0
	bl BufferPlayersName
	ldrh r0, [r4, #50]
	ldr r1, [r5, #0]
	ldr r2, [r5, #44]
	bl MapID_GetLandmarkName
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r5, #40]
	ldr r2, [r5, #44]
	mov r1, #1
	mov r3, #2
	bl BufferString
	add r1, r4, #0
	ldr r0, [r5, #44]
	add r1, #24
	bl CopyU16ArrayToString
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	mov r1, #2
	ldr r0, [r5, #40]
	ldr r2, [r5, #44]
	add r3, r1, #0
	bl BufferString
	mov r0, #2
	str r0, [sp, #0]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [r4, #56]
	ldr r0, [r5, #40]
	lsr r2, r2, #24
	lsl r2, r2, #24
	lsr r3, r2, #24
	mov r2, #125
	lsl r2, r2, #4
	add r2, r3, r2
	mov r1, #3
	mov r3, #4
	bl BufferIntegerAsString
	mov r3, #2
	str r3, [sp, #0]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [r4, #56]
	ldr r0, [r5, #40]
	lsr r2, r2, #16
	lsl r2, r2, #24
	mov r1, #4
	lsr r2, r2, #24
	bl BufferIntegerAsString
	mov r3, #2
	str r3, [sp, #0]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [r4, #56]
	ldr r0, [r5, #40]
	lsr r2, r2, #8
	lsl r2, r2, #24
	mov r1, #5
	lsr r2, r2, #24
	bl BufferIntegerAsString
	add r0, r4, #0
	bl ov109_021E7850
	cmp r0, #1
	ldr r0, [r5, #40]
	bls _DE_021E731E
	ldr r1, [r5, #44]
	ldr r2, [r5, #76]
	bl StringExpandPlaceholders
	b _DE_021E7326
_DE_021E731E:
	ldr r1, [r5, #44]
	ldr r2, [r5, #72]
	bl StringExpandPlaceholders
_DE_021E7326:
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #255
	str r0, [sp, #4]
	ldr r0, _DE_021E7368
	add r3, r1, #0
	str r0, [sp, #8]
	str r1, [sp, #12]
	add r0, r5, #0
	ldr r2, [r5, #44]
	add r0, #112
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	add r0, #112
	bl ScheduleWindowCopyToVram
	mov r0, #8
	str r0, [sp, #0]
	ldrb r1, [r4, #4]
	add r0, r5, #0
	mov r2, #7
	lsl r1, r1, #24
	lsr r1, r1, #25
	add r1, r1, #1
	lsl r1, r1, #24
	lsr r1, r1, #24
	mov r3, #13
	bl ov109_021E7114
	add sp, #16
	pop {r3, r4, r5, pc}
	nop
_DE_021E7368:
	.word 0x00030200
	thumb_func_end ov109_021E7248
