; ------------------------------------------------------------
; Copy a block of 5 bytes from 30H..34H to 40H..44H
; Source pointer in R0, destination pointer in R1, count in R2
; @R0 / @R1 register-indirect addressing, DJNZ for the count
; ------------------------------------------------------------
ORG 0000H
; -- preload the source block so the copy is testable --
    MOV 30H, #11H
    MOV 31H, #22H
    MOV 32H, #33H
    MOV 33H, #44H
    MOV 34H, #55H

; -- copy loop --
    MOV R0, #30H         ; source start
    MOV R1, #40H         ; destination start
    MOV R2, #05H         ; 5 bytes to copy
LOOP:   MOV A, @R0       ; get a byte from source
        MOV @R1, A       ; put it in destination
        INC R0
        INC R1
        DJNZ R2, LOOP
    ;MOV A, R2           ; (was checking R2 here during testing)
HERE: SJMP HERE
END
; result: 40H=11H 41H=22H 42H=33H 43H=44H 44H=55H
