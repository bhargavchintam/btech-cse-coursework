; Immediate and register addressing demonstration
; Loads immediate data into the accumulator and a register, moves a value
; between registers through A, adds using register addressing, stores to RAM.
ORG 0000H
    MOV A, #25H       ; immediate: the 25H is inside the instruction
    MOV R0, #1AH      ; immediate: load 1AH into R0
    MOV R1, A         ; register: keep a copy of 25H in R1
    ADD A, R0         ; register: A = A + R0 = 25H + 1AH = 3FH
    MOV 40H, A        ; store the sum in internal RAM 40H
    MOV A, R1         ; register: bring the saved 25H back into A
    MOV 41H, A        ; store the original operand in 41H
HERE: SJMP HERE
END
; result: 40H = 3FH (25H + 1AH), 41H = 25H
