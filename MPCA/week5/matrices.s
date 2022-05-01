.data
c: .word 0
a: .word 10,20,30,40,50,60,70,80,90
b: .word 1,2,3,4,5,6,7,8,9
.text
ldr r0,=a
ldr r1,=b
ldr r2,=c
mov r3,#0 //sum
mov r4,#9 //counter
loop:
	ldr r5,[r0],#4
	ldr r6,[r1],#4
	add r3,r5,r6
	str r3,[r2]
	add r2,r2,#4
	sub r4,r4,#1
	cmp r4,#0
	bne loop
swi 0x11

