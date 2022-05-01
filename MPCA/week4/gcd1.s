.data
RES: .word 0
.text
mov r0,#56
mov r1,#16
ldr r2,=RES
l1:
	cmp r0,#0
	beq l4
	cmp r1,#0
	beq l5
	cmp r0,r1
	beq l4
	bgt l2
	b l3
l2:
	sub r0,r0,r1
	b l1
l3:
	sub r1,r1,r0
	b l1
l4:
	str r1,[r2]
	b end
l5:
	str r0,[r2]
	b end
end:
	swi 0x011
