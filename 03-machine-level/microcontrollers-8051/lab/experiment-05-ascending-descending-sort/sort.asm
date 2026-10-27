; ---------------------------------------------------------------
; ASCENDING AND DESCENDING SORT (BUBBLE SORT)
; Sort 5 bytes into ascending order at 40H..44H and into descending
; order at 50H..54H. The same input is loaded into both areas, then
; each is bubble-sorted in place. Adjacent pair compared with CJNE;
; the carry after CJNE decides whether to swap with XCH.
; ---------------------------------------------------------------
ORG 0000H

; input array -> ascending copy at 40H, descending copy at 50H
        MOV 40H, #42H
        MOV 41H, #15H
        MOV 42H, #7EH
        MOV 43H, #03H
        MOV 44H, #5CH
        MOV 50H, #42H
        MOV 51H, #15H
        MOV 52H, #7EH
        MOV 53H, #03H
        MOV 54H, #5CH

; --- ascending sort on 40H..44H ---
        MOV R1, #04H         ; N-1 passes
ASCP:   MOV R0, #40H
        MOV R2, #04H         ; N-1 comparisons per pass
ASCI:   MOV A, @R0           ; A = arr[j]
        INC R0               ; R0 -> arr[j+1]
        CJNE A, @R0, ASCD
        SJMP ASCN            ; equal - leave as is
ASCD:   JC  ASCN             ; C=1 : arr[j] < arr[j+1], in order
        XCH A, @R0           ; swap : arr[j+1] gets the larger
        DEC R0
        MOV @R0, A           ; arr[j] gets the smaller
        INC R0
ASCN:   DJNZ R2, ASCI
        DJNZ R1, ASCP

; --- descending sort on 50H..54H ---
        MOV R1, #04H
DSCP:   MOV R0, #50H
        MOV R2, #04H
DSCI:   MOV A, @R0
        INC R0
        CJNE A, @R0, DSCD
        SJMP DSCN
DSCD:   JNC DSCN             ; C=0 : arr[j] > arr[j+1], in order
        XCH A, @R0           ; swap : arr[j+1] gets the smaller
        DEC R0
        MOV @R0, A           ; arr[j] gets the larger
        INC R0
DSCN:   DJNZ R2, DSCI
        DJNZ R1, DSCP
HERE:   SJMP HERE
END
; result: 40H..44H = 03H 15H 42H 5CH 7EH (ascending)
;         50H..54H = 7EH 5CH 42H 15H 03H (descending)
