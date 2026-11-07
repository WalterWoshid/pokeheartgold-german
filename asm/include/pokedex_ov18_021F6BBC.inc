	thumb_func_start ov18_021F6BBC
ov18_021F6BBC:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, _DE_021F6A1C
	mov r1, #0
	str r1, [r5, r0]
	add r0, sp, #4
	add r1, sp, #0
	bl System_GetTouchNewCoords
	cmp r0, #1
	bne _DE_021F68BC
	ldr r0, _DE_021F6A20
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _DE_021F684A
	add sp, #8
	add r0, r1, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F684A:
	lsl r1, r0, #2
	ldr r0, _DE_021F6A24
	ldr r4, [r0, r1]
	cmp r4, #0
	bne _DE_021F6892
	ldr r1, [sp, #0]
	ldr r0, [sp, #4]
	sub r1, r1, #4
	sub r0, #27
	str r1, [sp, #0]
	mov r1, #40
	str r0, [sp, #4]
	blx _u32_div_f
	add r6, r0, #0
	ldr r0, [sp, #0]
	mov r1, #40
	blx _u32_div_f
	lsl r1, r0, #2
	add r0, r0, r1
	add r0, r6, r0
	lsl r0, r0, #24
	lsr r2, r0, #24
	ldr r0, _DE_021F6A28
	ldrb r1, [r5, r0]
	cmp r2, r1
	bne _DE_021F6888
	add sp, #8
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6888:
	strb r2, [r5, r0]
	ldr r0, _DE_021F6A2C
	bl PlaySE
	b _DE_021F68B6
_DE_021F6892:
	cmp r4, #14
	bne _DE_021F689E
	ldr r0, _DE_021F6A30
	bl PlaySE
	b _DE_021F68B6
_DE_021F689E:
	cmp r4, #2
	bne _DE_021F68AA
	ldr r0, _DE_021F6A2C
	bl PlaySE
	b _DE_021F68B6
_DE_021F68AA:
	cmp r4, #5
	bne _DE_021F68B6
	mov r0, #37
	lsl r0, r0, #6
	bl PlaySE
_DE_021F68B6:
	add sp, #8
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F68BC:
	ldr r2, _DE_021F6A1C
	mov r6, #1
	ldr r7, _DE_021F6A34
	str r6, [r5, r2]
	ldr r3, [r7, #76]
	mov r0, #64
	tst r0, r3
	beq _DE_021F68EC
	ldr r0, _DE_021F6A28
	ldrb r1, [r5, r0]
	cmp r1, #5
	bhs _DE_021F68DA
	add sp, #8
	mov r0, #10
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F68DA:
	sub r1, r1, #5
	add r2, #140
	strb r1, [r5, r0]
	add r0, r2, #0
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F68EC:
	mov r0, #128
	tst r0, r3
	beq _DE_021F6918
	ldr r0, _DE_021F6A28
	ldrb r0, [r5, r0]
	cmp r0, #10
	blo _DE_021F6904
	cmp r0, #15
	bhs _DE_021F6904
	add sp, #8
	mov r0, #12
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6904:
	ldr r0, _DE_021F6A28
	ldrb r1, [r5, r0]
	add r1, r1, #5
	strb r1, [r5, r0]
	ldr r0, _DE_021F6A38
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6918:
	mov r0, #32
	add r1, r3, #0
	tst r1, r0
	beq _DE_021F6952
	ldr r3, _DE_021F6A28
	ldrb r1, [r5, r3]
	cmp r1, #0
	beq _DE_021F693A
	sub r0, r1, #1
	add r2, #140
	strb r0, [r5, r3]
	add r0, r2, #0
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F693A:
	sub r1, r3, #1
	ldrb r1, [r5, r1]
	cmp r1, #0
	beq _DE_021F694C
	mov r0, #14
	strb r0, [r5, r3]
	add sp, #8
	mov r0, #9
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F694C:
	add sp, #8
	sub r0, #33
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6952:
	mov r0, #16
	tst r0, r3
	beq _DE_021F6996
	ldr r0, _DE_021F6A28
	ldrb r1, [r5, r0]
	add r1, r1, #1
	cmp r1, #15
	beq _DE_021F6972
	add r2, #140
	strb r1, [r5, r0]
	add r0, r2, #0
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6972:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F8950
	ldr r1, _DE_021F6A3C
	ldrb r2, [r5, r1]
	add r2, r2, #1
	cmp r2, r0
	bhi _DE_021F6990
	mov r2, #0
	add r0, r1, #1
	strb r2, [r5, r0]
	add sp, #8
	mov r0, #11
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6990:
	add sp, #8
	sub r0, r6, #2
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6996:
	ldr r1, [r7, #72]
	add r0, r1, #0
	tst r0, r6
	beq _DE_021F69A4
	add sp, #8
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F69A4:
	mov r4, #2
	add r0, r1, #0
	tst r0, r4
	beq _DE_021F69BA
	add r2, #228
	add r0, r2, #0
	bl PlaySE
	add sp, #8
	mov r0, #6
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F69BA:
	lsl r0, r4, #9
	tst r0, r1
	beq _DE_021F69C6
	add sp, #8
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F69C6:
	lsl r0, r4, #10
	tst r0, r1
	beq _DE_021F69DA
	add r2, #141
	add r0, r2, #0
	bl PlaySE
	add sp, #8
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F69DA:
	lsl r0, r4, #8
	tst r0, r3
	beq _DE_021F69E6
	add sp, #8
	mov r0, #9
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F69E6:
	add r4, #254
	add r0, r3, #0
	tst r0, r4
	beq _DE_021F69F4
	add sp, #8
	mov r0, #11
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F69F4:
	mov r0, #4
	tst r0, r1
	beq _DE_021F6A00
	add sp, #8
	mov r0, #8
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6A00:
	mov r0, #8
	tst r1, r0
	beq _DE_021F6A14
	add r2, #150
	add r0, r2, #0
	bl PlaySE
	add sp, #8
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F6A14:
	sub r0, #9
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_DE_021F6A1C:
	.word 0x0000085C
_DE_021F6A20:
	.word ov18_021FB8A4
_DE_021F6A24:
	.word ov18_021FB84C
_DE_021F6A28:
	.word 0x00001852
_DE_021F6A2C:
	.word 0x000008E9
_DE_021F6A30:
	.word 0x000008F2
_DE_021F6A34:
	.word gSystem
_DE_021F6A38:
	.word 0x000008E8
_DE_021F6A3C:
	.word 0x00001851
	thumb_func_end ov18_021F6BBC
