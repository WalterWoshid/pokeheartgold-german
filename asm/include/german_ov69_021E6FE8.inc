	thumb_func_start ov69_021E6FE8
ov69_021E6FE8:
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #32
	ldr r6, _DE_021E702C
	add r4, r0, #0
	ldmia r6!, {r0, r1}
	add r5, sp, #8
	add r2, r5, #0
	stmia r5!, {r0, r1}
	ldr r0, [r6, #0]
	add r1, r2, #0
	str r0, [r5, #0]
	add r7, sp, #20
	mov r3, #0
	str r3, [r7, #0]
	str r3, [r7, #4]
	str r3, [r7, #8]
	ldr r0, _DE_021E7030
	str r3, [sp, #0]
	ldr r0, [r4, r0]
	ldr r2, _DE_021E7034
	str r0, [sp, #4]
	add r0, r7, #0
	bl Camera_Init_FromTargetAndPos
	ldr r2, _DE_021E7030
	mov r1, #25
	ldr r2, [r4, r2]
	mov r0, #0
	lsl r1, r1, #14
	bl Camera_SetPerspectiveClippingPlane
	ldr r1, _DE_021E7030
	mov r0, #0
	ldr r1, [r4, r1]
	bl Camera_ApplyPerspectiveType
	ldr r0, _DE_021E7030
	ldr r0, [r4, r0]
	bl Camera_SetStaticPtr
	ldr r0, _DE_021E7038
	mov r1, #1
	strh r1, [r4, r0]
_DE_021E701E:
	add r0, r4, #0
	bl ov69_021E737C
	cmp r0, #1
	bne _DE_021E701E
	add sp, #32
	pop {r3, r4, r5, r6, r7, pc}
_DE_021E702C:
	.word ov69_021E767C
_DE_021E7030:
	.word 0x0000C2DC
_DE_021E7034:
	.word 0x000005C1
_DE_021E7038:
	.word 0x0000C2E8
	thumb_func_end ov69_021E6FE8
