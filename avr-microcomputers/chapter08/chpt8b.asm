.include "m32def.inc"

LDS R18,0x60
LDS R19,0x61
;load values of SRAM to R19 and R20 (0x60, 0x61)
MUL R18,R16
;multiply signed R18 with unsigned R16 (saves to R1:R0)
MOVW R3:R2,R1:R0
;move word from R1:R0 to R3:R2

MULSU R19,R16
;multiply signed R19 with unsigned R16 (>>)

ADD R3,R0
;R0+R3->R3
ADC R4,R1
;add with carry R1->R4

STS 0x62,R2
STS 0x63,R3
STS 0x64,R4
;send the values to new SRAM locations

loop:
	RJMP loop

