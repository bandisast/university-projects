.include "m32def.inc"
;include ATMega32A definitions

;These are implied, but I still added them
.cseg 
;code segment
.org 0
;memory origin 0 


	LDI R16,15 
	;load immediate, const "15" -> R16
	STS 0x060,R16 
	;store SRAM, value of R16 -> 0x060

telos:
JMP telos 
;empty "infinite" loop

;===================
;code size: 10 words
;code:
	;LDI: E0 0F
	;STS: 93 00 00 60
	;JMP: 94 0C 00 03
;time:
	;LDI: 1 clk ccl
	;STS: 2 clk ccl
	;JMP: 3 clc ccl
