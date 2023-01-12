.include "m32def.inc"
.def work=R16

    SER work
    OUT DDRB,work ;ενεργοποίηση θύρας Β
    LDI work,16
    OUT OCR0,work ;μέτρα μέχρι το 16
    LDI work,(1<<CS00)|(1<<WGM01)|(1<<COM00) ;α|β|γ
    OUT TCCR0,work ;prescaler=1, CTC mode, αντιστρ. Β3

loop:
    NOP
    RJMP loop
