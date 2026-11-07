	thumb_func_start ov18_021F1324
ov18_021F1324:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	add r5, r0, #0
	add r6, r1, #0
	ldr r4, _DE_021F1294
	beq _DE_021F1220
	mov r7, #1
_DE_021F11FE:
	ldr r0, _DE_021F1298
	str r7, [sp, #0]
	str r7, [sp, #4]
	add r0, r4, r0
	str r0, [sp, #8]
	ldr r0, _DE_021F129C
	ldr r1, _DE_021F12A0
	ldr r2, _DE_021F12A4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	mov r3, #76
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	add r4, r4, #1
	cmp r4, r6
	blo _DE_021F11FE
_DE_021F1220:
	bl sub_02074490
	mov r1, #133
	lsl r1, r1, #4
	ldr r2, [r5, r1]
	ldr r3, _DE_021F129C
	str r2, [sp, #0]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #3
	str r0, [sp, #12]
	mov r0, #1
	str r0, [sp, #16]
	ldr r0, _DE_021F1298
	sub r1, #8
	str r0, [sp, #20]
	ldr r2, [r5, r3]
	add r3, r3, #4
	ldr r0, [r5, r1]
	ldr r3, [r5, r3]
	mov r1, #2
	bl SpriteSystem_LoadPaletteBufferFromOpenNarc
	bl sub_0207449C
	add r3, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, _DE_021F1298
	mov r2, #133
	ldr r1, _DE_021F129C
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	lsl r2, r2, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	bl sub_020744A8
	add r3, r0, #0
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, _DE_021F1298
	mov r2, #133
	ldr r1, _DE_021F129C
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	lsl r2, r2, #4
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F1294:
	.word 0x00000000
_DE_021F1298:
	.word 0x0000C550
_DE_021F129C:
	.word 0x00000668
_DE_021F12A0:
	.word 0x0000066C
_DE_021F12A4:
	.word 0x0000084C
	thumb_func_end ov18_021F1324
