	thumb_func_start ov18_021F1024
ov18_021F1024:
	push {r4, r5, r6, r7, lr}
	sub sp, #76
	add r4, r0, #0
	mov r0, #37
	bl SpriteSystem_Alloc
	ldr r1, _DE_021F0F84
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	bl SpriteManager_New
	ldr r7, _DE_021F0F88
	add r2, sp, #44
	ldr r3, _DE_021F0F8C
	str r0, [r4, r7]
	ldmia r3!, {r0, r1}
	add r6, r2, #0
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	ldr r5, _DE_021F0F90
	stmia r2!, {r0, r1}
	add r3, sp, #24
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5, #0]
	add r1, r6, #0
	str r0, [r3, #0]
	sub r0, r7, #4
	ldr r0, [r4, r0]
	mov r3, #32
	bl SpriteSystem_Init
	ldr r3, _DE_021F0F94
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r1, r7, #4
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mov r2, #118
	bl SpriteSystem_InitSprites
	sub r1, r7, #4
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	add r2, sp, #0
	bl SpriteSystem_InitManagerWithCapacities
	sub r0, r7, #4
	ldr r0, [r4, r0]
	bl SpriteSystem_GetRenderer
	mov r2, #2
	mov r1, #0
	lsl r2, r2, #20
	bl G2dRenderer_SetSubSurfaceCoords
	add sp, #76
	pop {r4, r5, r6, r7, pc}
_DE_021F0F84:
	.word 0x00000668
_DE_021F0F88:
	.word 0x0000066C
_DE_021F0F8C:
	.word ov18_021FA3C8
_DE_021F0F90:
	.word ov18_021FA36C
_DE_021F0F94:
	.word ov18_021FA380
	thumb_func_end ov18_021F1024
