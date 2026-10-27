# Experiment 9 — Square Wave Generation using Timer0

**Date:** 08/02/2019

## Aim
Write an 8051 assembly program to generate a square wave on port pin P1.0 using
a Timer0 delay, and state the resulting frequency and the timer reload value.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Set TMOD = 01H to run Timer0 in mode 1 (16-bit timer).
2. Complement P1.0 to change the output level.
3. Call a delay routine that holds the level for one half-period.
4. Repeat forever, so P1.0 keeps toggling.
5. Delay: load TH0:TL0 with the reload value, set TR0 to start the timer, poll
   TF0 until it overflows, then clear TR0 and TF0 and return.

## Program
`square_wave.asm` — toggles P1.0 with a Timer0 mode-1 half-period delay.

## Result
Crystal 12 MHz → 1 machine cycle = 1 µs. For a 1 ms (1000 µs) half-period the
reload count is 65536 − 1000 = 64536 = 0FC18H, so TH0 = 0FCH and TL0 = 18H.
Full period = 2 ms → frequency = 500 Hz.

| Item | Value |
| ---- | ----- |
| Half-period | 1 ms (1000 µs) |
| Reload value (TH0:TL0) | 0FC18H (TH0 = 0FCH, TL0 = 18H) |
| Full period | 2 ms |
| Output frequency at P1.0 | 500 Hz |

Observed on the simulator: P1.0 produces a continuous 500 Hz square wave, high
for 1 ms and low for 1 ms.
