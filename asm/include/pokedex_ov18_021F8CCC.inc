	thumb_func_start ov18_021F8CCC
ov18_021F8CCC:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	add r5, r0, #0
	add r4, r5, #0
	ldr r6, _DE_021F8B68
	mov r7, #0
	add r4, #36
_DE_021F893E:
	ldr r0, [r5, #0]
	add r1, r4, #0
	add r2, r6, #0
	bl AddWindow
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r7, r7, #1
	add r6, #8
	add r4, #16
	cmp r7, #9
	blo _DE_021F893E
	ldr r2, _DE_021F8B6C
	ldr r3, [r5, #20]
	mov r0, #0
	mov r1, #27
	bl NewMsgDataFromNarc
	add r4, r0, #0
	ldr r0, [r5, #20]
	bl MessageFormat_New
	add r6, r0, #0
	mov r0, #1
	ldr r1, [r5, #20]
	lsl r0, r0, #10
	bl String_New
	str r0, [sp, #16]
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F8B70
	add r1, r4, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	add r0, #36
	mov r2, #144
	mov r3, #112
	bl ov18_021F9648
	mov r1, #145
	lsl r1, r1, #2
	ldr r0, [r5, #16]
	ldr r1, [r5, r1]
	bl Pokedex_ConvertToCurrentDexNo
	add r2, r0, #0
	mov r0, #2
	str r0, [sp, #0]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r6, #0
	mov r1, #0
	mov r3, #3
	bl BufferIntegerAsString
	add r0, r4, #0
	mov r1, #9
	bl NewString_ReadMsgData
	add r7, r0, #0
	ldr r1, [sp, #16]
	add r0, r6, #0
	add r2, r7, #0
	bl StringExpandPlaceholders
	mov r0, #4
	str r0, [sp, #0]
	ldr r0, _DE_021F8B70
	ldr r1, [sp, #16]
	str r0, [sp, #4]
	add r0, r5, #0
	mov r3, #0
	add r0, #52
	mov r2, #1
	str r3, [sp, #8]
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #145
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [r5, #20]
	mov r1, #5
	bl ov18_021E590C
	add r7, r0, #0
	mov r0, #4
	str r0, [sp, #0]
	ldr r0, _DE_021F8B70
	mov r2, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #68
	add r1, r7, #0
	add r3, r2, #0
	str r2, [sp, #8]
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #145
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, [r5, #20]
	mov r1, #5
	bl ov18_021E595C
	add r7, r0, #0
	add r0, r5, #0
	add r0, #84
	bl GetWindowWidth
	lsl r0, r0, #3
	sub r2, r0, #4
	mov r0, #4
	str r0, [sp, #0]
	ldr r0, _DE_021F8B70
	add r1, r7, #0
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #84
	mov r3, #0
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #145
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r3, [r5, #20]
	mov r1, #5
	mov r2, #0
	bl ov18_021E59A8
	add r7, r0, #0
	add r0, r5, #0
	add r0, #100
	bl GetWindowWidth
	str r0, [sp, #20]
	mov r0, #0
	add r1, r7, #0
	add r2, r0, #0
	bl FontID_String_GetWidthMultiline
	ldr r1, [sp, #20]
	mov r3, #0
	lsl r1, r1, #3
	sub r0, r1, r0
	lsr r2, r0, #1
	ldr r0, _DE_021F8B70
	str r3, [sp, #0]
	str r0, [sp, #4]
	add r0, r5, #0
	add r0, #100
	add r1, r7, #0
	str r3, [sp, #8]
	bl ov18_021F95FC
	add r0, r7, #0
	bl String_Delete
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F8B70
	add r1, r4, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	add r0, #116
	mov r2, #10
	mov r3, #20
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F8B70
	add r1, r4, #0
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	add r0, #148
	mov r2, #11
	mov r3, #20
	bl ov18_021F9648
	add r0, r6, #0
	bl MessageFormat_Delete
	add r0, r4, #0
	bl DestroyMsgData
	bl GetDexHeightMsgBank
	add r2, r0, #0
	ldr r3, [r5, #20]
	mov r0, #0
	mov r1, #27
	bl NewMsgDataFromNarc
	mov r1, #0
	add r4, r0, #0
	str r1, [sp, #0]
	mov r2, #145
	ldr r0, _DE_021F8B70
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #12]
	lsl r2, r2, #2
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r0, #132
	add r1, r4, #0
	mov r3, #4
	bl ov18_021F9648
	add r0, r4, #0
	bl DestroyMsgData
	bl GetDexWeightMsgBank
	add r2, r0, #0
	ldr r3, [r5, #20]
	mov r0, #0
	mov r1, #27
	bl NewMsgDataFromNarc
	mov r1, #0
	add r4, r0, #0
	str r1, [sp, #0]
	mov r2, #145
	ldr r0, _DE_021F8B70
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #12]
	lsl r2, r2, #2
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r0, #164
	add r1, r4, #0
	mov r3, #4
	bl ov18_021F9648
	add r0, r4, #0
	bl DestroyMsgData
	ldr r0, [sp, #16]
	bl String_Delete
	mov r4, #0
	add r5, #36
_DE_021F8B56:
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add r4, r4, #1
	add r5, #16
	cmp r4, #9
	blo _DE_021F8B56
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F8B68:
	.word ov18_021FBDB4
_DE_021F8B6C:
	.word 0x00000322
_DE_021F8B70:
	.word 0x00020100
	thumb_func_end ov18_021F8CCC
