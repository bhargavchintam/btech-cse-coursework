# Unit 6 — Instruction Set and Addressing Modes

## Instruction format fields

An instruction is just a bit pattern the control unit decodes. The usual fields:

```
+--------+------+----------+-------------------+
| opcode | mode | register |   address field   |
+--------+------+----------+-------------------+
```

- **Opcode** — which operation (ADD, LOAD, JMP...). k opcode bits give 2^k operations.
- **Mode bits** — how to interpret the address field (direct/indirect/indexed...).
- **Register field(s)** — which register(s) take part. r bits address 2^r registers.
- **Address field** — a memory address, a displacement, or an immediate constant,
  depending on the mode bits.

Not every instruction has every field. A register-to-register ADD has no address
field; a PUSH on a stack machine has no register field. The number of *explicit
operand addresses* in the format is what classifies the machine below.

## 3-, 2-, 1- and 0-address instructions

The classic exam question: evaluate **X = (A+B) * (C+D)** on each type of machine.
A, B, C, D, X are memory locations. Write the sequence, count the instructions.

**3-address** (result and both operands named explicitly):

```
ADD  R1, A, B      R1 <- M[A] + M[B]
ADD  R2, C, D      R2 <- M[C] + M[D]
MUL  X,  R1, R2    M[X] <- R1 * R2
```
3 instructions. Shortest program, but each instruction is long (three address fields).

**2-address** (first operand is also the destination, so one operand gets overwritten):

```
MOV  R1, A         R1 <- M[A]
ADD  R1, B         R1 <- R1 + M[B]
MOV  R2, C         R2 <- M[C]
ADD  R2, D         R2 <- R2 + M[D]
MUL  R1, R2        R1 <- R1 * R2
MOV  X,  R1        M[X] <- R1
```
6 instructions. Extra MOVs appear because a source gets destroyed by the result.

**1-address** (accumulator machine — AC is implicit in everything):

```
LOAD  A            AC <- M[A]
ADD   B            AC <- AC + M[B]
STORE T            M[T] <- AC        (T is a temporary location)
LOAD  C            AC <- M[C]
ADD   D            AC <- AC + M[D]
MUL   T            AC <- AC * M[T]
STORE X            M[X] <- AC
```
7 instructions. Only one AC, so the first sum has to be parked in memory at T.

**0-address** (stack machine — operands are implicitly the top of stack).
Convert to reverse Polish first: `AB+CD+*`.

```
PUSH A             stack: A
PUSH B             stack: A B
ADD                stack: (A+B)
PUSH C             stack: (A+B) C
PUSH D             stack: (A+B) C D
ADD                stack: (A+B) (C+D)
MUL                stack: (A+B)*(C+D)
POP  X             M[X] <- top
```
8 instructions. Most instructions, but each one is tiny — PUSH/POP carry one
address, the ALU ops carry none.

| Format | Instructions | Instruction size | Memory traffic |
|--------|--------------|------------------|----------------|
| 3-address | 3 | longest | fewest instruction fetches |
| 2-address | 6 | medium | medium |
| 1-address | 7 | short | AC forces STORE/LOAD of temporaries |
| 0-address | 8 | shortest | most instructions, all stack ops |

> Sir's trick for the count: 3, 6, 7, 8 for this exact expression. If your count
> differs, you wrote the sequence wrong.

## Addressing modes

Mode decides how the effective address (EA) — and hence the operand — is found.
A = address field of the instruction, R = register named in the instruction.

| Mode | EA | Operand | One-line example |
|------|----|---------|------------------|
| Immediate | — (no EA) | A itself | `ADD #25` adds the constant 25 |
| Direct | EA = A | M[A] | `LOAD 500` loads M[500] |
| Indirect | EA = M[A] | M[M[A]] | `LOAD @500` loads M[M[500]] |
| Register | — | R | `ADD R1` adds contents of R1 |
| Register indirect | EA = R | M[R] | `LOAD (R1)` loads M[R1] |
| Displacement / indexed | EA = A + R | M[A+R] | `LOAD 500(BR)` loads M[500+BR] |
| Relative | EA = PC + A | M[PC+A] | `BR +8` branches 8 past the next instruction |
| Stack | EA = SP | M[SP] | `ADD` pops the top two, pushes the sum |

Points that come up in theory questions:

- Immediate needs **zero** extra memory accesses for the operand; direct needs
  one; indirect needs **two** (one to get the address, one to get the operand).
