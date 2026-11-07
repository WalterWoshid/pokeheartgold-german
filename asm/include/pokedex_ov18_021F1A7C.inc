	thumb_func_start ov18_021F1A7C
ov18_021F1A7C:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #64
	str r2, [sp, #20]
	str r3, [sp, #24]
	ldr r3, _DE_021F1A80
	add r2, sp, #32
	add r5, r0, #0
	add r4, r1, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	mov r1, #50
	mov r0, #37
	lsl r1, r1, #6
	bl Heap_AllocAtEnd
	add r7, r0, #0
	mov r0, #0
	add r1, sp, #48
	mov r2, #16
	blx MIi_CpuClearFast
	ldr r0, _DE_021F1A84
	cmp r4, r0
	bne _DE_021F198E
	add r0, sp, #72
	ldrb r0, [r0, #16]
	cmp r0, #2
	bne _DE_021F198E
	ldr r0, [r5, #0]
	mov r1, #0
	ldr r0, [r0, #0]
	bl Pokedex_GetSeenSpindaPersonality
	add r6, r0, #0
	b _DE_021F1990
_DE_021F198E:
	mov r6, #0
_DE_021F1990:
	mov r0, #0
	str r0, [sp, #0]
	ldr r0, [sp, #20]
	add r3, sp, #72
	str r0, [sp, #4]
	str r6, [sp, #8]
	ldrb r3, [r3, #16]
	ldr r2, [sp, #24]
	add r0, sp, #48
	add r1, r4, #0
	bl GetMonSpriteCharAndPlttNarcIdsEx
	str r7, [sp, #0]
	str r6, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r0, sp, #72
	ldrb r0, [r0, #16]
	add r1, sp, #32
	mov r2, #37
	str r0, [sp, #12]
	str r4, [sp, #16]
	ldrh r0, [r1, #16]
	ldrh r1, [r1, #18]
	add r3, sp, #32
	bl sub_02014510
	mov r0, #103
	lsl r0, r0, #4
	add r4, r5, r0
	ldr r0, [sp, #92]
	lsl r6, r0, #2
	ldr r0, [r4, r6]
	ldr r0, [r0, #0]
	bl Sprite_GetImageProxy
	mov r1, #2
	blx NNS_G2dGetImageLocation
	mov r1, #50
	str r0, [sp, #28]
	add r0, r7, #0
	lsl r1, r1, #6
	blx DC_FlushRange
	mov r2, #50
	ldr r1, [sp, #28]
	add r0, r7, #0
	lsl r2, r2, #6
	blx GXS_LoadOBJ
	ldr r0, [r4, r6]
	ldr r0, [r0, #0]
	bl Sprite_GetPaletteProxy
	mov r1, #2
	blx NNS_G2dGetImagePaletteLocation
	add r4, r0, #0
	ldr r0, [sp, #96]
	cmp r0, #0
	bne _DE_021F1A34
	mov r0, #32
	str r0, [sp, #0]
	mov r0, #37
	str r0, [sp, #4]
	add r1, sp, #32
	ldrh r0, [r1, #16]
	ldrh r1, [r1, #20]
	mov r2, #5
	add r3, r4, #0
	bl GfGfxLoader_GXLoadPal
	ldr r0, _DE_021F1A88
	lsl r2, r4, #15
	ldr r0, [r5, r0]
	mov r1, #3
	lsr r2, r2, #16
	mov r3, #32
	bl PaletteData_LoadPaletteSlotFromHardware
	b _DE_021F1A76
_DE_021F1A34:
	cmp r0, #1
	bne _DE_021F1A58
	mov r0, #3
	str r0, [sp, #0]
	mov r0, #32
	str r0, [sp, #4]
	lsl r0, r4, #15
	lsr r0, r0, #16
	str r0, [sp, #8]
	ldr r0, _DE_021F1A88
	add r2, sp, #32
	ldrh r1, [r2, #16]
	ldrh r2, [r2, #20]
	ldr r0, [r5, r0]
	mov r3, #37
	bl PaletteData_LoadNarc
	b _DE_021F1A76
_DE_021F1A58:
	lsr r1, r4, #1
	lsl r0, r1, #16
	lsr r0, r0, #16
	add r1, #16
	str r0, [sp, #0]
	lsl r0, r1, #16
	lsr r0, r0, #16
	str r0, [sp, #4]
	ldr r0, _DE_021F1A88
	mov r1, #3
	ldr r0, [r5, r0]
	mov r2, #2
	mov r3, #0
	bl PaletteData_FillPaletteInBuffer
_DE_021F1A76:
	add r0, r7, #0
	bl Heap_Free
	add sp, #64
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F1A80:
	.word ov18_021FA328
_DE_021F1A84:
	.word 0x00000147
_DE_021F1A88:
	.word 0x00000848
	thumb_func_end ov18_021F1A7C
