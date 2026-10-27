; Arithmetic group demo: ADD, ADDC, SUBB, INC, MUL, DIV
; Each result is stored to its own internal RAM byte (40H onwards).
ORG 0000H
    ; --- ADD (no carry in) ---
    MOV A, #25H
    ADD A, #34H       ; 25H + 34H = 59H
    MOV 40H, A        ; 40H = 59H

    ; --- ADDC picks up the carry from a previous overflow ---
    MOV A, #0F0H
    ADD A, #20H       ; F0H + 20H = 110H : A=10H, C=1
    MOV A, #10H       ; (MOV does not disturb C)
    ADDC A, #20H      ; 10H + 20H + 1 = 31H
    MOV 41H, A        ; 41H = 31H

    ; --- SUBB always subtracts the borrow, so clear C first ---
    CLR C
    MOV A, #50H
    SUBB A, #12H      ; 50H - 12H - 0 = 3EH
    MOV 42H, A        ; 42H = 3EH

    ; --- INC wraps FF -> 00 ---
    MOV A, #0FFH
    INC A             ; FFH + 1 = 00H
    MOV 43H, A        ; 43H = 00H

    ; --- MUL AB : 16-bit product, low in A, high in B ---
    MOV A, #0FH
    MOV B, #10H
    MUL AB            ; 0FH * 10H = 00F0H
    MOV 44H, A        ; 44H = F0H  (low byte)
    MOV 45H, B        ; 45H = 00H  (high byte)

    ; --- DIV AB : quotient in A, remainder in B ---
    MOV A, #64H       ; 100
    MOV B, #09H       ; 9
    DIV AB            ; 100 / 9 = 11 rem 1
    MOV 46H, A        ; 46H = 0BH  (quotient)
    MOV 47H, B        ; 47H = 01H  (remainder)
HERE: SJMP HERE
END
; result: 40H=59H, 41H=31H, 42H=3EH, 43H=00H, 44H=F0H, 45H=00H, 46H=0BH, 47H=01H
