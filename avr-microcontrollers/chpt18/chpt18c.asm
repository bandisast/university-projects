.include "m32def.inc"

.equ compA = 32000    
.equ compB = 48000    

.org 0x0000
    RJMP reset

.org 0x000E                
    RJMP T1_COMPA        

.org 0x0010                
    RJMP T1_COMPB

.org 0x0012            
    RJMP T1_OVF
    
reset:
    LDI R16,high(RAMEND)
    OUT SPH,R16
    LDI R16,low(RAMEND)
    OUT SPL,R16
    
    LDI R16,high(compA)    
    OUT OCR1AH,R16    
    LDI R16,low(compA)
    OUT OCR1AL,R16

    
    LDI R16,high(compB)    
    OUT OCR1BH,R16    
    LDI R16,low(compB)
    OUT OCR1BL,R16

    LDI R16,(1<<OCF1B)|(1<<OCF1A)|(1<<TOV1)
    OUT TIFR,R16    
    OUT TIMSK,R16    

    LDI R16,(1<<CS10)    
    OUT TCCR1B,R16        

    SEI
    
main:
    RJMP main
    
T1_COMPA:
    PUSH R16
    IN R16,SREG
    PUSH R16
    PUSH R17

    IN R16,OCR1AL            
    SUBI R16,low(-compA)    
    IN R17, OCR1AH            
    SBCI R17,high(-compA)    

    OUT OCR1AH,R17        
    OUT OCR1AL,R16        

    NOP            

    POP R17
    POP R16
    OUT SREG, R16
    POP R16

    RETI

T1_COMPB:
    PUSH R16
    IN R16,SREG
    PUSH R16
    PUSH R17

    IN R16, OCR1BL            
    SUBI R16,low(-compB)    
    IN R17, OCR1BH            
    SBCI R17,high(-compB)    

    OUT OCR1BH,R17        
    OUT OCR1BL,R16        
    NOP            
    POP R17
    POP R16
    OUT SREG,R16
    POP R16

    RETI

T1_OVF:
    NOP            
    RETI
