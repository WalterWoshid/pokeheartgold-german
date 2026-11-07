	thumb_func_start ov18_021F32B8
ov18_021F32B8:
	push {r4, r5, r6, r7, lr}
	sub sp, #52
	mov r7, #103
	ldr r6, _DE_021F32D4
	add r5, r0, #0
	mov r4, #0
	lsl r7, r7, #4
_DE_021F318A:
	ldr r0, _DE_021F32D8
	ldr r1, _DE_021F32DC
	mov r2, #52
	mul r2, r4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, r2
	bl SpriteSystem_NewSprite
	lsl r1, r4, #2
	add r1, r5, r1
	str r0, [r1, r7]
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #0
	bl ov18_021F11C0
	add r0, r4, #1
	lsl r0, r0, #16
	lsr r4, r0, #16
	cmp r4, #23
	bls _DE_021F318A
	ldr r1, _DE_021F32D8
	mov r3, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, _DE_021F32E0
	lsl r3, r3, #20
	bl SpriteSystem_NewSpriteWithYOffset
	ldr r1, _DE_021F32E4
	mov r2, #0
	str r0, [r5, r1]
	add r0, r5, #0
	mov r1, #41
	bl ov18_021F11C0
	ldr r1, _DE_021F32D8
	mov r3, #2
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	ldr r2, _DE_021F32E8
	lsl r3, r3, #20
	bl SpriteSystem_NewSpriteWithYOffset
	mov r1, #109
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	sub r0, #104
	sub r1, #100
	mov r3, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, _DE_021F32EC
	lsl r3, r3, #20
	bl SpriteSystem_NewSpriteWithYOffset
	ldr r1, _DE_021F32F0
	mov r2, #0
	str r0, [r5, r1]
	add r0, r5, #0
	mov r1, #25
	bl ov18_021F11C0
	ldr r4, _DE_021F32F4
	add r3, sp, #0
	mov r2, #6
_DE_021F3216:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _DE_021F3216
	ldr r0, [r4, #0]
	mov r4, #26
	str r0, [r3, #0]
	add r7, sp, #0
_DE_021F3226:
	cmp r4, #26
	bne _DE_021F3268
	mov r0, #224
	strh r0, [r7, #0]
	mov r0, #72
	strh r0, [r7, #2]
	ldr r0, _DE_021F32D8
	ldr r1, _DE_021F32DC
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	lsl r1, r4, #2
	add r2, r5, r1
	mov r1, #103
	lsl r1, r1, #4
	str r0, [r2, r1]
	ldr r0, _DE_021F32F8
	ldr r2, [r5, r0]
	cmp r2, #14
	bne _DE_021F325E
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #0
	bl ov18_021F11C0
	b _DE_021F32BC
_DE_021F325E:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F118C
	b _DE_021F32BC
_DE_021F3268:
	add r0, r4, #0
	sub r0, #27
	lsl r0, r0, #16
	lsr r6, r0, #16
	add r0, r6, #0
	mov r1, #5
	blx _s32_div_f
	mov r0, #48
	mul r0, r1
	add r0, #32
	strh r0, [r7, #0]
	add r0, r6, #0
	mov r1, #5
	blx _s32_div_f
	mov r1, #40
	mul r1, r0
	add r1, #56
	strh r1, [r7, #2]
	ldr r0, _DE_021F32D8
	ldr r1, _DE_021F32DC
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, sp, #0
	bl SpriteSystem_NewSprite
	lsl r1, r4, #2
	add r2, r5, r1
	mov r1, #103
	lsl r1, r1, #4
	str r0, [r2, r1]
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov18_021F118C
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #0
	bl ov18_021F11C0
_DE_021F32BC:
	add r0, r4, #1
	lsl r0, r0, #16
	lsr r4, r0, #16
	cmp r4, #40
	bls _DE_021F3226
	add r0, r5, #0
	mov r1, #57
	bl ov18_021F1424
	add sp, #52
	pop {r4, r5, r6, r7, pc}
	nop
_DE_021F32D4:
	.word ov18_021FB004
_DE_021F32D8:
	.word 0x00000668
_DE_021F32DC:
	.word 0x0000066C
_DE_021F32E0:
	.word ov18_021FA520
_DE_021F32E4:
	.word 0x00000714
_DE_021F32E8:
	.word ov18_021FB54C
_DE_021F32EC:
	.word ov18_021FB580
_DE_021F32F0:
	.word 0x000006D4
_DE_021F32F4:
	.word ov18_021FA4EC
_DE_021F32F8:
	.word 0x00001884
	thumb_func_end ov18_021F32B8
