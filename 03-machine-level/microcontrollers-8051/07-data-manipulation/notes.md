# Unit 7 — Data Manipulation

Data manipulation on the 8051 means walking through a block of bytes in internal
RAM with a pointer register (R0 or R1 through `@Ri`) and doing something to each:
moving it, comparing it, counting it, sorting it. There is no `for` loop — the
loop is a label plus `DJNZ` on a counter. Everything here uses the same skeleton:
set a pointer, set a count, do the body, `DJNZ` back.

## The pointer + counter skeleton

| Register | Typical use |
|----------|-------------|
| R0 / R1  | address pointer, dereferenced with `@R0` / `@R1` |
| R2       | outer / element counter for `DJNZ` |
| R3, R4   | tallies (counts) |
| A        | the byte being worked on; running max/min |

Only R0 and R1 can be used as pointers in register-indirect addressing. `@R2` is
not legal. Data lives in internal RAM from 30H upward (20H–2FH is bit-addressable,
below that are the register banks and stack).

> Sir said: `@Ri` reaches only the lower 128 bytes of internal RAM. To touch
> external RAM you need `MOVX @DPTR, A`. Exam trap.

## Block move and block exchange

A block move copies N bytes from a source block to a destination block. Two
pointers, one counter:

```
        MOV R0, #30H      ; source
        MOV R1, #40H      ; destination
        MOV R2, #08H      ; count
LOOP:   MOV A, @R0
        MOV @R1, A
        INC R0
        INC R1
        DJNZ R2, LOOP
```

A block exchange swaps the two blocks instead of overwriting. The idiomatic way
is `XCH A, @Ri`, which exchanges A with the addressed byte in one instruction:

```
        MOV A, @R0        ; A = source byte
        XCH A, @R1        ; A <-> dest byte  (A now holds dest byte)
        MOV @R0, A        ; source byte gets old dest byte
```

`XCH` does the swap without a temporary RAM location — it is the reason bubble
sort and block exchange are short on the 8051.

## Largest and smallest — compare with CJNE

`CJNE A, @R0, target` compares A with the addressed byte and, as a side effect,
sets the carry: **C = 1 when A < operand**, C = 0 when A ≥ operand. It jumps to
`target` when the two differ. That single flag drives both max and min.

Keep the running result in A. Load the first element, then for each remaining
element:

- **Largest:** if `C = 1` (A is smaller than the element), take the element.
  So after `CJNE` use `JNC skip` — skip the update when A is already ≥.
- **Smallest:** if `C = 0` (A is larger than the element), take the element.
  So use `JC skip` — skip the update when A is already ≤.

```
        MOV A, @R0        ; first element = current max
        INC R0
        DEC R2
LOOP:   CJNE A, @R0, DIFF
        SJMP SKIP         ; equal
DIFF:   JNC SKIP          ; C=0, A already >= element
        MOV A, @R0        ; C=1, element is larger
SKIP:   INC R0
        DJNZ R2, LOOP
```

Remember: immediate data needs the `#`, a direct address does not — `MOV A, #40H`
loads the number 40H, `MOV A, 40H` loads the *contents* of 40H. Lost marks in IA1.

## Bubble sort — nested DJNZ, swap with XCH

For N bytes, do N−1 passes; each pass makes N−1 adjacent comparisons and bubbles
the extreme value to the end. Outer counter in R1, inner counter in R2, pointer
reset to the start of the array at the top of every pass.

```
        MOV R1, #04H      ; N-1 passes
PASS:   MOV R0, #40H
        MOV R2, #04H      ; N-1 compares
INNER:  MOV A, @R0        ; arr[j]
        INC R0            ; -> arr[j+1]
        CJNE A, @R0, DIFF
        SJMP NEXT
DIFF:   JC  NEXT          ; ascending: C=1 means already in order
        XCH A, @R0        ; swap the pair
        DEC R0
        MOV @R0, A
        INC R0
NEXT:   DJNZ R2, INNER
        DJNZ R1, PASS
```

For **descending** order the only change is `JNC NEXT` instead of `JC NEXT`: swap
when the left byte is the smaller one. The compare after loading A into the
accumulator and pointing R0 at the next byte means `CJNE A, @R0` compares
arr[j] with arr[j+1].

## Counting with rotates and masks

To classify a byte by one of its bits, rotate that bit into the carry and branch.

| Test | Instruction | Then |
|------|-------------|------|
| Even / odd (bit 0) | `RRC A` | C = old bit0; `JC` for odd |
| Sign (bit 7)       | `RLC A` | C = old bit7; `JC` for negative |

`RRC A` rotates A right through carry, so bit0 ends up in C; `RLC A` rotates left,
so bit7 ends up in C. A masking alternative is `ANL A, #01H` then `JZ` for even,
but the rotate is one instruction and leaves the count logic clean. Keep two
tallies in R3 and R4 and store them at the end with `MOV 60H, R3`.

## Searching

Linear search walks the block comparing each byte with a key held in a register:
`CJNE A, key, notfound` — equal falls through, so a match is the *fall-through*
path. Count occurrences by incrementing a tally on every match instead of
stopping at the first.

## Solved numericals

**1. Find the largest of five bytes 34H, 56H, 12H, 78H, 45H.**
Load A = 34H. Compare: 34H<56H so max=56H; 56H>12H keep; 56H<78H so max=78H;
78H>45H keep.
**Ans:** largest = **78H**.

**2. Count even and odd bytes in 22H, 15H, 30H, 07H, 44H.**
Bit0 of each: 22H→0 even, 15H→1 odd, 30H→0 even, 07H→1 odd, 44H→0 even.
**Ans:** even = **03**, odd = **02**.
