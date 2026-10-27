# 8051 Quick Reference — one-page revision sheet

12 MHz crystal → machine cycle = 1 µs (÷12). Serial/baud math uses 11.0592 MHz.
Hex literals in Keil take an H suffix and a leading 0 if they start with a letter (`0FFH`).

## SFR address map

| SFR | Addr | Bit-addr | SFR | Addr | Bit-addr |
|-----|------|----------|-----|------|----------|
| P0  | 80H | yes | P1  | 90H | yes |
| SP  | 81H | no  | SCON| 98H | yes |
| DPL | 82H | no  | SBUF| 99H | no  |
| DPH | 83H | no  | P2  | A0H | yes |
| PCON| 87H | no  | IE  | A8H | yes |
| TCON| 88H | yes | P3  | B0H | yes |
| TMOD| 89H | no  | IP  | B8H | yes |
| TL0 | 8AH | no  | PSW | D0H | yes |
| TL1 | 8BH | no  | ACC | E0H | yes |
| TH0 | 8CH | no  | B   | F0H | yes |
| TH1 | 8DH | no  |     |     |     |

An SFR is bit-addressable exactly when its address ends in 0 or 8 (a multiple of 8).

## Internal RAM (00H–7FH, 128 bytes)

| Range | Size | Use |
|-------|------|-----|
| 00H–1FH | 32 B | four register banks, R0–R7 each |
| 20H–2FH | 16 B | bit-addressable, bit addresses 00H–7FH |
| 30H–7FH | 80 B | scratchpad + default stack |

bit address = (byte − 20H) × 8 + bit_no. Store lab results at 40H onward.

## Register banks

| Bank | RS1 | RS0 | R0–R7 |
|------|-----|-----|-------|
| 0 | 0 | 0 | 00H–07H |
| 1 | 0 | 1 | 08H–0FH |
| 2 | 1 | 0 | 10H–17H |
| 3 | 1 | 1 | 18H–1FH |

Reset → Bank 0. `SETB RS0`/`SETB RS1` switch; selecting a bank only re-points R0–R7.

## PSW (D0H, bit-addressable)

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|-----|---|---|---|---|---|---|---|---|
| Name | CY | AC | F0 | RS1 | RS0 | OV | — | P |
| Bit addr | D7H | D6H | D5H | D4H | D3H | D2H | D1H | D0H |

CY carry/borrow out of bit7 · AC half-carry out of bit3 (feeds DA A) · F0 user flag ·
OV signed overflow · P = 1 when A has an odd number of 1s (hardware-maintained) · PSW.1 unused.

## TMOD (89H, byte-only) — upper nibble Timer1, lower nibble Timer0

| Bit | 7/3 | 6/2 | 5/1 | 4/0 |
|-----|-----|-----|-----|-----|
| Name | GATE | C/T | M1 | M0 |
| Meaning | 1 = gated on INTx | 0 timer / 1 counter | mode hi | mode lo |

`MOV TMOD, #01H` = Timer0 mode1. `MOV TMOD, #20H` = Timer1 mode2 (baud). `MOV TMOD, #50H` = Timer1 counter, mode1.

## TCON (88H, bit-addressable)

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|-----|---|---|---|---|---|---|---|---|
| Name | TF1 | TR1 | TF0 | TR0 | IE1 | IT1 | IE0 | IT0 |

TFx overflow flag (HW sets, SW clears) · TRx run control · IEx external-int edge flag ·
ITx 0 = level / 1 = falling-edge triggered on INTx.

## Timer modes (M1 M0)

| M1 | M0 | Mode | Size | Note |
|----|----|------|------|------|
| 0 | 0 | 0 | 13-bit | TL(5)+TH(8), max 8192, legacy |
| 0 | 1 | 1 | 16-bit | max 65536, general delay |
| 1 | 0 | 2 | 8-bit auto-reload | TL counts, TH reloads it; used for baud |
| 1 | 1 | 3 | split | Timer0 → two 8-bit timers |

## Timer reload formula (12 MHz, 1 µs/count)

- Mode 1: reload = 65536 − count, TH = reload high byte, TL = low byte.
- Mode 2: reload = 256 − count, put in TH; TL reloads from TH each overflow.
- Delay in µs = count. Longer than 65.536 ms → repeat a fixed delay in a loop.

| Delay (mode1) | count | reload | TH | TL |
|------|------|------|----|----|
| 100 µs | 100 | FF9CH | FFH | 9CH |
| 500 µs | 500 | FE0CH | FEH | 0CH |
| 1 ms | 1000 | FC18H | FCH | 18H |
| 2 ms | 2000 | F830H | F8H | 30H |
| 5 ms | 5000 | EC78H | ECH | 78H |
| 10 ms | 10000 | D8F0H | D8H | F0H |
| 50 ms | 50000 | 3CB0H | 3CH | B0H |

