.include "m32def.inc"
.def work=R17
.def T0value=R18
.def stimer=R16

    LDI stimer,21 ;software timer
    LDI T0value,-188+5 ;επιθυμητή καθυστέρηση
    OUT TCNT0,T0value ;αρχ. τιμή Τ0, πρώτο τρέξιμο
    LDI work,(1<<TOV0) 
    OUT TIFR,work ;μηδενισμός σήματος
    LDI work,(1<<CS00)
    OUT TCCR0,work ;Prescaler=1
    
loop: 
    IN work,TIFR ;polling
    SBRS work,TOV0 
    RJMP loop
    OUT TCNT0,T0value ;αρχ. τιμή Τ0 για όλες τις υπόλοιπες φορές
    LDI work,(1<<TOV0) 
    OUT TIFR,work ;μηδενισμός σημαίας διακοπής
    DEC stimer
    BRNE loop
    LDI stimer,21
    NOP ;breakpoint
    NOP ;κάποια περιοδική εργασία ...
    NOP
    RJMP loop
    
