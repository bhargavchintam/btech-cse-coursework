; ---------------------------------------------------------------
; DESCENDING SORT (BUBBLE SORT)
; Sort 5 bytes at 40H..44H into descending order, in place.
; Same bubble sort, but the pair is swapped when the left byte is
; smaller than the right (carry set after CJNE).
; ---------------------------------------------------------------
ORG 0000H

        MOV 40H, #25H
        MOV 41H, #12H
        MOV 42H, #0AH
        MOV 43H, #33H
        MOV 44H, #05H

        MOV R1, #04H         ; N-1 passes
PASS:   MOV R0, #40H         ; start of array
        MOV R2, #04H         ; N-1 comparisons per pass
INNER:  MOV A, @R0           ; A = arr[j]
        INC R0               ; R0 -> arr[j+1]
        CJNE A, @R0, DIFF    ; compare the pair
        SJMP NEXT            ; equal - leave as is
DIFF:   JNC NEXT             ; C=0 : arr[j] >= arr[j+1], already in order
        XCH A, @R0           ; else swap: arr[j+1] gets the smaller
        DEC R0
        MOV @R0, A           ; arr[j] gets the larger
        INC R0
NEXT:   DJNZ R2, INNER
        DJNZ R1, PASS
HERE:   SJMP HERE
END
; result: 40H..44H = 33H 25H 12H 0AH 05H (descending)