1 s = 20 × 50 ms (20 × 50000 µs = 1 000 000 µs). Mode 2, 250 µs → reload 06H.

Poll delay: `MOV TMOD,#01H` / load TH0,TL0 / `SETB TR0` / `WAIT: JNB TF0,WAIT` / `CLR TR0` / `CLR TF0`.

## SCON (98H, bit-addressable)

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|-----|---|---|---|---|---|---|---|---|
| Name | SM0 | SM1 | SM2 | REN | TB8 | RB8 | TI | RI |

SM0:SM1 pick the serial mode (00 shift, **01 = mode1, 8-bit UART**, 10 mode2, 11 mode3).
REN = 1 enables reception · TB8/RB8 = 9th bit in modes 2/3 · TI transmit-done flag ·
RI receive-done flag. TI and RI are cleared by software. Mode 1 setup: `MOV SCON, #50H`.

### Baud rate — Timer1 mode 2, 11.0592 MHz, SMOD = 0

TH1 = 256 − ( crystal / (384 × baud) ). crystal/384 = 11059200/384 = 28800.

| Baud | 28800/baud | TH1 |
|------|-----------|-----|
| 1200 | 24 | E8H |
| 2400 | 12 | F4H |
| 4800 | 6 | FAH |
| 9600 | 3 | FDH |

19200 is non-integer at SMOD = 0; set SMOD = 1 (double baud) → TH1 = FDH.
Baud sequence: `MOV TMOD,#20H` / `MOV TH1,#0FDH` / `MOV SCON,#50H` / `SETB TR1`, then poll TI/RI.

## Interrupt vector table

| Source | Vector | Enable bit (IE) |
|--------|--------|-----------------|
| Reset | 0000H | — |
| INT0 (external 0) | 0003H | EX0 |
| Timer 0 | 000BH | ET0 |
| INT1 (external 1) | 0013H | EX1 |
| Timer 1 | 001BH | ET1 |
| Serial (TI/RI) | 0023H | ES |
| Timer 2 (8052) | 002BH | ET2 |

Vectors are 8 bytes apart. IE.7 = EA is the global enable — set EA last, e.g. `MOV IE, #82H` enables Timer0 (`EA + ET0`).
IP sets priority (1 = high). Reset SP = 07H; stack grows UP.

## Addressing modes

| Mode | Example | Operand is |
|------|---------|-----------|
| Immediate | `MOV A, #25H` | constant in the instruction (needs #) |
| Register | `MOV A, R2` | contents of R2 (current bank) |
| Direct | `MOV A, 40H` | contents of address 40H (also SFRs) |
| Register-indirect | `MOV A, @R0` | contents of the address held in R0 (R0/R1/DPTR only) |
| Indexed | `MOVC A, @A+DPTR` | code byte at DPTR + A (table lookup) |

`MOV R1, R2` does not exist. SFRs are reachable only by direct addressing.

## Instruction groups

| Group | Examples |
|-------|----------|
| Data transfer | MOV, MOVC, MOVX, PUSH, POP, XCH, XCHD |
| Arithmetic | ADD, ADDC, SUBB, INC, DEC, MUL AB, DIV AB, DA A |
| Logical | ANL, ORL, XRL, CLR A, CPL A, RL, RLC, RR, RRC, SWAP |
| Boolean (bit) | SETB, CLR, CPL, MOV C, ANL C, ORL C, JC, JNC, JB, JNB |
| Branch | SJMP, LJMP, AJMP, JMP @A+DPTR, ACALL, LCALL, RET, RETI, DJNZ, CJNE, JZ, JNZ |

`MUL AB` → product B:A (high:low), OV set if > 255, CY = 0.
`DIV AB` → A = quotient, B = remainder, OV set on ÷0.
`SUBB` always subtracts CY, so `CLR C` before the first byte. `DA A` only follows ADD/ADDC.

## Seven-segment codes (common cathode, dp off)

Byte layout bit0=a, bit1=b, … bit6=g, bit7=dp. Segment ON = 1.

| Digit | Segments on | Code |
|-------|-------------|------|
| 0 | a b c d e f | 3FH |
| 1 | b c | 06H |
| 2 | a b d e g | 5BH |
| 3 | a b c d g | 4FH |
| 4 | b c f g | 66H |
| 5 | a c d f g | 6DH |
| 6 | a c d e f g | 7DH |
| 7 | a b c | 07H |
| 8 | a b c d e f g | 7FH |
| 9 | a b c d f g | 6FH |

`DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH` — read with `MOVC A, @A+DPTR`.
Common anode = bit-complement: `DB 0C0H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,90H`.
