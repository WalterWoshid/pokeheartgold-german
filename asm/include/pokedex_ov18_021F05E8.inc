	thumb_func_start ov18_021F05E8
ov18_021F05E8:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #16
	ldr r1, _DE_021F06E8
	mov r2, #13
	add r5, r0, #0
	bl ov18_021EE35C
	mov r6, #0
	add r4, r5, #0
	add r4, #12
	add r7, r6, #0
_DE_021F04C6:
	add r0, r4, #0
	add r1, r7, #0
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #16
	cmp r6, #13
	blo _DE_021F04C6
	ldr r1, _DE_021F06EC
	ldr r0, [r5, #0]
	ldrh r1, [r5, r1]
	ldr r0, [r0, #0]
	bl Pokedex_CheckMonCaughtFlag
	cmp r0, #0
	beq _DE_021F04EA
	mov r4, #2
	b _DE_021F04EC
_DE_021F04EA:
	mov r4, #1
_DE_021F04EC:
	mov r3, #0
	str r3, [sp, #0]
	mov r0, #4
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	str r3, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #12
	mov r2, #143
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #60
	mov r2, #136
	mov r3, #48
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #76
	mov r2, #10
	mov r3, #20
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #108
	mov r2, #10
	mov r3, #20
	bl ov18_021F9648
	ldr r0, _DE_021F06EC
	mov r1, #5
	ldrh r0, [r5, r0]
	mov r2, #37
	bl ov18_021E590C
	add r6, r0, #0
	mov r3, #0
	ldr r0, _DE_021F06F0
	str r3, [sp, #0]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #28
	add r1, r6, #0
	mov r2, #32
	bl ov18_021F95FC
	add r0, r6, #0
	bl String_Delete
	ldr r0, [r5, #0]
	mov r1, #37
	ldr r0, [r0, #4]
	bl PlayerProfile_GetPlayerName_NewString
	add r6, r0, #0
	mov r3, #0
	ldr r0, _DE_021F06F0
	str r3, [sp, #0]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #44
	add r1, r6, #0
	mov r2, #32
	bl ov18_021F95FC
	add r0, r6, #0
	bl String_Delete
	mov r0, #28
	str r0, [sp, #0]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	ldr r1, _DE_021F06EC
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	ldrh r1, [r5, r1]
	add r0, r5, #0
	add r2, r4, #0
	mov r3, #5
	bl ov18_021EEA84
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06F8
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #140
	mov r2, #137
	mov r3, #48
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06FC
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #156
	mov r2, #11
	mov r3, #20
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06FC
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #188
	mov r2, #11
	mov r3, #20
	bl ov18_021F9648
	mov r0, #28
	str r0, [sp, #0]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, _DE_021F06FC
	ldr r1, _DE_021F06EC
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	ldrh r1, [r5, r1]
	add r0, r5, #0
	add r2, r4, #0
	mov r3, #10
	bl ov18_021EEB34
	ldr r0, [r5, #0]
	ldr r0, [r0, #4]
	bl PlayerProfile_GetTrainerGender
	cmp r0, #0
	ldr r1, _DE_021F06F4
	bne _DE_021F0698
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	mov r2, #138
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #124
	mov r3, #28
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06FC
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #204
	mov r2, #140
	mov r3, #28
	bl ov18_021F9648
	b _DE_021F06D2
_DE_021F0698:
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06F0
	mov r2, #139
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #124
	mov r3, #28
	bl ov18_021F9648
	mov r0, #0
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F06FC
	ldr r1, _DE_021F06F4
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #12]
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r0, #204
	mov r2, #141
	mov r3, #28
	bl ov18_021F9648
_DE_021F06D2:
	mov r4, #0
	add r5, #12
_DE_021F06D6:
	add r0, r5, #0
	bl ScheduleWindowCopyToVram
	add r4, r4, #1
	add r5, #16
	cmp r4, #13
	blo _DE_021F06D6
	add sp, #16
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F06E8:
	.word ov18_021F9DE4
_DE_021F06EC:
	.word 0x0000189A
_DE_021F06F0:
	.word 0x00020100
_DE_021F06F4:
	.word 0x0000065C
_DE_021F06F8:
	.word 0x00050900
_DE_021F06FC:
	.word 0x000F0500
	thumb_func_end ov18_021F05E8
