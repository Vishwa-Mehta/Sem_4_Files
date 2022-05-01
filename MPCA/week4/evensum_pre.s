.data
NUM: .word 10,20,30,40,50
RES: .word 0
.text
ldr r0,=NUM
ldr r1,=RES
mov r2,#0 //sum
mov r3,#4 //step
mov r4,#1 //counter
l1:
    ldr r5,[r0,r3]
    add r2,r2,r5
    add r3,r3,#8
    add r4,r4,#2
    cmp r4,#5
    bne l1
str r2,[r1]
swi 0x011
