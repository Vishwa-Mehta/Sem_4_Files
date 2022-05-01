.text
mov r0,#4
mov r1,#5
stmea r13!,{r0,r1}
ldmea r13!,{r5,r6}
ldmfd r13!,{r7,r8}
stmfa r13!,{r0,r1}
.end
