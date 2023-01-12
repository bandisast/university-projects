.include "m32def.inc"

	CLR R16
	;clear register 16
	LDI R17,0x94
	;insert value 0x94 (decimal "148") to register 17

LOOP:
	SUB R16,R17
	;subtract R17 and R16 to R16
	RJMP LOOP
	;loop

;uid | c | v | result
; 1  | 1 | 0 | 0x6C
; 2  | 1 | 1 | 0xD8
; 3  | 0 | 0 | 0x44
; 4  | 1 | 1 | 0xB0
; 5  | 0 | 0 | 0x1C
; 6  | 1 | 1 | 0x88
; 7  | 1 | 0 | 0xF4
; 8  | 0 | 0 | 0x60
