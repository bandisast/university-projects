.include "m32def.inc"
.def work=R16
.equ xronos=15624

.org 0
    RJMP reset

.org OC1Aaddr
    RJMP T1compA

reset:
    LDI work,high(RAMEND)
    OUT SPH,work
    LDI work,low(RAMEND)
    OUT SPL,work

    SBI DDRC,0
    CBI PORTC,0

    LDI work,high(xronos)
    OUT OCR1AH,work
    LDI work,low(xronos)
    OUT OCR1AL,work

    CLR work
    OUT TCCR1A,work
    LDI work,(1<<WGM12)|(1<<CS12)|(1<<CS10)
    OUT TCCR1B,work

    LDI work,(1<<OCIE1A)
    OUT TIMSK,work
    OUT TIFR,work

    SEI
loop:
    NOP
    RJMP loop

T1compA:
    SBIC PINC,0
    CBI PORTC,0
    SBIS PINC,0
    SBI PORTC,0
    RETI
