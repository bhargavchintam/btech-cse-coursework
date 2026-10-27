# Experiment 2 — Addition and Subtraction (8-bit and 16-bit)

**Date:** 07/12/2018

## Aim
Write an 8051 assembly language program to perform 8-bit and 16-bit
addition and subtraction of two numbers, preserving the carry after
addition and the borrow after subtraction.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. **8-bit addition:** load the first number in A, `ADD` the second.
   Any carry out sets CY, so add 00H + 00H with `ADDC` to capture the
   carry into a second byte.
2. **8-bit subtraction:** clear CY, load the minuend in A and `SUBB`
   the subtrahend. `SUBB` computes A − source − CY; the borrow appears
   in CY and is captured into a byte with `ADDC A,#00H`.
3. **16-bit addition:** add the low bytes with `ADD`, then the high
   bytes with `ADDC` so the carry from the low byte is included; a final
   `ADDC A,#00H` captures the overall carry.
4. **16-bit subtraction:** clear CY, `SUBB` the low bytes, then `SUBB`
   the high bytes (the borrow chains through CY); capture the final
   borrow.
5. Store each result and its carry/borrow byte in internal RAM. Halt.

## Program
`add_sub.asm` — 8-bit add (6AH+CFH), 8-bit subtract (64H−9FH), 16-bit
add (7A63H+9BD4H) and 16-bit subtract (7A63H−9BD4H), each with its
carry/borrow byte.

## Result
| Operation        | Inputs         | Location | Value |
| ---------------- | -------------- | -------- | ----- |
| 8-bit add        | 6AH + CFH      | 40H      | 39H   |
|                  |                | 41H      | 01H   |
| 8-bit subtract   | 64H − 9FH      | 42H      | C5H   |
|                  |                | 43H      | 01H   |
| 16-bit add       | 7A63H + 9BD4H  | 44H      | 37H   |
|                  |                | 45H      | 16H   |
|                  |                | 46H      | 01H   |
| 16-bit subtract  | 7A63H − 9BD4H  | 47H      | 8FH   |
|                  |                | 48H      | DEH   |
|                  |                | 49H      | 01H   |

8-bit: 6AH + CFH = 139H (sum 39H, carry 1); 64H − 9FH = C5H with borrow
1 (true value −3BH). 16-bit: 7A63H + 9BD4H = 11637H (low 37H, high 16H,
carry 1); 7A63H − 9BD4H = DE8FH with borrow 1 (negative result, two's
complement of −2171H).
