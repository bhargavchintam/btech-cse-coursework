; ------------------------------------------------------------
; Sum of first N natural numbers  (1 + 2 + ... + N)
; N is placed in R2, running sum kept in A, result stored to 40H
; N = 10 -> 55 = 37H  (fits in 8 bits, no carry needed)
; ------------------------------------------------------------
ORG 0000H
    MOV R2, #0AH         ; N = 10
    MOV A, #00H          ; sum = 0
LOOP:   ADD A, R2        ; sum = sum + R2
        DJNZ R2, LOOP    ; R2 = R2 - 1, repeat while R2 != 0
    MOV 40H, A           ; store the result
HERE: SJMP HERE
END
; result: 40H = 37H (55 decimal)
