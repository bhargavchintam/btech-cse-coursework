; ---------------------------------------------------------------
; BLOCK DATA TRANSFER
; Transfer a block of N bytes from a source area (40H..) to a
; destination area (50H..) in internal RAM. R0 points to source,
; R1 to destination, R2 holds the byte count N.
; ---------------------------------------------------------------
ORG 0000H

; build the source block, N = 8 bytes
        MOV 40H, #25H
        MOV 41H, #12H
        MOV 42H, #0AH
        MOV 43H, #33H
        MOV 44H, #05H
        MOV 45H, #99H
        MOV 46H, #7FH
        MOV 47H, #88H

        MOV R0, #40H         ; source pointer
        MOV R1, #50H         ; destination pointer
        MOV R2, #08H         ; N bytes to move
LOOP:   MOV A, @R0           ; read a byte from source
        MOV @R1, A           ; write it to destination
        INC R0
        INC R1
        DJNZ R2, LOOP        ; repeat until count = 0
HERE:   SJMP HERE
END
; result: 50H..57H = 25H 12H 0AH 33H 05H 99H 7FH 88H (copy of 40H..47H)
