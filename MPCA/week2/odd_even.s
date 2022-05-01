mov r1,#11
ands r2,r1,#1
beq l1
mov r0,#0xFF
B l2
l1: mov r0,#0x00
l2: swi 0x011