- Register and register indirect keep instructions short — a register field is
  4–5 bits against a 16–20 bit address field.
- Displacement covers both index addressing (A is the array base, R is the index)
  and base-register addressing (R is the segment base, A is the offset). Same
  hardware, different intent.
- Relative addressing makes code position-independent — the branch target moves
  with the code. Used by almost every branch instruction.
- Stack mode has no address at all; the SP is implicit.

## Worked numerical — one instruction, every mode

A two-word instruction sits at addresses 200–201. Word 1 is opcode + mode, word 2
is the address field **A = 500**. After the fetch, **PC = 202**. Registers:
**R1 = 400**, base register **BR = 100**, **SP = 999**.

Memory:

| Address | Contents |
|---------|----------|
| 400 | 700 |
| 500 | 800 |
| 600 | 900 |
| 702 | 325 |
| 800 | 300 |
| 999 | 1200 |

What operand does the instruction fetch under each mode?

| Mode | EA | Operand fetched |
|------|-----|-----------------|
| Immediate | — | 500 (the field itself) |
| Direct | 500 | M[500] = 800 |
| Indirect | M[500] = 800 | M[800] = 300 |
| Register | — | R1 = 400 |
| Register indirect | R1 = 400 | M[400] = 700 |
| Displacement (base) | 500 + BR = 600 | M[600] = 900 |
| Relative | PC + 500 = 702 | M[702] = 325 |
| Stack | SP = 999 | M[999] = 1200 |

Remember: relative uses the **updated** PC (202, after the two-word fetch), not
200. Wrote 700 instead of 702 in a class test once — one careless mark gone.

`addressing_modes.c` in this folder sets up exactly this memory picture and
prints the same table.

## RISC vs CISC

| | RISC | CISC |
|---|------|------|
| Instruction count | few, simple | many, some very complex |
| Instruction length | fixed (one word) | variable (1 to ~15 bytes) |
| Addressing modes | 3–5 | 12 or more |
| Memory access | only LOAD/STORE touch memory | most instructions can |
| Registers | large register file (32+) | few (8–16) |
| Control unit | hardwired | usually microprogrammed |
| Cycles per instruction | ~1 (pipelined) | several |
| Code size | larger | smaller |
| Examples | MIPS, ARM, SPARC | x86, VAX |

The RISC bet: compilers use only the simple instructions anyway, so make those
fast and throw the rest out. Fixed length + load/store discipline is what makes
clean pipelining possible (Unit 10).

## Instruction length vs number of registers

The fields fight over a fixed instruction width. In a 16-bit, 3-register format:

- 16 registers → each register field is 4 bits → 3×4 = 12 bits used → 4 bits
  of opcode → only 16 operations.
- 32 registers → each field is 5 bits → 3×5 = 15 bits used → 1 bit of opcode
  → 2 operations. Useless.

So more addressable registers means wider register fields, which squeezes the
opcode (fewer operations) or forces a longer instruction (more fetch bandwidth,
bigger code). This is why real ISAs sit around 16–32 registers.

## Solved numericals

**Q1.** A computer uses 32-bit instructions with an 8-bit opcode, one 4-bit
register field and one memory address field. Find the number of opcodes, the
number of registers, and the maximum directly addressable memory.

Address field = 32 − 8 − 4 = 20 bits.
Opcodes = 2^8 = 256. Registers = 2^4 = 16.
Memory = 2^20 words = 1M words.
**Ans:** 256 opcodes, 16 registers, 1M (1048576) words.

**Q2.** A machine has 16-bit instructions and register-to-register operations of
the form `OP R1, R2, R3`. How many opcodes are possible with 16 registers? What
happens if the register file grows to 32?

16 registers → 4 bits per field → 3×4 = 12 bits → opcode = 16 − 12 = 4 bits
→ 2^4 = 16 opcodes.
32 registers → 5 bits per field → 3×5 = 15 bits → opcode = 1 bit → 2 opcodes.
**Ans:** 16 opcodes with 16 registers; only 2 opcodes with 32 — doubling the
registers cost 87.5% of the opcode space (14 of 16 opcodes gone).

**Q3.** A relative branch instruction is at address 750 (one word). Its 8-bit
displacement field holds 11010001 (2's complement). Where does the branch go?

11010001 as 2's complement: MSB is 1 so negative; invert + 1 → 00101111 = 47,
so the displacement is −47.
PC after fetch = 751. Target = 751 − 47 = 704.
**Ans:** branch target = 704.
