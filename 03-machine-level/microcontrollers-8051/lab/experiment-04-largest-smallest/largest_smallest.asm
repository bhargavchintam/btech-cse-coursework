; ---------------------------------------------------------------
; LARGEST AND SMALLEST IN AN ARRAY
; Scan an array of 8 bytes at 40H..47H. First pass keeps the running
; maximum in A, second pass keeps the running minimum. CJNE sets CY
; when A < element, which decides whether to update.
; Largest stored at 50H, smallest at 51H.
; ---------------------------------------------------------------
ORG 0000H

; array under test
        MOV 40H, #3AH
        MOV 41H, #91H
        MOV 42H, #17H
        MOV 43H, #0FEH
        MOV 44H, #4CH
        MOV 45H, #08H
        MOV 46H, #0A3H
        MOV 47H, #62H

; --- find the largest ---
        MOV R0, #40H
        MOV R2, #08H
        MOV A, @R0           ; first element is the initial max
        INC R0
        DEC R2               ; N-1 comparisons remain
MAXLP:  CJNE A, @R0, MAXD    ; compare max with element
        SJMP MAXS            ; equal - no change
MAXD:   JNC MAXS             ; C=0 : A > element, keep max
        MOV A, @R0           ; C=1 : element is bigger, take it
MAXS:   INC R0
        DJNZ R2, MAXLP
        MOV 50H, A           ; store largest

; --- find the smallest ---
        MOV R0, #40H
        MOV R2, #08H
        MOV A, @R0           ; first element is the initial min
        INC R0
        DEC R2
MINLP:  CJNE A, @R0, MIND    ; compare min with element
        SJMP MINS            ; equal - no change
MIND:   JC  MINS             ; C=1 : A < element, keep min
        MOV A, @R0           ; C=0 : element is smaller, take it
MINS:   INC R0
        DJNZ R2, MINLP
        MOV 51H, A           ; store smallest
HERE:   SJMP HERE
END
; result: 50H = FEH (largest), 51H = 08H (smallest)
;         array = 3AH 91H 17H FEH 4CH 08H A3H 62H
