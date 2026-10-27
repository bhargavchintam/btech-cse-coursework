; Logical group demo: ANL, ORL, XRL, CPL, RL, SWAP
; One sample byte per operation, result written to internal RAM 40H..45H.
ORG 0000H
    MOV A, #0F0H
    ANL A, #3CH       ; F0 AND 3C = 30H  (mask out bits)
    MOV 40H, A        ; 40H = 30H

    MOV A, #0F0H
    ORL A, #0DH       ; F0 OR 0D = FDH   (set bits)
    MOV 41H, A        ; 41H = FDH

    MOV A, #0AAH
    XRL A, #0FFH      ; AA XOR FF = 55H  (toggle bits = CPL)
    MOV 42H, A        ; 42H = 55H

    MOV A, #25H
    CPL A             ; NOT 25 = DAH
    MOV 43H, A        ; 43H = DAH

    MOV A, #85H
    RL A              ; rotate left, bit7 -> bit0 : 85 -> 0B
    MOV 44H, A        ; 44H = 0BH

    MOV A, #3CH
    SWAP A            ; exchange nibbles : 3C -> C3
    MOV 45H, A        ; 45H = C3H
HERE: SJMP HERE
END
; result: 40H=30H, 41H=FDH, 42H=55H, 43H=DAH, 44H=0BH, 45H=C3H
