.data
A: .word 1234
X: .word 0xCCCCCCCD
RES: .word 0

.text

ldr r0,=A
ldr r0,[r0] ; 1234
ldr r1,=X
ldr r1,[r1] ; magic num
ldr r2,=RES
mov r3,#0 ; result
loop: ; we check if no. less than 10 if yes then that must be added to the sum of digits
	cmp r0,#10
	blt add
	mov r4,r0
	b mod

mod: ; we divide by 10 if the number isn't less than 10 and find the mod
	cmp r4,#10
	blt div ; to divide by 10
	sub r4,r4,#10
	b mod

div: ; divide by 10
	add r3,r3,r4 ; add the mod value to the result
	umull r5,r0,r0,r1 ; next 2 lines are for dividing the number to 10
	mov r0,r0,lsr #3
	b loop

add:
	add r3,r3,r0
	str r3,[r2]
	.end
