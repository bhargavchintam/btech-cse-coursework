# Unit 8 — Processor and Control Unit

## Single-bus organization

Inside the CPU everything talks over one internal bus. Only one register can put its
value on the bus in a given step — that single rule shapes every control sequence in
this unit.

```
              internal processor bus
                       |
   PC   <---->---------|
   MAR  <--------------|-----> address lines (to memory)
   MDR  <---->---------|<----> data lines (to/from memory)
   IR   <--------------|-----> instruction decoder --> control unit
   R0..R(n-1) <---->----|
                       |
   Y    <--------------|
        Y --> [A input]
              [  ALU  ] <-- [B input] (from bus)
               |  ^-- MUX: SelectY / Select4 (constant 4)
   Z    <-- ALU output
   Z    ---->----------|
```

Because there is only one bus, the ALU cannot get both operands from it in the same
step. So one operand is parked in the temporary register Y first, and the ALU result
goes into another temporary Z, which is gated onto the bus in the next step. The
constant 4 at the MUX is there for PC increment — memory is byte addressable and a
word is 4 bytes, so fetch does PC + 4.

## Micro-operations and control signals

An instruction is executed as a sequence of small register transfers called
micro-operations. Each one is caused by asserting control signals for exactly one
clock step.

| Signal | What it does |
|---|---|
| Rin | open the input gate of register R (load R from the bus) |
| Rout | put contents of R on the bus |
| MARin, MDRin, MDRout, PCin, PCout, IRin, Yin, Zin, Zout | same idea for the named registers |
| Read / Write | start a memory read / write cycle |
| WMFC | wait for memory function complete — stall until memory raises MFC |
| Add, Sub, ... | select the ALU function for this step |
| Select4 / SelectY | MUX at the ALU A input: constant 4 or register Y |
| End | this step is the last one; go back to step 1 (fetch) |

A transfer like R1 <- R2 is just: R2out, R1in in one step. Memory is much slower
than the CPU, so any step that needs data from memory asserts Read and a later step
asserts WMFC before using MDR.

## Control sequence (a): instruction fetch

Every instruction begins with the same three steps.

| Step | Micro-operation | Control signals asserted |
|---|---|---|
| 1 | MAR <- [PC], start read, Z <- [PC] + 4 | PCout, MARin, Read, Select4, Add, Zin |
| 2 | PC <- [Z], Y <- [Z], wait for memory | Zout, PCin, Yin, WMFC |
| 3 | IR <- [MDR] | MDRout, IRin |

Step 1 does two things with one bus transfer: PC goes to MAR (address of the
instruction) and, at the same time, through the ALU with the constant 4 to compute
the incremented PC into Z. The Yin in step 2 stashes the updated PC in Y — useless
here, but branch instructions need it (target = updated PC + offset).

> Sir's favourite viva question: why can't PC <- PC + 4 happen in one step? Because
> PC can't be on the bus and loading from Z at the same time. One bus, one transfer.

## Control sequence (b): ADD R1,(R2)

Meaning: R1 <- R1 + M[[R2]]. The operand address is in R2 (register indirect).
Steps 1–3 are fetch, then the execution phase.

| Step | Micro-operation | Control signals asserted |
|---|---|---|
| 1 | MAR <- [PC], Read, Z <- [PC] + 4 | PCout, MARin, Read, Select4, Add, Zin |
| 2 | PC <- [Z], Y <- [Z], wait | Zout, PCin, Yin, WMFC |
| 3 | IR <- [MDR] | MDRout, IRin |
| 4 | MAR <- [R2], start operand read | R2out, MARin, Read |
| 5 | Y <- [R1], wait for operand | R1out, Yin, WMFC |
| 6 | Z <- [Y] + [MDR] | MDRout, SelectY, Add, Zin |
| 7 | R1 <- [Z], done | Zout, R1in, End |

Step 5 overlaps usefully: while memory is still fetching the operand, R1 is moved
into Y, so the moment MDR is valid (after WMFC) step 6 can add. Write this table
exactly like this in the exam — steps numbered, signals comma separated, End on the
last step.

## Hardwired control

The control unit's job: in step k of instruction X, assert this exact set of
signals. A hardwired control unit builds that as pure logic:

```
 clock --> [step counter] --> [step decoder: T1..T7]
 IR     --> [instruction decoder: ADD, BR, ...]        --> [encoder
 flags  ------------------------------------------------->  (AND/OR
 external inputs (MFC etc.) ---------------------------->   logic)] --> Zin, PCout, End, ...
```

Each control signal is an OR of the situations where it must be 1. For example,
from our sequences:

