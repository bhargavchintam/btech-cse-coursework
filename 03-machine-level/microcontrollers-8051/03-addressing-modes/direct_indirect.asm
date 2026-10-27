; Direct and register-indirect addressing
; Bindu Bhargava  04-12-18
; Part 1: copy one byte 30H -> 40H using direct addressing.
; Part 2: copy a 4-byte block 30H..33H -> 50H..53H using @R0/@R1 indirect.
ORG 0000H
; --- set up the source data in RAM 30H..33H ---
    MOV 30H, #11H
    MOV 31H, #22H
    MOV 32H, #33H
    MOV 33H, #44H
; --- part 1: single byte copy, direct addressing ---
    MOV A, 30H        ; direct: read the byte at address 30H
    MOV 40H, A        ; direct: write it to address 40H
; --- part 2: block copy, register-indirect addressing ---
    MOV R0, #30H      ; R0 = source pointer
    MOV R1, #50H      ; R1 = destination pointer
    MOV R2, #04H      ; R2 = byte count
LOOP:
    MOV A, @R0        ; indirect: A = contents of address in R0
    MOV @R1, A        ; indirect: address in R1 gets A
    INC R0
    INC R1
    DJNZ R2, LOOP
HERE: SJMP HERE
END
; result: 40H = 11H; block 50H=11H, 51H=22H, 52H=33H, 53H=44H
