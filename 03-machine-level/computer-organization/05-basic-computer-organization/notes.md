# Unit 5 — Basic Computer Organization

## Functional units of a computer

Every computer, from the 8085 to whatever is in my phone, is built from the same
five blocks. The processor is the ALU + control unit together.

```
            +-----------------------------------+
            |            PROCESSOR              |
  +-----+   |  +---------+      +------------+  |   +------+
  |INPUT|-->|  |   ALU   |<---->|  CONTROL   |  |-->|OUTPUT|
  +-----+   |  +---------+      |    UNIT    |  |   +------+
            |       ^           +------------+  |
            +-------|---------------------------+
                    v
              +-----------+
              |  MEMORY   |
              +-----------+
```

- Input unit: gets data and programs in (keyboard, mouse).
- Memory: stores both the program and the data. Primary (RAM) is what the CPU
  talks to directly; secondary (disk) is for keeps.
- ALU: does the actual arithmetic and logic. Everything else exists to feed it.
- Control unit: reads instructions and generates the timing/control signals
  that make the other units do their job. It does no computation itself.
- Output unit: results go out (monitor, printer).

## Von Neumann vs Harvard

| Point | Von Neumann | Harvard |
|---|---|---|
| Memory | One memory for program + data | Separate program and data memories |
| Buses | Single bus shared by both | Separate buses, can fetch instr and data together |
| Speed | Bottlenecked by the shared bus | Faster, parallel access |
| Cost / flexibility | Cheaper, program can be treated as data | Costlier, fixed split |
| Where used | General purpose PCs | Microcontrollers, DSPs (8051 is Harvard) |

The shared-bus limit of von Neumann is called the *von Neumann bottleneck* —
the CPU can either fetch an instruction or move data in one cycle, not both.

## The stored program concept

Before this idea, machines like ENIAC were programmed by rewiring plugboards.
Von Neumann's idea (1945): store the instructions in the same memory as data,
as numbers. Then the machine can fetch them one by one, and a program can even
be loaded, modified or generated like any other data. This one idea is why a
single computer can run a game, a compiler and a calculator without touching
the hardware.

## Registers every CPU has

| Register | Full form | One-line job |
|---|---|---|
| PC | Program Counter | holds the address of the NEXT instruction to fetch |
| IR | Instruction Register | holds the instruction currently being executed |
| MAR | Memory Address Register | holds the address for the current memory access |
| MDR | Memory Data Register | holds the data going to / coming from memory |
| ACC | Accumulator | holds one ALU operand and receives the ALU result |
| R0..Rn | General purpose | scratch registers the programmer uses freely |

MAR holds the address, MDR holds the data — I mixed these up in IA1. MAR
connects to the address bus, MDR connects to the data bus. That is how to
remember it.

## Bus structure

A bus is just a bundle of wires shared by many units. In the single bus
organization, all registers, the ALU and memory hang off one internal bus, so
only one transfer can happen per clock — cheap but slow. Multi-bus
organizations allow parallel transfers at extra cost.

Externally the system bus is split by purpose:

| Bus | Direction | Carries | Width decides |
|---|---|---|---|
| Address bus | CPU -> memory/IO | the address | how much memory is addressable |
| Data bus | bidirectional | the data / instruction | word transferred per access |
| Control bus | mixed | READ, WRITE, clock, interrupt lines | — |

A 24-bit address bus can address 2^24 = 16M locations, whatever the data bus
width is. The two widths are independent.

## Register transfer notation

RTL is the shorthand for describing micro-operations. Square brackets mean
"contents of".

- `R1 <- [R2]` : copy the contents of R2 into R1 (R2 unchanged).
- `MAR <- [PC]` : PC's contents go to MAR.
- `MDR <- M[[MAR]]` : read memory at the address held in MAR, into MDR.
  Usually written `MDR <- M[MAR]` for short.
- `R3 <- [R1] + [R2]` : add and store — one ALU micro-operation.
- A condition prefixes with a colon: `ACC=0 : PC <- addr` (the jump-if-zero).

## The instruction cycle

The machine does exactly one thing forever: fetch, decode, execute, repeat.

**Fetch** — same four micro-operations for every instruction:

| Step | RTL | What happens |
|---|---|---|
| T1 | `MAR <- [PC]` | address of next instruction to MAR |
| T2 | `MDR <- M[MAR]` | memory read, instruction lands in MDR |
| T3 | `IR <- [MDR]` | instruction moves into IR |
| T4 | `PC <- [PC] + 1` | PC now points to the following instruction |

T2 and T4 can overlap in real machines since they use different paths, but for
the exam write them as separate steps.

**Decode** — the control unit looks at the opcode field of IR and works out
which execute sequence to run. No RTL, it is pure combinational logic on the
opcode bits.

**Execute** — depends on the instruction. Example, single-address machine,
`ADD X` meaning ACC <- ACC + M[X]:

| Step | RTL |
|---|---|
| T5 | `MAR <- IR(address)` |
| T6 | `MDR <- M[MAR]` |
| T7 | `ACC <- [ACC] + [MDR]` |

So one `ADD X` costs two memory accesses in total: one to fetch the
instruction, one to fetch the operand.

## Interrupt cycle in brief

After every execute phase, the CPU checks the interrupt line. If an interrupt
is pending: save the PC (to stack or a fixed location), load PC with the
address of the interrupt service routine, and continue fetching from there.
The ISR ends by restoring the saved PC. The check happens only at instruction
boundaries — an instruction is never abandoned halfway.

## Word length and addressable memory

Word length = number of bits the CPU handles as one unit (register width,
usually data bus width too). Addressability is a separate question: with `n`
address bits you can address `2^n` locations, each location being one word (or
one byte, in byte-addressable machines).

The two formulas that solve every problem of this type:

- number of address bits `n = log2(number of locations)`
- total capacity = number of locations x bits per location

For 64K words: 64K = 64 x 1024 = 65536 = 2^16, so **16 address bits**. Number
of locations only — word size does not enter this calculation.

## Solved numericals

**Q1. A memory stores 64K words of 16 bits each. How many address bits and
data bits are needed, and what is the total capacity in bytes?**

64K = 2^16 locations, so address bits = 16.
Each word is 16 bits, so data lines = 16.
Total = 65536 x 16 = 1048576 bits = 131072 bytes = **128 KB**.

**Ans:** 16 address bits, 16 data bits, 128 KB.

**Q2. A RAM chip is organised as 2K x 8. (a) How many address and data lines
on the chip? (b) How many such chips build a 16K x 8 memory?**

(a) 2K = 2048 = 2^11, so 11 address lines; 8 data lines.
(b) 16K / 2K = 8 chips, stacked with a 3-to-8 decoder on the top 3 address
bits (16K needs 14 address bits = 11 to each chip + 3 to the decoder).

**Ans:** 11 address lines, 8 data lines; 8 chips.

**Q3. A machine has a 20-bit address bus. (a) Maximum memory if it is
byte-addressable? (b) If instead each address selects a 32-bit word, what is
the capacity in bytes?**

(a) 2^20 bytes = 1048576 bytes = **1 MB**.
(b) 2^20 words x 4 bytes/word = 4194304 bytes = **4 MB**.

**Ans:** 1 MB byte-addressable; 4 MB word-addressable.

> Same address bus, four times the memory — addressability is about locations,
> not bytes. Classic one-mark trap.
