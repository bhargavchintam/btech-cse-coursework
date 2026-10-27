; ---------------------------------------------------------------
; LARGEST IN AN ARRAY
; Find the largest byte in an array of 8 bytes at 40H..47H.
; Keep the running maximum in A, compare each element with CJNE
; (carry set when A < element) and update on carry.
; Result stored at 60H.
; ---------------------------------------------------------------
ORG 0000H

; array under test
        MOV 40H, #25H
        MOV 41H, #7FH
        MOV 42H, #12H
        MOV 43H, #0AH
        MOV 44H, #99H
        MOV 45H, #33H
        MOV 46H, #05H
        MOV 47H, #88H

        MOV R0, #40H         ; array pointer
        MOV R2, #08H         ; element count
        MOV A, @R0           ; first element is the initial max
        INC R0
        DEC R2               ; N-1 comparisons remain
LOOP:   CJNE A, @R0, DIFF    ; compare max with element
        SJMP SKIP            ; equal - no change
DIFF:   JNC SKIP             ; C=0 : A >= element, keep max
        MOV A, @R0           ; C=1 : element is bigger, take it
SKIP:   INC R0
        DJNZ R2, LOOP
        MOV 60H, A           ; store the largest
HERE:   SJMP HERE
END
; result: 60H = 99H (largest of 25H 7FH 12H 0AH 99H 33H 05H 88H)
