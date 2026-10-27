; ---------------------------------------------------------------
; COUNT EVEN AND ODD NUMBERS IN AN ARRAY
; Scan a block of 10 bytes at 40H..49H. Rotate each byte right
; through carry (RRC) so bit0 lands in C: C=0 -> even, C=1 -> odd.
; Even count -> 50H, odd count -> 51H.
; Bindu Bhargava  18-01-19
; ---------------------------------------------------------------
ORG 0000H

; -- load the array first so the count is testable --
        MOV 40H, #22H
        MOV 41H, #15H
        MOV 42H, #30H
        MOV 43H, #07H
        MOV 44H, #44H
        MOV 45H, #0AH
        MOV 46H, #11H
        MOV 47H, #08H
        MOV 48H, #63H
        MOV 49H, #50H

        MOV R0, #40H         ; array pointer
        MOV R2, #0AH         ; 10 bytes
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
        MOV 50H, R3          ; store even count
        MOV 51H, R4          ; store odd count
HERE:   SJMP HERE
END
; result: 50H = 06H (even), 51H = 04H (odd)
