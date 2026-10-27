# Unit 4 — The 8051 Instruction Set

The 8051 has 111 instructions. They split into five groups: data transfer, arithmetic,
logical, boolean (bit) and program branching. Most are one or two bytes and finish in one
or two machine cycles; MUL and DIV are the slow ones at four cycles. Everything below assumes
the standard mnemonics as typed into Keil.

The immediate-data marker `#` is the thing that trips people up. `MOV A, #25H` loads the
number 25H. `MOV A, 25H` loads whatever is *stored at RAM address 25H*. Same three letters,
completely different action.

> Sir said: MImmediate data needs the #, direct address doesn't — lost marks on this in IA1.

## Addressing modes used by the instructions

| Mode | Example | Meaning |
|------|---------|---------|
| Immediate | `MOV A, #25H` | operand is a constant in the instruction |
| Register | `MOV A, R0` | operand is a register in the active bank |
| Direct | `MOV A, 40H` | operand is an internal RAM / SFR address |
| Register-indirect | `MOV A, @R0` | R0/R1 (or DPTR) holds the address |
| Indexed | `MOVC A, @A+DPTR` | look-up table access in code memory |

## Data transfer group

Copies data around. None of these change any flag except that writing PSW obviously changes
whatever bits you wrote.

| Instruction | Action |
|-------------|--------|
| `MOV A, #n` / `MOV A, Rn` / `MOV A, direct` / `MOV A, @Ri` | load A |
| `MOV direct, A` / `MOV @Ri, A` / `MOV Rn, #n` | store / load registers |
| `MOV DPTR, #16bit` | load the 16-bit data pointer |
| `MOVX A, @DPTR` / `MOVX @DPTR, A` | read / write **external** RAM |
| `MOVC A, @A+DPTR` | read a byte from **code** memory (look-up tables) |
| `PUSH direct` / `POP direct` | stack push / pop (direct address only) |
| `XCH A, Rn` / `XCH A, direct` / `XCH A, @Ri` | exchange A with source |
| `XCHD A, @Ri` | exchange only the low nibbles |

`MOVX` is the only way to reach off-chip RAM, and it always goes through A. `MOVC` reads the
program ROM, which is how a seven-segment or sine table is fetched. `PUSH` and `POP` take a
*direct address*, so to push the accumulator you write `PUSH ACC` (ACC is the direct name for
the A register at E0H), never `PUSH A`.

## Arithmetic group

There is **no plain `SUB`** on the 8051 — only `SUBB` (subtract with borrow). If you want a
straight subtraction you must `CLR C` first so the borrow starts at zero.

| Instruction | Action | Flags affected |
|-------------|--------|----------------|
| `ADD A, src` | A = A + src | CY, AC, OV, P |
| `ADDC A, src` | A = A + src + CY | CY, AC, OV, P |
| `SUBB A, src` | A = A − src − CY | CY(borrow), AC, OV, P |
| `INC A/Rn/direct/@Ri` | source + 1 | P (only when A) |
| `INC DPTR` | DPTR + 1 | none |
| `DEC A/Rn/direct/@Ri` | source − 1 | P (only when A) |
| `MUL AB` | B:A = A × B (16-bit) | CY=0, OV, P |
| `DIV AB` | A = A/B, B = A mod B | CY=0, OV, P |
| `DA A` | decimal-adjust A after a BCD add | CY |

Flag meaning: **CY** carry out of bit 7; **AC** auxiliary carry out of bit 3 (used only by
`DA A`); **OV** signed overflow (carry into bit 7 differs from carry out); **P** parity of A.
`INC` and `DEC` do *not* touch CY, so a multi-byte counter uses `CJNE` or a compare, not the
carry. `MUL` leaves the high byte in B and clears CY; OV is set when the product exceeds FFH.
`DIV` clears CY too, and sets OV if you divide by zero.

## Logical group

| Instruction | Action |
|-------------|--------|
| `ANL` / `ORL` / `XRL` | bitwise AND / OR / XOR (A or a direct byte as destination) |
| `CLR A` | A = 00H |
| `CPL A` | one's complement (flip every bit) |
| `RL A` | rotate left, bit7 → bit0 |
| `RR A` | rotate right, bit0 → bit7 |
| `RLC A` | rotate left through carry: bit7 → CY → bit0 |
| `RRC A` | rotate right through carry: bit0 → CY → bit7 |
| `SWAP A` | exchange the two nibbles of A |

`ANL` masks bits (AND with 0 clears), `ORL` sets bits (OR with 1 sets), `XRL` toggles bits.
`RLC`/`RRC` carry data through CY, which is how you build a multi-byte shift or test the bit
that just fell off the end. `SWAP A` is a nibble exchange, equal to `RL A` done four times.

## Boolean (bit) group

The 8051 is a bit-addressable machine: bits 00H–7FH live in RAM bytes 20H–2FH, and the SFR
bits (P0–P3, PSW, TCON, SCON, IE, IP) are addressable by name. CY is the "bit accumulator".

| Instruction | Action |
|-------------|--------|
| `SETB bit` / `SETB C` | set a bit to 1 |
| `CLR bit` / `CLR C` | clear a bit to 0 |
| `CPL bit` / `CPL C` | complement a bit |
| `MOV C, bit` / `MOV bit, C` | copy a bit to/from carry |
| `ANL C, bit` / `ORL C, bit` | bit logic into carry |
| `JC rel` / `JNC rel` | jump if CY = 1 / CY = 0 |
| `JB bit, rel` / `JNB bit, rel` | jump if bit = 1 / bit = 0 |
| `JBC bit, rel` | jump if bit = 1, **and clear it** |

