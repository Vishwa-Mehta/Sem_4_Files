.data
B: .word 0
.text
ldr r4,=B
mov r2,#0
mov r5,#1
l1: add r2,r2,r5
    str r2,[r4]
    add r5,r5,#1
    cmp r5,#6
    bne l1
    swi 0x011
