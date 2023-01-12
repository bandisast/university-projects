.include "m32def.inc"

	CLR R16
	CLR R17
	CLR R24
	CLR R25
	;clear registers 16, 17, 24, 25
	LDI R24, -5
	;insert constant "-5" to register 24
	LDI R25, 255
	;insert constant "255" to register 25
LOOP:
	ADD R16,R24
	;add -5 to R16
	ADC R17,R25
	;add "255" with carry to R17
	RJMP LOOP 
	;loop
	
