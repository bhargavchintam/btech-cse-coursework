; Bindu Bhargava  14-12-18
; ---------------------------------------------------------------
; multi-digit (4-digit) packed BCD addition with DA A
; NUM1 = 6789 (67H,89H), NUM2 = 4567 (45H,67H)
; add low BCD byte, DA A, then high BCD byte with carry, DA A
; result low in 40H, high in 41H, carry digit in 42H
; ---------------------------------------------------------------
ORG 0000H
    MOV A, #89H      ; low byte of NUM1
    ADD A, #67H      ; 89 + 67 = F0H (binary), AC = 1
    DA A             ; adjust to BCD -> 56H, CY = 1
    MOV 40H, A       ; low BCD result = 56

    MOV A, #67H      ; high byte of NUM1
    ADDC A, #45H     ; 67 + 45 + carry = ADH (binary)
    DA A             ; adjust to BCD -> 13H, CY = 1
    MOV 41H, A       ; high BCD result = 13

    MOV A, #00H
    ADDC A, #00H     ; carry-out digit
    MOV 42H, A       ; carry = 01
HERE: SJMP HERE
END
; result: 40H = 56H, 41H = 13H, 42H = 01H  (6789 + 4567 = 11356 decimal)
