	thumb_func_start ov18_021F3448
ov18_021F3448:
	push {r4, lr}
	add r4, r0, #0
	mov r1, #24
	bl ov18_021F10E8
	add r0, r4, #0
	mov r1, #25
	bl ov18_021F10E8
	ldr r0, _DE_021F3348
	ldr r1, _DE_021F334C
	ldr r0, [r4, r0]
	bl SpriteManager_UnloadCharObjById
	ldr r0, _DE_021F3348
	ldr r1, _DE_021F3350
	ldr r0, [r4, r0]
	bl SpriteManager_UnloadPlttObjById
	ldr r0, _DE_021F3348
	ldr r1, _DE_021F3354
	ldr r0, [r4, r0]
	bl SpriteManager_UnloadCellObjById
	ldr r0, _DE_021F3348
	ldr r1, _DE_021F3354
	ldr r0, [r4, r0]
	bl SpriteManager_UnloadAnimObjById
	pop {r4, pc}
_DE_021F3348:
	.word 0x0000066C
_DE_021F334C:
	.word 0x0000C59E
_DE_021F3350:
	.word 0x0000C55F
_DE_021F3354:
	.word 0x0000C55C
	thumb_func_end ov18_021F3448
