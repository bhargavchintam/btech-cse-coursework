# Unit 3 — Addressing Modes

An addressing mode is the way an instruction names the operand it works on — the
source of the data, or where the result goes. The 8051 has five of them:
immediate, register, direct, register-indirect, and indexed. Getting the mode
right is half of getting the instruction right; the same `MOV A, ...` can mean
four completely different things depending on how the operand is written.

## The five modes at a glance

| Mode | Example | What the operand is | Where the data comes from |
|------|---------|---------------------|---------------------------|
| Immediate | `MOV A, #25H` | the constant 25H | the instruction byte itself |
| Register | `MOV A, R2` | contents of R2 | the current register bank |
| Direct | `MOV A, 40H` | contents of address 40H | internal RAM / SFR by address |
| Register-indirect | `MOV A, @R0` | contents of *[R0]* | RAM at the address held in R0 |
| Indexed | `MOVC A, @A+DPTR` | a code byte | program (code) memory table |

Remember: immediate data needs the `#`, a direct address does not. `MOV A, #40H`
loads the number 40H; `MOV A, 40H` loads whatever is *stored at* address 40H.
Dropping or adding a `#` is the single most common exam mistake — lost marks on
this in IA1.

## 1. Immediate addressing

The operand is a constant coded into the instruction, marked by `#`.

- `MOV A, #35H` — put the number 35H in A.
- `MOV DPTR, #2500H` — load the 16-bit constant 2500H into DPTR.
- `ADD A, #10H` — add the constant 10H to A.

The value is fetched from the program bytes; no RAM is read. Hex constants that
start with a letter take a leading zero: `#0FFH`, `#0A5H`.

## 2. Register addressing

The operand is one of the working registers R0–R7 of the currently selected bank
(or A, B).

- `MOV A, R2` — copy R2 into A.
- `ADD A, R5` — add R5 to A.
- `INC R0` — increment R0.

Which physical RAM bytes R0–R7 are depends on RS1:RS0 in PSW — bank 0 is 00–07H,
bank 1 is 08–0FH, bank 2 is 10–17H, bank 3 is 18–1FH. Register addressing is the
fastest and shortest (the register number is packed into the opcode).

> Sir said: `MOV R1, R2` does **not** exist on the 8051. You cannot move register
> to register directly — go through A or through a direct address. Exam trap.

## 3. Direct addressing

The operand is named by its 8-bit internal address (00H–7FH RAM, or 80H–FFH for
the SFRs). No `#`, no `@`.

- `MOV A, 40H` — read the byte at address 40H.
- `MOV 50H, A` — write A to address 50H.
- `MOV 30H, 40H` — copy address 40H to address 30H (direct-to-direct).

### SFR direct addressing

The special function registers live in the 80H–FFH direct-address space, so you
reach them by direct addressing. `MOV A, 90H` reads port P1 (P1 is at 90H), and
`MOV 90H, A` writes it — exactly the same as `MOV A, P1` / `MOV P1, A`, because
the assembler just substitutes the address for the name. SFRs can *only* be
reached by direct addressing; there is no register-indirect path to them (an
`@R0` of 90H would hit RAM in the upper 80H–FFH block on an 8052, not the SFR).

## 4. Register-indirect addressing

The register holds the *address* of the operand, not the operand. Marked by `@`.
Only R0, R1, and DPTR can be pointers.

- `MOV A, @R0` — A = contents of the RAM byte whose address is in R0.
- `MOV @R1, A` — store A at the address held in R1.
- `MOVX A, @DPTR` — read external RAM at the 16-bit address in DPTR.

### @R0/@R1 vs @DPTR — when to use which

`@R0` and `@R1` are 8-bit pointers: they can address only 00H–FFH, so they reach
internal RAM (and, with `MOVX`, one 256-byte page of external RAM). `@DPTR` is a
16-bit pointer and can address the full 0000H–FFFFH — used for external RAM and
code-memory tables. Rule of thumb: stepping through an internal RAM buffer, use
`@R0`/`@R1` with `INC R0`; reaching out to external memory or a big table, use
`@DPTR`.

## 5. Indexed addressing

The address is formed by *adding* A to a base pointer (DPTR or PC). Used almost
entirely for reading tables in code memory with `MOVC`.

- `MOVC A, @A+DPTR` — A = code byte at address (DPTR + A).
- `MOVC A, @A+PC` — A = code byte at (PC + A), for a table just after the
  instruction.
- `JMP @A+DPTR` — a jump table: branch to (DPTR + A).

### MOVC A, @A+DPTR for a table lookup

Load DPTR with the base of the table, put the index in A, and `MOVC` fetches the
entry. To read the square of 5 from a `DB` table of squares:

```
    MOV DPTR, #SQTAB   ; base of table
    MOV A, #05H        ; index 5
    MOVC A, @A+DPTR    ; A <- SQTAB[5] = 19H
SQTAB: DB 00H,01H,04H,09H,10H,19H,24H,31H,40H,51H
```

The table stores the squares as hex: 5×5 = 25 = 19H, so A comes back as 19H.
`MOVC` reads *code* memory, which is why tables sit in `DB` bytes in the program.

## Memory-picture worked example

Take this machine state before each instruction runs:

| Item | Value |
|------|-------|
| R2 (register addressing source) | 47H |
| R0 (pointer) | 40H |
| RAM address 40H | 88H |
| DPTR | base of SQTAB above |
| A (index, for the indexed row only) | 03H |

Now `MOV A, ...` (or `MOVC`) in each mode fetches this operand:

| Instruction | Mode | Operand A receives |
|-------------|------|--------------------|
| `MOV A, #35H` | immediate | 35H (from the instruction) |
| `MOV A, R2` | register | 47H (the value in R2) |
| `MOV A, 40H` | direct | 88H (content of address 40H) |
| `MOV A, @R0` | indirect | 88H (R0 = 40H, so content of 40H) |
| `MOVC A, @A+DPTR` | indexed | 09H (SQTAB[3] = square of 3) |

Notice direct `40H` and indirect `@R0` land on the same byte here only because R0
happens to hold 40H — that is the whole point of the distinction.

## Solved numericals

**Q1.** A code-memory table is defined `TAB: DB 30H,31H,32H,33H,34H,35H,36H,37H,
38H,39H` (the ASCII codes of '0'..'9'). With `MOV DPTR, #TAB`, `MOV A, #07H`,
`MOVC A, @A+DPTR`, what is in A?

Indexed addressing fetches TAB[7]. The 7th entry (index 0 is the first) is 37H,
which is ASCII '7'.

**Ans:** A = 37H.

**Q2.** R0 = 45H, and internal RAM location 45H contains 0AAH. Give the
accumulator after each of: (a) `MOV A, R0`  (b) `MOV A, @R0`  (c) `MOV A, 45H`.

(a) Register addressing — A gets the *value held in R0*, which is 45H.
(b) Register-indirect — A gets the *content of the address in R0*, i.e. of 45H,
which is AAH.
(c) Direct — A gets the content of address 45H, which is AAH.

**Ans:** (a) A = 45H, (b) A = AAH, (c) A = AAH.
