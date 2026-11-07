	thumb_func_start ov18_021F09D8
ov18_021F09D8:
	push {r3, r4, r5, lr}
	sub sp, #8
	ldr r2, _DE_021F0A30
	add r4, r0, #0
	ldrh r0, [r4, r2]
	ldr r3, _DE_021F0A34
	cmp r0, r3
	bgt _DE_021F08E6
	sub r5, r3, #1
	cmp r0, r5
	blt _DE_021F08C2
	add r2, r5, #0
	cmp r0, r2
	beq _DE_021F0954
	cmp r0, r3
	beq _DE_021F0954
	b _DE_021F09E6
_DE_021F08C2:
	cmp r0, #201
	bgt _DE_021F08CE
	bge _DE_021F093E
	cmp r0, #172
	beq _DE_021F09C4
	b _DE_021F09E6
_DE_021F08CE:
	add r5, r3, #0
	sub r5, #62
	cmp r0, r5
	bgt _DE_021F08DE
	sub r3, #62
	cmp r0, r3
	beq _DE_021F09A4
	b _DE_021F09E6
_DE_021F08DE:
	sub r3, #27
	cmp r0, r3
	beq _DE_021F0964
	b _DE_021F09E6
_DE_021F08E6:
	add r5, r3, #0
	add r5, #66
	cmp r0, r5
	bgt _DE_021F0926
	add r5, r3, #0
	add r5, #66
	cmp r0, r5
	bge _DE_021F0994
	add r5, r3, #0
	add r5, #8
	cmp r0, r5
	bgt _DE_021F0906
	add r3, #8
	cmp r0, r3
	beq _DE_021F09B4
	b _DE_021F09E6
_DE_021F0906:
	add r2, r3, #0
	add r2, #10
	cmp r0, r2
	bgt _DE_021F09E6
	add r2, r3, #0
	add r2, #9
	cmp r0, r2
	blt _DE_021F09E6
	add r2, r3, #0
	add r2, #9
	cmp r0, r2
	beq _DE_021F0944
	add r3, #10
	cmp r0, r3
	beq _DE_021F0944
	b _DE_021F09E6
_DE_021F0926:
	add r5, r3, #0
	add r5, #74
	cmp r0, r5
	bgt _DE_021F0936
	add r3, #74
	cmp r0, r3
	beq _DE_021F0984
	b _DE_021F09E6
_DE_021F0936:
	add r3, #79
	cmp r0, r3
	beq _DE_021F0974
	b _DE_021F09E6
_DE_021F093E:
	add sp, #8
	mov r0, #121
	pop {r3, r4, r5, pc}
_DE_021F0944:
	ldr r0, _DE_021F0A38
	add r1, r4, r1
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #116
	pop {r3, r4, r5, pc}
_DE_021F0954:
	ldr r0, _DE_021F0A38
	add r1, r4, r1
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #118
	pop {r3, r4, r5, pc}
_DE_021F0964:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #145
	pop {r3, r4, r5, pc}
_DE_021F0974:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #149
	pop {r3, r4, r5, pc}
_DE_021F0984:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #151
	pop {r3, r4, r5, pc}
_DE_021F0994:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #153
	pop {r3, r4, r5, pc}
_DE_021F09A4:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #160
	pop {r3, r4, r5, pc}
_DE_021F09B4:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	add sp, #8
	eor r0, r1
	add r0, #164
	pop {r3, r4, r5, pc}
_DE_021F09C4:
	add r1, r4, r1
	add r0, r2, #2
	ldrb r1, [r1, r0]
	mov r0, #128
	eor r0, r1
	bne _DE_021F09D6
	add sp, #8
	mov r0, #114
	pop {r3, r4, r5, pc}
_DE_021F09D6:
	cmp r0, #1
	bne _DE_021F09E0
	add sp, #8
	mov r0, #115
	pop {r3, r4, r5, pc}
_DE_021F09E0:
	add sp, #8
	mov r0, #166
	pop {r3, r4, r5, pc}
_DE_021F09E6:
	add r2, r4, r1
	ldr r1, _DE_021F0A38
	ldrb r1, [r2, r1]
	cmp r1, #1
	bne _DE_021F09F6
	add sp, #8
	mov r0, #114
	pop {r3, r4, r5, pc}
_DE_021F09F6:
	cmp r1, #2
	bne _DE_021F0A00
	add sp, #8
	mov r0, #115
	pop {r3, r4, r5, pc}
_DE_021F0A00:
	mov r1, #5
	mov r2, #37
	bl ov18_021E590C
	add r5, r0, #0
	mov r0, #1
	str r0, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #102
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	add r2, r5, #0
	mov r3, #2
	bl BufferString
	add r0, r5, #0
	bl String_Delete
	mov r0, #159
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_DE_021F0A30:
	.word 0x0000189A
_DE_021F0A34:
	.word 0x0000019D
_DE_021F0A38:
	.word 0x0000189C
	thumb_func_end ov18_021F09D8
