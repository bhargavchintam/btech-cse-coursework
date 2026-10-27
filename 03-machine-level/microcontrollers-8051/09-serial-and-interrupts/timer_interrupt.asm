; Timer 0 overflow interrupt - ISR toggles a pin and reloads the timer
; Timer 0 in mode 1 counts 50 ms, overflows to the ISR at vector 000BH, which
; complements P1.0 and reloads the count. Result is a 10 Hz square wave on P1.0.
; Reload for 50 ms @ 12 MHz: 65536 - 50000 = 15536 = 3CB0H -> TH0 = 3CH, TL0 = 0B0H.
ORG 0000H
    SJMP MAIN          ; skip past the vector area
; --- Timer 0 overflow ISR at its vector 000BH ---
ORG 000BH
    CLR TR0            ; stop the timer while reloading
    MOV TH0, #3CH      ; reload high byte  (3CB0H = 65536 - 50000)
    MOV TL0, #0B0H     ; reload low byte
    CPL P1.0           ; toggle the output pin
    SETB TR0           ; restart the timer
    RETI
; --- main program ---
ORG 0030H
MAIN:
    MOV TMOD, #01H     ; Timer 0, mode 1 (16-bit)
    MOV TH0, #3CH      ; initial count for the first 50 ms interval
    MOV TL0, #0B0H
    MOV IE, #82H       ; EA + ET0 -> enable Timer 0 interrupt (80H + 02H)
    SETB TR0           ; start Timer 0
HERE:
    SJMP HERE          ; main just idles; the ISR does the toggling
END
; result: P1.0 toggles every 50 ms -> 100 ms period -> 10 Hz square wave.
;         TH0/TL0 reload = 3CH/0B0H, IE = 82H (EA + ET0).
