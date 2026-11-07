	thumb_func_start ov18_021F4A6C
ov18_021F4A6C:
	push {r4, lr}
	sub sp, #24
	mov r1, #1
	add r4, r0, #0
	bl ov18_021F1324
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F48F4
	ldr r1, _DE_021F48F8
	str r0, [sp, #8]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #76
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	bl sub_02074490
	mov r2, #133
	lsl r2, r2, #4
	ldr r1, [r4, r2]
	ldr r3, _DE_021F48F8
	str r1, [sp, #0]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r1, #3
	str r1, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r0, _DE_021F48F4
	sub r2, #8
	str r0, [sp, #20]
	ldr r0, [r4, r2]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r3, [r4, r3]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F4900
	ldr r1, _DE_021F48F8
	str r0, [sp, #4]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #106
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F4900
	ldr r1, _DE_021F48F8
	str r0, [sp, #4]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #107
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F4904
	ldr r1, _DE_021F48F8
	str r0, [sp, #4]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #112
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F4904
	ldr r1, _DE_021F48F8
	str r0, [sp, #4]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #113
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	ldr r0, [r4, #0]
	ldr r0, [r0, #4]
	bl PlayerProfile_GetTrainerGender
	cmp r0, #0
	ldr r1, _DE_021F48F8
	bne _DE_021F4842
	mov r0, #1
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F4908
	ldr r2, _DE_021F48FC
	str r0, [sp, #8]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #105
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F490C
	ldr r1, _DE_021F48F8
	str r0, [sp, #8]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #105
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F4910
	ldr r1, _DE_021F48F8
	str r0, [sp, #8]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #111
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _DE_021F48FC
	ldr r3, _DE_021F48F8
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp, #0]
	mov r1, #108
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #12]
	str r1, [sp, #16]
	ldr r1, _DE_021F4914
	str r1, [sp, #20]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #2
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	ldr r0, _DE_021F48FC
	ldr r3, _DE_021F48F8
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp, #0]
	mov r1, #108
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #12]
	mov r1, #2
	str r1, [sp, #16]
	ldr r1, _DE_021F4918
	str r1, [sp, #20]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	add sp, #24
	pop {r4, pc}
_DE_021F4842:
	mov r0, #1
	str r0, [sp, #0]
	str r0, [sp, #4]
	ldr r0, _DE_021F4908
	ldr r2, _DE_021F48FC
	str r0, [sp, #8]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #109
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F490C
	ldr r1, _DE_021F48F8
	str r0, [sp, #8]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #109
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F4910
	ldr r1, _DE_021F48F8
	str r0, [sp, #8]
	ldr r2, _DE_021F48FC
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #114
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _DE_021F48FC
	ldr r3, _DE_021F48F8
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp, #0]
	mov r1, #110
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #12]
	str r1, [sp, #16]
	ldr r1, _DE_021F4914
	str r1, [sp, #20]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #2
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	ldr r0, _DE_021F48FC
	ldr r3, _DE_021F48F8
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp, #0]
	mov r1, #110
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #12]
	mov r1, #2
	str r1, [sp, #16]
	ldr r1, _DE_021F4918
	str r1, [sp, #20]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	add sp, #24
	pop {r4, pc}
	nop
_DE_021F48F4:
	.word 0x0000C551
_DE_021F48F8:
	.word 0x00000668
_DE_021F48FC:
	.word 0x0000084C
_DE_021F4900:
	.word 0x0000C55A
_DE_021F4904:
	.word 0x0000C55B
_DE_021F4908:
	.word 0x0000C59B
_DE_021F490C:
	.word 0x0000C59C
_DE_021F4910:
	.word 0x0000C59D
_DE_021F4914:
	.word 0x0000C55D
_DE_021F4918:
	.word 0x0000C55E
	thumb_func_end ov18_021F4A6C
