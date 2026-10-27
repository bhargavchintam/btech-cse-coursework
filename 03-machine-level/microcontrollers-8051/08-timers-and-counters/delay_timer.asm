; ---------------------------------------------------------------
; 1 ms delay using Timer0, mode 1 (16-bit), by polling TF0
; 12 MHz crystal => 1 machine cycle = 1 us
; count = 1000, reload = 65536 - 1000 = 64536 = 0FC18H
; ---------------------------------------------------------------
ORG 0000H
    MOV TMOD, #01H     ; Timer0, mode 1 (16-bit timer, C/T=0)
    MOV TH0, #0FCH     ; high byte of the reload value
    MOV TL0, #18H      ; low byte of the reload value
    SETB TR0           ; start Timer0
WAIT: JNB TF0, WAIT    ; spin until the timer rolls over
    ;MOV A, TL0        ; was checking the low byte on the sim
    CLR TR0            ; stop Timer0
    CLR TF0            ; clear the overflow flag for next time
HERE: SJMP HERE
END
; result: after ~1 ms TF0 is set then cleared; TH0:TL0 count from 0FC18H up to 0000H
