mov r0,#-1
cmp	r0,#0
beq l1
bmi l2
mov r1,#2
l1: mov r1,#1
b l3
l2: mov r1,#3
l3: swi 0x011
