.data
c: .word 0
a: .word 10,20,30,40,50,60,70,80,90
.text
ldr r0,=a
ldr r2,=c
mov r1,#3
loop:
	mov r3,#0 //sum
	mov r4,#3 //counter
	inner:
		ldr r5,[r0],#4
		add r3,r3,r5
		sub r4,r4,#1
		cmp r4,#0
		bne inner
	str r3,[r2],#4
	sub r1,r1,#1
	cmp r1,#0
	bne loop
swi 0x11

