.text
mov r0,#1
mov r1,#4
cmp r0,r1
beq l1
sub r2,r0,r1
b l2
l1: add r2,r0,r1
l2: .end
