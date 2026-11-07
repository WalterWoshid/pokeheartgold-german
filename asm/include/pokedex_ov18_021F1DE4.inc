	thumb_func_start ov18_021F1DE4
ov18_021F1DE4:
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	ldr r0, _DE_021F1D28
	add r4, r1, #0
	ldrb r0, [r5, r0]
	add r6, r3, #0
	cmp r0, #5
	bne _DE_021F1CDE
	cmp r4, #0
	beq _DE_021F1CDE
	lsl r0, r2, #2
	add r2, r5, r0
	ldr r0, _DE_021F1D2C
	ldrh r0, [r2, r0]
	cmp r0, #1
	beq _DE_021F1CDE
	ldr r0, _DE_021F1D30
	cmp r4, r0
	bne _DE_021F1CF2
	ldr r0, [r5, #0]
	mov r2, #0
	ldr r0, [r0, #0]
	bl Pokedex_GetSeenFormByIdx
	cmp r0, #1
	bne _DE_021F1CF2
_DE_021F1CDE:
	lsl r0, r6, #2
	add r1, r5, r0
	mov r0, #103
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	add sp, #4
	pop {r3, r4, r5, r6, pc}
_DE_021F1CF2:
	lsl r0, r6, #2
	add r1, r5, r0
	mov r0, #103
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetDrawFlag
	add r0, r4, #0
	mov r1, #37
	bl ov18_021F9694
	add r4, r0, #0
	mov r0, #2
	str r0, [sp, #0]
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	mov r3, #128
	bl ov18_021F111C
	add r0, r4, #0
	bl Heap_Free
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_DE_021F1D28:
	.word 0x00001854
_DE_021F1D2C:
	.word 0x0000102A
_DE_021F1D30:
	.word 0x000001E7
	thumb_func_end ov18_021F1DE4
