.data
S: .asciz "This is MPCA lab week 6."
C: .asciz "i"
RES: .word 0
.text
ldr r0,=S
ldr r1,=C
mov r2,#0 ; result
ldr r5,=RES
ldrb r4,[r1]

loop:
	ldrb r3,[r0],#1
	cmp r4,r3
	addeq r2,r2,#1
	cmp r3,#0
	bne loop
str r2,[r5]
.end
