	thumb_func_start ov112_021F298C
ov112_021F298C:
	push {r4, r5, r6, lr}
	ldr r1, _DE_021F2A30
	add r5, r0, #0
	ldrb r1, [r5, r1]
	mov r4, #0
	mov r2, #1
	lsl r1, r1, #2
	add r1, r5, r1
	add r1, #192
	ldr r6, [r1, #0]
	add r1, r4, #0
	bl ov112_021F2204
	add r0, r5, #0
	ldr r1, [r5, #12]
	add r0, #132
	lsl r1, r1, #24
	ldr r0, [r0, #0]
	lsr r1, r1, #24
	mov r2, #3
	bl ov112_021F22B0
	ldr r0, [r6, #124]
	mov r1, #100
	blx _u32_div_f
	ldr r1, _DE_021F2A34
	cmp r0, r1
	ble _DE_021F29A0
	add r0, r1, #0
_DE_021F29A0:
	add r4, r4, r0
	ldr r0, _DE_021F2A38
	ldrb r1, [r5, r0]
	mov r0, #10
	mul r0, r1
	cmp r0, #40
	ble _DE_021F29B0
	mov r0, #40
_DE_021F29B0:
	add r4, r4, r0
	ldr r0, _DE_021F2A3C
	ldrb r1, [r5, r0]
	mov r0, #10
	mul r0, r1
	cmp r0, #40
	ble _DE_021F29C0
	mov r0, #40
_DE_021F29C0:
	add r4, r4, r0
	ldr r0, _DE_021F2A40
	ldrb r1, [r5, r0]
	mov r0, #15
	mul r0, r1
	cmp r0, #150
	ble _DE_021F29D0
	mov r0, #150
_DE_021F29D0:
	mov r2, #81
	lsl r2, r2, #2
	ldr r3, [r5, r2]
	add r0, r4, r0
	lsl r1, r3, #23
	lsr r4, r1, #31
	lsl r3, r3, #22
	mov r1, #250
	add r6, r4, #0
	lsr r3, r3, #31
	mul r6, r1
	add r4, r3, #0
	add r0, r0, r6
	mul r4, r1
	add r0, r0, r4
	add r2, #226
	cmp r0, r2
	blo _DE_021F29F8
	mov r2, #72
	b _DE_021F2A24
_DE_021F29F8:
	add r1, #50
	cmp r0, r1
	blo _DE_021F2A02
	mov r2, #73
	b _DE_021F2A24
_DE_021F2A02:
	cmp r0, #200
	blo _DE_021F2A0A
	mov r2, #74
	b _DE_021F2A24
_DE_021F2A0A:
	cmp r0, #150
	blo _DE_021F2A12
	mov r2, #75
	b _DE_021F2A24
_DE_021F2A12:
	cmp r0, #100
	blo _DE_021F2A1A
	mov r2, #76
	b _DE_021F2A24
_DE_021F2A1A:
	cmp r0, #30
	blo _DE_021F2A22
	mov r2, #77
	b _DE_021F2A24
_DE_021F2A22:
	mov r2, #78
_DE_021F2A24:
	add r0, r5, #0
	mov r1, #71
	bl ov112_021F1624
	pop {r4, r5, r6, pc}
	nop
_DE_021F2A30:
	.word 0x0000013D
_DE_021F2A34:
	.word 0x0000028F
_DE_021F2A38:
	.word 0x00000142
_DE_021F2A3C:
	.word 0x00000141
_DE_021F2A40:
	.word 0x00000143
	thumb_func_end ov112_021F298C
