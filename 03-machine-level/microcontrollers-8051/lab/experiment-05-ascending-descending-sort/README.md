# Experiment 5 — Ascending and Descending Sort

**Date:** 11/01/2019

## Aim
Write an 8051 assembly language program to sort an array of bytes into
ascending order and into descending order using the bubble sort method.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Load the same input array into two areas: 40H–44H (to be sorted
   ascending) and 50H–54H (to be sorted descending).
2. **Bubble sort (ascending):** run N−1 passes. In each pass point R0
   at the start and compare each adjacent pair arr[j], arr[j+1] with
   `CJNE`. If arr[j] > arr[j+1] (carry clear) swap them with `XCH` so the
   smaller moves left. After all passes 40H–44H is in ascending order.
3. **Bubble sort (descending):** repeat on 50H–54H, but swap when
   arr[j] < arr[j+1] (carry set) so the larger moves left.
4. Halt.

## Program
`sort.asm` — bubble-sorts the 5-byte input twice: ascending into
40H–44H and descending into 50H–54H.

## Result
Input array: 42H 15H 7EH 03H 5CH

| Ascending (40H–44H) | Value | Descending (50H–54H) | Value |
| ------------------- | ----- | -------------------- | ----- |
| 40H                 | 03H   | 50H                  | 7EH   |
| 41H                 | 15H   | 51H                  | 5CH   |
| 42H                 | 42H   | 52H                  | 42H   |
| 43H                 | 5CH   | 53H                  | 15H   |
| 44H                 | 7EH   | 54H                  | 03H   |

In decimal the input is 66, 21, 126, 3, 92; ascending gives
3, 21, 66, 92, 126 and descending gives 126, 92, 66, 21, 3.
