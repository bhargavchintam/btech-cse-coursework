; ---------------------------------------------------------------
; 8-BIT AND 16-BIT ADDITION AND SUBTRACTION
; Adds and subtracts 8-bit numbers keeping carry/borrow, then does
; the same for 16-bit numbers (low byte first, ADDC/SUBB chain).
; Bindu Bhargava  07-12-18
; ---------------------------------------------------------------
ORG 0000H

; --- 8-bit addition : 6AH + CFH ---
        MOV A, #6AH
        ADD A, #0CFH         ; 6A + CF = 139H, CY = 1
        MOV 40H, A           ; sum low byte = 39H
        MOV A, #00H
        ADDC A, #00H         ; take the carry into a second byte
        MOV 41H, A           ; carry = 01H

; --- 8-bit subtraction : 64H - 9FH ---
        CLR C                ; no incoming borrow
        MOV A, #64H
        SUBB A, #9FH         ; 64 - 9F = C5H, CY = 1 (borrow)
        MOV 42H, A           ; result = C5H (two's complement of -3BH)
        MOV A, #00H
        ADDC A, #00H         ; move the borrow (CY) into a byte
        MOV 43H, A           ; borrow = 01H

; --- 16-bit addition : 7A63H + 9BD4H ---
        MOV A, #63H
        ADD A, #0D4H         ; low bytes: 63 + D4 = 137H, CY = 1
        MOV 44H, A           ; sum low = 37H
        MOV A, #7AH
        ADDC A, #9BH         ; high bytes: 7A + 9B + 1 = 116H, CY = 1
        MOV 45H, A           ; sum high = 16H
        MOV A, #00H
        ADDC A, #00H
        MOV 46H, A           ; carry = 01H  (7A63 + 9BD4 = 11637H)

; --- 16-bit subtraction : 7A63H - 9BD4H ---
        CLR C
        MOV A, #63H
        SUBB A, #0D4H        ; low bytes: 63 - D4 = 8FH, CY = 1 (borrow)
        MOV 47H, A           ; diff low = 8FH
        MOV A, #7AH
        SUBB A, #9BH         ; high bytes: 7A - 9B - 1 = DEH, CY = 1
        MOV 48H, A           ; diff high = DEH
        MOV A, #00H
        ADDC A, #00H
        MOV 49H, A           ; borrow = 01H  (result DE8FH, negative)
HERE:   SJMP HERE
END
; result: 40H=39H 41H=01H (8-bit add), 42H=C5H 43H=01H (8-bit sub),
;         44H=37H 45H=16H 46H=01H (16-bit add 11637H),
;         47H=8FH 48H=DEH 49H=01H (16-bit sub, borrow set)
