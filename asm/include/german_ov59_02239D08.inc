	thumb_func_start ov59_02239D08
ov59_02239D08:
	push {r4, r5, r6, lr}
	sub sp, #8
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #6
	beq _DE_02239CFE
	cmp r4, #12
	beq _DE_02239D1A
	cmp r4, #21
	beq _DE_02239D5E
	b _DE_02239DC0
_DE_02239CFE:
	ldr r0, [r5, #16]
	bl sub_02031C08
	mov r1, #0
	str r1, [sp, #0]
	mov r3, #1
	str r3, [sp, #4]
	add r6, r0, #0
	mov r2, #5
	ldr r0, [r5, #96]
	sub r2, r2, r6
	bl BufferIntegerAsString
	b _DE_02239DD0
_DE_02239D1A:
	add r0, #78
	ldrb r0, [r0, #0]
	cmp r0, #1
	ldr r0, [r5, #96]
	bls _DE_02239D36
	add r2, r5, #0
	add r2, #77
	ldrb r3, [r2, #0]
	ldr r2, _DE_02239DEC
	mov r1, #0
	add r2, r3, r2
	bl BufferItemNamePlural
	b _DE_02239D46
_DE_02239D36:
	add r2, r5, #0
	add r2, #77
	ldrb r3, [r2, #0]
	ldr r2, _DE_02239DEC
	mov r1, #0
	add r2, r3, r2
	bl BufferItemName
_DE_02239D46:
	mov r0, #0
	add r2, r5, #0
	str r0, [sp, #0]
	mov r1, #1
	str r1, [sp, #4]
	add r2, #78
	ldrb r2, [r2, #0]
	ldr r0, [r5, #96]
	mov r3, #2
	bl BufferIntegerAsString
	b _DE_02239DD0
_DE_02239D5E:
	add r0, #34
	bl sub_02032004
	add r1, r0, #0
	ldr r0, [r5, #92]
	ldr r2, [r5, #100]
	add r1, #19
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp, #0]
	mov r0, #5
	str r0, [sp, #4]
	ldr r0, [r5, #96]
	ldr r2, [r5, #100]
	mov r3, #2
	bl BufferString
	mov r0, #0
	str r0, [sp, #0]
	mov r1, #1
	str r1, [sp, #4]
	ldrb r2, [r5, #21]
	ldr r0, [r5, #96]
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp, #0]
	mov r0, #1
	str r0, [sp, #4]
	ldrb r2, [r5, #22]
	ldr r0, [r5, #96]
	mov r1, #2
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0
	str r0, [sp, #0]
	mov r3, #1
	str r3, [sp, #4]
	ldrb r6, [r5, #24]
	mov r2, #5
	ldr r0, [r5, #96]
	mov r1, #3
	sub r2, r2, r6
	bl BufferIntegerAsString
	b _DE_02239DD0
_DE_02239DC0:
	add r4, #27
	ldr r0, [r5, #92]
	ldr r2, [r5, #104]
	add r1, r4, #0
	bl ReadMsgDataIntoString
	add sp, #8
	pop {r4, r5, r6, pc}
_DE_02239DD0:
	add r4, #27
	ldr r0, [r5, #92]
	ldr r2, [r5, #100]
	add r1, r4, #0
	bl ReadMsgDataIntoString
	ldr r0, [r5, #96]
	ldr r1, [r5, #104]
	ldr r2, [r5, #100]
	bl StringExpandPlaceholders
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_DE_02239DEC:
	.word 0x000001E5
	thumb_func_end ov59_02239D08
