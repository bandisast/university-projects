.include "m32def.inc"
;include definitions of ATMega32A

;important values:
;unsigned comparator:
	;R16: 2, 3, 4, -1 (should return: 5, 5, 6, 5)
	;R17: 3
;signed comparator:
	;R16: 2, 3, 4, -1 (should return: 5, 5, 6, 5)
	;R17: 3
	;and
	;R16: 2, -2, -3, -4 (should return: 6, 6, 5, 5
	;R17: -3

;=======USER=VALUES=========

LDI R16,-4
;insert myValue to R16
LDI R17,-3
;insert myValue2 to R17
LDI R26,1
;insert 1 or 0 to R26 (1 = sgnComp, 0 = unsgnComp)

;==========MAIN=============
LDI R20,5
;insert value "5" to register 20
CPI R26,1
;compare R26 and "1"
BREQ sgnComp
;GOTO signed (R17) comparator if R26 = 1 
TST R16
;check the sign of R16
BRPL unsgnComp
;GOTO unsigned (R17) comparator if R16 is >=0 
RJMP loop
;if R16<0, GOTO loop

;===========================
unsgnComp:
	CP R17,R16
	;compare R17 and R16
	BRSH loop
	;goto end if R17>=16 (unsigned)
	LDI R20,6
	;insert value "6" to R20
	RJMP loop
	;GOTO loop
;===========================
sgnComp:
	CP R17,R16
	;compare R17 and R16
	BRGE loop
	;GOTO loop if R17 >= 16 (signed)
	LDI R20,6 
	;insert value "6" to register 20
	RJMP loop
	;RJMP probably not needed at this specific code point
	;but not placing it just in case feels like bad practice
;===========================
loop:
	RJMP loop




