.include "m32def.inc"
	LDI R16,LOW(RAMEND)
	;load ram end low-byte address to R16
	OUT SPL,R16
	;send contents of R16 to stack pointer low byte
	LDI R16,HIGH(RAMEND)
	;(>>) high-byte (>>)
	OUT SPH,R16
	;(>>) stack pointer high byte

	;look at: PROGRAM COUNTER, STACK POINTER, END OF SRAM, REGISTERS
	LDI R16,0x12
	LDI R17,0x34
	LDI R18,0x56
	LDI R19,0x78
	;load values to registers
	PUSH R16
	;send to stack
	PUSH R17
	;send to stack
	RCALL subr1
	;relative call subr1
test:
	POP R16
	;remove from stack
	POP R17
	;remove from stack
	RCALL subr1
telos:
	RJMP telos

subr1:
	MOV R20,R18
	MOV R18,R19
	MOV R19,R20
	RJMP test

.org 0x1234
	NOP
	;no operation
	JMP telos

.org 0x3412
	NOP
	JMP telos
