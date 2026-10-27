# Experiment 3 — 8-bit Multiplication and Division

**Date:** 14/12/2018

## Aim
Write an 8051 assembly language program to multiply two 8-bit numbers
and to divide one 8-bit number by another, using the `MUL` and `DIV`
instructions.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. **Multiplication:** load the multiplicand into A and the multiplier
   into B. Execute `MUL AB`. The 16-bit product is returned in B:A,
   with B the high byte and A the low byte. Store both bytes.
2. **Division:** load the dividend into A and the divisor into B.
   Execute `DIV AB`. Afterwards A holds the quotient and B holds the
   remainder. Store both bytes.
3. Halt.

## Program
`mul_div.asm` — multiplies 37H × 2AH with `MUL AB` and divides FBH ÷ 0CH
with `DIV AB`, storing product and quotient/remainder in internal RAM.

## Result
| Operation      | Inputs      | Location | Value | Meaning        |
| -------------- | ----------- | -------- | ----- | -------------- |
| Multiplication | 37H × 2AH   | 40H      | 06H   | product low    |
|                |             | 41H      | 09H   | product high   |
| Division       | FBH ÷ 0CH   | 42H      | 14H   | quotient       |
|                |             | 43H      | 0BH   | remainder      |

37H × 2AH = 55 × 42 = 2310 = 0906H (low 06H, high 09H). FBH ÷ 0CH =
251 ÷ 12 = 20 remainder 11 (quotient 14H, remainder 0BH).
