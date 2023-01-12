.include "m32def.inc"
.equ ramaddr=0x0060

LDI ZL,low(temp<<1)
LDI ZH,high(temp<<1)

LDI YL,low(ramaddr)
LDI YH,high(ramaddr)

rom2sram:
LPM R16,Z+
ST Y+,R16
CPI R16,0
BRNE rom2sram

loop:
	RJMP loop

temp:
.db "Antonoglou  ", " 7", " 5"
.db "Papadopoulou", " 5", " 6"
.db "Bantis      ", "10", " 9"
.db "Anastasiadis", " 4", " 8"
.db "Papaioannou ", " 6", "10"
.db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