`JBC` is the handy one for polling a flag: it tests and clears in a single instruction, so you
do not forget to reset a timer/serial flag by hand.

## Program branching group

| Instruction | Range | Action |
|-------------|-------|--------|
| `SJMP rel` | −128..+127 | short jump (2 bytes) |
| `AJMP addr11` | 2 KB page | absolute jump |
| `LJMP addr16` | full 64 KB | long jump |
| `JMP @A+DPTR` | — | computed jump (jump tables) |
| `JZ rel` / `JNZ rel` | ±127 | jump if A = 0 / A ≠ 0 |
| `CJNE dst, src, rel` | ±127 | compare, jump if not equal, set CY on `<` |
| `DJNZ Rn, rel` / `DJNZ direct, rel` | ±127 | decrement, jump if result ≠ 0 |
| `ACALL addr11` / `LCALL addr16` | 2 KB / 64 KB | call subroutine |
| `RET` / `RETI` | — | return / return from interrupt |
| `NOP` | — | do nothing, one cycle |

`CJNE` does double duty: it branches on inequality and it leaves CY = 1 when the destination
is smaller than the source, so a following `JC`/`JNC` sorts the two into greater/less. `DJNZ`
is the standard loop-counter and delay-loop instruction — one instruction decrements and tests.

A subtlety on the jump ranges: `SJMP`, and every conditional jump (`JZ`, `JNZ`, `JC`, `JB`,
`CJNE`, `DJNZ` …) use an 8-bit *relative* offset, so the target must sit within −128..+127 bytes
of the instruction after the jump. If the label is farther away the assembler complains and you
have to reach it with `LJMP`. Only `LJMP`/`LCALL` cover the whole 64 KB.

## Bytes and machine cycles (12 MHz → 1 µs per cycle)

| Instruction | Bytes | Cycles | Time at 12 MHz |
|-------------|-------|--------|----------------|
| `MOV A, Rn` | 1 | 1 | 1 µs |
| `MOV A, direct` | 2 | 1 | 1 µs |
| `ADD A, #n` | 2 | 1 | 1 µs |
| `DJNZ Rn, rel` | 2 | 2 | 2 µs |
| `LCALL addr16` | 3 | 2 | 2 µs |
| `MUL AB` / `DIV AB` | 1 | 4 | 4 µs |

This byte/cycle table is what a delay loop is costed from: a `DJNZ` inner loop of count N takes
about `2N` µs, which is the arithmetic behind the timer notes in Unit 8.

## The stack, and how CALL/RET use it

The stack pointer `SP` resets to 07H on power-up, so the stack starts at 08H (right on top of
register bank 1). Any program that uses the stack should move SP up, e.g. `MOV SP, #30H`, to
keep clear of the register banks and bit area.

> Sir said: on the 8051 the stack grows UP, not down. Opposite of the x86. Exam trap.

- `PUSH direct` : SP ← SP + 1, then (SP) ← (direct).
- `POP direct`  : (direct) ← (SP), then SP ← SP − 1.
- `LCALL/ACALL` : push the return address (PC low byte first, then PC high byte), SP moves up
  by 2, then load the target into PC.
- `RET` : pop the high byte then the low byte back into PC, SP moves down by 2.

Because the return address is on the stack, a subroutine that also pushes registers must pop
them in the reverse order before `RET`, or `RET` will grab the wrong bytes and the program
jumps into the weeds. Last in, first out.

## DA A explained, worked

After an `ADD`/`ADDC` of two packed-BCD bytes, the accumulator holds a *binary* sum that may
not be valid BCD. `DA A` fixes it with two conditional additions:

1. If the low nibble > 9, **or** AC = 1, add 06H.
2. If the high nibble > 9, **or** CY = 1, add 60H (and this sets CY).

Worked example — add BCD 47 and 38:

```
MOV A, #47H
ADD A, #38H    ; 47H + 38H = 7FH  (binary), AC = 0
DA A           ; low nibble F > 9 -> +06 -> 85H ; high nibble 8, no add
```

`7FH + 06H = 85H`, and 47 + 38 = 85 in decimal, so the BCD answer is correct. Without `DA A`
you would be left with 7FH, which is meaningless as BCD. `DA A` only ever works right straight
after a BCD addition — it is not a general-purpose "make it decimal" instruction.

## Solved numericals

**1.** Add the BCD numbers 38 and 45 and give the adjusted result.
`38H + 45H = 7DH` in binary. Low nibble D > 9, so `DA A` adds 06H: `7DH + 06H = 83H`. High
nibble 8 is fine, no second add.
**Ans:** A = 83H, CY = 0 (decimal 38 + 45 = 83).

**2.** A = 9AH and CY = 1. Give A and CY after `RLC A`, then after `RRC A` from the same start.
`RLC A`: bit7 (1) goes to CY, old CY (1) comes into bit0. 1001 1010 → 0011 0101 = 35H, CY = 1.
`RRC A`: bit0 (0) goes to CY, old CY (1) comes into bit7. 1001 1010 → 1100 1101 = CDH, CY = 0.
**Ans:** RLC → A = 35H, CY = 1.  RRC → A = CDH, CY = 0.

**3.** Multiply 50H by 0AH with `MUL AB` and give the register contents.
`50H = 80`, `0AH = 10`, product = 800 = 0320H. Low byte → A, high byte → B.
**Ans:** A = 20H, B = 03H, OV = 1 (product > FFH), CY = 0.
