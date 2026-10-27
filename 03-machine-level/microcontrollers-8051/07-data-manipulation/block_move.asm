; ---------------------------------------------------------------
; BLOCK MOVE
; Move a block of 8 bytes from source (30H..37H) to
; destination (40H..47H) in internal RAM using pointers.
; Bindu Bhargava  18-12-18
; ---------------------------------------------------------------
ORG 0000H

; set up the source block first
        MOV 30H, #11H
        MOV 31H, #22H
        MOV 32H, #33H
        MOV 33H, #44H
        MOV 34H, #55H
        MOV 35H, #66H
        MOV 36H, #77H
        MOV 37H, #88H

        MOV R0, #30H         ; source pointer
        MOV R1, #40H         ; destination pointer
        MOV R2, #08H         ; byte count
LOOP:   MOV A, @R0           ; get a byte from source
        MOV @R1, A           ; put it at destination
        INC R0
        INC R1
        DJNZ R2, LOOP
HERE:   SJMP HERE
END
; result: 40H..47H = 11H 22H 33H 44H 55H 66H 77H 88H (copy of 30H..37H)
