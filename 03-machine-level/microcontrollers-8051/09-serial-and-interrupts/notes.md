# Unit 9 — Serial Communication and Interrupts

Two features that turn the 8051 from a number cruncher into something that talks to
the outside world. The serial port sends and receives bytes one bit at a time over
two pins (TXD, RXD); interrupts let a hardware event grab the CPU without the program
having to sit in a polling loop. Both are exam-heavy: the baud calculation and the
vector table are almost guaranteed marks if you get the arithmetic right.

## The serial port hardware

The 8051 has one full-duplex UART. It uses two Port 3 pins:

| Pin | Signal | Function |
|-----|--------|----------|
| P3.0 | RXD | serial receive (data in) |
| P3.1 | TXD | serial transmit (data out) |

"Full duplex" means it can transmit and receive at the same time. The port is driven
by one SFR pair: **SBUF** (the data buffer, 99H) and **SCON** (the control register,
98H). SBUF is physically two registers sharing one address — writing SBUF loads the
transmit register, reading SBUF reads the receive register.

## SCON — Serial Control register (98H, bit-addressable)

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|-----|---|---|---|---|---|---|---|---|
| Name | SM0 | SM1 | SM2 | REN | TB8 | RB8 | TI | RI |

- **SM0, SM1** — serial mode select (the two bits pick modes 0–3, table below).
- **SM2** — multiprocessor-communication enable; in mode 1, leave it 0 for normal use.
- **REN** — receive enable. Must be set to 1 to let bytes be shifted in.
- **TB8** — the 9th transmit bit in modes 2 and 3. Unused in mode 1.
- **RB8** — the 9th received bit in modes 2/3; in mode 1 it catches the stop bit.
- **TI** — transmit interrupt flag. Hardware sets it when a byte has finished going
  out. **Software must clear it.**
- **RI** — receive interrupt flag. Hardware sets it when a byte has been fully
  received. **Software must clear it.**

> Sir's trap: TI and RI are set by hardware but cleared by YOU. Forget to clear TI
> and the next poll sees a stale flag and you transmit garbage timing. Lost marks in IA2.

For mode 1 with receive enabled, the usual init byte is `SCON = 50H`
(SM0=0, SM1=1 → mode 1; REN=1). Verified bit pattern: 0101 0000 = 50H.

## The four serial modes

| Mode | SM0 | SM1 | Type | Baud rate |
|------|-----|-----|------|-----------|
| 0 | 0 | 0 | 8-bit shift register | fixed, crystal/12 |
| 1 | 0 | 1 | 8-bit UART | variable (Timer 1) |
| 2 | 1 | 0 | 9-bit UART | fixed, crystal/32 or /64 |
| 3 | 1 | 1 | 9-bit UART | variable (Timer 1) |

**Mode 1** is the one used almost everywhere and the one this unit focuses on. A frame
is 10 bits: one start bit (0), the 8 data bits (LSB first), and one stop bit (1). The
baud rate is set by the Timer 1 overflow rate, so it is programmable. Modes 2 and 3
carry a 9th data bit (TB8/RB8), handy for a parity bit or for addressing slaves in a
multiprocessor setup.

## Baud rate generation — Timer 1, mode 2

To make a standard baud rate, Timer 1 is put in **mode 2** (8-bit auto-reload). It
overflows repeatedly; each overflow ticks the serial clock. The baud rate is:

```
baud = (2^SMOD / 32) × (Timer 1 overflow rate)
     = (2^SMOD / 32) × crystal / (12 × (256 − TH1))
```

With SMOD = 0 this collapses to the reload formula everyone memorises:

```
TH1 = 256 − ( crystal / (384 × baud) )        [384 = 32 × 12]
```

A crystal of **11.0592 MHz** is used precisely because it divides cleanly into the
common baud rates — 1.8432 MHz / 32 = 57600, which is an exact multiple of 9600, 4800,
2400, 1200… so the reload comes out to a whole number with zero error.

**Setup sequence for 9600 baud, mode 1:**
```
MOV TMOD, #20H    ; Timer 1, mode 2 (8-bit auto-reload)
MOV TH1, #0FDH    ; reload for 9600 baud @ 11.0592 MHz
MOV SCON, #50H    ; mode 1, REN=1
SETB TR1          ; start Timer 1
```

### Worked baud calculation — 9600 baud @ 11.0592 MHz

```
TH1 = 256 − 11059200 / (384 × 9600)
    = 256 − 11059200 / 3686400
    = 256 − 3
    = 253 = 0FDH
```
**Ans: TH1 = 0FDH.** (python3: `256 - 11059200/(384*9600) = 253` → 0xFD)

Standard reloads at 11.0592 MHz (all exact, SMOD = 0):

| Baud | crystal/(384×baud) | TH1 (dec) | TH1 (hex) |
|------|--------------------|-----------|-----------|
| 9600 | 3 | 253 | 0FDH |
| 4800 | 6 | 250 | 0FAH |
| 2400 | 12 | 244 | 0F4H |
| 1200 | 24 | 232 | 0E8H |

## Doubling the baud rate with SMOD (PCON)

**SMOD** is bit 7 of the **PCON** register (address 87H, byte-only, NOT bit-addressable).
Setting SMOD = 1 doubles the baud rate for the same TH1 (the 32 in the formula becomes
16). Because PCON is not bit-addressable, you set SMOD by OR-ing:

```
MOV A, PCON
SETB ACC.7        ; SMOD = 1
MOV PCON, A
```

