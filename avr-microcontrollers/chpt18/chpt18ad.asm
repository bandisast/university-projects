.include "m32def.inc"
.def work=R16
.def ST2=R17
.def ST3=R18
.equ period=32000-1

.org 0
	RJMP reset

.org OC1Aaddr
	RJMP T1ctcA

reset:
	LDI work,low(RAMEND)
	OUT SPL,work
	LDI work,high(RAMEND)
	OUT SPH,work
	LDI ST2,2
	LDI ST3,3
	LDI work,high(period)
	OUT OCR1AH,work
	LDI work,low(period)
	OUT OCR1AL,work
	LDI work,(1<<OCF1A)
	OUT TIFR,work
	OUT TIMSK,work
	CLR work
	OUT TCCR1A,work
	LDI work,(1<<CS10)|(1<<WGM12)
	OUT TCCR1B,work
	SEI 

loop:
	RJMP loop

T1ctcA:
	PUSH work
	IN work,SREG
	PUSH work
	DEC ST2
	BRNE OXI4ms
	LDI ST2,2
	NOP

OXI4ms:
	DEC ST3
	BRNE telos
	LDI ST3,3
	NOP

telos:
	POP work
	OUT SREG,work
	POP work
	RETI
