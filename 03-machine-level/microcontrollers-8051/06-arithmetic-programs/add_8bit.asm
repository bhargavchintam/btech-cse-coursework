; ---------------------------------------------------------------
; 8-bit addition of two numbers, keeping the carry
; NUM1 + NUM2, low byte in 40H, carry byte in 41H
; ---------------------------------------------------------------
ORG 0000H
    MOV A, #0A5H     ; first number
    ADD A, #0C7H     ; A5H + C7H = 16CH, CY = 1
    MOV 40H, A       ; low byte of sum = 6CH
    MOV A, #00H
    ADDC A, #00H     ; pick up the carry into a second byte
    MOV 41H, A       ; carry byte = 01H
HERE: SJMP HERE
END
; result: 40H = 6CH (sum low), 41H = 01H (carry)
