; Serial receive - read a byte by polling RI, then echo it back out TXD
; Same 9600 baud, mode 1 setup. Byte in comes on RXD (P3.0), goes back on TXD (P3.1).
; Bindu Bhargava  22-01-19
ORG 0000H
; --- serial port init ---
    MOV TMOD, #20H     ; Timer 1, mode 2 for the baud clock
    MOV TH1, #0FDH     ; 9600 baud @ 11.0592 MHz
    MOV SCON, #50H     ; mode 1, REN = 1 so bytes can be received
    SETB TR1           ; start Timer 1
; --- receive then echo, forever ---
AGAIN:
    JNB RI, $          ; wait here until a byte has fully arrived (RI = 1)
    MOV A, SBUF        ; read the received byte
    CLR RI             ; clear RI for the next byte
    MOV 40H, A         ; keep a copy in RAM for inspection
;   MOV P1, A          ; (was also showing the byte on P1 while testing)
    MOV SBUF, A        ; echo the same byte back
    JNB TI, $          ; wait until it has gone out
    CLR TI             ; clear TI
    SJMP AGAIN         ; back for the next byte
END
; result: each byte received on RXD is copied to 40H and echoed back on TXD unchanged
;         (e.g. send 41H 'A' -> 40H = 41H and 'A' is transmitted back).
