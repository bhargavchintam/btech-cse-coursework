; ---------------------------------------------------------------
; SQUARE WAVE GENERATION using a Timer0 mode-1 delay
; 12 MHz crystal => 1 machine cycle = 1 us.
; half-period = 1000 us -> full period = 2 ms -> 500 Hz square wave
; count = 1000, reload = 65536 - 1000 = 64536 = 0FC18H
; ---------------------------------------------------------------
ORG 0000H
        MOV TMOD, #01H       ; Timer0, mode 1 (16-bit)
BACK:   CPL P1.0             ; toggle the output pin
        ACALL DELAY          ; hold this level for one half-period
        SJMP BACK

DELAY:  MOV TH0, #0FCH       ; reload high byte
        MOV TL0, #18H        ; reload low byte
        SETB TR0             ; start Timer0
WAIT:   JNB TF0, WAIT        ; wait for the 1 ms overflow
        CLR TR0              ; stop
        CLR TF0              ; clear the overflow flag
        RET
END
; result: P1.0 outputs a 500 Hz square wave (1 ms high, 1 ms low)
