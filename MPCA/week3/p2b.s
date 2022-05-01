.data
A: .hword 1,21,3,43,5
B: .hword 0
.text
ldr r1,=A
ldr r4,=B
mov r2,#0
mov r5,#1 //counter
l1: ldrh r3,[r1]
	add r2,r2,r3
	strh r2,[r4]
    add r1,r1,#2
    add r5,r5,#1
    cmp r5,#6
    bne l1
    swi 0x011
