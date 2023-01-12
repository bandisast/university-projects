.include "m32def.inc"

	CLR R16
	;clear register 16
	LDI R17,0x94
	;insert value 0x94 (decimal "148") to register 17

LOOP:
	ADD R16,R17
	;add R17 and R16 to R16
	RJMP LOOP
	;loop

;uid | c | v | unsigned | signed | result
; 1  | 0 | 0 |    148   |  -108  |  0x94
; 2  | 1 | 1 |  40 (OF) |    40  |  0x28
; 3  | 0 | 0 |    188   |   -68  |  0xBC
; 4  | 1 | 1 |  80 (OF) |    80  |  0x50
; 5  | 0 | 0 |    228   |   -28  |  0xE4
; 6  | 1 | 1 | 120 (OF) |   120  |  0x78
; 7  | 1 | 0 |  12 (OF) |    12  |  0x0C
; 8  | 0 | 0 |    160   |   -96  |  0xA0


