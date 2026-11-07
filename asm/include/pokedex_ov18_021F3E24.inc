	thumb_func_start ov18_021F3E24
ov18_021F3E24:
	push {r4, lr}
	sub sp, #24
	add r4, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F3C0C
	ldr r1, _DE_021F3C10
	str r0, [sp, #8]
	ldr r2, _DE_021F3C14
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
	ldr r3, _DE_021F3C10
	str r1, [sp, #0]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r1, #3
	str r1, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r0, _DE_021F3C18
	sub r2, #8
	str r0, [sp, #20]
	ldr r0, [r4, r2]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r3, [r4, r3]
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	bl sub_0207449C
	add r3, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, _DE_021F3C0C
	mov r2, #133
	ldr r1, _DE_021F3C10
	str r0, [sp, #4]
	ldr r0, [r4, r1]
	add r1, r1, #4
	lsl r2, r2, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	bl sub_020744A8
	add r3, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, _DE_021F3C0C
	mov r2, #133
	ldr r1, _DE_021F3C10
	str r0, [sp, #4]
	ldr r0, [r4, r1]
	add r1, r1, #4
	lsl r2, r2, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F3C1C
	ldr r1, _DE_021F3C10
	str r0, [sp, #8]
	ldr r2, _DE_021F3C14
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #115
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _DE_021F3C14
	ldr r3, _DE_021F3C10
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp, #0]
	mov r1, #118
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #1
	str r1, [sp, #12]
	mov r1, #2
	str r1, [sp, #16]
	ldr r1, _DE_021F3C20
	str r1, [sp, #20]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F3C24
	ldr r1, _DE_021F3C10
	str r0, [sp, #4]
	ldr r2, _DE_021F3C14
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #116
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F3C24
	ldr r1, _DE_021F3C10
	str r0, [sp, #4]
	ldr r2, _DE_021F3C14
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #117
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F3C28
	ldr r1, _DE_021F3C10
	str r0, [sp, #8]
	ldr r2, _DE_021F3C14
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #119
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	ldr r0, _DE_021F3C14
	ldr r3, _DE_021F3C10
	ldr r1, [r4, r0]
	sub r0, r0, #4
	str r1, [sp, #0]
	mov r1, #122
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #2
	str r1, [sp, #12]
	str r1, [sp, #16]
	ldr r1, _DE_021F3C2C
	str r1, [sp, #20]
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F3C30
	ldr r1, _DE_021F3C10
	str r0, [sp, #4]
	ldr r2, _DE_021F3C14
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #120
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F3C30
	ldr r1, _DE_021F3C10
	str r0, [sp, #4]
	ldr r2, _DE_021F3C14
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r2, [r4, r2]
	mov r3, #121
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add sp, #24
	pop {r4, pc}
_DE_021F3C0C:
	.word 0x0000C550
_DE_021F3C10:
	.word 0x00000668
_DE_021F3C14:
	.word 0x0000084C
_DE_021F3C18:
	.word 0x0000C551
_DE_021F3C1C:
	.word 0x0000C59C
_DE_021F3C20:
	.word 0x0000C55E
_DE_021F3C24:
	.word 0x0000C55A
_DE_021F3C28:
	.word 0x0000C59A
_DE_021F3C2C:
	.word 0x0000C55C
_DE_021F3C30:
	.word 0x0000C559
	thumb_func_end ov18_021F3E24
