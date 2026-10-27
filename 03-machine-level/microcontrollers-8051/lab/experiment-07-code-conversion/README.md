# Experiment 7 — Code Conversion: Hex to BCD and BCD to ASCII

**Date:** 25/01/2019

## Aim
Write 8051 assembly to perform two standard code conversions: convert a
hexadecimal (binary) byte to its BCD digits, and convert a packed BCD byte to
its two ASCII characters.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
Part 1 — hex (binary) to BCD, for the byte FFH (255):
1. Load A with FFH and B with 64H (100). DIV AB leaves the hundreds digit in A
   and the remainder in B.
2. Store the hundreds digit in 50H.
3. Move the remainder to A, load B with 0AH (10), DIV AB. The quotient is the
   tens digit and the remainder is the units digit.
4. Store tens in 51H and units in 52H.

Part 2 — BCD to ASCII, for the packed BCD byte 25H:
5. Copy 25H, SWAP the nibbles and mask with 0FH to isolate the high digit (2),
   OR with 30H to form ASCII '2', store in 53H.
6. Mask the original with 0FH to isolate the low digit (5), OR with 30H to form
   ASCII '5', store in 54H. Halt.

## Program
`code_conversion.asm` — hex→BCD by repeated DIV AB, BCD→ASCII by nibble
splitting and ORing with 30H.

## Result
FFH = 255 → BCD digits 2, 5, 5. 25H (BCD) → ASCII '2' '5' = 32H 35H.

| Location | Value | Meaning |
| -------- | ----- | ------- |
| 50H      | 02H   | hundreds digit of 255 |
| 51H      | 05H   | tens digit of 255     |
| 52H      | 05H   | units digit of 255    |
| 53H      | 32H   | ASCII '2'             |
| 54H      | 35H   | ASCII '5'             |
