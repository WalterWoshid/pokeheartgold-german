	thumb_func_start ov18_021F17FC
ov18_021F17FC:
	push {r4, lr}
	sub sp, #24
	add r4, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F178C
	ldr r1, _DE_021F1790
	str r0, [sp, #8]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #8
	mov r3, #76
	bl SpriteSystem_LoadCharResObj
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, _DE_021F1794
	ldr r1, _DE_021F1790
	str r0, [sp, #8]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #8
	mov r3, #76
	bl SpriteSystem_LoadCharResObj
	mov r0, #8
	str r0, [sp, #0]
	mov r0, #75
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r0, _DE_021F1798
	ldr r3, _DE_021F1790
	str r0, [sp, #20]
	ldr r0, _DE_021F179C
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #8
	str r0, [sp, #0]
	mov r0, #75
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #12]
	mov r0, #2
	str r0, [sp, #16]
	ldr r0, _DE_021F17A0
	ldr r3, _DE_021F1790
	str r0, [sp, #20]
	ldr r0, _DE_021F179C
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	mov r1, #3
	bl SpriteSystem_LoadPaletteBuffer
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, _DE_021F17A4
	ldr r1, _DE_021F1790
	str r0, [sp, #4]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #8
	mov r3, #77
	bl SpriteSystem_LoadCellResObj
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, _DE_021F17A4
	ldr r1, _DE_021F1790
	str r0, [sp, #4]
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #8
	mov r3, #78
	bl SpriteSystem_LoadAnimResObj
	add sp, #24
	pop {r4, pc}
	nop
_DE_021F178C:
	.word 0x0000C58C
_DE_021F1790:
	.word 0x00000668
_DE_021F1794:
	.word 0x0000C58D
_DE_021F1798:
	.word 0x0000C552
_DE_021F179C:
	.word 0x00000848
_DE_021F17A0:
	.word 0x0000C553
_DE_021F17A4:
	.word 0x0000C551
	thumb_func_end ov18_021F17FC
