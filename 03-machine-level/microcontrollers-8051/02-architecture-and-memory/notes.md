# Unit 2 — 8051 Architecture and Memory Organization

The 8051 is a single-chip microcontroller: CPU, ROM, RAM, timers, serial port and
four I/O ports all on one 40-pin package. This unit is the one examiners lean on for
the pinout, the internal RAM map and the register-bank/PSW arithmetic. Get the memory
map straight and half the paper writes itself.

## The 40-pin DIP, by function group

The standard 8051/8031 comes in a 40-pin dual-in-line package. Grouped by what the
pins actually do:

| Group | Pins | Function |
|-------|------|----------|
| Power | Vcc (40), Vss (20) | +5 V supply and ground |
| Oscillator | XTAL1 (19), XTAL2 (18) | crystal across these two; 11.0592 MHz is the usual value |
| Reset | RST (9) | active-HIGH reset; hold high ≥ 2 machine cycles |
| Port 0 | P0.0–P0.7 (39–32) | 8-bit open-drain I/O; needs pull-ups. Doubles as AD0–AD7 (multiplexed low address + data) for external memory |
| Port 1 | P1.0–P1.7 (1–8) | plain 8-bit I/O, no alternate function |
| Port 2 | P2.0–P2.7 (21–28) | 8-bit I/O; doubles as A8–A15 (high address byte) for external memory |
| Port 3 | P3.0–P3.7 (10–17) | 8-bit I/O with alternate functions (see below) |
| Control | EA (31), PSEN (29), ALE (30) | external-access, program-store-enable, address-latch-enable |

Port 3's alternate functions are worth memorising — a favourite one-mark question:

| Pin | Alt. function | Meaning |
|-----|---------------|---------|
| P3.0 | RXD | serial receive |
| P3.1 | TXD | serial transmit |
| P3.2 | INT0 | external interrupt 0 |
| P3.3 | INT1 | external interrupt 1 |
| P3.4 | T0 | timer 0 external input |
| P3.5 | T1 | timer 1 external input |
| P3.6 | WR | external data-memory write strobe |
| P3.7 | RD | external data-memory read strobe |

The three control pins:
- **EA (External Access)** — tie HIGH to run code from on-chip ROM first, LOW to force
  all fetches from external memory. On the ROM-less 8031, EA is permanently grounded.
- **PSEN (Program Store Enable)** — the read strobe for *external program* memory (code).
  Active low, pulsed on every external code fetch.
- **ALE (Address Latch Enable)** — latches the low address byte out of P0 into an
  external latch (74LS373) so P0 can then carry data. Also runs at 1/6 of the crystal
  frequency, usable as an external clock.

> Sir's trap: PSEN reads *code*, RD reads *data*. Two different strobes, two different
> memory spaces. Mixing them up cost marks in IA1.

## Program memory vs data memory

The 8051 keeps code and data in **separate address spaces** (Harvard architecture).

**Program (code) memory** — where instructions live:
- On-chip: 4 KB of ROM, addresses 0000H–0FFFH.
- External: up to 64 KB total, addresses 0000H–FFFFH.
- With EA = 1 the CPU runs 0000H–0FFFH from internal ROM, then automatically fetches
  1000H–FFFFH from external ROM. With EA = 0 everything comes from external ROM.
- Fetched using PSEN. Read only.

**Data memory** — where variables live:
- Internal: 128 bytes of RAM (00H–7FH) on the 8051, plus the SFRs at 80H–FFH.
- External: up to 64 KB, addresses 0000H–FFFFH, reached only with the `MOVX`
  instruction (`MOVX A, @DPTR` / `MOVX @DPTR, A`), strobed by RD and WR.

Because they are separate spaces, address 0000H of code and 0000H of external data are
two different physical bytes. `MOVC` reads code space, `MOVX` reads external data space.

## Internal RAM organization (00H–7FH)

The 128 bytes of on-chip RAM split into three regions:

| Address range | Size | Purpose |
|---------------|------|---------|
| 00H–1FH | 32 bytes | four register banks (Bank 0–3), R0–R7 each |
| 20H–2FH | 16 bytes | bit-addressable area — 128 individually addressable bits, bit addresses 00H–7FH |
| 30H–7FH | 80 bytes | general-purpose scratchpad; also the default stack area |

16 bytes × 8 bits = 128 bits, so the bit-addressable block gives exactly bit addresses
00H through 7FH. The scratchpad from 30H up is what you use for arrays and results in
the lab programs (I store sums and sorted lists at 40H onwards).

## The four register banks

Addresses 00H–1FH are carved into four banks of eight registers (R0–R7). Only one bank
is "live" at a time; **RS1:RS0** in PSW pick it.

| Bank | RS1 | RS0 | Address range (R0–R7) |
|------|-----|-----|-----------------------|
| Bank 0 | 0 | 0 | 00H–07H |
| Bank 1 | 0 | 1 | 08H–0FH |
| Bank 2 | 1 | 0 | 10H–17H |
| Bank 3 | 1 | 1 | 18H–1FH |

