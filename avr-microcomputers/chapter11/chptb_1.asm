.include "m32def.inc"

.dseg
	string: .byte 2
	;assign two bytes of unused memory slots to "string"
.cseg

	.def counter = R20
	.def aux = R18
	;define tags for registers

	LDI XL,low(string)
	LDI XH,high(string)
	;assign "string" initial memory address to X pointer
	CLR counter
	;clear R20

whileCharNotZero:
	LD aux,X+
	;send value of X+ to R18
	CPI aux,0
	;check if char's hex value == 0x00
	BREQ loop
	;exit if 0x00
	INC counter
	;increment counter
	RJMP whileCharNotZero
	;GOTO while loop

loop:
	RJMP loop

