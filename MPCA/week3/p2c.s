.data
A: .byte 1,21,3,43,5
B: .byte 0
.text
ldr r1,=A
ldr r4,=B
mov r2,#0
mov r5,#1 //counter
l1: ldrb r3,[r1]
	add r2,r2,r3
	strb r2,[r4]
    add r1,r1,#1
    add r5,r5,#1
    cmp r5,#6
    bne l1
    swi 0x011
