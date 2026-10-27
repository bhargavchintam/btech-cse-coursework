# Unit 1 — Introduction to Microcontrollers and the 8051

## Microprocessor vs microcontroller

A microprocessor is only the CPU on a chip — the ALU, registers and control unit.
To build a working system you bolt on RAM, ROM, timers and I/O ports externally and
wire them across an address/data bus. That is what a PC motherboard does around an
8086 or a Pentium. A microcontroller puts the CPU *and* a fixed amount of RAM, ROM,
timers, a serial port and I/O ports on the one die. It is a whole computer on a chip,
built for one dedicated job rather than general computing.

| Aspect                 | Microprocessor (8085/8086)      | Microcontroller (8051)            |
|------------------------|----------------------------------|------------------------------------|
| On chip                | CPU only                         | CPU + RAM + ROM + I/O + timer + serial |
| RAM / ROM / I/O        | external, chosen by the designer | fixed amount, on chip              |
| System size            | large (many chips)               | single chip                        |
| Purpose               | general purpose, expandable       | dedicated, embedded control        |
| Instruction set        | rich data-processing set         | control/bit-handling oriented      |
| Cost of full system    | higher                           | lower                              |
| Power consumption      | higher                           | lower                              |
| Address/data bus       | brought out on pins              | mostly internal                    |
| Typical use            | computers, general computing     | washing machine, car ECU, toys     |

> Sir's one-liner: a microprocessor is a CPU looking for memory; a microcontroller
> already brought its own. Lost half a mark in IA1 for writing "no ROM" for the 8051 —
> the 8051 *has* 4K of on-chip ROM, it is the 8031 that has none.

## Harvard vs von Neumann in the 8051

Two ways to organise program and data memory:

- **von Neumann (Princeton):** one memory space holds both code and data, reached over
  a single bus. Simple, but the CPU cannot fetch an instruction and a data byte in the
  same cycle. This is the x86/8085 style.
- **Harvard:** program memory and data memory are *separate* address spaces with
  separate buses, so an instruction fetch and a data access can overlap.

The 8051 is a **Harvard** machine. Its on-chip ROM (code) and its RAM (data) are
different address spaces reached by different instructions, and even the external
64K code space and external 64K data space are distinct — the chip tells them apart
with separate control signals (`PSEN` strobes external code, `RD`/`WR` strobe external
data). So an address like 2000H can name a code byte *or* a data byte depending on the
instruction: `MOVC A, @A+DPTR` reads code memory, `MOVX A, @DPTR` reads external data.
Code memory is read-only while the program runs.

## The 8051 family — 8031 / 8051 / 8052

The 8051 is the core of a family. Members differ mainly in how much on-chip memory
they carry and how many timers and interrupts they have; the CPU and instruction set
are identical, so code written for one runs on the others.

| Feature (on chip)      | 8031      | 8051   | 8052   |
|------------------------|-----------|--------|--------|
| ROM (program memory)   | 0 (none)  | 4 KB   | 8 KB   |
| RAM (data memory)      | 128 bytes | 128 bytes | 256 bytes |
| Timers/counters        | 2         | 2      | 3      |
| I/O pins               | 32        | 32     | 32     |
| Serial ports           | 1         | 1      | 1      |
| Interrupt sources      | 6         | 6      | 7      |

