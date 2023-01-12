.include "m32def.inc"
;include definitions of ATMega32A

;two options (long-short):
	;long: if (R16>10) then R20 = 0x01, else R20 = 0x02
	;short: R20 = 0x02; if (R16>0x0A) then R20=0x01
	;important values of R16 to check: 0x09, 0x0A, 0x0B.

LDI R16,0x09
;insert myValue to register 16
LDI R20,0x02
;insert const. "0x02" to register 20
CPI R16,0x0A
;compare the contents of register 16 with const. "10" (0x0A)
BREQ loop
;GOTO loop if R16=0x0A
BRLO loop
;GOTO loop if R16<0x0A
LDI R20,0x01
;insert const. "0x01" to register 20

loop:
	RJMP loop
