.include "m32def.inc"

.def ypolH=R3
.def ypolL=R2
.def numAH=R21
.def numAL=R20
.def resultH=R17
.def resultL=R16
.def numBH=R19
.def numBL=R18
.def counter=R24

LDI numAH,high(0xFEED)
LDI numAL,low(0xFEED)
LDI numBH,high(0x1234)
LDI numBL,low(0x1234)
MOVW resultH:resultL,numAH:numAL

div16u:
	CLR ypolH
	CLR ypolL
	CLC
	LDI counter,17

div16uloop:
	ROL resultL
	ROL resultH
	DEC counter
	BREQ div16uend
	ROL ypolL
	ROL ypolH
	SUB ypolL,numBL
	SBC ypolH,numBH
	BRPL div16uout
	ADD ypolL,numBL
	ADC ypolH,numBH
	CLC
	RJMP div16uloop

div16uout:
	SEC
	RJMP div16uloop
div16uend:
	RJMP div16uend
