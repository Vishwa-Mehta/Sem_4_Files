.text
ldr r0,=data1
ldr r3,=res
ldr r4,=0x05 //length of the loop
ldr r1,[r0],#4
sub r4,r4,#1
back:
	ldr r2,[r0]
	cmp r1,r2
	bls less
	mov r1,r2
less:
	add r0,r0,#4
	sub r4,r4,#1
	cmp r4,#0
	bne back
	str r1,[r3]
swi 0x011
.data
data1: .word 10,20,7,8,100
res: .word 0