On reset RS1:RS0 = 00, so Bank 0 is selected and R0 sits at 00H, R7 at 07H. Switching
bank is just two bit writes, e.g. `SETB RS0` selects Bank 1. A common use: keep the main
routine on Bank 0 and give an interrupt service routine its own bank so registers don't
have to be pushed.

> Remember: selecting a bank does NOT copy anything. It only re-points R0–R7 at a
> different 8-byte slice of RAM. The old bank's bytes are still sitting there.

## PSW — Program Status Word

PSW is an 8-bit SFR at address D0H. It is bit-addressable. Layout:

| Bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|-----|---|---|---|---|---|---|---|---|
| Name | CY | AC | F0 | RS1 | RS0 | OV | — | P |
| Bit address | D7H | D6H | D5H | D4H | D3H | D2H | D1H | D0H |

- **CY** — carry flag; set by an arithmetic carry/borrow out of bit 7, and by many
  logical/rotate instructions.
- **AC** — auxiliary carry; carry out of bit 3, used by DA A for BCD arithmetic.
- **F0** — a free user flag, general purpose.
- **RS1:RS0** — register-bank select (table above).
- **OV** — signed overflow flag.
- **P** — parity of the accumulator; P = 1 when A holds an odd number of 1s. Hardware
  keeps this updated after every instruction that changes A.
- Bit 1 (PSW.1) is unused/reserved.

## Bit-addressable memory — worked example

Bytes 20H–2FH are the bit-addressable RAM. To find the bit address of a given bit:

```
bit address = (byte_address − 20H) × 8 + bit_number
```

**Which bit address is bit 3 of byte 22H?**
(22H − 20H) × 8 + 3 = 2 × 8 + 3 = 19 = 13H.
**Ans: 13H.** (verified in python3: `(0x22-0x20)*8+3 = 0x13`)

Sanity-check the endpoints the same way: bit 0 of 20H is (0)×8+0 = 00H, and bit 7 of
2FH is 15×8+7 = 127 = 7FH — exactly the 00H–7FH range claimed above.

## SFR map — the addresses to know

The Special Function Registers occupy 80H–FFH. The ones on the syllabus:

| SFR | Address | SFR | Address |
|-----|---------|-----|---------|
| P0 | 80H | P2 | A0H |
| SP | 81H | IE | A8H |
| DPL | 82H | P3 | B0H |
| DPH | 83H | IP | B8H |
| PCON | 87H | PSW | D0H |
| TCON | 88H | A (ACC) | E0H |
| TMOD | 89H | B | F0H |
| TL0 | 8AH | SCON | 98H |
| TL1 | 8BH | SBUF | 99H |
| TH0 | 8CH | P1 | 90H |
| TH1 | 8DH | | |

The SFRs whose address is a multiple of 8 are also **bit-addressable**: P0 (80H),
TCON (88H), P1 (90H), SCON (98H), P2 (A0H), IE (A8H), P3 (B0H), IP (B8H), PSW (D0H),
ACC (E0H) and B (F0H). The rest (SP, DPL, DPH, PCON, TMOD, the timer count registers,
SBUF) are byte-only.

## The stack

The stack lives in internal RAM and is tracked by the **Stack Pointer (SP)** at 81H.

- On reset SP = **07H**. That means the first PUSH writes to 08H — the start of Bank 1.
  So if you intend to use the stack heavily, move it up into the scratchpad first, e.g.
  `MOV SP, #2FH`, to avoid clobbering the register banks.
- The 8051 stack **grows UP** (toward higher addresses), the opposite of the x86.
- **PUSH first increments SP, then stores**: SP ← SP+1, then RAM[SP] ← data.
- **POP first reads, then decrements**: data ← RAM[SP], then SP ← SP−1.

> Sir said: on the 8051 the stack grows UP, not down. Classic exam trap — draw the
> arrow pointing up.

## Solved numericals

**1. Bit address.** Find the bit address of bit 5 of byte 2AH.
(2AH − 20H) × 8 + 5 = 10 × 8 + 5 = 85 = 55H.
**Ans: 55H.** (python3: `(0x2A-0x20)*8+5 = 0x55`)

**2. Which bank?** Register R2 is being accessed and the CPU reads RAM location 12H.
Which register bank is selected, and what are RS1:RS0?
12H falls in the 10H–17H range, and 12H = bank_base(10H) + 2, i.e. R2 of that bank.
That range is **Bank 2**, so RS1:RS0 = **10**.
**Ans: Bank 2, RS1:RS0 = 10.**

**3. SFR address / reverse bit lookup.** (a) State the address of TMOD. (b) Bit address
4FH belongs to which byte and which bit of the bit-addressable RAM?
(a) TMOD = **89H** (byte-only, not bit-addressable).
(b) 4FH = 79. byte = 20H + 79÷8 = 20H + 9 = 29H; bit = 79 mod 8 = 7.
**Ans: (a) 89H. (b) bit 7 of byte 29H.** (python3: `0x20+79//8 = 0x29`, `79%8 = 7`)
