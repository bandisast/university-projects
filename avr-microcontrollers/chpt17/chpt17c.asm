.include "m32def.inc"
	
	SBI DDRB,3
	LDI R16,243
	OUT OCR0,R16 ;επιθυμητή τιμή μέτρησης
	LDI R16,(1<<CS00)|(1<<CS02)|(1<<COM00)|(1<<WGM01) 
	    ;P=1024, Fcpu=1MHz, αντιστρ. κατάστασης B3, CTC mode
	OUT TCCR0,R16

loop:
	RJMP loop
