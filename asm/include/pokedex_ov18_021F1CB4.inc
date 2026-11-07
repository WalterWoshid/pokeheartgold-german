	thumb_func_start ov18_021F1CB4
ov18_021F1CB4:
	push {r3, r4, r5, lr}
	sub sp, #24
	add r5, r0, #0
	bl ov18_021E5900
	add r4, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F1C04
	ldr r1, _DE_021F1C08
	str r0, [sp, #8]
	ldr r2, _DE_021F1C0C
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	mov r3, #77
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	bl ov18_021E5908
	str r4, [sp, #0]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r0, _DE_021F1C10
	ldr r3, _DE_021F1C08
	str r0, [sp, #20]
	ldr r0, _DE_021F1C14
	ldr r2, [r5, r3]
	add r3, r3, #4
	ldr r0, [r5, r0]
	ldr r3, [r5, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F1C18
	ldr r1, _DE_021F1C08
	str r0, [sp, #4]
	ldr r2, _DE_021F1C0C
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	mov r3, #78
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp, #0]
	ldr r0, _DE_021F1C18
	ldr r1, _DE_021F1C08
	str r0, [sp, #4]
	ldr r2, _DE_021F1C0C
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	mov r3, #79
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add sp, #24
	pop {r3, r4, r5, pc}
_DE_021F1C04:
	.word 0x0000C599
_DE_021F1C08:
	.word 0x00000668
_DE_021F1C0C:
	.word 0x0000084C
_DE_021F1C10:
	.word 0x0000C55B
_DE_021F1C14:
	.word 0x00000848
_DE_021F1C18:
	.word 0x0000C558
	thumb_func_end ov18_021F1CB4
