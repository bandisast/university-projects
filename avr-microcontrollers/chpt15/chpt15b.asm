.include "m32def.inc"


CBI DDRC, 7
SBI PORTC, 7

CBI DDRC, 6
SBI PORTC, 6

SBI DDRC, 0



loop: 
SBIC PINC, 7
RJMP vale0

SBIC PINC, 6
RJMP vale0

SBI PORTC, 0

RJMP loop

vale0:
CBI PORTC, 0
RJMP loop
