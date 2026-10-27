; ---------------------------------------------------------------
; EXCHANGE TWO BLOCKS OF MEMORY
; Swap block-1 (30H..34H) with block-2 (40H..44H) byte by byte.
; R0 points into block-1, R1 into block-2. XCH swaps A with the
; block-2 byte, then A is written back into block-1.
; ---------------------------------------------------------------
ORG 0000H

; -- preload both blocks so the exchange is testable --
        MOV 30H, #11H
        MOV 31H, #22H
        MOV 32H, #33H
        MOV 33H, #44H
        MOV 34H, #55H

        MOV 40H, #0AAH
        MOV 41H, #0BBH
        MOV 42H, #0CCH
        MOV 43H, #0DDH
        MOV 44H, #0EEH

        MOV R0, #30H         ; block-1 pointer
        MOV R1, #40H         ; block-2 pointer
        MOV R2, #05H         ; byte count
LOOP:   MOV A, @R0           ; A = block-1 byte
        XCH A, @R1           ; A = block-2 byte, block-2 <- block-1 byte
        MOV @R0, A           ; block-1 <- old block-2 byte
        INC R0
        INC R1
        DJNZ R2, LOOP
HERE:   SJMP HERE
END
; result: 30H..34H = AAH BBH CCH DDH EEH,  40H..44H = 11H 22H 33H 44H 55H
