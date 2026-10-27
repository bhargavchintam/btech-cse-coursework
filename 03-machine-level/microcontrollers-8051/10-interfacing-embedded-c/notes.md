# Unit 10 — Interfacing and Embedded C

Assembly gives you exact control of every machine cycle, but for interfacing work —
LEDs, seven-segment displays, an LCD, a stepper, a DAC — C is faster to write and easy
to read. The 8051 C compiler here is **SDCC**. It produces the same kind of code the
assembler would, but you write `P1 = 0xFF;` instead of `MOV P1, #0FFH`. The catch is
that C hides the machine cycles, so anything time-critical (an exact baud rate, a precise
period) still belongs to a hardware timer, not a C `for` loop.

> Sir said: learn assembly first so you know what the C is doing underneath. A `for`
> delay in C is never exact — the compiler decides the loop's cycle count, not you.

## The SDCC header

`#include <8051.h>` pulls in the SFR names as C symbols. After that every register is
just a variable you assign to:

| C symbol | What it is | Assembly equivalent |
|----------|-----------|---------------------|
| `P0 P1 P2 P3` | the four 8-bit ports | `P0`…`P3` |
| `TMOD TCON` | timer mode / control | same |
| `TH0 TL0 TH1 TL1` | timer count registers | same |
| `SCON SBUF` | serial control / buffer | same |
| `IE IP` | interrupt enable / priority | same |
| `PSW` | program status word | same |

Whole-port write: `P1 = 0x0F;` puts 00001111 on port 1. Read: `x = P2;` latches the pins.
There is no `MOV` — assignment *is* the move.

## Bit access — `P1_0` style

SDCC declares each port pin as its own bit symbol: `P1_0` through `P1_7`, `P2_0`, `P3_5`,
and so on. These map to the bit-addressable SFR bits, so writing one pin does not disturb
the other seven.

```c
P1_0 = 1;      // drive P1.0 high
P1_0 = 0;      // drive it low
P1_7 = ~P1_7;  // toggle P1.7
if (P3_2 == 0) { ... }   // read INT0 pin
```

`P1_0 = 1` compiles to `SETB P1.0`, a single bit instruction — not a read-modify-write of
the whole port. This matters when other pins on the same port are inputs.

## Why `while(1)`

An 8051 program has nowhere to return to — there is no operating system waiting to take
control back. So `main` never ends; it drops into an infinite loop and stays there:

```c
void main(void) {
    // one-time setup here
    while (1) {
        // the forever job
    }
}
```

This is the C form of the assembly `HERE: SJMP HERE`. Leave `main` without a `while(1)`
and SDCC's startup code just loops on an empty exit — harmless, but you never write it
that way. The setup (port directions, timer mode, enabling interrupts) goes once, before
the loop; the repeating work goes inside it.

## Delay functions and why they drift

The usual delay is an empty counting loop:

```c
void delay(unsigned int n) {
    unsigned int i;
    while (n--)
        for (i = 0; i < 120; i++);   // burn cycles
}
```

It works, but the exact time depends on how SDCC compiles the loop — how many machine
cycles each `i++` and comparison take. Change the optimiser, the crystal, or the loop body
and the timing shifts. That is fine for "blink an LED so a human sees it" but wrong for
anything that must be exact. For an exact period you load a **hardware timer** (Unit 8) and
poll its overflow flag, or take a timer interrupt. Rule of thumb: a `for` delay for
human-visible timing, a timer for machine-visible timing.

## Memory models — `data`, `xdata`, `code`

The 8051 has separate address spaces, and SDCC lets you place a variable in each with a
storage keyword:

| Keyword | Where it lives | Size | Use |
|---------|---------------|------|-----|
| `data` | internal RAM 00–7FH | 128 B | fast scratch variables, the default |
| `idata` | internal RAM 80–FFH (indirect) | 128 B | extra internal RAM on an 8052 |
| `xdata` | external RAM, via MOVX/DPTR | up to 64 KB | large buffers, external devices |
| `code` | program ROM, via MOVC | up to 64 KB | constant tables, strings — never changes |

A lookup table you never modify goes in `code` so it does not waste RAM:

```c
__code unsigned char seg[10] = { 0x3F, 0x06, ... };
```

Internal `data` access is a single instruction and fastest; `xdata` needs DPTR and a MOVX,
so it is slower. Put hot variables in `data`, big arrays in `xdata`, constants in `code`.

## Interfacing an LED — sink vs source

A port pin can either **source** current (pin high, current flows out of the pin through
the LED to ground) or **sink** it (pin low, current flows from Vcc through the LED into the
pin). The 8051's ports sink far more current than they source — P1/P2/P3 can pull down a
few milliamps cleanly but source almost nothing. So the standard wiring is
**Vcc → LED → resistor → pin**, and you turn the LED **on by writing 0** (sink) and off by
writing 1. Always a series resistor (≈330 Ω) to limit current.

