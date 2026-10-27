; ------------------------------------------------------------
; Toggle all bits of Port 1 with a delay in between
; The classic first program - square wave on every P1 pin
; 8051, 12 MHz crystal
; ------------------------------------------------------------
ORG 0000H
    MOV P1, #00H         ; start with P1 all low
BACK:   XRL P1, #0FFH    ; invert every bit of P1 (no CPL for a whole port)
        ACALL DELAY
        SJMP BACK

; ---- DELAY: about 50.3 ms (nested DJNZ) ----
DELAY:  MOV R1, #100
D1:     MOV R2, #250
D2:     DJNZ R2, D2
        DJNZ R1, D1
        RET
END
; result: P1 toggles every ~50.3 ms; period ~100.6 ms -> ~9.9 Hz square wave on each pin
