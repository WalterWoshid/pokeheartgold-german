	thumb_func_start ov18_021F3190
ov18_021F3190:
	push {r4, r5, r6, r7, lr}
	sub sp, #52
	add r5, r0, #0
	bl ov18_021F17FC
	add r0, r5, #0
	bl ov18_021F1CB4
	add r0, r5, #0
	bl ov18_021F1E70
	add r0, r5, #0
	bl ov18_021F2724
	add r0, r5, #0
	bl ov18_021F2348
	ldr r1, _DE_021F3130
	mov r3, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, _DE_021F3134
	lsl r3, r3, #20
	bl SpriteSystem_NewSpriteWithYOffset
	ldr r1, _DE_021F3138
	mov r3, #2
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #176
	sub r1, #172
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _DE_021F313C
	lsl r3, r3, #20
	bl SpriteSystem_NewSpriteWithYOffset
	ldr r1, _DE_021F3140
	str r0, [r5, r1]
	add r0, r5, #0
	mov r1, #44
	bl ov18_021F1A30
	add r0, r5, #0
	mov r1, #46
	bl ov18_021F1D98
	add r0, r5, #0
	mov r1, #47
	bl ov18_021F1FDC
	ldr r4, _DE_021F3144
	add r3, sp, #0
	mov r2, #6
_DE_021F30C2:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _DE_021F30C2
	ldr r0, [r4, #0]
	add r4, r5, #0
	ldr r6, _DE_021F3148
	str r0, [r3, #0]
	mov r7, #51
	add r4, #204
_DE_021F30D6:
	ldr r0, _DE_021F314C
	add r2, sp, #0
	sub r1, r6, r0
	add r0, sp, #0
	strh r1, [r0, #0]
	add r0, r5, #0
	add r1, r7, #0
	bl ov18_021F2424
	ldr r0, _DE_021F3150
	ldr r1, _DE_021F3154
	ldr r0, [r5, r0]
	mov r2, #2
	bl SpriteManager_FindPlttResourceOffset
	add r1, r0, #0
	mov r0, #103
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl ManagedSprite_SetPaletteOverride
	add r7, r7, #1
	add r6, #24
	add r4, r4, #4
	cmp r7, #56
	bls _DE_021F30D6
	mov r7, #103
	lsl r7, r7, #4
	mov r4, #42
	add r5, #168
	add r6, r7, #0
_DE_021F3114:
	ldr r0, [r5, r7]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r5, r6]
	mov r1, #2
	bl ManagedSprite_SetPriority
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #56
	bls _DE_021F3114
	add sp, #52
	pop {r4, r5, r6, r7, pc}
_DE_021F3130:
	.word 0x00000668
_DE_021F3134:
	.word ov18_021FAB58
_DE_021F3138:
	.word 0x00000718
_DE_021F313C:
	.word ov18_021FAB8C
_DE_021F3140:
	.word 0x0000071C
_DE_021F3144:
	.word ov18_021FA484
_DE_021F3148:
	.word 0x000004C8
_DE_021F314C:
	.word 0x0000044C
_DE_021F3150:
	.word 0x0000066C
_DE_021F3154:
	.word 0x0000C55A
	thumb_func_end ov18_021F3190
