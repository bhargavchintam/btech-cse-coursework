; Data transfer group demo: MOV, XCH, PUSH, POP
; Moves sample bytes between registers, internal RAM and the stack.
; Results end up in internal RAM 40H..45H so they can be checked.
ORG 0000H
    ; --- register / direct / indirect MOV ---
    MOV A, #25H       ; A = 25H  (immediate -> A)
    MOV R0, #40H      ; R0 points to RAM 40H
    MOV @R0, A        ; 40H = 25H   (indirect store)
    MOV R1, #12H      ; R1 = 12H
    MOV 41H, R1       ; 41H = 12H   (register -> direct)

    ; --- XCH swaps A with a register ---
    MOV A, #0AAH      ; A = AAH
    MOV B, A          ; B = AAH  (keep a copy)
    XCH A, R1         ; A <-> R1 : A = 12H, R1 = AAH
    MOV 42H, A        ; 42H = 12H
    MOV 43H, R1       ; 43H = AAH

    ; --- stack: PUSH grows UP, POP shrinks ---
    MOV SP, #4FH      ; stack top just above the result area
    MOV A, #33H
    PUSH ACC          ; SP->50H, 50H = 33H
    MOV A, #44H
    PUSH ACC          ; SP->51H, 51H = 44H
    POP 44H           ; 44H = 44H  (top popped first)
    POP 45H           ; 45H = 33H  (LIFO order)
HERE: SJMP HERE
END
; result: 40H=25H, 41H=12H, 42H=12H, 43H=AAH, 44H=44H, 45H=33H