The **8031** is the ROM-less version: it must fetch all its program from an external
ROM, which uses up Port 0 and Port 2 as the address/data bus. The **8051** is the
baseline part with 4 KB of mask ROM burned in at the factory. The **8052** is the
enhanced part — double the ROM and RAM, a third timer (Timer 2) and one more interrupt
source (Timer 2's own vector at 002BH). The **8751** is the same as the 8051 but with UV-erasable EPROM instead of
mask ROM, and the **89C51** (Atmel) uses flash, which is what the college lab boards use
because flash can be reprogrammed at your desk.

## Key features of the 8051

The standard feature list, worth memorising verbatim for the exam:

- 8-bit CPU optimised for control applications
- 4 KB of on-chip ROM (program memory)
- 128 bytes of on-chip RAM (data memory)
- Four 8-bit bidirectional I/O ports — P0, P1, P2, P3 — giving 32 I/O lines
- Two 16-bit timers/counters (Timer 0 and Timer 1)
- One full-duplex serial port (UART)
- Six interrupt sources (two external, two timer, one serial, plus RESET), with two
  priority levels
- On-chip oscillator and clock circuitry (crystal across XTAL1/XTAL2, usually 12 MHz)
- A Boolean (bit) processor — instructions that set, clear, test and move single bits
- Can address 64 KB of external program memory and 64 KB of external data memory
- 40-pin DIP package; a CISC instruction set of 111 instructions

At a 12 MHz crystal the machine cycle is 1 µs (the 8051 divides the crystal by 12),
which is the number every timer/delay calculation in this course starts from.

## Internal architecture — reading the block diagram

Everything hangs off an internal 8-bit bus that ties these blocks together:

- **CPU / control unit** — fetches each instruction from program memory, decodes it and
  sequences the rest of the chip. Holds the Program Counter (PC, 16-bit) that points at
  the next code byte.
- **ALU** — the 8-bit arithmetic/logic unit. Does ADD, SUBB, MUL, DIV, AND, OR, XOR,
  rotates and comparisons. Works with the **A (accumulator)** and **B** registers; B is
  the partner register for `MUL AB` and `DIV AB`. Results set the flags in **PSW**
  (carry, auxiliary carry, overflow, parity).
- **On-chip ROM (4 KB)** — non-volatile program memory holding the code.
- **On-chip RAM (128 bytes)** — read/write data memory: four register banks (R0–R7),
  a bit-addressable region, and general scratch/stack space.
- **SFRs (special function registers)** — a block of control/status registers sitting in
  the 80H–FFH address range: A, B, PSW, the port latches P0–P3, TMOD, TCON, TH0/TL0,
  TH1/TL1, SCON, SBUF, IE, IP, DPTR (DPL/DPH), SP. Programming the 8051 is largely a
  matter of writing the right SFRs.
- **Four I/O ports (P0–P3)** — the pins to the outside world; each has a latch, an output
  driver and an input buffer.
- **Two timers/counters** — 16-bit up-counters that tick off machine cycles (timer mode)
  or external pulses (counter mode).
- **Serial port** — the UART, using SBUF for data and SCON for control, for byte-serial
  communication.
- **Interrupt control** — logic that lets the external pins, the timers and the serial
  port break into the program; enabled through IE and prioritised through IP.
- **Oscillator and timing** — the on-chip clock generator driven by the external crystal.

## CISC nature

The 8051 is a **CISC** (Complex Instruction Set Computer). Its instructions are
variable length — one, two or three bytes — and a single instruction can do a fairly
involved job (`MOVC A, @A+DPTR` does an addition and a code fetch; `DJNZ` decrements,
tests and branches). There are many addressing modes and the control logic is
microcoded, so different instructions take different numbers of machine cycles. This is
the opposite of the RISC idea (few, fixed-length, single-cycle instructions). CISC keeps
programs compact — an asset when your whole program has to fit in 4 KB of ROM.

## Typical embedded applications

Microcontrollers are hidden inside things that are not obviously "computers":

- Home appliances — washing machines, microwave ovens, air conditioners, TVs, remotes
- Automotive — engine control units, ABS, airbags, dashboard, climate control
- Office equipment — printers, photocopiers, keyboards, mice
- Instrumentation and industrial control — sensors, motor control, robotics, PLCs
- Consumer/portable — toys, cameras, cordless phones, fitness gadgets

A modern car alone hides dozens of microcontrollers. The common thread: a dedicated,
cost-sensitive, real-time control job — exactly what the 8051 was designed for.

## Criteria for choosing a microcontroller

Mazidi frames the choice around three questions:

1. **Does it meet the computing need efficiently and cheaply?** Look at speed, the
   package and pin count, power consumption, amount of RAM and ROM, number of I/O pins,
   number of timers, how easily the design can be upgraded, and above all the cost per
   unit — a few rupees matter when you build a million units.
2. **Are software development tools available?** Assemblers, C compilers, debuggers,
   simulators, emulators and in-circuit programmers, plus good technical support and
   documentation. A powerful chip with no tools is unusable.
3. **Is the part widely and reliably available?** More than one vendor should second-source
   it so the design is not held hostage to one supplier. The 8051 scores heavily here —
   it is second-sourced by Intel, Atmel, Philips, Dallas, Siemens and many others, which
   is why it is still taught and used decades on.

## Solved short-answer items

**Q1.** State the on-chip memory and timer count of the 8051, and how the 8052 differs.

The 8051 has 4 KB of on-chip ROM (program) and 128 bytes of on-chip RAM (data), with two
16-bit timers and six interrupt sources. The 8052 doubles both memories to 8 KB ROM and
256 bytes RAM, adds a third timer (Timer 2) and provides seven interrupt sources. The CPU
and instruction set are identical, so 8051 code runs unchanged on an 8052.

**Ans:** 8051 = 4 KB ROM / 128 B RAM / 2 timers / 6 interrupts; 8052 = 8 KB / 256 B /
3 timers / 7 interrupts.

**Q2.** The 8051's Program Counter and DPTR are both 16 bits wide. What is the maximum
program memory and external data memory the chip can address?

A 16-bit pointer spans 2¹⁶ distinct addresses = 65536 bytes = 64 KB. The PC addresses
program (code) memory, so up to 64 KB of program memory. DPTR is the data pointer for
external memory, so up to 64 KB of external data memory. The two are separate spaces
(Harvard), so this is 64 KB of code *and* a separate 64 KB of data, not 64 KB shared.

**Ans:** 2¹⁶ = 64 KB of external program memory and 64 KB of external data memory.