With SMOD = 1, TH1 = 0FDH now gives 19200 baud instead of 9600 (double). Equivalently,
to get 9600 baud with SMOD = 1 you would reload TH1 = 0FAH.
(python3: `256 - 11059200/(192*9600) = 250` → 0xFA.)

## Polling transmit and receive

Without interrupts, you drive the port by watching TI and RI.

**Transmit one byte:**
```
MOV SBUF, A       ; load byte -> starts transmission
WAIT: JNB TI, WAIT  ; wait until TI = 1 (byte gone)
CLR TI            ; clear it by hand for next time
```

**Receive one byte:**
```
WAIT: JNB RI, WAIT  ; wait until RI = 1 (byte arrived)
MOV A, SBUF       ; read the received byte
CLR RI            ; clear for next time
```

The whole trick is: **the flag tells you the operation finished; you clear it so the
next one can be detected.** Transmitting a string is just this transmit loop run over
each character until a terminator (00H) is reached.

## Interrupts — the six sources

An interrupt suspends the main program, runs a service routine (ISR) at a fixed vector
address, and returns. The 8051 has five interrupt sources plus RESET; each has a fixed
vector in low code memory, spaced 8 bytes apart:

| Source | Trigger | Vector address |
|--------|---------|----------------|
| RESET | reset pin | 0000H |
| INT0 (external 0) | pin P3.2 | 0003H |
| TF0 (Timer 0 overflow) | Timer 0 rolls over | 000BH |
| INT1 (external 1) | pin P3.3 | 0013H |
| TF1 (Timer 1 overflow) | Timer 1 rolls over | 001BH |
| Serial (TI or RI) | byte sent/received | 0023H |

The 8-byte spacing (0003, 000B, 0013, 001B, 0023) is enough for a short ISR or a jump
to the real routine. RESET is not really an interrupt — it is where execution begins.

> Remember: the serial interrupt is ONE vector for both TI and RI. Inside the ISR you
> test which flag is set, then clear it. Timer/external flags are auto-cleared on entry;
> the serial flags are not.

## IE — Interrupt Enable register (A8H, bit-addressable)

Nothing fires unless it is enabled. IE is the master switchboard:

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|-----|---|---|---|---|---|---|---|---|
| Name | EA | — | — | ES | ET1 | EX1 | ET0 | EX0 |

- **EA** — global enable. If EA = 0, every interrupt is off regardless of the other
  bits. You must set EA to 1 for anything to work.
- **ES** — enable serial interrupt.
- **ET1 / ET0** — enable Timer 1 / Timer 0 overflow interrupt.
- **EX1 / EX0** — enable external interrupt 1 / 0.

Two ways to enable, e.g. external 0: `MOV IE, #81H` (EA + EX0 = 80H + 01H) or the
readable `SETB EX0` then `SETB EA`. To enable Timer 0: `MOV IE, #82H` (EA + ET0).

## IP — Interrupt Priority register (B8H, bit-addressable)

Each source can be given high (1) or low (0) priority. On reset IP = 00H, so all
sources are low priority and are then resolved by the fixed **polling order**:

```
INT0  >  TF0  >  INT1  >  TF1  >  serial
```

A high-priority interrupt can interrupt a low-priority ISR, but not vice versa, and a
source cannot interrupt another of the same priority. IP bits: PS(4), PT1(3), PX1(2),
PT0(1), PX0(0). Setting `SETB PX0` makes external 0 high priority so it jumps the queue.

## The interrupt sequence

When an enabled interrupt is granted, the hardware:
1. finishes the instruction currently executing,
2. pushes the **PC** (program counter, both bytes) onto the stack,
3. blocks further interrupts of equal/lower priority,
4. loads the PC with the source's **vector address** and runs the ISR,
5. on **RETI**, pops the PC back off the stack and resumes the main program.

Note it is **RETI**, not RET, that ends an ISR — RETI also restores the priority logic
so lower interrupts can fire again. Using RET leaves the interrupt system stuck.

## Edge vs level triggering — external interrupts

INT0 and INT1 can respond either to a level or to an edge, chosen by **IT0** (TCON.0)
and **IT1** (TCON.2):

| ITx | Trigger | Behaviour |
|-----|---------|-----------|
| 0 | level (low) | interrupt as long as the pin is held LOW |
| 1 | edge (falling) | interrupt on a HIGH-to-LOW transition only |

Edge-triggered (ITx = 1) is the usual choice — one clean pulse gives exactly one
interrupt. Level-triggered will re-fire continuously while the pin stays low, which can
retrigger the ISR if the signal is slow to release. The request is latched in **IE0**
(TCON.1) / **IE1** (TCON.3); in edge mode the hardware clears it on ISR entry.

## Solved numericals

**1. Baud reload for 4800 baud @ 11.0592 MHz.**
```
TH1 = 256 − 11059200 / (384 × 4800) = 256 − 6 = 250 = 0FAH
```
**Ans: TH1 = 0FAH.** (python3: `256 - 11059200/(384*4800) = 250` → 0xFA)

**2. Baud reload for 1200 baud @ 11.0592 MHz.**
```
TH1 = 256 − 11059200 / (384 × 1200) = 256 − 24 = 232 = 0E8H
```
**Ans: TH1 = 0E8H.** (python3: `256 - 11059200/(384*1200) = 232` → 0xE8)

**3. Vector address.** A program uses the Timer 0 overflow interrupt. At what code
address must its ISR (or a jump to it) be placed, and which IE bit enables it?
Timer 0 overflow (TF0) vectors to **000BH**; it is enabled by **ET0** (IE.1), which
needs EA set too, so `MOV IE, #82H`.
**Ans: 000BH, enabled by ET0 (with EA).**
