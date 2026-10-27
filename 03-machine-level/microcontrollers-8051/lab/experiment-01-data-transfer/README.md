# Experiment 1 — Block Data Transfer

**Date:** 30/11/2018

## Aim
Write an 8051 assembly language program to transfer a block of N bytes
of data from one area of internal RAM to another area.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Initialise the source block at 40H onwards with N data bytes.
2. Load R0 with the source start address (40H) and R1 with the
   destination start address (50H).
3. Load R2 with the byte count N (08H).
4. Read the byte pointed to by R0 into A and store it at the location
   pointed to by R1.
5. Increment both pointers R0 and R1.
6. Decrement R2 with DJNZ; if it is not zero, repeat from step 4.
7. When R2 reaches zero the whole block has been copied. Halt.

## Program
`data_transfer.asm` — copies 8 bytes from the source block (40H–47H) to
the destination block (50H–57H) using pointer registers.

## Result
Input block placed at 40H–47H and the destination after the copy:

| Location | Value | Location | Value |
| -------- | ----- | -------- | ----- |
| 40H      | 25H   | 50H      | 25H   |
| 41H      | 12H   | 51H      | 12H   |
| 42H      | 0AH   | 52H      | 0AH   |
| 43H      | 33H   | 53H      | 33H   |
| 44H      | 05H   | 54H      | 05H   |
| 45H      | 99H   | 55H      | 99H   |
| 46H      | 7FH   | 56H      | 7FH   |
| 47H      | 88H   | 57H      | 88H   |

N = 8 bytes. The destination block 50H–57H holds an exact copy of the
source block 40H–47H.
