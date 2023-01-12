.include "m32def.inc"

LDI R16,LOW(RAMEND) 
OUT SPL,R16
LDI R16,HIGH(RAMEND)
OUT SPH,R16

LDI XL,low(0x060-1) 
LDI XH,high(0x060-1)
CLR R0
CLR R1
LDI R17,4 

loop: 
	RCALL AddSignedX 
	DEC R17
	BRNE loop

telos:
	RJMP telos

AddSignedX:
	ADIW XH:XL,1
	RCALL SignExtX
	ADD R0,R2
	ADC R1,R3
	RET

SignExtX:
	CLR R3
	LD R2,X
	TST R2
	BRPL returnF
	DEC R3 
	returnF:
		RET
