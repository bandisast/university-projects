.include "m32def.inc"
.org 0
RJMP reset ;πέρνα πάνω από το διάνυσμα interrupt του INT0

.org INT0addr ;αρχικοποίηση interrupt INT0
RJMP INT0_irqRout ;πάνε στην υπορουτίνα αν έρθει σήμα interrupt

reset:
LDI R16,low(RAMEND)
OUT SPL,R16 ;αρχικοποίηση του stack pointer
LDI R16,high(RAMEND)
OUT SPH,R16

CBI DDRD,2 ;αρχικοποίηση INT0 ως είσοδος με pull-up
SBI PORTD,2

SBI DDRC,0 ;αρχικοποίηση C0 ως έξοδος

LDI R16,(1<<ISC01)|(1<<ISC00) ;0|0=low, 1|1=rising, 1|0=falling edge
;LDI R16,(0<<ISC01)|(0<<ISC00)
OUT MCUCR,R16 ;falling edge επιλογή -> MCUCR

LDI R16,(1<<INTF0)
OUT GIFR,R16 ;αλλαγή σημαίας διακοπής INT0

LDI R16,(1<<INT0)
OUT GICR,R16 ;ενεργοποίηση INT0 μέσω μάσκας

SEI ;ενεργοποίηση interrupts (I flag, SREG)

main:
NOP ;οποιοδήποτε πρόγραμμα εδώ
RJMP main

INT0_irqRout:
SBIC PINC,0 ;πρόγραμμα ενεργοποίησης/απενεργοποίησης LED
CBI PORTC,0
SBIS PINC,0
SBI PORTC,0
RETI ;Περίπου η λειτουργία RET *και* SEI στην ίδια εντολή