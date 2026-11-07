	thumb_func_start ov18_021F7974
ov18_021F7974:
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	add r4, r1, #0
	add r0, sp, #4
	add r1, sp, #0
	bl System_GetTouchNewCoords
	cmp r0, #1
	bne _DE_021F767A
	ldr r0, _DE_021F77B8
	bl TouchscreenHitbox_FindRectAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _DE_021F75FC
	add sp, #8
	add r0, r1, #0
	pop {r4, r5, r6, pc}
_DE_021F75FC:
	lsl r1, r0, #2
	ldr r0, _DE_021F77BC
	ldr r4, [r0, r1]
	cmp r4, #0
	bne _DE_021F765C
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
	ldr r0, _DE_021F77C0
	ldrb r1, [r5, r0]
	cmp r2, r1
	bne _DE_021F7652
	cmp r1, #0
	bne _DE_021F764C
	sub r0, r0, #1
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _DE_021F764C
	ldr r0, _DE_021F77C4
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r4, r5, r6, pc}
_DE_021F764C:
	add sp, #8
	mov r0, #4
	pop {r4, r5, r6, pc}
_DE_021F7652:
	strb r2, [r5, r0]
	ldr r0, _DE_021F77C4
	bl PlaySE
	b _DE_021F7674
_DE_021F765C:
	cmp r4, #2
	bne _DE_021F7668
	ldr r0, _DE_021F77C4
	bl PlaySE
	b _DE_021F7674
_DE_021F7668:
	cmp r4, #5
	bne _DE_021F7674
	mov r0, #37
	lsl r0, r0, #6
	bl PlaySE
_DE_021F7674:
	add sp, #8
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_DE_021F767A:
	ldr r1, _DE_021F77C8
	mov r0, #64
	ldr r2, [r1, #76]
	tst r0, r2
	beq _DE_021F76A2
	ldr r0, _DE_021F77C0
	ldrb r1, [r5, r0]
	cmp r1, #5
	bhs _DE_021F7692
	add sp, #8
	mov r0, #10
	pop {r4, r5, r6, pc}
_DE_021F7692:
	sub r1, r1, #5
	strb r1, [r5, r0]
	ldr r0, _DE_021F77CC
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_DE_021F76A2:
	mov r0, #128
	tst r0, r2
	beq _DE_021F76CE
	ldr r0, _DE_021F77C0
	ldrb r0, [r5, r0]
	cmp r0, #10
	blo _DE_021F76BA
	cmp r0, #15
	bhs _DE_021F76BA
	add sp, #8
	mov r0, #12
	pop {r4, r5, r6, pc}
_DE_021F76BA:
	ldr r0, _DE_021F77C0
	ldrb r1, [r5, r0]
	add r1, r1, #5
	strb r1, [r5, r0]
	ldr r0, _DE_021F77CC
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_DE_021F76CE:
	mov r0, #32
	add r3, r2, #0
	tst r3, r0
	beq _DE_021F7706
	ldr r2, _DE_021F77C0
	ldrb r1, [r5, r2]
	cmp r1, #0
	beq _DE_021F76EE
	sub r0, r1, #1
	strb r0, [r5, r2]
	ldr r0, _DE_021F77CC
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_DE_021F76EE:
	sub r1, r2, #1
	ldrb r1, [r5, r1]
	cmp r1, #0
	beq _DE_021F7700
	mov r0, #14
	strb r0, [r5, r2]
	add sp, #8
	mov r0, #9
	pop {r4, r5, r6, pc}
_DE_021F7700:
	add sp, #8
	sub r0, #33
	pop {r4, r5, r6, pc}
_DE_021F7706:
	mov r0, #16
	tst r0, r2
	beq _DE_021F774A
	ldr r0, _DE_021F77C0
	ldrb r1, [r5, r0]
	add r1, r1, #1
	cmp r1, #15
	beq _DE_021F7724
	strb r1, [r5, r0]
	ldr r0, _DE_021F77CC
	bl PlaySE
	add sp, #8
	mov r0, #0
	pop {r4, r5, r6, pc}
_DE_021F7724:
	add r0, r5, #0
	add r1, r4, #0
	bl ov18_021F8950
	ldr r1, _DE_021F77D0
	ldrb r2, [r5, r1]
	add r2, r2, #1
	cmp r2, r0
	bhi _DE_021F7742
	mov r2, #0
	add r0, r1, #1
	strb r2, [r5, r0]
	add sp, #8
	mov r0, #11
	pop {r4, r5, r6, pc}
_DE_021F7742:
	mov r0, #0
	add sp, #8
	mvn r0, r0
	pop {r4, r5, r6, pc}
_DE_021F774A:
	ldr r0, [r1, #72]
	mov r1, #1
	tst r1, r0
	beq _DE_021F7758
	add sp, #8
	mov r0, #4
	pop {r4, r5, r6, pc}
_DE_021F7758:
	mov r3, #2
	add r1, r0, #0
	tst r1, r3
	beq _DE_021F776E
	mov r0, #37
	lsl r0, r0, #6
	bl PlaySE
	add sp, #8
	mov r0, #6
	pop {r4, r5, r6, pc}
_DE_021F776E:
	lsl r1, r3, #9
	tst r1, r0
	beq _DE_021F777A
	add sp, #8
	mov r0, #3
	pop {r4, r5, r6, pc}
_DE_021F777A:
	lsl r1, r3, #10
	tst r1, r0
	beq _DE_021F778C
	ldr r0, _DE_021F77C4
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r4, r5, r6, pc}
_DE_021F778C:
	lsl r1, r3, #8
	tst r1, r2
	beq _DE_021F7798
	add sp, #8
	mov r0, #9
	pop {r4, r5, r6, pc}
_DE_021F7798:
	add r3, #254
	add r1, r2, #0
	tst r1, r3
	beq _DE_021F77A6
	add sp, #8
	mov r0, #11
	pop {r4, r5, r6, pc}
_DE_021F77A6:
	mov r1, #4
	tst r0, r1
	beq _DE_021F77B2
	add sp, #8
	mov r0, #8
	pop {r4, r5, r6, pc}
_DE_021F77B2:
	sub r0, r1, #5
	add sp, #8
	pop {r4, r5, r6, pc}
_DE_021F77B8:
	.word ov18_021FB8A4
_DE_021F77BC:
	.word ov18_021FB84C
_DE_021F77C0:
	.word 0x00001852
_DE_021F77C4:
	.word 0x000008E9
_DE_021F77C8:
	.word gSystem
_DE_021F77CC:
	.word 0x000008E8
_DE_021F77D0:
	.word 0x00001851
	thumb_func_end ov18_021F7974
