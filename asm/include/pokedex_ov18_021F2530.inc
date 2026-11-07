	thumb_func_start ov18_021F2530
ov18_021F2530:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #24
	str r1, [sp, #0]
	add r6, r0, #0
	ldr r0, [sp, #0]
	str r2, [sp, #4]
	cmp r0, #0
	beq _DE_021F2410
	ldr r0, [r6, #0]
	ldr r0, [r0, #0]
	bl Pokedex_GetInternationalViewFlag
	cmp r0, #0
	bne _DE_021F243E
_DE_021F2410:
	ldr r0, [sp, #4]
	lsl r0, r0, #16
	asr r4, r0, #16
	ldr r0, [sp, #4]
	add r7, r0, #6
	cmp r4, r7
	bhs _DE_021F2502
	lsl r0, r4, #2
	add r5, r6, r0
	mov r6, #103
	lsl r6, r6, #4
_DE_021F2426:
	ldr r0, [r5, r6]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #1
	lsl r0, r0, #16
	asr r4, r0, #16
	add r5, r5, #4
	cmp r4, r7
	blo _DE_021F2426
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F243E:
	ldr r0, [sp, #4]
	mov r7, #0
	add r0, r0, #5
	lsl r0, r0, #16
	asr r5, r0, #16
	ldr r0, [sp, #4]
	cmp r5, r0
	blo _DE_021F2502
	lsl r0, r5, #2
	add r4, r6, r0
_DE_021F2452:
	ldr r0, [sp, #4]
	sub r0, r5, r0
	str r0, [sp, #8]
	bl sub_020912AC
	bl sub_02091294
	str r0, [sp, #12]
	ldr r2, [sp, #12]
	ldr r1, [sp, #0]
	lsl r2, r2, #16
	add r0, r6, #0
	lsr r2, r2, #16
	bl ov18_021E6D10
	cmp r0, #1
	beq _DE_021F247A
	ldr r0, [sp, #12]
	cmp r0, #5
	bne _DE_021F24E8
_DE_021F247A:
	ldr r0, _DE_021F2508
	ldrb r0, [r6, r0]
	bl LanguageToDexFlag
	str r0, [sp, #16]
	ldr r0, [sp, #8]
	bl sub_020912AC
	add r2, r0, #0
	ldr r0, [sp, #16]
	cmp r2, r0
	bne _DE_021F249C
	add r0, r6, #0
	add r1, r5, #0
	bl ov18_021F118C
	b _DE_021F24A6
_DE_021F249C:
	add r0, r6, #0
	add r1, r5, #0
	add r2, r2, #6
	bl ov18_021F118C
_DE_021F24A6:
	mov r0, #103
	lsl r0, r0, #4
	add r1, sp, #20
	ldr r0, [r4, r0]
	add r1, #2
	add r2, sp, #20
	bl ManagedSprite_GetPositionXY
	mov r1, #5
	sub r2, r1, r7
	mov r1, #24
	mul r1, r2
	mov r0, #103
	lsl r0, r0, #4
	add r1, #124
	lsl r1, r1, #16
	add r3, sp, #20
	mov r2, #0
	ldrsh r2, [r3, r2]
	ldr r0, [r4, r0]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
	mov r0, #103
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r7, #1
	lsl r0, r0, #16
	asr r7, r0, #16
	b _DE_021F24F4
_DE_021F24E8:
	mov r0, #103
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
_DE_021F24F4:
	sub r0, r5, #1
	lsl r0, r0, #16
	asr r5, r0, #16
	ldr r0, [sp, #4]
	sub r4, r4, #4
	cmp r5, r0
	bhs _DE_021F2452
_DE_021F2502:
	add sp, #24
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F2508:
	.word 0x00001854
	thumb_func_end ov18_021F2530
