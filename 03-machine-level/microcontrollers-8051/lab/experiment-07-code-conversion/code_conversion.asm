; ---------------------------------------------------------------
; CODE CONVERSION : hex(binary) -> BCD  and  BCD -> ASCII
; Part 1 : convert the byte FFH (255) to BCD digits by repeated
;          division. DIV AB gives quotient in A, remainder in B.
;          hundreds -> 50H, tens -> 51H, units -> 52H.
; Part 2 : convert packed BCD 25H to two ASCII characters.
;          Split the nibbles and OR each with 30H.
;          '2' -> 53H, '5' -> 54H.
; ---------------------------------------------------------------
ORG 0000H

; --- Part 1 : hex to BCD (FFH = 255) ---
        MOV A, #0FFH
        MOV B, #64H          ; 100
        DIV AB               ; A = 02 (hundreds), B = 55 remainder
        MOV 50H, A           ; hundreds digit
        MOV A, B
        MOV B, #0AH          ; 10
        DIV AB               ; A = 05 (tens), B = 05 (units)
        MOV 51H, A           ; tens digit
        MOV 52H, B           ; units digit

; --- Part 2 : BCD to ASCII (25H) ---
        MOV A, #25H
        MOV R2, A            ; keep a copy
        SWAP A               ; bring high nibble down -> 02
        ANL A, #0FH
        ORL A, #30H          ; 02 -> 32H = '2'
        MOV 53H, A
        MOV A, R2
        ANL A, #0FH          ; low nibble -> 05
        ORL A, #30H          ; 05 -> 35H = '5'
        MOV 54H, A
HERE:   SJMP HERE
END
; result: 50H=02H 51H=05H 52H=05H (FFH -> 255 BCD),
;         53H=32H ('2') 54H=35H ('5')  (25H BCD -> ASCII)
