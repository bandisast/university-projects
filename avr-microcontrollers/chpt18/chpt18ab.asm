.include "m32def.inc"
def work=R16
def work2=R17
.equ period=16000

.org 0
    RJMP reset

.org 0x00E
    RJMP T1compA

reset:    
    LDI work,low(RAMEND)
    OUT SPL,work
    LDI work,high(RAMEND)
    OUT SPH,work

    LDI work,high(period) 
    OUT OCR1AH,work
    LDI work,low(period)
    OUT OCR1AL,work

    LDI work,(1<<0CF1A)
    OUT TIFR,work
    OUT TIMSK,work

    CLR work
    OUT TCCR1A,work

    LDI work, (1<<CS10)
    OUT TCCR1B,work
    SEI

loop: 
   RJMP loop

T1compA:
    PUSH work
    IN work,SREG
    PUSH work 

    IN work2,OCR1AL
    SUBI work2,low(-period) 

    IN work,OCR1AH
    SBCI work,high(-period) 
    OUT OCR1AH,work
    OUT OCR1AL,work2


    POP work 
    OUT SREG,work
    POP work
    RETI
