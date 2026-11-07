	thumb_func_start ov18_021F463C
ov18_021F463C:
	push {r4, r5, r6, r7, lr}
	sub sp, #12
	mov r1, #0
	str r1, [sp, #8]
	str r1, [sp, #4]
	ldr r1, _DE_021F4404
	add r5, r0, #0
	ldrsb r2, [r5, r1]
	cmp r2, #0
	bne _DE_021F435C
	add r1, #54
	ldr r0, [r5, r1]
	mov r4, #1
	cmp r0, #1
	ble _DE_021F433E
	ldr r7, _DE_021F4408
	add r6, r7, #0
_DE_021F42B2:
	ldrb r2, [r5, r6]
	add r0, r5, #0
	add r1, r4, #0
	lsl r2, r2, #25
	lsr r2, r2, #31
	bl ov18_021E8ACC
	cmp r0, #0
	beq _DE_021F42E8
	lsl r0, r4, #2
	add r1, r5, r0
	mov r0, #105
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	ldrb r1, [r5, r7]
	lsl r1, r1, #25
	lsr r1, r1, #31
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
	add r1, r4, #0
	add r0, r5, #0
	add r1, #8
	mov r2, #1
	bl ov18_021F11C0
	b _DE_021F4312
_DE_021F42E8:
	add r1, r4, #0
	add r0, r5, #0
	add r1, #8
	mov r2, #0
	bl ov18_021F11C0
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021E8AB0
	cmp r0, #0
	beq _DE_021F4312
	ldr r0, _DE_021F440C
	ldr r1, [r5, r0]
	lsl r0, r4, #2
	ldr r0, [r1, r0]
	bl ov18_021E8B18
	add r1, sp, #4
	bl ov18_021F47C0
_DE_021F4312:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021E8AB0
	cmp r0, #0
	beq _DE_021F4330
	ldr r0, _DE_021F440C
	ldr r1, [r5, r0]
	lsl r0, r4, #2
	ldr r0, [r1, r0]
	bl ov18_021E8B18
	add r1, sp, #8
	bl ov18_021F47C0
_DE_021F4330:
	add r0, r4, #1
	lsl r0, r0, #16
	lsr r4, r0, #16
	ldr r0, _DE_021F4410
	ldr r0, [r5, r0]
	cmp r4, r0
	blt _DE_021F42B2
_DE_021F433E:
	ldr r0, _DE_021F4408
	add r4, #8
	ldrb r0, [r5, r0]
	add r3, r4, #0
	lsl r0, r0, #25
	lsr r0, r0, #31
	add r0, r0, #4
	str r0, [sp, #0]
	ldr r1, [sp, #8]
	ldr r2, [sp, #4]
	add r0, r5, #0
	bl ov18_021F48AC
	add sp, #12
	pop {r4, r5, r6, r7, pc}
_DE_021F435C:
	bl ov18_021F4620
	ldr r2, _DE_021F4404
	add r0, r5, #0
	ldrsb r1, [r5, r2]
	add r2, r2, #1
	ldrb r2, [r5, r2]
	lsl r2, r2, #25
	lsr r2, r2, #31
	bl ov18_021E8ACC
	cmp r0, #0
	beq _DE_021F4394
	ldr r1, _DE_021F4408
	ldr r0, _DE_021F4414
	ldrb r1, [r5, r1]
	ldr r0, [r5, r0]
	lsl r1, r1, #25
	lsr r1, r1, #31
	add r1, r1, #4
	bl ManagedSprite_SetPaletteOverride
	add r0, r5, #0
	mov r1, #9
	mov r2, #1
	bl ov18_021F11C0
	b _DE_021F43C2
_DE_021F4394:
	add r0, r5, #0
	mov r1, #9
	mov r2, #0
	bl ov18_021F11C0
	ldr r1, _DE_021F4404
	add r0, r5, #0
	ldrsb r1, [r5, r1]
	bl ov18_021E8AB0
	cmp r0, #0
	beq _DE_021F43C2
	ldr r0, _DE_021F440C
	ldr r1, [r5, r0]
	sub r0, #50
	ldrsb r0, [r5, r0]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl ov18_021E8B18
	add r1, sp, #4
	bl ov18_021F47C0
_DE_021F43C2:
	ldr r1, _DE_021F4404
	add r0, r5, #0
	ldrsb r1, [r5, r1]
	bl ov18_021E8AB0
	cmp r0, #0
	beq _DE_021F43E6
	ldr r0, _DE_021F440C
	ldr r1, [r5, r0]
	sub r0, #50
	ldrsb r0, [r5, r0]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl ov18_021E8B18
	add r1, sp, #8
	bl ov18_021F47C0
_DE_021F43E6:
	ldr r0, _DE_021F4408
	mov r3, #10
	ldrb r0, [r5, r0]
	lsl r0, r0, #25
	lsr r0, r0, #31
	add r0, r0, #4
	str r0, [sp, #0]
	ldr r1, [sp, #8]
	ldr r2, [sp, #4]
	add r0, r5, #0
	bl ov18_021F48AC
	add sp, #12
	pop {r4, r5, r6, r7, pc}
	nop
_DE_021F4404:
	.word 0x000018C2
_DE_021F4408:
	.word 0x000018C3
_DE_021F440C:
	.word 0x000018F4
_DE_021F4410:
	.word 0x000018F8
_DE_021F4414:
	.word 0x00000694
	thumb_func_end ov18_021F463C
