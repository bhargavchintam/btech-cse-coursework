; ---------------------------------------------------------------
; SMALLEST IN AN ARRAY
; Find the smallest byte in an array of 8 bytes at 40H..47H.
; Keep the running minimum in A. CJNE sets carry when A < element,
; so update the min only when carry is clear (A > element).
; Result stored at 60H.
; ---------------------------------------------------------------
ORG 0000H

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
        MOV A, @R0           ; first element is the initial min
        INC R0
        DEC R2               ; N-1 comparisons remain
LOOP:   CJNE A, @R0, DIFF    ; compare min with element
        SJMP SKIP            ; equal - no change
DIFF:   JC  SKIP             ; C=1 : A < element, keep min
        MOV A, @R0           ; C=0 : element is smaller, take it
SKIP:   INC R0
        DJNZ R2, LOOP
        MOV 60H, A           ; store the smallest
HERE:   SJMP HERE
END
; result: 60H = 05H (smallest of 25H 7FH 12H 0AH 99H 33H 05H 88H)
