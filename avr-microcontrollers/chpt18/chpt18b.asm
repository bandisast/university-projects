.include "m32def.inc"
.equ Palmoi = 15625-1

.org 0x0000
    RJMP reset

.org 0x000E
    RJMP T1_COMPA        

.org 0x0014
    RJMP T0_COMP        

reset:
    LDI R16,low(RAMEND)
    OUT SPL,R16
    LDI R16,high(RAMEND)
    OUT SPH,R16

    CBI DDRB,0
    SBI PORTB,0        
    SBI DDRD,5            
    CBI PORTD,5
    
    LDI R16,9
    OUT OCR0, R16        
    
    LDI R16,high(Palmoi)    
    OUT OCR1AH,R16            
    LDI R16,low(Palmoi)
    OUT OCR1AL,R16

    LDI R16,(1<<OCF0)|(1<<OCF1A)    
    OUT TIFR,R16                    
    OUT TIMSK,R16                    

    LDI R16,(1<<COM1A0)
    OUT TCCR1A,R16        

    LDI R16,(1<<CS02)|(1<<CS01)|(1<<WGM01)
    OUT TCCR0,R16    

    SEI
    
main:
    RJMP main

T0_COMP:
    LDI R16,(1<<COM1A0)|(1<<FOC1A)
    OUT TCCR1A,R16        
    LDI R16,(1<<CS12)|(1<<CS10)|(1<<WGM12)
    OUT TCCR1B,R16        
    RETI
        
T1_COMPA:
    CLR R16
    OUT TCCR1B,R16        
    OUT TCNT1H,R16        
    OUT TCNT1L,R16        
    RETI
