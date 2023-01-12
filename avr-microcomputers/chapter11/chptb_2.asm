.include "m32def.inc"

	.def currNumLow = R24
	.def currNumHigh = R25
	.def sumLow = R16
	.def sumMid = R17
	.def sumHigh = R18
	.def carryZ = R2
	;define register tags

		LDI currNumLow,low(1000)
		LDI currNumHigh,high(1000)
		;store low and high byte of 1000 to registers
		MOVW sumMid:sumLow,currNumHigh:currNumLow
		;copy 1000 to sum registers

forloop:
	SBIW currNumHigh:currNumLow, 2
	;subtract 2 from currNum registers

	ADD sumLow,currNumLow
	ADC sumMid,currNumHigh
	ADC sumHigh,carryZ
	;add new number to sum registers
	
	CPI currNumHigh,0
	BRNE forloop
	CPI currNumLow,0
	BRNE forloop
	;check if current number is 0. GOTO forloop if not.

loop:
	RJMP loop
	;the end
