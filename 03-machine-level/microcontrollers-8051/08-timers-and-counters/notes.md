# Unit 8 — Timers and Counters

The 8051 has two 16-bit timer/counters, **Timer0** and **Timer1**. Each is really a
pair of 8-bit registers — TH0/TL0 for Timer0, TH1/TL1 for Timer1 — that can be read
and written separately. The same hardware serves two jobs: as a **timer** it counts
machine cycles (so it measures elapsed time), and as a **counter** it counts pulses
arriving on an external pin. One bit, C/T, decides which.

On a 12 MHz crystal one machine cycle is 1 µs, so a timer clocked internally increments
once every microsecond. That single fact drives every delay calculation below.

> Sir said: the timer counts UP to FFFFH and rolls over to 0000H, setting the overflow
> flag. You always load `65536 − count`, never the count itself. Exam trap every year.

## The clock source

- **Timer mode (C/T = 0):** the register is fed from the on-chip oscillator ÷ 12. At
  12 MHz that is a 1 MHz tick → 1 µs per count. Used for delays and periods.
- **Counter mode (C/T = 1):** the register is fed from an external pin — **T0 = P3.4**
  for Timer0, **T1 = P3.5** for Timer1. It increments on the 1→0 (falling) edge of the
  pin. Used to count events (parts on a belt, revolutions, button presses).

## The timer SFRs and their addresses

All of these live in the SFR space (80H–FFH). Only TCON is bit-addressable among the
control registers here.

| SFR | Address | Bit-addressable | Purpose |
|-----|---------|-----------------|---------|
| TCON | 88H | yes | run/overflow flags + external-interrupt bits |
| TMOD | 89H | no  | gate/counter/mode select for both timers |
| TL0  | 8AH | no  | Timer0 low byte |
| TL1  | 8BH | no  | Timer1 low byte |
| TH0  | 8CH | no  | Timer0 high byte |
| TH1  | 8DH | no  | Timer1 high byte |

TMOD at 89H is not bit-addressable, so it is always written as a whole byte with a
`MOV TMOD, #..`. The run and flag bits sit in TCON, which is bit-addressable, so those
are set and tested by name.

## TMOD — the mode register (not bit-addressable)

TMOD is one byte: the upper nibble configures Timer1, the lower nibble Timer0. Same four
bits in each nibble.

| Bit | Timer1 | Timer0 | Name | Meaning |
|-----|--------|--------|------|---------|
| 7 / 3 | GATE | GATE | GATE | 1 = timer runs only while INTx pin is high AND TRx=1; 0 = TRx alone controls it |
| 6 / 2 | C/T  | C/T  | C/T  | 0 = timer (internal clock); 1 = counter (external pin) |
| 5 / 1 | M1   | M1   | M1   | mode select high bit |
| 4 / 0 | M0   | M0   | M0   | mode select low bit |

You write TMOD once at the start. Example: `MOV TMOD, #01H` → Timer0, GATE=0, C/T=0,
M1M0=01 (mode 1). `MOV TMOD, #50H` → Timer1 as a counter (C/T=1) in mode 1, Timer0 left
at 0. GATE is almost always 0; leave it 0 unless a program explicitly gates on INT0/INT1.

## The four modes (M1 M0)

| M1 | M0 | Mode | Timer size | Notes |
|----|----|------|-----------|-------|
| 0 | 0 | 0 | 13-bit | TL uses 5 bits + TH 8 bits; max count 8192. Legacy, rarely used |
| 0 | 1 | 1 | 16-bit | TH+TL full 16 bits; max count 65536. The workhorse for delays |
| 1 | 0 | 2 | 8-bit auto-reload | TL counts, TH holds the reload value, reloaded automatically on overflow |
| 1 | 1 | 3 | split | Timer0 splits into two independent 8-bit timers; Timer1 just holds its count |

Mode 1 for a general delay of any length up to 65.536 ms. Mode 2 for an exact repeating
period (no software reload, so no jitter) — this is what baud-rate generation uses. Mode 3
is a special case to squeeze a third timer out of the chip.

## TCON — the control register (bit-addressable)

The upper nibble runs the timers; the lower nibble belongs to the external interrupts.

| Bit | Name | Meaning |
|-----|------|---------|
| 7 | TF1 | Timer1 overflow flag — set by hardware on rollover, cleared by software (or by vectoring to the ISR) |
| 6 | TR1 | Timer1 run control — set to start, clear to stop |
| 5 | TF0 | Timer0 overflow flag |
| 4 | TR0 | Timer0 run control |
| 3 | IE1 | External interrupt 1 edge flag |
| 2 | IT1 | INT1 edge/level select |
| 1 | IE0 | External interrupt 0 edge flag |
| 0 | IT0 | INT0 edge/level select |

Because TCON is bit-addressable, you write `SETB TR0`, `CLR TR0`, `JNB TF0, WAIT`,
`CLR TF0` directly by bit name — no need to read-modify-write the whole byte.

## Generating a delay in mode 1

The recipe, every time:

