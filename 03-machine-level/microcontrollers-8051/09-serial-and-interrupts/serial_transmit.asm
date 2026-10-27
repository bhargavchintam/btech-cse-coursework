; Serial transmission - send a string over the UART by polling TI
; Timer 1 mode 2 for 9600 baud @ 11.0592 MHz (TH1 = 0FDH), mode 1, 8-bit UART.
; Transmits the null-terminated string "HI" out of TXD (P3.1).
ORG 0000H
; --- serial port init ---
    MOV TMOD, #20H     ; Timer 1, mode 2 (8-bit auto-reload) for baud clock
    MOV TH1, #0FDH     ; reload -> 9600 baud (256 - 11059200/(384*9600) = 253)
    MOV SCON, #50H     ; serial mode 1, REN = 1
    SETB TR1           ; start Timer 1 generating the baud clock
; --- transmit the string ---
    MOV DPTR, #MSG     ; DPTR -> message table
NEXT:
    CLR A
    MOVC A, @A+DPTR    ; fetch next character from code memory
    JZ DONE            ; 00H terminator -> finished
    MOV SBUF, A        ; load char -> transmission starts
WAIT:
    JNB TI, WAIT       ; poll until the byte has fully gone out
    CLR TI             ; clear TI by hand for the next character
    INC DPTR
    SJMP NEXT
DONE:
    SJMP DONE          ; park here
MSG: DB 'H', 'I', 00H
END
; result: 'H' (48H) then 'I' (49H) shifted out of TXD at 9600 baud,
;         each framed with 1 start + 8 data + 1 stop bit; TI set/cleared per byte.
