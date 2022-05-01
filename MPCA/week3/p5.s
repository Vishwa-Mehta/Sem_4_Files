.data
A: .word 12
B: .word 5
C: .word 5
D: .word 0
E: .word 0
.text
ldr r0,=A
ldr r1,=B
ldr r2,=C
ldr r3,=D
ldr r4,=E

ldr r5,[r0]
ldr r6,[r1]
ldr r7,[r2]

cmp r5,r6
beq l1
cmp r6,r7
beq l2
b l3

l1: add r8,r5,r6
	str r8,[r2]
	b l
l2: sub r9,r5,r6
	str r9,[r3]
	b l
l3: mul r10,r5,r6
	str r10,[r4]
l: swi 0x011
