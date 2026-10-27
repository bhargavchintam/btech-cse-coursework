; BCD addition with DA A
; ADD works in binary; DA A corrects the sum back to packed BCD.
; Bindu Bhargava  21-11-18
ORG 0000H
    ; --- example 1 : 47 + 38 = 85, no carry out ---
    MOV A, #47H       ; BCD 47
    ADD A, #38H       ; binary 47H + 38H = 7FH
    DA A              ; lower nibble F>9 so +06 -> 85H
    MOV 40H, A        ; 40H = 85H

    ; --- example 2 : 59 + 48 = 107, carries out ---
    MOV A, #59H       ; BCD 59
    ADD A, #48H       ; binary 59H + 48H = A1H, AC=1
    DA A              ; +06 then +60 -> 07H, C=1
    MOV 41H, A        ; 41H = 07H  (low two BCD digits)
    MOV A, #00H
    ADDC A, #00H      ; fold the BCD carry into the hundreds digit
    MOV 42H, A        ; 42H = 01H
HERE: SJMP HERE
END
; result: 40H=85H (47+38), 41H=07H & 42H=01H (59+48 = 107)
