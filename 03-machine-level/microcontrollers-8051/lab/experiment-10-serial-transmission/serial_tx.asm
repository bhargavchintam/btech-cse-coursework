; ---------------------------------------------------------------
; SERIAL TRANSMISSION at 9600 baud by polling TI
; Timer1 mode 2 (8-bit auto-reload) makes the baud clock.
; @ 11.0592 MHz : TH1 = 256 - 11059200/(384*9600) = 256 - 3 = 253 = 0FDH
; SCON = 50H -> serial mode 1 (8-bit UART), REN = 1.
; Transmits the null-terminated string "REVA" out of TXD (P3.1).
; ---------------------------------------------------------------
ORG 0000H
; --- serial port init ---
        MOV TMOD, #20H       ; Timer1, mode 2 for the baud clock
        MOV TH1, #0FDH       ; reload -> 9600 baud
        MOV SCON, #50H       ; mode 1, REN = 1
        SETB TR1             ; start Timer1 generating the baud clock

; --- transmit the string ---
        MOV DPTR, #MSG       ; DPTR -> message table
NEXT:   CLR A
        MOVC A, @A+DPTR      ; fetch next character from code memory
        JZ  DONE             ; 00H terminator -> finished
        MOV SBUF, A          ; load char -> transmission starts
WAIT:   JNB TI, WAIT         ; poll until the byte has gone out
        CLR TI               ; clear TI by hand for the next character
        INC DPTR
        SJMP NEXT
DONE:   SJMP DONE            ; park here

MSG:    DB 'R', 'E', 'V', 'A', 00H
END
; result: 'R'(52H) 'E'(45H) 'V'(56H) 'A'(41H) shifted out of TXD at 9600 baud,
;         each framed with 1 start + 8 data + 1 stop bit; TI set/cleared per byte.
