; ------------------------------------------------------------
; DELAY subroutine (nested DJNZ), called twice
; 8051, 12 MHz crystal -> 1 machine cycle = 1 us
; Bindu Bhargava  18-12-18
; ------------------------------------------------------------
ORG 0000H
    ACALL DELAY          ; first delay
    ACALL DELAY          ; second delay
HERE: SJMP HERE          ; stop here

; ---- DELAY: about 50.3 ms ----
; MOV R1 = 1 cycle ; inner DJNZ runs 250 times = 500 cycles
; per outer pass = MOV R2(1) + inner(500) + DJNZ R1(2) = 503
; body = 1 + 100*503 = 50301 ; + RET(2) = 50303 us = 50.303 ms
DELAY:  MOV R1, #100
BACK:   MOV R2, #250
INLOOP: DJNZ R2, INLOOP
        DJNZ R1, BACK
        RET
END
; result: DELAY = 50303 us (~50.3 ms) each, so ~100.6 ms of total delay before halt
