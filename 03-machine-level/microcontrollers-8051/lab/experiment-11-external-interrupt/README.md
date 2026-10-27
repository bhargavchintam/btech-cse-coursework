# Experiment 11 — External Interrupt INT0 Toggling an LED

**Date:** 22/02/2019

## Aim
Write an 8051 assembly program that uses external interrupt INT0 to toggle an
LED connected to P1.0, with the interrupt service routine placed at the INT0
vector.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. At reset (0000H) jump over the vector area to the main routine.
2. Place the INT0 service routine at its fixed vector 0003H. The ISR complements
   P1.0 and returns with RETI.
3. In main, set IT0 = 1 so INT0 responds to a falling edge (one pulse = one
   interrupt).
4. Load IE = 81H to set EA (global enable) and EX0 (external interrupt 0).
5. Clear P1.0 so the LED starts off.
6. Sit in an idle loop; every falling edge on INT0 (P3.2) vectors to the ISR,
   which flips P1.0.

## Program
`ext_interrupt.asm` — edge-triggered INT0 with an ISR at 0003H that toggles
P1.0.

## Result
IE = 81H enables EA + EX0. IT0 = 1 selects edge triggering. Each falling edge on
INT0 runs the ISR once and complements P1.0.

| Event | P1.0 (LED) |
| ----- | ---------- |
| after reset | 0 (off) |
| 1st INT0 pulse | 1 (on) |
| 2nd INT0 pulse | 0 (off) |
| 3rd INT0 pulse | 1 (on) |

Observed on the simulator: P1.0 toggles once per INT0 pulse, so the LED changes
state on every falling edge applied to P3.2.
