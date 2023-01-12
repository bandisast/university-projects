.include "m32def.inc"

;R0 * (R3:R2) * (R7:R6:R5) = R19:R18:R17:R16 =
;  C  C   C  R0  (C=R20)
;  C  C   R3 R2  (C=R21)
;+ C  R7  R6 R5  (C=R22)
;==============
;R19:R18:R17:R16

CLR R20
CLR R21
CLR R22

;check0:
TST R0
BRPL check1
;check if R0 is positive. GOTO check1 if positive.
SER R20
;if negative, set R20 to "255"

check1:
	TST R3
	BRPL check2
	SER R21
	;akin to previous check but for the second row

check2:
	TST R7
	BRPL calc
	SER R22
	;akin to previous checks but for the third row

calc:
	MOVW R17:R16,R3:R2 ;move word R3:R2 to R17:R16
	MOV R18,R21 ;move R21 to R18
	MOV R19,R21 ;move R21 to R19
	;R19:R18:R17:R16 is now the same as line 2.
	ADD R16,R0
	ADC R17,R20
	ADC R18,R20
	ADC R19,R20
	;add R0 and its carry bits to R19:...:R16. (it is now line 1 + line 2)
	ADD R16,R5
	ADC R17,R6
	ADC R18,R7
	ADC R19,R22
	;add line 3 word and its carry to R19:...:R16 (now line 1 + line 2 + line 3)

loop:
RJMP loop
;the end
