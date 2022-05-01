.text
movs r1,#-10
mrs r0,cpsr
and r0,r0,#0000
msr cpsr_f,r0
.end
