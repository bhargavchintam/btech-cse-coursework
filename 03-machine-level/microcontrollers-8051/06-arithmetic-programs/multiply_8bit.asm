; ---------------------------------------------------------------
; 8-bit multiplication with MUL AB
; product is 16-bit, returned in B:A (B = high byte, A = low byte)
; ---------------------------------------------------------------
ORG 0000H
    MOV A, #0FFH     ; multiplicand
    MOV B, #0FFH     ; multiplier
    MUL AB           ; FFH * FFH = FE01H -> B = FEH, A = 01H
    MOV 40H, A       ; low byte of product = 01H
    MOV 41H, B       ; high byte of product = FEH
HERE: SJMP HERE
END
; result: 40H = 01H (product low), 41H = FEH (product high); FF*FF = FE01H
