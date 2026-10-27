; ---------------------------------------------------------------
; Square wave on P1.0 using a Timer0 mode-1 delay
; Bindu Bhargava  14-02-19
; half-period = 500 us -> full period 1 ms -> 1 kHz square wave
; count = 500, reload = 65536 - 500 = 65036 = 0FE0CH
; ---------------------------------------------------------------
ORG 0000H
    MOV TMOD, #01H     ; Timer0, mode 1
BACK: CPL P1.0         ; toggle the output pin
    ACALL DELAY        ; hold this level for one half-period
    SJMP BACK

DELAY: MOV TH0, #0FEH  ; reload high byte
    MOV TL0, #0CH      ; reload low byte
    SETB TR0           ; start Timer0
W: JNB TF0, W          ; wait for the 500 us overflow
    CLR TR0            ; stop
    CLR TF0            ; clear the flag
    RET
END
; result: P1.0 outputs a 1 kHz square wave (500 us high, 500 us low)
