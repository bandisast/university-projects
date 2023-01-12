.include "m32def.inc"
;include ATMega32A definitions

;These are implied, but I still added them
.cseg 
;code segment
.org 0
;memory origin 0 

LOOP:
	MOV R4,R0 ;move contents of R0 to R4 
	MOV R0,R3 ;move contents of R3 to R0
	MOV R3,R2 ;move contents of R2 to R3
	MOV R2,R1 ;move contents of R1 to R2
	MOV R1,R4 ;move contents of R4 to R1
RJMP LOOP

