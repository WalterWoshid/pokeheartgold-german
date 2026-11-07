	thumb_func_start ov18_021F8884
ov18_021F8884:
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r1, _DE_021F8568
	ldr r2, _DE_021F856C
	mov r0, #0
	add r1, r5, r1
	blx MIi_CpuClear32
	cmp r4, #1
	ldr r0, _DE_021F8570
	bne _DE_021F853A
	ldrh r0, [r5, r0]
	mov r6, #0
	cmp r0, #0
	bls _DE_021F8564
	ldr r7, _DE_021F8570
	add r4, r5, #0
_DE_021F8508:
	ldr r0, _DE_021F8574
	mov r1, #135
	lsl r1, r1, #4
	ldrb r0, [r5, r0]
	ldrh r1, [r4, r1]
	bl Pokedex_ConvertToCurrentDexNo
	mov r1, #135
	lsl r1, r1, #4
	sub r0, r0, #1
	ldrh r2, [r4, r1]
	lsl r0, r0, #2
	ldr r1, _DE_021F8568
	add r0, r5, r0
	strh r2, [r0, r1]
	ldr r1, _DE_021F8578
	add r6, r6, #1
	ldrh r2, [r4, r1]
	ldr r1, _DE_021F857C
	add r4, r4, #4
	strh r2, [r0, r1]
	ldrh r0, [r5, r7]
	cmp r6, r0
	blo _DE_021F8508
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F853A:
	ldrh r0, [r5, r0]
	mov r1, #0
	cmp r0, #0
	bls _DE_021F8564
	ldr r3, _DE_021F8580
	ldr r4, _DE_021F8578
	add r7, r3, #0
	add r0, r5, #0
	add r6, r3, #2
	sub r7, #8
_DE_021F854E:
	mov r2, #135
	lsl r2, r2, #4
	ldrh r2, [r0, r2]
	add r1, r1, #1
	strh r2, [r0, r3]
	ldrh r2, [r0, r4]
	strh r2, [r0, r6]
	ldrh r2, [r5, r7]
	add r0, r0, #4
	cmp r1, r2
	blo _DE_021F854E
_DE_021F8564:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F8568:
	.word 0x00001028
_DE_021F856C:
	.word 0x00000818
_DE_021F8570:
	.word 0x00001024
_DE_021F8574:
	.word 0x00001850
_DE_021F8578:
	.word 0x00000872
_DE_021F857C:
	.word 0x0000102A
_DE_021F8580:
	.word 0x0000102C
	thumb_func_end ov18_021F8884
