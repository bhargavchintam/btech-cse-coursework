; ---------------------------------------------------------------
; 8-bit subtraction using SUBB, with borrow handling
; NUM1 - NUM2, result in 40H, borrow flag in 41H
; SUBB does A - source - CY, so clear CY before the first subtract
; ---------------------------------------------------------------
ORG 0000H
    CLR C            ; no incoming borrow
    MOV A, #32H      ; minuend
    SUBB A, #4EH     ; 32H - 4EH = E4H, CY = 1 (borrow, answer is negative)
    MOV 40H, A       ; result byte = E4H
    MOV A, #00H
    ADDC A, #00H     ; move the borrow (CY) into 41H
    MOV 41H, A       ; borrow = 01H
HERE: SJMP HERE
END
; result: 40H = E4H (32H - 4EH as two's complement), 41H = 01H (borrow set)
