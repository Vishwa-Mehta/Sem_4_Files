.data
STRING: .asciz "Hey, hope you're having a good day."
SUBSTRING: .asciz "good"
RESULT1: .asciz "Sub-string present"
RESULT2: .asciz "Sub-string absent"

.text
ldr r1,=STRING
ldr r2,=SUBSTRING

loop:
	ldrb r3,[r1],#1
	ldrb r4,[r2],#1
	cmp r4,#0 // check if substring has been completely traversed
	beq success //substring present
	cmp r3,#0 // check if string has been completely traversed
	beq fail // substring not present
	cmp r3,r4 // checks if string character and substring character are equal
	beq loop // if equal continue
	ldr r2,=SUBSTRING // else re-initialise substring
	b loop
b fail

success:
	ldr r0,=RESULT1
	swi 0x02
	swi 0x11
	
fail:
	ldr r0,=RESULT2
	swi 0x02
	swi 0x11
	
.end
