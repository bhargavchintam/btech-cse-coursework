# Experiment 12 — LED Blinking

**Date:** 05/03/2019

## Aim
Interface eight LEDs to port 1 of the 8051 and blink them on and off at roughly
1 Hz using embedded C and a software delay.

## Tools
Keil µVision 4 / SDCC.

## Algorithm
1. Include the 8051 header so the port SFRs are available.
2. Write a `delay()` routine that spins an inner `for` loop the given number of times.
3. In `main`, loop forever:
   a. Drive P1 = 00H so the port sinks current and the active-low LEDs turn on.
   b. Call `delay()` to hold that state for about half a second.
   c. Drive P1 = FFH so all LEDs turn off.
   d. Call `delay()` again for the other half of the period.

## Program
`led_blink.c` — blinks all eight LEDs on P1 with a software delay.

## Result
The LEDs are wired active-low (common anode to Vcc, cathodes to P1 through
resistors), so P1 = 00H lights them and P1 = FFH clears them. With the delay
loop tuned to about 500 ms per half cycle the eight LEDs turn on together, stay
on, then turn off together at a visible rate.

| Location | Value | Effect        |
| P1       | 00H   | all LEDs on   |
| P1       | FFH   | all LEDs off  |

Observed behaviour: P1 LEDs toggle at ~1 Hz.
