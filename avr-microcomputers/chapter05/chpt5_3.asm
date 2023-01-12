.include "m32def.inc"
;include ATMega32A definitions

;These are implied, but I still added them
.cseg 
;code segment
.org 0
;memory origin 0 

;assuming 0x065-0x066 are empty
	LDS R20,0x064 ;load SRAM 0x064 -> R20
	STS 0x066,R20 ;store SRAM R20 -> 0x066
	LDS R20,0x063 ;load SRAM 0x063 -> R20
	STS 0x065,R20 ;store SRAM R20 -> 0x065
	LDS R20,0x062 ;load SRAM 0x062 -> R20
	STS 0x064,R20 ;store SRAM R20 -> 0x064
	LDS R20,0x061 ;load SRAM 0x061 -> R20
	STS 0x063,R20 ;store SRAM R20 -> 0x063
	LDS R20,0x060 ;load SRAM 0x060 -> R20
	STS 0x062,R20 ;store SRAM R20 -> 0x062


LOOP:
	RJMP LOOP 
