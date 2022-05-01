.data
A: .word 1,4,6,8,9,10,14,17,19,21 // array to be searched
K: .word 7 // key to be searched in array
RESULT1: .asciz "successful search" // result if a successful search
RESULT2: .asciz "unsuccessful search" // result if an unsuccessful search

.text
ldr r9,=K
ldr r8,[r9] // r8 = value of key
ldr r1,=A // array pointer
mov r2,#4 // step
mov r3,#9 // initial high value
mov r4,#0 // initial low value
loop:
	add r5,r3,r4
	mov r5,r5,lsr #1 // r5 = mid value
	mul r6,r5,r2 // position of mid from the start of array
	ldr r7,[r1,r6] // r7 = array[mid]
	cmp r7,r8 // compare array[mid] and key
	beq success // key was found (array[mid] == key)
	bgt l1 // array[mid] > key
	b l2 // array[mid] < key
b fail // key not found

success:
	ldr r0,=RESULT1
	swi 0x02
	swi 0x11

l1:
	mov r3,r5
	sub r3,r3,#1 // high = mid - 1
	cmp r4,r3
	ble loop

l2:
	mov r4,r5
	add r4,r4,#1 // low = mid + 1
	cmp r4,r3
	ble loop

fail:
	ldr r0,=RESULT2
	swi 0x02
	swi 0x11
.end
