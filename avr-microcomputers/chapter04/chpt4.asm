.include "m32def.inc" ;include definitions of atmega32a

.cseg ;place program in code memory segment (ROM)
.org 0 ;code origin point in memory: 0

	CLR R16 ;clear register R16

LOOP: ;unending loop
	INC R16 ;increment R16
	RJMP LOOP ;goto LOOP
