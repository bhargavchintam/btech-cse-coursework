; ---------------------------------------------------------------
; 16-bit addition of two numbers stored in internal RAM
; NUM1 = 8F2AH at 40H(low),41H(high)
; NUM2 = 9C15H at 42H(low),43H(high)
; result (3 bytes) at 44H(low), 45H(high), 46H(carry)
; ---------------------------------------------------------------
ORG 0000H
    ; load the two 16-bit numbers into RAM (low byte first)
    MOV 40H, #2AH
    MOV 41H, #8FH
    MOV 42H, #15H
    MOV 43H, #9CH

    MOV A, 40H
    ADD A, 42H       ; add low bytes: 2A + 15 = 3F, CY = 0
    MOV 44H, A
    MOV A, 41H
    ADDC A, 43H      ; add high bytes with carry: 8F + 9C = 12B, CY = 1
    MOV 45H, A
    MOV A, #00H
    ADDC A, #00H     ; final carry into third byte
    MOV 46H, A
HERE: SJMP HERE
END
; result: 44H = 3FH (low), 45H = 2BH (high), 46H = 01H (carry)
;         true sum 8F2AH + 9C15H = 12B3FH
