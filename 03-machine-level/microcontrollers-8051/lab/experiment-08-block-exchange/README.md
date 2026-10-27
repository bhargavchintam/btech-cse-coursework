# Experiment 8 — Exchange Two Blocks of Memory

**Date:** 01/02/2019

## Aim
Write an 8051 assembly program to exchange (swap) two blocks of five bytes each
in internal RAM.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Preload block-1 into 30H..34H (11H..55H) and block-2 into 40H..44H
   (AAH..EEH).
2. Point R0 at block-1, R1 at block-2, set R2 = 05H (byte count).
3. Load A with the block-1 byte (@R0).
4. XCH A, @R1 — this puts the block-2 byte into A and writes the block-1 byte
   into block-2.
5. MOV @R0, A — write the old block-2 byte (now in A) into block-1.
6. Advance both pointers, decrement R2 and repeat from step 3 until R2 = 0. Halt.

## Program
`block_exchange.asm` — swaps two 5-byte blocks byte by byte using XCH.

## Result
Before: 30H..34H = 11H 22H 33H 44H 55H, 40H..44H = AAH BBH CCH DDH EEH.
After the two blocks have traded contents:

| Location | Value | Location | Value |
| -------- | ----- | -------- | ----- |
| 30H      | AAH   | 40H      | 11H   |
| 31H      | BBH   | 41H      | 22H   |
| 32H      | CCH   | 42H      | 33H   |
| 33H      | DDH   | 43H      | 44H   |
| 34H      | EEH   | 44H      | 55H   |