```
Zin = T1 + T6.ADD + T4.BR + ...
End = T7.ADD + T5.BR + ...
```

The step counter is reset by End; WMFC gates the counter's advance so the CPU
actually waits for slow memory. Hardwired control is fast — signals come straight
out of gates, no memory lookup in the path. It is rigid for the same reason: adding
an instruction or fixing a bug means rewiring the encoder logic, i.e. a new chip.
RISC processors use it because their instruction sets are small and regular.

## Microprogrammed control

Different idea: store the control signals instead of computing them. Each step's
signals become a control word — a string of 0s and 1s, one bit per signal (PCin,
PCout, MARin, Read, Add, Zin, ... ). The sequence of control words for one
instruction is its microroutine, and all microroutines live in a small fast memory
called the control store. A microprogram counter (microPC) walks through it:

```
 IR --> [starting address generator] --+
                                       v
                        [microPC] --> [control store] --> control word --> signals
                             ^ +1 each clock
```

The fetch microroutine sits at address 0. After IR is loaded, the starting address
generator maps the opcode to the first microinstruction of that instruction's
microroutine, and the microPC continues from there. End (as a bit in the control
word) resets the microPC to 0.

Sequencing has two designs. Incrementing microPC: microinstructions execute in
order, plus a mapping jump after decode — simple, but conditional behaviour needs
extra hardware. Next-address field: every microinstruction carries the address of
its successor — branching is free (it is just a different next address), but the
field makes every word wider and eats control store.

Big win: to change the instruction set you rewrite the microprogram, not the
hardware. Big cost: every micro-step is a control store read, so it is slower than
hardwired. Classic CISC machines (VAX, 8086 family) are microprogrammed.

## Horizontal vs vertical microinstructions

| | Horizontal | Vertical |
|---|---|---|
| Format | one bit per control signal | signals grouped, each group encoded in a small field |
| Width | very wide (60–100+ bits) | narrow (16–32 bits) |
| Decoding | none — bits drive signals directly | each field needs a decoder |
| Parallelism | any combination of signals in one step | only one signal per group per step |
| Speed | faster (no decode delay) | slower |
| Control store | large | small |

The grouping trick in vertical format works because many signals can never be
asserted together anyway — only one register drives the bus at a time, so all the
Rout signals can share one encoded field. Width vs decode time is the whole
trade-off; real designs often sit in between.

## Hardwired vs microprogrammed

| | Hardwired | Microprogrammed |
|---|---|---|
| Signals generated by | combinational logic (counter + decoders + gates) | control words read from control store |
| Speed | fast | slower (store access every micro-step) |
| Flexibility | none — changes need redesign | high — edit the microprogram |
| Instruction set suited | small, regular (RISC) | large, complex (CISC) |
| Design effort | hard to design and debug | systematic, easier to modify |
| Cost for complex ISA | grows badly | handles it cheaply |

Remember: hardwired = fast + rigid, microprogrammed = flexible + slow. I wrote them
the wrong way round in a class test once. Never again.

## Solved numericals

**Q1.** A processor needs 46 control signals. They fall into four groups of mutually
exclusive signals: 20, 12, 8 and 6 signals. Find the control word width for
(i) horizontal and (ii) vertical organization. Each vertical field must also encode
"no signal active".

(i) Horizontal: one bit per signal = **46 bits**.

(ii) Vertical: a group of k mutually exclusive signals plus the none-code needs
ceil(log2(k+1)) bits.

| Group | Signals | Codes needed | Bits |
|---|---|---|---|
| 1 | 20 | 21 | 5 |
| 2 | 12 | 13 | 4 |
| 3 | 8 | 9 | 4 |
| 4 | 6 | 7 | 3 |

Width = 5 + 4 + 4 + 3 = 16 bits.

**Ans:** horizontal 46 bits, vertical 16 bits — a saving of 30 bits per
microinstruction, paid for with four decoders and lost parallelism.

**Q2.** A microprogrammed control unit has a control store of 1024 words. Each
microinstruction has 32 control signal bits, a flag-select field to choose one of 8
condition flags, and a next-address field. Find the microinstruction width and the
total control store size.

Next-address field: must address 1024 words = ceil(log2(1024)) = 10 bits.
Flag-select field: 8 conditions = ceil(log2(8)) = 3 bits.

Width = 32 + 3 + 10 = 45 bits.

Control store size = 1024 x 45 = 46080 bits = 46080 / 8 = 5760 bytes.

**Ans:** microinstruction width = 45 bits, control store = 46080 bits = 5760 bytes
= 5.625 KB.
