.data
A: .word 10,20,30,40,50,60,70,80,90,100
B: .word 0,0,0,0,0,0,0,0,0,0
.text
ldr r1,=A
ldr r2,=B
mov r5,#1
l1: ldr r3,[r1]
	str r3,[r2]
	add r1,r1,#4 
	add r2,r2,#4
	add r5,r5,#1 
	cmp r5,#11
	bne l1
	swi 0x011
