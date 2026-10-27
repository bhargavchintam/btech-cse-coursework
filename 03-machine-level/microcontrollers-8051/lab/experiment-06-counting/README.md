# Experiment 6 — Counting Even and Odd Numbers in an Array

**Date:** 18/01/2019

## Aim
Write an 8051 assembly program to count how many numbers in a given array are
even and how many are odd, and store the two counts in internal RAM.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Load the array of 10 bytes into internal RAM starting at 40H.
2. Point R0 at the array, set R2 = 0AH (count of bytes), clear the even tally R3
   and the odd tally R4.
3. Fetch a byte into A and rotate it right through carry (RRC A) so bit0 moves
   into the carry flag.
4. If C = 1 the number is odd, so increment R4; otherwise it is even, so
   increment R3.
5. Advance the pointer and decrement R2; repeat from step 3 until R2 = 0.
6. Store the even count in 50H and the odd count in 51H. Halt.

## Program
`counting.asm` — counts even and odd bytes using RRC to test bit0.

## Result
Array (40H..49H): 22H 15H 30H 07H 44H 0AH 11H 08H 63H 50H

Even numbers (LSB = 0): 22H, 30H, 44H, 0AH, 08H, 50H → 6
Odd numbers (LSB = 1): 15H, 07H, 11H, 63H → 4

| Location | Value | Meaning |
| -------- | ----- | ------- |
| 50H      | 06H   | count of even numbers |
| 51H      | 04H   | count of odd numbers  |

The two counts sum to 10, the array length.
