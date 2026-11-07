	thumb_func_start ov18_021F7C14
ov18_021F7C14:
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r1, #0
	bl ov18_021F7B94
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _DE_021F794A
	bl System_GetTouchNew
	cmp r0, #1
	bne _DE_021F78AC
	ldr r0, _DE_021F794C
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _DE_021F78A0
	add r0, r1, #0
	pop {r3, r4, r5, pc}
_DE_021F78A0:
	mov r1, #1
	str r1, [r5, #0]
	lsl r1, r0, #2
	ldr r0, _DE_021F7950
	ldr r0, [r0, r1]
	pop {r3, r4, r5, pc}
_DE_021F78AC:
	mov r0, #0
	str r0, [r5, #0]
	ldr r2, _DE_021F7954
	mov r0, #64
	ldr r1, [r2, #76]
	tst r0, r1
	beq _DE_021F78BE
	mov r0, #5
	pop {r3, r4, r5, pc}
_DE_021F78BE:
	mov r0, #128
	tst r0, r1
	beq _DE_021F78C8
	mov r0, #7
	pop {r3, r4, r5, pc}
_DE_021F78C8:
	ldr r0, [r2, #72]
	mov r2, #1
	tst r2, r0
	beq _DE_021F78E8
	ldr r0, _DE_021F7958
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _DE_021F78DC
	mov r0, #14
	pop {r3, r4, r5, pc}
_DE_021F78DC:
	cmp r0, #1
	bne _DE_021F78E4
	mov r0, #15
	pop {r3, r4, r5, pc}
_DE_021F78E4:
	mov r0, #13
	pop {r3, r4, r5, pc}
_DE_021F78E8:
	mov r3, #4
	add r2, r0, #0
	tst r2, r3
	beq _DE_021F7902
	mov r0, #99
	lsl r0, r0, #6
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _DE_021F78FE
	mov r0, #12
	pop {r3, r4, r5, pc}
_DE_021F78FE:
	mov r0, #11
	pop {r3, r4, r5, pc}
_DE_021F7902:
	mov r2, #99
	lsl r2, r2, #6
	ldrsb r2, [r4, r2]
	cmp r2, #0
	bne _DE_021F7916
	add r3, #252
	tst r0, r3
	beq _DE_021F7920
	mov r0, #12
	pop {r3, r4, r5, pc}
_DE_021F7916:
	lsl r2, r3, #7
	tst r0, r2
	beq _DE_021F7920
	mov r0, #11
	pop {r3, r4, r5, pc}
_DE_021F7920:
	mov r0, #32
	tst r0, r1
	beq _DE_021F792A
	mov r0, #16
	pop {r3, r4, r5, pc}
_DE_021F792A:
	mov r0, #16
	tst r1, r0
	beq _DE_021F7948
	ldr r1, _DE_021F795C
	ldr r0, [r4, #0]
	ldrh r1, [r4, r1]
	ldr r0, [r0, #0]
	bl Pokedex_CheckMonCaughtFlag
	cmp r0, #0
	beq _DE_021F7944
	mov r0, #1
	pop {r3, r4, r5, pc}
_DE_021F7944:
	mov r0, #2
	pop {r3, r4, r5, pc}
_DE_021F7948:
	sub r0, #17
_DE_021F794A:
	pop {r3, r4, r5, pc}
_DE_021F794C:
	.word ov18_021FB934
_DE_021F7950:
	.word ov18_021FB904
_DE_021F7954:
	.word gSystem
_DE_021F7958:
	.word 0x000018C1
_DE_021F795C:
	.word 0x0000189A
	thumb_func_end ov18_021F7C14
