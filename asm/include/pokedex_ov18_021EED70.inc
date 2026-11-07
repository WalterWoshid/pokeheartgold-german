	thumb_func_start ov18_021EED70
ov18_021EED70:
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _DE_021EEDD4
	add r4, r1, #0
	add r0, r5, r0
	add r6, r2, #0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDD8
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDDC
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDE0
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDE4
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDE8
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDEC
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDF0
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, _DE_021EEDF4
	add r0, r5, r0
	bl ClearWindowTilemapAndScheduleTransfer
	cmp r4, #0
	beq _DE_021EEDD2
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #85
	bl ov18_021EE984
	ldr r0, _DE_021EEDF8
	ldrb r0, [r5, r0]
	cmp r0, #5
	bne _DE_021EEDA6
	add r0, r5, #0
	mov r1, #86
	bl ov18_021EE9FC
	add r0, r5, #0
	mov r1, #88
	bl ov18_021EEA40
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #87
	bl ov18_021EEAE4
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #89
	bl ov18_021EEB94
	pop {r4, r5, r6, pc}
_DE_021EEDA6:
	add r0, r5, #0
	mov r1, #90
	bl ov18_021EEBE4
	ldr r3, _DE_021EEDF8
	add r0, r5, #0
	ldrb r3, [r5, r3]
	add r1, r4, #0
	mov r2, #91
	bl ov18_021EEC34
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #92
	bl ov18_021EECB0
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	mov r3, #93
	bl ov18_021EED00
_DE_021EEDD2:
	pop {r4, r5, r6, pc}
_DE_021EEDD4:
	.word 0x0000056C
_DE_021EEDD8:
	.word 0x0000058C
_DE_021EEDDC:
	.word 0x0000055C
_DE_021EEDE0:
	.word 0x0000057C
_DE_021EEDE4:
	.word 0x0000059C
_DE_021EEDE8:
	.word 0x000005AC
_DE_021EEDEC:
	.word 0x000005BC
_DE_021EEDF0:
	.word 0x000005CC
_DE_021EEDF4:
	.word 0x000005DC
_DE_021EEDF8:
	.word 0x00001854
	thumb_func_end ov18_021EED70