1. Load TMOD to pick the timer and mode 1 (e.g. `MOV TMOD, #01H`).
2. Load TH and TL with the reload value = `65536 − count`, high byte to TH, low to TL.
3. `SETB TRx` to start the timer.
4. Poll the overflow flag: `WAIT: JNB TFx, WAIT` — spin until the timer rolls over.
5. `CLR TRx` to stop it, then `CLR TFx` so the flag is ready for next time.

The timer runs from the reload value up to FFFFH and then to 0000H; that last step sets
the flag. The number of counts is therefore exactly `65536 − reload`, and at 1 µs each,
the delay in µs equals that count.

Remember: you must clear TFx yourself when polling. It is only cleared automatically if
you use the timer interrupt. Forgetting it means the second delay returns instantly.

## Square-wave generation

A square wave is just a pin toggled at a fixed interval. Toggle the pin, wait one
half-period, toggle again, forever:

```
BACK:  CPL  P1.0        ; flip the level
       ACALL DELAY      ; wait one half-period
       SJMP BACK
```

If the delay is D µs, the pin is high for D and low for D, so the **period is 2D** and
the **frequency is 1 / (2D)**. A 500 µs delay gives a 1 ms period → 1 kHz.

## Auto-reload mode 2 for exact periods

In mode 2 only TL counts. TH holds a copy of the reload value. On overflow the hardware
copies TH back into TL in the same cycle — no software reload, no jitter, so the period
is exact. The trade-off is range: TL is 8 bits, so `reload = 256 − count` and the
maximum single period is 256 µs.

```
       MOV TMOD, #02H   ; Timer0, mode 2 (8-bit auto-reload)
       MOV TH0, #06H    ; reload value 06H -> count = 256 - 6 = 250 us
       MOV TL0, #06H    ; prime TL the same on the first run
       SETB TR0
```

This is exactly how Timer1 makes a serial baud rate: mode 2, TH1 set to a reload value,
and every overflow clocks the UART.

## Timer vs counter — using Timer1 to count events

Set C/T = 1 and the register counts falling edges on the pin instead of machine cycles.
Nothing else changes — the same TH/TL, TR, TF, and modes apply. To count pulses on T1
(P3.5):

```
       MOV TMOD, #50H   ; Timer1: C/T1 = 1 (counter), mode 1 (16-bit)
       MOV TL1, #00H    ; clear the count
       MOV TH1, #00H
       SETB TR1         ; enable — now every 1->0 edge on P3.5 bumps the count
```

The count then sits live in TH1:TL1 and can be copied out at any moment. There is no
timing math here: the register simply holds however many edges have arrived, and TF1
sets if it wraps past 65536.

| | Timer | Counter |
|--|-------|---------|
| C/T | 0 | 1 |
| Clock | oscillator ÷ 12 (internal) | external pin T0/T1 |
| Measures | elapsed time | number of events |
| Typical use | delays, square waves, baud rate | tachometer, event/part counting |

## Delays longer than 65.536 ms

One pass of mode 1 tops out at 65.536 ms. For a bigger delay, put a fixed timer delay
inside a counted loop. For 1 second, run a 50 ms timer delay 20 times:

```
       MOV R2, #20      ; 20 x 50 ms = 1000 ms
AGAIN: ACALL DELAY50    ; each call = 50 ms (reload 3CB0H)
       DJNZ R2, AGAIN
```

50 ms needs count = 50000, reload = 65536 − 50000 = 15536 = 3CB0H → TH0 = 3CH, TL0 = B0H.
Twenty of them make exactly 1 s. Verified: 20 × 50000 µs = 1 000 000 µs = 1 s.

## Worked reload calculation — 1 ms at 12 MHz (mode 1)

- Machine cycle = 1 µs, so 1 ms needs **count = 1000**.
- reload = 65536 − 1000 = **64536 = 0FC18H**.
- Split: **TH0 = 0FCH, TL0 = 18H**.

Load FC18H, start the timer; it counts 1000 ticks (FC18H → 0000H) and sets TF0 after
exactly 1 ms. Verified: 65536 − 1000 = 64536, and 64536 = 0xFC18.

## Worked reload calculation — 250 µs (mode 2)

- count = 250 → reload = 256 − 250 = **6 = 06H**, loaded into TH0.
- On each overflow TL0 reloads to 06H automatically and produces another 250 µs tick.

## Solved numericals

**1.** Find the reload value for a 2 ms delay on Timer0 in mode 1 at 12 MHz, and give
TH0, TL0.
count = 2 ms / 1 µs = 2000. reload = 65536 − 2000 = 63536 = 0F830H.
**Ans:** TH0 = 0F8H, TL0 = 30H.

**2.** A timer in mode 1 is loaded with FA24H and started. How long until it overflows
at 12 MHz?
count = 65536 − 0FA24H = 65536 − 64036 = 1500. At 1 µs each, delay = 1500 µs.
**Ans:** 1.5 ms.

**3.** What is the largest delay obtainable from a single pass of Timer0 in mode 1, and
in mode 2, at 12 MHz?
Mode 1 counts up to 65536 → 65536 µs. Mode 2 counts up to 256 → 256 µs.
**Ans:** mode 1 = 65.536 ms; mode 2 = 256 µs. (For longer delays, nest a loop that
repeats a fixed timer delay, e.g. 20 × 50 ms = 1 s.)
