# Unit 5 — Assembly Language Programming

The 8051 is programmed by writing mnemonics, running them through an assembler
(Keil A51 in the lab, or SDCC's `sdas8051` at home), and burning the resulting
hex into the chip or loading it into the simulator. This unit is about the shape
of a real program: the directives that set it up, labels and subroutines, and the
delay loops that every timing program leans on.

## Assembler directives

Directives are not 8051 instructions. They are orders to the assembler and
generate no opcode by themselves (except `DB`/`DW`, which place bytes). They tell
it where to put code, what names mean, and where the source ends.

| Directive | Meaning | Example |
|-----------|---------|---------|
| `ORG`  | Set the location counter (where the next byte goes) | `ORG 0000H` |
| `END`  | Marks the end of the source file; nothing after it is assembled | `END` |
| `EQU`  | Give a name a constant value (no memory used) | `COUNT EQU 250` |
| `DATA` | Name an internal-RAM / SFR address | `SUM DATA 40H` |
| `BIT`  | Name a single bit address | `LED BIT P1.0` |
| `DB`   | Define byte(s) in code memory | `TABLE: DB 25H, 12H, 0AH` |
| `DW`   | Define word(s), 16-bit, high byte first | `DW 1234H` |

`EQU` is pure text substitution done at assemble time. `DATA` and `BIT` attach a
name to an address so `MOV SUM, A` reads better than `MOV 40H, A`. They cost no
memory — only `DB`/`DW` actually lay down bytes.

> Sir said: `EQU` has no `H` of its own — the radix is on the number you give it.
> `COUNT EQU 250` is decimal 250; `MASK EQU 0F0H` is hex. Mixing these up loses marks.

## Structure of an 8051 assembly program

Every program follows the same skeleton:

```
        ORG 0000H        ; reset vector - execution starts here
        ; ... your instructions ...
HERE:   SJMP HERE        ; trap: sit here forever when done
        ; subroutines below, or a DB table
        END              ; end of source
```

Points that matter in the lab:
- After reset the program counter is `0000H`, so the first useful instruction
  must sit at `ORG 0000H` (or a jump placed there).
- An 8051 program never "returns to an OS". When the work is finished you park the
  CPU with `HERE: SJMP HERE` (or the shorthand `SJMP $`, where `$` means "here").
- Immediate data needs the `#`: `MOV A, #25H` loads the *number* 25H; `MOV A, 25H`
  loads the *contents of RAM address* 25H. Direct address takes no `#`.
- Hex literals carry an `H` suffix and need a leading `0` when they start with a
  letter: `#0FFH`, `#0AH`. Numbers with no suffix are decimal.

Remember: immediate needs the `#`, direct address doesn't — I lost marks on this in IA1.

## Labels and subroutines (ACALL / RET)

A label is just a name for an address; the assembler works out the real number.
Jumps (`SJMP`, `AJMP`, `LJMP`, `DJNZ ..., LABEL`) and calls point at labels so you
never hand-count addresses.

A subroutine is a block ending in `RET`. You reach it with `ACALL` (2-byte, same
2K page) or `LCALL` (3-byte, anywhere in 64K). Both push the return address onto
the stack; `RET` pops it back into the PC.

```
        ACALL DELAY      ; push return addr, jump to DELAY
        ; ... execution comes back here after RET ...
DELAY:  MOV R2, #250
D1:     DJNZ R2, D1
        RET              ; pop return addr into PC
```

> Sir said: on the 8051 the stack grows **UP**, not down. `SP` resets to 07H, and
> a `PUSH` does `SP = SP + 1` first. Opposite of the x86. Classic exam trap.

Because `ACALL`/`RET` use the stack, a subroutine can call another one — as long as
the stack (default just above the register banks, from 08H up) has room.

## How a delay loop works

The CPU has no "wait" instruction, so delay is made by wasting a known number of
machine cycles. At a **12 MHz** crystal the machine cycle is
12 clocks / 12 MHz = **1 µs**, which makes the arithmetic easy: cycles = µs.

`DJNZ Rn, label` — "decrement Rn, jump if not zero" — takes **2 machine cycles**
every time it runs, whether it jumps or falls through. That is the workhorse of
every delay.

### Single loop

```
        MOV R2, #250     ; 1 cycle
L1:     DJNZ R2, L1      ; 2 cycles, runs 250 times
```

Time = 1 (the `MOV`) + 250 × 2 (the `DJNZ`) = **501 µs ≈ 0.5 ms**.

One 8-bit register maxes out near 256 × 2 = 512 µs, so a single loop cannot reach
1 ms. For longer delays you nest.

### Nested loop

```
        MOV R1, #100     ; 1 cycle              (outer count)
OUT:    MOV R2, #250     ; 1 cycle  (per outer pass)
IN:     DJNZ R2, IN      ; inner: 250 x 2 = 500 cycles per pass
        DJNZ R1, OUT     ; 2 cycles (per outer pass)
```

Per outer pass = `MOV R2` (1) + inner (500) + `DJNZ R1` (2) = **503 µs**.
Total = `MOV R1` (1) + 100 × 503 = **50301 µs ≈ 50.3 ms**. Add `RET` (2) if it is
wrapped as a subroutine → 50303 µs.

For roughly **1 ms**, keep the same inner loop but only 2 outer passes:
total = 1 + 2 × 503 = **1007 µs ≈ 1 ms**.

These are the reload constants used in `delay_subroutine.asm` and `toggle_port.asm`
in this folder.

## Assembly-to-hex flow

The chip runs machine code, not text. The path from source to silicon:

1. **Write** the `.asm` source (mnemonics + directives).
2. **Assemble** it — Keil A51 (or `sdas8051`) turns each mnemonic into opcodes and
   produces an object file plus a listing (`.lst`) that shows address, opcode, and
   source side by side.
3. **Link / locate** — fix the code at the addresses set by `ORG`, producing an
   absolute object.
4. **Convert to Intel HEX** (`.hex`) — an ASCII record format the programmer and
   most simulators expect.
5. **Burn or simulate** — flash the `.hex` into the 8051's program memory, or load
   it into the Keil simulator / Proteus and single-step it.

The `.lst` file is the one to check when a jump lands in the wrong place: it shows
the exact byte address the assembler gave each label.

## Solved numericals

**1. Find the delay produced at a 12 MHz crystal.**

```
        MOV R3, #200
L:      DJNZ R3, L
```

Machine cycle = 1 µs. `MOV` = 1 cycle; `DJNZ` runs 200 times at 2 cycles each.
Delay = 1 + 200 × 2 = 401 cycles.
**Ans: 401 µs.**

**2. Find the total delay of this nested loop at 12 MHz.**

```
        MOV R1, #50
AGAIN:  MOV R2, #100
HERE:   DJNZ R2, HERE
        DJNZ R1, AGAIN
```

Inner loop = 100 × 2 = 200 cycles.
Per outer pass = `MOV R2` (1) + 200 + `DJNZ R1` (2) = 203 cycles.
Total = `MOV R1` (1) + 50 × 203 = 1 + 10150 = 10151 cycles.
**Ans: 10151 µs ≈ 10.15 ms.**
