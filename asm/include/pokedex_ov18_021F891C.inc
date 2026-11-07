	thumb_func_start ov18_021F891C
ov18_021F891C:
	push {r3, lr}
	add r2, r0, #0
	cmp r1, #0
	bne _DE_021F8592
	ldr r0, _DE_021F85AC
	ldrh r0, [r2, r0]
	pop {r3, pc}
_DE_021F8592:
	ldr r1, _DE_021F85AC
	ldr r0, _DE_021F85B0
	ldrh r1, [r2, r1]
	ldrb r0, [r2, r0]
	sub r1, r1, #1
	lsl r1, r1, #2
	add r2, r2, r1
	mov r1, #135
	lsl r1, r1, #4
	ldrh r1, [r2, r1]
	bl Pokedex_ConvertToCurrentDexNo
	pop {r3, pc}
_DE_021F85AC:
	.word 0x00001024
_DE_021F85B0:
	.word 0x00001850
	thumb_func_end ov18_021F891C
