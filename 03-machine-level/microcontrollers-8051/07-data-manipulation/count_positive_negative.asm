; ---------------------------------------------------------------
; COUNT POSITIVE AND NEGATIVE BYTES
; Scan an array of 8 bytes at 40H..47H. Treating each byte as a
; signed number, MSB=0 is positive and MSB=1 is negative. Rotate
; left through carry (RLC) so bit7 lands in C.
; Positive count -> 60H, negative count -> 61H.
; ---------------------------------------------------------------
ORG 0000H

        MOV 40H, #7FH
        MOV 41H, #80H
        MOV 42H, #05H
        MOV 43H, #0F0H
        MOV 44H, #22H
        MOV 45H, #0A5H
        MOV 46H, #10H
        MOV 47H, #33H

        MOV R0, #40H         ; array pointer
        MOV R2, #08H         ; count of bytes
        MOV R3, #00H         ; positive tally
        MOV R4, #00H         ; negative tally
LOOP:   MOV A, @R0
        RLC A                ; bit7 -> C
        JC  NEG
        INC R3               ; C=0 : MSB clear, positive
        SJMP NEXT
NEG:    INC R4               ; C=1 : MSB set, negative
NEXT:   INC R0
        DJNZ R2, LOOP
        MOV 60H, R3          ; store positive count
        MOV 61H, R4          ; store negative count
HERE:   SJMP HERE
END
; result: 60H = 05H (positive, MSB=0), 61H = 03H (negative, MSB=1)
