; ---------------------------------------------------------------
; EXTERNAL INTERRUPT INT0 toggling an LED on P1.0
; INT0 is set edge-triggered (IT0 = 1) so one pulse on P3.2 gives
; exactly one interrupt. IE = 81H enables EA + EX0. The ISR sits at
; the INT0 vector 0003H and complements P1.0 each time.
; ---------------------------------------------------------------
ORG 0000H
        SJMP MAIN            ; step over the interrupt vector

; --- INT0 service routine at vector 0003H ---
ORG 0003H
        CPL P1.0             ; toggle the LED on each falling edge
        RETI                 ; RETI, not RET, to end an ISR

ORG 0030H                    ; main starts past the vector area
MAIN:   SETB IT0             ; INT0 edge-triggered (falling edge)
        MOV IE, #81H         ; EA = 1, EX0 = 1  (enable external 0)
        CLR P1.0             ; start with the LED off
BACK:   SJMP BACK            ; idle; the ISR does all the work
END
; result: each falling edge on INT0 (P3.2) toggles P1.0;
;         LED off -> on -> off ... one flip per pulse
