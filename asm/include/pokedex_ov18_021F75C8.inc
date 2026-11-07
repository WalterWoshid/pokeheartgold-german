	thumb_func_start ov18_021F75C8
ov18_021F75C8:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _DE_021F7284
	add r4, r1, #0
	ldr r0, [r5, r0]
	bl GridInputHandler_GetDpadBox
	add r1, sp, #0
	add r1, #1
	add r2, sp, #0
	bl DpadMenuBox_GetPosition
	cmp r4, #0
	bne _DE_021F7254
	ldr r1, _DE_021F7288
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov18_021F3AD0
	add r1, sp, #0
	strb r0, [r1, #1]
	b _DE_021F7266
_DE_021F7254:
	cmp r4, #1
	bne _DE_021F7266
	ldr r1, _DE_021F728C
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov18_021F3AD0
	add r1, sp, #0
	strb r0, [r1, #1]
_DE_021F7266:
	mov r0, #103
	add r2, sp, #0
	lsl r0, r0, #4
	ldrb r1, [r2, #1]
	ldrb r2, [r2, #0]
	ldr r0, [r5, r0]
	bl ManagedSprite_SetPositionXY
	ldr r2, _DE_021F7290
	add r0, r5, #0
	ldrb r2, [r2, r4]
	mov r1, #0
	bl ov18_021F118C
	pop {r3, r4, r5, pc}
_DE_021F7284:
	.word 0x0000185C
_DE_021F7288:
	.word 0x0000187C
_DE_021F728C:
	.word 0x00001878
_DE_021F7290:
	.word ov18_021FB61C
	thumb_func_end ov18_021F75C8
