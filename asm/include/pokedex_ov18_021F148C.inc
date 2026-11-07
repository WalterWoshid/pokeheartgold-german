	thumb_func_start ov18_021F148C
ov18_021F148C:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, r1, #0
	mov r1, #0
	add r4, r3, #0
	bl GetBattleMonIconNaixEx
	add r1, r0, #0
	mov r0, #37
	str r0, [sp, #0]
	mov r0, #133
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r2, #0
	add r3, r4, #0
	bl GfGfxLoader_GetCharDataFromOpenNarc
	pop {r3, r4, r5, pc}
	thumb_func_end ov18_021F148C
