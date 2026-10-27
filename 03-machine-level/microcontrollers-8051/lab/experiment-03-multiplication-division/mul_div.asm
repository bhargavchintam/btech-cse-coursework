; ---------------------------------------------------------------
; 8-BIT MULTIPLICATION AND DIVISION
; MUL AB : A * B -> 16-bit product in B:A (B high, A low)
; DIV AB : A / B -> A = quotient, B = remainder
; ---------------------------------------------------------------
ORG 0000H

; --- multiplication : 37H * 2AH ---
        MOV A, #37H          ; multiplicand = 55
        MOV B, #2AH          ; multiplier   = 42
        MUL AB               ; 37H * 2AH = 906H -> B = 09H, A = 06H
        MOV 40H, A           ; product low  = 06H
        MOV 41H, B           ; product high = 09H

; --- division : FBH / 0CH ---
        MOV A, #0FBH         ; dividend = 251
        MOV B, #0CH          ; divisor  = 12
        DIV AB               ; 251 / 12 = 20 rem 11 -> A = 14H, B = 0BH
        ;MOV R3, A           ; (debug) keep quotient in R3 as well
        MOV 42H, A           ; quotient  = 14H
        MOV 43H, B           ; remainder = 0BH
HERE:   SJMP HERE
END
; result: 40H = 06H, 41H = 09H  (55 * 42 = 2310 = 0906H)
;         42H = 14H, 43H = 0BH  (251 / 12 = 20 remainder 11)
