# Unit 10 — I/O Organization and Pipelining

## Memory-mapped vs isolated I/O

The CPU has to talk to device registers (status, control, data buffers) somehow.
Two schemes:

| Point | Memory-mapped I/O | Isolated (I/O-mapped) I/O |
|---|---|---|
| Address space | Device registers sit inside the memory address space | Separate I/O address space |
| Instructions | Ordinary LOAD/STORE work on devices | Special IN/OUT instructions |
| Address decoding | One decoder for everything | Extra control line (IO/M') picks the space |
| Cost | Loses some memory addresses to devices | Loses opcodes to IN/OUT |
| Example | ARM, most RISC machines | 8085/8086 (IN, OUT) |

Memory-mapped is simpler for the programmer — any instruction and addressing
mode that touches memory also works on a device register. Isolated I/O keeps
the full memory space but needs the extra IO/M' line to pick the space.

> Sir's one-liner: memory-mapped eats address space, isolated eats opcodes.
> Two marks, every year.

## Programmed I/O and busy-waiting

The CPU itself moves every byte. Typical loop for reading from a device:

```
WAIT:  read status register
       if READY bit = 0, jump to WAIT     <- busy-waiting
       read data register
       store byte to memory
       if more bytes, jump to WAIT
```

The problem is the wait loop. A keyboard delivers a byte maybe 10 times a
second; a 100 MHz CPU spins through millions of useless status reads in
between. Fine for a tiny embedded controller with nothing else to do,
terrible for a general purpose machine.

## Interrupt-driven I/O

Instead of the CPU asking "ready yet?", the device taps the CPU on the
shoulder when it is ready. The CPU runs the main program and only breaks off
when the interrupt line is asserted.

The interrupt cycle, added at the end of every instruction cycle:

1. Finish the current instruction (interrupts are checked only at instruction
   boundaries, so the machine state is clean).
2. If interrupts are enabled and a request is pending: save the PC (and flags)
   on the stack.
3. Disable further interrupts (so the handler is not interrupted immediately).
4. Load the PC with the address of the interrupt service routine (ISR).
5. ISR runs, services the device, returns (restoring flags and PC).
6. Main program continues as if nothing happened.

**Finding who interrupted — polled vs vectored.** With a single shared INTR
line the CPU has two ways to find the source:

- Polled: the ISR reads the status register of every device in a fixed order
  until it finds the one with its ready bit set. Cheap hardware, slow, and the
  polling order itself fixes the priority.
- Vectored: the interrupting device sends its own vector (a number) on the
  data bus during the interrupt-acknowledge cycle. CPU uses it as an index
  into the interrupt vector table and jumps straight to the right ISR. Fast,
  needs more hardware.

**Priority by daisy chain.** Devices share one INTR line; the acknowledge
signal INTA is threaded through the devices in series:

```
CPU --INTA--> | Dev 1 | --> | Dev 2 | --> | Dev 3 |
              +-------+     +-------+     +-------+
                  |             |             |
INTR <------------+-------------+-------------+
              (highest)                   (lowest)
```

A device that requested the interrupt swallows INTA and puts its vector on
the bus; one that did not passes INTA down the chain. Electrical position IS
the priority — Dev 1, closest to the CPU, always wins.

**Enabling, disabling, nesting.** Interrupts can be masked globally (the
interrupt-enable flag, cleared automatically in step 3 and by DI/EI type
instructions) or per device (mask bits in a controller register). If the ISR
re-enables interrupts, a higher priority device can interrupt the handler
itself — nested interrupts. Each level pushes its own return address on the
stack so they unwind in order; devices at or below the current priority stay
masked, otherwise one chatty device could stack interrupts forever.

## DMA — direct memory access

Interrupts fix the waiting problem but the CPU still copies every word. For a
disk delivering millions of bytes per second that is hopeless. DMA hands the
copying job to a dedicated DMA controller that moves data between device and
memory directly, with no CPU in the data path.

The controller has three registers the CPU can program: address (where in
memory), word count (how much) and control (direction, mode) — plus the bus
handshake lines BR (bus request / HOLD) and BG (bus grant / HLDA).

DMA transfer, step by step:

1. CPU programs the controller: memory start address, word count, direction
   (read/write) and mode into the control register.
2. Device tells the controller it has data (or room) — DMA request.
3. Controller asserts BR (HOLD) to the CPU asking for the buses.
4. CPU finishes the current bus cycle, tri-states its address/data/control
   bus drivers and replies with BG (HLDA).
5. Controller drives the bus: transfers a word directly between device and
   memory, increments the address register, decrements the count.
6. When the count reaches zero the controller releases the bus and raises an
   interrupt to tell the CPU the whole block is done.

Remember: the CPU gets exactly ONE interrupt per block, at the end — not one
per byte. Got this wrong in an IA2 MCQ.

**Cycle stealing vs burst.** In burst (block) mode the controller keeps the
bus for the whole block — fastest transfer, but the CPU is locked out of
memory the whole time. In cycle stealing the controller takes the bus for one
word at a time, sneaking transfers into cycles when the CPU is not using
memory — the CPU barely notices, the transfer takes longer. Disks like burst,
slow devices use cycle stealing.

## Pipelining — the idea

A non-pipelined CPU fetches an instruction, decodes it, executes it, and only
then fetches the next — so the fetch hardware idles during execute and vice
versa. Pipelining overlaps them like an assembly line: while instruction 1
executes, instruction 2 is decoded and instruction 3 fetched. No single
instruction gets faster; *throughput* goes up because one instruction
finishes every cycle once the pipe is full.

The classic 5-stage pipeline:

| Stage | Name | Does |
|---|---|---|
| IF | Instruction fetch | read instruction at PC, PC = PC + 4 |
| ID | Instruction decode | decode, read source registers |
| EX | Execute | ALU operation / address calculation |
| MEM | Memory access | load or store data memory |
| WB | Write back | write result into register file |

Latches between stages hold each instruction's intermediate results, and the
slowest stage sets the clock period.

## Space-time diagram (k = 5, n = 8)

| Instr | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| I1 | IF | ID | EX | MEM | WB | | | | | | | |
| I2 | | IF | ID | EX | MEM | WB | | | | | | |
| I3 | | | IF | ID | EX | MEM | WB | | | | | |
| I4 | | | | IF | ID | EX | MEM | WB | | | | |
| I5 | | | | | IF | ID | EX | MEM | WB | | | |
| I6 | | | | | | IF | ID | EX | MEM | WB | | |
| I7 | | | | | | | IF | ID | EX | MEM | WB | |
| I8 | | | | | | | | IF | ID | EX | MEM | WB |

Read a column top to bottom: in cycle 5 all five stages are busy with five
different instructions. 8 instructions finish in 12 cycles, not 40.

## Speedup

The first instruction takes k cycles to fill the pipe; after that one
instruction completes per cycle, so the remaining n−1 take n−1 cycles:

- Pipelined: k + (n − 1) cycles
- Non-pipelined: n·k cycles

```
        n k
S  =  ---------
      k + n - 1
```

For k = 5, n = 8: S = 40/12 = 3.33. Not 5 — the fill (and drain) of the pipe
costs us. As n → ∞ the k − 1 term stops mattering and S → k. So a k-stage
pipeline gives AT MOST k times speedup, and only for long instruction streams.

## Hazards — when the pipeline stalls

Three kinds, learn the names:

1. **Structural** — two instructions need the same hardware in the same cycle.
   Classic case: one memory for instructions and data, so an IF and a MEM
   collide. Fix: split I-cache and D-cache (Harvard style), or stall.
2. **Data** — an instruction needs a result that is not written yet. The
   common one is RAW (read after write):

```
ADD R1, R2, R3    ; R1 written in WB, cycle 5
SUB R4, R1, R5    ; R1 read in ID, cycle 3  <- too early!
```

   SUB decodes in cycle 3 but ADD only writes R1 back in cycle 5. If the
   register file writes in the first half of a cycle and reads in the second
   half, SUB can pick up R1 in cycle 5 — so it must stall in ID for 2 cycles.
3. **Control** — a branch changes the PC, but by the time it is decided the
   pipeline has already fetched the next sequential instructions. They must be
   thrown away (flushed).

## Forwarding and stalls

The value SUB needs already exists at the end of ADD's EX stage (cycle 3) —
it just has not reached the register file. Forwarding (bypassing) wires the
EX/MEM latch output straight back to the ALU input, so SUB's EX in cycle 4
uses it and no stall is needed. Forwarding kills most RAW stalls; the one it
cannot fully fix is load-use (an instruction using a register the LW just
before it loads), since the data only appears after MEM — 1 bubble even with
forwarding. Without forwarding the hardware inserts bubbles: the dependent
instruction sits in ID and everything behind it waits too. `pipeline_sim.c`
draws this exact picture.

## Branch penalty and prediction

Every taken branch flushes the wrongly fetched instructions behind it — if
the branch is resolved in stage b, that is b − 1 wasted cycles, the branch
penalty. With 20–30% of instructions being branches this wrecks the ideal
CPI of 1, so real machines predict: static prediction guesses one way always
(e.g. backward branches taken, since loops branch back), dynamic prediction
keeps a small table of what each branch did last time (1-bit, or 2-bit
saturating counters so one odd iteration does not flip the guess). A correct
prediction costs nothing; a misprediction costs the flush. Deeper pipelines →
bigger penalty → better predictors needed.

## Solved numericals

**Q1.** A 4-stage pipeline has stage delays 60, 50, 70 and 80 ns, and the
interstage latches add 10 ns. Find the speedup for 100 instructions over a
non-pipelined version built from the same stages.

Pipeline clock = max(60,50,70,80) + 10 = 90 ns.
Non-pipelined time per instruction = 60+50+70+80 = 260 ns (no latches).

- T(non-pipe) = 100 × 260 = 26000 ns
- T(pipe) = (4 + 100 − 1) × 90 = 103 × 90 = 9270 ns

**Ans:** S = 26000 / 9270 = 2.80

**Q2.** A 5-stage pipeline executes 100 instructions of which 20 are branches,
each costing a 2-cycle penalty. No other stalls. Total cycles and CPI?

Base cycles = k + n − 1 = 5 + 100 − 1 = 104. Penalty = 20 × 2 = 40.
Total = 104 + 40 = 144 cycles.

**Ans:** 144 cycles, CPI = 144/100 = 1.44

**Q3.** A 5-stage pipeline runs at 2 GHz and executes 1000 instructions with
no stalls. Find speedup, efficiency and throughput.

Cycle time = 0.5 ns. Total cycles = 5 + 1000 − 1 = 1004.

- Time = 1004 × 0.5 = 502 ns
- S = (1000 × 5) / 1004 = 4.98
- Efficiency = S/k = n/(k+n−1) = 1000/1004 = 0.996 → 99.6%
- Throughput = 1000 / 502 ns = 1.99 × 10⁹ instructions per second

**Ans:** S = 4.98, η = 99.6%, throughput ≈ 2 GIPS — long stream, pipe is
practically ideal.
