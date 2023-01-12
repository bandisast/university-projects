.include "m32def.inc"

.equ arithmos=0x0060
.def apotelesmaL= R1
.def apotelesmaH= R0

CLR R16
CLR R0
CLR R1

LDS R16,arithmos
MUL R16,R16

STS 0x0062,apotelesmaL
STS 0x0061,apotelesmaH

LOOP:
RJMP LOOP

