; Indexed addressing - table look-up with MOVC A, @A+DPTR
; A DB table holds the squares of 0..9. Look up the square of 5 and
; store it to internal RAM 40H.
ORG 0000H
    MOV DPTR, #SQTAB  ; DPTR = base address of the squares table
    MOV A, #05H       ; index = 5, we want the square of 5
    MOVC A, @A+DPTR   ; A = code byte at (DPTR + 5) = SQTAB[5] = 19H
;   MOV R7, A         ; (was keeping a copy in R7 while testing)
    MOV 40H, A        ; store the looked-up square to RAM 40H
HERE: SJMP HERE
SQTAB: DB 00H, 01H, 04H, 09H, 10H, 19H, 24H, 31H, 40H, 51H
END
; result: 40H = 19H (= 25 decimal, the square of 5)
