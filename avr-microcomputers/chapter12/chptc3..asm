.include "m32def.inc"

.def orgnum=R16
.def prgnum=R17
.def aux=R18
.def counter=R24

	LDI orgnum,0b11001010 ; 0xCA
	MOV prgnum,orgnum
	LDI counter,8
	CLR aux
	
inverseloop:
	LSL prgnum
	ROR aux
	DEC counter
	BREQ sxedontelos
	RJMP inverseloop

sxedontelos:
	MOV prgnum,aux
telos:
	RJMP telos


