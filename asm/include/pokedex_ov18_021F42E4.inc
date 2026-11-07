	thumb_func_start ov18_021F42E4
ov18_021F42E4:
	push {r3, r4, r5, r6, r7, lr}
	add r6, r2, #0
	mov r2, #25
	lsl r2, r2, #8
	mov ip, r1
	ldr r2, [r0, r2]
	lsl r1, r1, #2
	ldrb r7, [r2, r1]
	mov r2, #25
	lsl r2, r2, #8
	sub r2, #64
	add r4, r3, #0
	ldrsb r3, [r0, r2]
	mov r2, #22
	ldr r5, [sp, #24]
	mul r2, r3
	sub r2, r7, r2
	lsl r2, r2, #3
	add r2, #68
	strh r2, [r6, #0]
	mov r2, #25
	lsl r2, r2, #8
	ldr r0, [r0, r2]
	add r0, r0, r1
	ldrb r0, [r0, #1]
	lsl r0, r0, #3
	add r0, #44
	strh r0, [r4, #0]
	mov r0, ip
	bl ov18_021E8B18
	cmp r0, #124
	beq _DE_021F3F82
	add r1, r0, #0
	sub r1, #178
	cmp r1, #1
	bhi _DE_021F3F90
_DE_021F3F82:
	mov r0, #6
	strb r0, [r5, #0]
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r0, r0, #4
	strh r0, [r4, #0]
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F3F90:
	cmp r0, #96
	beq _DE_021F3F9A
	ldr r2, _DE_021F3FD4
	cmp r0, r2
	bne _DE_021F3FAC
_DE_021F3F9A:
	mov r1, #0
	strb r1, [r5, #0]
	ldrsh r0, [r6, r1]
	add r0, r0, #4
	strh r0, [r6, #0]
	ldrsh r0, [r4, r1]
	add r0, r0, #4
	strh r0, [r4, #0]
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F3FAC:
	cmp r0, #113
	beq _DE_021F3FC0
	add r1, r2, #0
	sub r1, #172
	cmp r0, r1
	beq _DE_021F3FC0
	add r1, r2, #3
	sub r0, r0, r1
	cmp r0, #2
	bhi _DE_021F3FCE
_DE_021F3FC0:
	mov r0, #6
	strb r0, [r5, #0]
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r0, r0, #4
	strh r0, [r4, #0]
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F3FCE:
	mov r0, #0
	strb r0, [r5, #0]
	pop {r3, r4, r5, r6, r7, pc}
_DE_021F3FD4:
	.word 0x000001E7
	thumb_func_end ov18_021F42E4
