.include "m32def.inc"

	CLR R16
	;clear register 16
	LDI R17,0x64
	;insert value 0x64 (decimal "100) to register 17

LOOP:
	ADD R16,R17
	;add R17 and R16 to R16
	RJMP LOOP
	;loop

;uid | c | v | unsigned | signed |    calculation    | result
; 1  | 0 | 0 |    100   |   100  |      0+100        |  0x64
; 2  | 0 | 1 |    200   |   -56  |      100+100      |  0xC8
; 3  | 1 | 0 |  44 (OF) |   -44  | 200+100 | -56+100 |  0x2C
; 4  | 0 | 1 |    144   |  -112  |      100+44       |  0x90
; 5  | 0 | 0 |    244   |   -12  | 144+100 | -112+100|  0xF4
; 6  | 1 | 0 |  88 (OF) |    88  | 244+100 | -12+100 |  0x58
; 7  | 0 | 1 |    188   |   -68  |      88+100       |  0xBC
; 8  | 1 | 0 |  32 (OF) |    32  | 188+100 | -68+100 |  0x20
