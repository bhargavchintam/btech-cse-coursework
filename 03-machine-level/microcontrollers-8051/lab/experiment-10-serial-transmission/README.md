# Experiment 10 — Serial Transmission at 9600 Baud

**Date:** 15/02/2019

## Aim
Write an 8051 assembly program to transmit a string of characters over the
serial port (UART) at 9600 baud.

## Tools
Keil µVision 4, 8051 simulator.

## Algorithm
1. Set TMOD = 20H so Timer1 runs in mode 2 (8-bit auto-reload) to generate the
   baud clock.
2. Load TH1 = 0FDH for 9600 baud at an 11.0592 MHz crystal.
3. Set SCON = 50H for serial mode 1 (8-bit UART) with REN = 1, then set TR1 to
   start the baud clock.
4. Point DPTR at the message table in code memory.
5. Fetch the next character with MOVC A, @A+DPTR. If it is 00H, stop.
6. Move the character into SBUF to start transmission; poll TI until the byte
   has been sent, then clear TI.
7. Advance DPTR and repeat from step 5.

## Program
`serial_tx.asm` — transmits the string "REVA" out of TXD (P3.1) by polling TI.

## Result
At 11.0592 MHz, TH1 = 256 − 11059200/(384 × 9600) = 256 − 3 = 253 = 0FDH, which
gives exactly 9600 baud. Each character is framed as 1 start bit + 8 data bits +
1 stop bit.

| Character | ASCII (SBUF) |
| --------- | ------------ |
| 'R'       | 52H          |
| 'E'       | 45H          |
| 'V'       | 56H          |
| 'A'       | 41H          |

Observed on the simulator: the four bytes 52H 45H 56H 41H are shifted out of TXD
at 9600 baud, with TI setting after each byte and being cleared in software.
