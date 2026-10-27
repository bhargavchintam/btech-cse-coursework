# Experiment 4 — Largest and Smallest in an Array

**Date:** 04/01/2019

## Aim
Write an 8051 assembly language program to find the largest and the
smallest element in an array of bytes stored in internal RAM.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Store the array of N bytes starting at 40H.
2. **Largest:** point R0 at the array and load the first element into A
   as the initial maximum. For each remaining element, compare it with A
   using `CJNE` (which sets CY when A < element). If CY = 1 the element
   is larger, so copy it into A. After N−1 comparisons A holds the
   largest; store it at 50H.
3. **Smallest:** repeat the scan from the start, but keep the minimum:
   when CY = 0 (A > element) copy the element into A. After the scan A
   holds the smallest; store it at 51H.
4. Halt.

## Program
`largest_smallest.asm` — scans the 8-byte array at 40H–47H twice, once
for the maximum (to 50H) and once for the minimum (to 51H), using `CJNE`
and the carry flag.

## Result
Array at 40H–47H: 3AH 91H 17H FEH 4CH 08H A3H 62H

| Location | Value | Meaning  |
| -------- | ----- | -------- |
| 50H      | FEH   | largest  |
| 51H      | 08H   | smallest |

In decimal the array is 58, 145, 23, 254, 76, 8, 163, 98; the largest is
254 (FEH) and the smallest is 8 (08H).
