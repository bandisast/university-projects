.include "m32def.inc"

.equ array1=0x0060
.equ array2=0x0068
.equ total=8
.def counter=R20

LDI ZL,low(array1)
LDI ZH,high(array1)

LDI YL,low(array2)
LDI YH,high(array2)

LDI counter,total

newdata:
	LD R16,Z+
	LD R17,Y+
	ADD R16,R17
	STD Y+7,R16
	DEC counter
	BRNE newdata

loop:
	RJMP loop
