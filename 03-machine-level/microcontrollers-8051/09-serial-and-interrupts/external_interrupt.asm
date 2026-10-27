; External interrupt INT0 - edge triggered, ISR toggles a port pin
; Each falling edge on P3.2 (INT0) fires the ISR at 0003H, which complements P1.0.
; Main program does nothing but wait; all the work happens in the ISR.
ORG 0000H
    SJMP MAIN          ; jump over the interrupt vector area
; --- INT0 service routine sits at its vector 0003H ---
ORG 0003H
    CPL P1.0           ; toggle the LED / pin on each external edge
    RETI               ; return and re-enable the interrupt logic
; --- main program ---
ORG 0030H
MAIN:
    SETB IT0           ; IT0 = 1 -> INT0 is edge (falling-edge) triggered
    SETB EX0           ; enable external interrupt 0
    SETB EA            ; global interrupt enable
HERE:
    SJMP HERE          ; idle - wait for edges on INT0
END
; result: P1.0 complements once per HIGH->LOW edge on INT0 (P3.2). IT0=1 (edge),
;         IE = 81H (EA + EX0). Two edges -> P1.0 back to its start level.
