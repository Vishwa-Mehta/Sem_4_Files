.data
NUM: .word 20,0
RES: .word 0
.text
ldr r0,=NUM
ldr r1,[r0]
ldr r2,[r0,#4]
ldr r3,=RES
l1:
	cmp r1,#0
	beq l4
	cmp r2,#0
	beq l5
	cmp r1,r2
	beq l4
	bgt l2
	b l3
l2:
	sub r1,r1,r2
	b l1
l3:
	sub r2,r2,r1
	b l1
l4:
	str r2,[r3]
	b end
l5:
	str r1,[r3]
	b end
end:
	swi 0x011
