.include "m32def.inc"
;include definitions of ATMega32A

;using a method similar to the one we used in ex. 7.1
	;R20=4; if(R16 < 10 || R16 >= 11) then do nothing, else R20=3
	;important values: -11, -10, -9, 10, 11, 12

LDI R16,12
;insert myValue to register 16
LDI R20,4
;insert constant "4" to register 20
CPI R16,-9
;compare contents of register 16 with const. "-9"
BRLT loop
;GOTO loop if R16<(-9)
CPI R16,11
;compare contents of register 16 with const "11"
BRGE loop
;GOTO loop if R16>=11
LDI R20,3
;insert constant "3" to register 20

loop:
	RJMP loop


