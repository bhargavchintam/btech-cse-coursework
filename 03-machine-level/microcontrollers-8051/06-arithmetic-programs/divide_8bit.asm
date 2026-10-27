; ---------------------------------------------------------------
; 8-bit division with DIV AB
; A / B ; afterwards A = quotient, B = remainder
; ---------------------------------------------------------------
ORG 0000H
    MOV A, #95H      ; dividend
    MOV B, #10H      ; divisor
    DIV AB           ; 95H / 10H -> A = 09H (quotient), B = 05H (remainder)
    MOV 40H, A       ; quotient = 09H
    MOV 41H, B       ; remainder = 05H
HERE: SJMP HERE
END
; result: 40H = 09H (quotient), 41H = 05H (remainder); 95H / 10H = 9 rem 5