> Common exam point: "active-low" output means 0 turns the device on. Most 8051 LED and
> relay circuits are active-low because the port sinks better than it sources.

## Seven-segment display

Seven LEDs (a–g) plus a decimal point, arranged as a figure-8. Two wiring types:

- **Common cathode:** all cathodes tie to ground; a segment lights when its pin is driven
  **high (1)**. Segment ON = 1.
- **Common anode:** all anodes tie to Vcc; a segment lights when its pin is pulled
  **low (0)**. The code is the bitwise complement of the common-cathode code.

Bit-to-segment mapping used below: bit0=a, bit1=b, bit2=c, bit3=d, bit4=e, bit5=f,
bit6=g, bit7=dp. The common-cathode hex codes for 0–9:

| Digit | Segments lit | Code |
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

Verify two by hand. **0** lights a,b,c,d,e,f = bits 0,1,2,3,4,5 = 00111111 = **3FH**. ✓
**1** lights only b,c = bits 1,2 = 00000110 = **06H**. ✓ For a common-anode display, invert:
0 → complement of 3FH = C0H, 1 → complement of 06H = F9H.

## LCD — the 16×2 character module

The HD44780 LCD takes an 8-bit data bus plus three control lines:

| Line | Meaning |
|------|---------|
| RS | 0 = the byte is a command; 1 = the byte is character data |
| RW | 0 = write to the LCD; 1 = read (usually tied low, we only write) |
| EN | enable — the LCD latches the bus on the **high→low** edge of EN |

To send a byte: put it on the data port, set RS (command or data), pulse EN high then low.
The controller needs an initialisation sequence of commands first:

| Command | Meaning |
|---------|---------|
| 38H | 8-bit bus, 2 lines, 5×7 font |
| 0EH | display on, cursor on |
| 01H | clear display |
| 06H | entry mode: auto-increment cursor |
| 80H | move cursor to line 1, column 0 |

After 38H/0EH/01H/06H you send character bytes with RS = 1 and each one appears at the
cursor, which then advances on its own.

## Stepper motor — the full-step sequence

A unipolar stepper turns one step each time you advance the coil pattern. Full-step drive
energises **two adjacent coils at a time**, which gives more torque than one coil. Four
patterns on the low nibble of a port (P1.0–P1.3 → coils A B C D), stepped in order:

| Step | Coils on | Pattern | Hex |
|------|----------|---------|-----|
| 1 | A D | 1001 | 09H |
| 2 | C D | 1100 | 0CH |
| 3 | B C | 0110 | 06H |
| 4 | A B | 0011 | 03H |

So the sequence is **09H, 0CH, 06H, 03H**, then repeat. Each pair overlaps the next by one
coil, which is what makes the rotor step smoothly. Send them in that order for one
direction; send them in **reverse** (03H, 06H, 0CH, 09H) to spin the other way. A delay
between steps sets the speed — too fast and the motor stalls.

## DAC — turning numbers into a voltage

An **R-2R ladder** DAC takes an 8-bit byte on a port and produces an analogue voltage
proportional to it: 00H → 0 V, FFH → full scale, and every step in between is linear.
Resistors of value R and 2R in a repeating ladder weight each bit by its binary place, so
the output is `(byte / 256) × Vref`. Waveforms are then just number sequences written to
the port in a loop:

- **Ramp (sawtooth):** write 0x00, 0x01, … 0xFF, wrap to 0x00. A rising line that snaps back.
- **Triangle:** count 0x00 up to 0xFF, then back down to 0x00. Symmetric rise and fall.
- **Square:** write 0x00 for half the period, 0xFF for the other half.

The output frequency is set by how fast you step and how many points are in one cycle. No
`for`-loop delay is exact, so for a specified frequency you clock the writes from a timer.

## Solved numericals

**1.** A common-cathode seven-segment is wired bit0=a … bit6=g. Give the hex to display
**5**, and the hex for the same digit on a common-anode display.
Digit 5 lights a,c,d,f,g = bits 0,2,3,5,6 = 01101101 = 6DH. Common anode is the
complement: FFH − 6DH = 92H.
**Ans:** common cathode = 6DH, common anode = 92H.

**2.** A stepper is driven full-step at 10 ms per step. How long for one full electrical
cycle of the four patterns, and how many electrical cycles per second?
One cycle = 4 steps × 10 ms = 40 ms. Cycles per second = 1 / 0.040 = 25.
**Ans:** 40 ms per 4-step cycle, 25 electrical cycles per second.

**3.** An 8-bit R-2R DAC has Vref = 5 V. What output voltage does the byte 80H produce,
and what is the smallest voltage step?
80H = 128, so V = (128 / 256) × 5 = 2.5 V. One LSB = 5 / 256 = 0.0195 V ≈ 19.5 mV.
**Ans:** 2.5 V, step ≈ 19.5 mV.
