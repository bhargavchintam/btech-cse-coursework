; ---------------------------------------------------------------
; Timer1 as a 16-bit external event counter (mode 1, C/T = 1)
; counts falling edges on the T1 pin (P3.5)
; the live count is kept in internal RAM 41H:40H (high:low)
; ---------------------------------------------------------------
ORG 0000H
    MOV TMOD, #50H     ; Timer1: C/T1 = 1 (counter), mode 1 (16-bit)
    MOV TL1, #00H      ; clear the count
    MOV TH1, #00H
    SETB TR1           ; enable counting of pulses on T1 (P3.5)
BACK: MOV 40H, TL1     ; copy live low byte to RAM
    MOV 41H, TH1       ; copy live high byte to RAM
    SJMP BACK          ; keep the stored count fresh
END
; result: 41H:40H hold the pulse count seen on T1; e.g. after 0100H pulses 41H=01H 40H=00H
