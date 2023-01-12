.include "m32def.inc"

.def assoi=R20
.def counter=R24
.def originH=R17
.def originL=R16
.def numH=R19
.def numL=R18

LDI originL,low(0xA305)
LDI originH,high(0xA305)
MOVW numH:numL,originH:originL

count1:
	CLR assoi
	LDI counter,16

count1loop:
	ROL numL
	ROL numH
	BRCC count1out
	INC assoi

count1out:
	DEC counter
	BRNE count1loop

telos:
	RJMP telos
