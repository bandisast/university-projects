.include "m32def.inc"

.def checksumLow = R16
.def checksumHigh = R17
.def carryZ = R2
.def counterLow = R24
.def counterHigh = R25
.def aux = R20
;define tags

	LDI ZL,low(0x7FFF)
	LDI ZH,high(0x7FFF)
	;load romend to Z pointer

forloop:
	LPM aux, Z
	;load program memory Z points to
	ADD checksumLow, aux
	ADC checksumHigh, carryZ
	;add with carry to checksum word
	CPI aux, 0xFF
	;check if aux contains 0xFF
	BRNE pointerloop
	;GOTO pointerloop if not 0xFF
	ADIW counterHigh:counterLow,1
	;add 1 to counter word

pointerloop:
	SBIW ZH:ZL, 1
	;subtract counter by 1
	CPI ZH,0xFF
	BRNE forloop
	CPI ZL,0xFF
	BRNE forloop
	;check if counter read all rom


loop:
	RJMP loop

