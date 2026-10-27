; ---------------------------------------------------------------
; square of an 8-bit number using MUL AB
; load the number in A, copy to B, multiply
; 16-bit result in B:A (B = high, A = low)
; ---------------------------------------------------------------
ORG 0000H
    MOV A, #0DH      ; number to square
    MOV B, A         ; B = same number
    ;MOV R3, A       ; keep a copy (not needed here)
    MUL AB           ; 0DH * 0DH = 00A9H -> B = 00H, A = A9H
    MOV 40H, A       ; low byte of square = A9H
    MOV 41H, B       ; high byte of square = 00H
HERE: SJMP HERE
END
; result: 40H = A9H (square low), 41H = 00H (square high); 13 x 13 = 169 = A9H
