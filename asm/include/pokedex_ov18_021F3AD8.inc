	thumb_func_start ov18_021F3AD8
ov18_021F3AD8:
	push {r3, r4, lr}
	sub sp, #4
	ldr r1, _DE_021F377C
	add r4, r0, #0
	ldr r1, [r4, r1]
	cmp r1, #1
	bne _DE_021F3778
	mov r1, #15
	mov r2, #1
	bl ov18_021F11C0
	add r0, r4, #0
	mov r1, #15
	bl ov18_021F2AC0
	ldr r0, _DE_021F3780
	add r1, sp, #0
	ldr r0, [r4, r0]
	add r1, #2
	add r2, sp, #0
	bl ManagedSprite_GetPositionXY
	ldr r0, _DE_021F3780
	add r3, sp, #0
	mov r1, #2
	ldrsh r2, [r3, r1]
	mov r1, #18
	lsl r1, r1, #4
	sub r1, r2, r1
	mov r2, #0
	lsl r1, r1, #16
	ldrsh r2, [r3, r2]
	ldr r0, [r4, r0]
	asr r1, r1, #16
	bl ManagedSprite_SetPositionXY
_DE_021F3778:
	add sp, #4
	pop {r3, r4, pc}
_DE_021F377C:
	.word 0x00001858
_DE_021F3780:
	.word 0x000006AC
	thumb_func_end ov18_021F3AD8
