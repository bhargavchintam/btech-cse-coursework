; ---------------------------------------------------------------
; COUNT EVEN AND ODD BYTES
; Scan an array of 8 bytes at 40H..47H. Rotate each byte right
; through carry (RRC) so bit0 lands in C: C=0 means even, C=1 odd.
; Even count -> 60H, odd count -> 61H.
; ---------------------------------------------------------------
ORG 0000H

        MOV 40H, #22H
        MOV 41H, #15H
        MOV 42H, #30H
        MOV 43H, #07H
        MOV 44H, #44H
        MOV 45H, #0AH
        MOV 46H, #11H
        MOV 47H, #08H

        MOV R0, #40H         ; array pointer
        MOV R2, #08H         ; count of bytes
        MOV R3, #00H         ; even tally
        MOV R4, #00H         ; odd tally
LOOP:   MOV A, @R0
        RRC A                ; bit0 -> C
        JC  ODD
        INC R3               ; C=0 : even
        SJMP NEXT
ODD:    INC R4               ; C=1 : odd
NEXT:   INC R0
        DJNZ R2, LOOP
        MOV 60H, R3          ; store even count
        MOV 61H, R4          ; store odd count
HERE:   SJMP HERE
END
; result: 60H = 05H (even), 61H = 03H (odd)
