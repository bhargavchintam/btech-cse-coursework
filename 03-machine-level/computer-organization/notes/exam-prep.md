# Exam prep — Computer Organization and Architecture

The questions that keep coming back, unit by unit. Marks are the usual weight
they carry. Work the numericals from the values here — they are the ones verified
in the unit notes.

## Unit 1 — Number Systems and Codes

- Convert (429)₁₀ to binary, octal and hexadecimal. (6 marks)
- Perform 23 − 45 using 8-bit 2's complement arithmetic and give the decimal result. (6 marks)
- Explain sign-magnitude, 1's complement and 2's complement; why do real machines use 2's complement? (8 marks)
- Add 27 and 48 in BCD, showing the +6 correction. (5 marks)
- Encode data 1011 into a (7,4) Hamming SEC codeword, then locate and correct a single-bit error in a received word. (10 marks) — came in the 2017 paper
- Convert 1011₂ to Gray code and back; why is Gray code used in shaft encoders? (6 marks)

## Unit 2 — Boolean Algebra and Logic Gates

- State and prove De Morgan's theorems. (6 marks)
- Simplify F(A,B,C,D) = Σm(0,1,2,5,8,9,10) using a K-map. (8 marks)
- Show that NAND is a universal gate by realising NOT, AND and OR with it. (6 marks)
- Simplify AB + A'C + BC using the consensus theorem and comment on the redundant term. (5 marks)
- Realise F = AB + A'C using NOR gates only. (6 marks)

## Unit 3 — Combinational Circuits

- Design a full adder: truth table, sum and carry expressions, logic diagram. (10 marks)
- Implement a 4-bit binary-to-Gray code converter. (6 marks)
- Design a 4-to-1 multiplexer and use it to implement F = Σm(1,2,4,7). (8 marks)
- Explain a 3-to-8 line decoder and its use in memory chip addressing. (6 marks)
- Design a 2-bit magnitude comparator giving A>B, A=B, A<B. (8 marks)

## Unit 4 — Sequential Circuits

- Differentiate a latch from a flip-flop; define setup time and hold time. (5 marks)
- Write the excitation tables of SR, JK, D and T flip-flops. (6 marks) — asked in IA1
- Explain race-around in a JK flip-flop and how the master-slave configuration removes it. (8 marks)
- Convert a JK flip-flop into a D flip-flop and into a T flip-flop. (8 marks)
- Design a mod-6 synchronous counter using JK flip-flops and verify it is self-correcting. (10 marks)
- Compare ring and Johnson counters; how many states does each give with n flip-flops, and how many flip-flops does a mod-60 counter need? (6 marks)

## Unit 5 — Basic Computer Organization

- Draw and explain the five functional units of a computer. (8 marks)
- Distinguish von Neumann and Harvard architectures; what is the von Neumann bottleneck? (6 marks)
- List the registers PC, IR, MAR, MDR and ACC and give the one-line role of each. (6 marks)
- Write the register-transfer micro-operations of the instruction fetch cycle. (6 marks)
- A memory stores 64K words of 16 bits each. Find the number of address lines, data lines and the total capacity in bytes. (6 marks)

## Unit 6 — Instruction Set and Addressing Modes

- Write programs to evaluate X = (A+B)*(C+D) on 3-, 2-, 1- and 0-address machines and compare the instruction counts. (10 marks) — came in the 2017 paper
- Explain every addressing mode with its effective-address expression and one example. (10 marks)
- For a given memory image, find the operand fetched under direct, indirect, indexed, register-indirect and relative modes. (8 marks)
- Compare RISC and CISC across at least six points. (8 marks)
- A 32-bit instruction has an 8-bit opcode, a 4-bit register field and one memory-address field. Find the number of opcodes, registers and the maximum addressable memory. (6 marks)
- Explain how instruction length trades off against the number of addressable registers in a fixed-width format. (5 marks)

## Unit 7 — Computer Arithmetic

- Multiply −3 by 4 using Booth's algorithm (4-bit), showing the register trace at every step. (10 marks) — came in the 2017 paper
- Divide two unsigned numbers using the restoring division algorithm and show the trace. (10 marks)
- Compare restoring and non-restoring division. (6 marks)
- Represent −6.75 in IEEE-754 single precision; label the sign, exponent and mantissa fields. (8 marks)
- Explain the IEEE-754 single and double precision formats; why is the exponent bias 127, not 128? (6 marks)
- Explain a carry-look-ahead adder and why it beats ripple-carry on delay. (8 marks)

## Unit 8 — Processor and Control Unit

- Draw the single-bus CPU datapath and explain why the temporary registers Y and Z are needed. (8 marks)
- Write the complete control sequence (micro-operations and control signals) for ADD R1,(R2). (10 marks) — came in the 2017 paper
- Explain hardwired control and write the signal expressions for Zin and End. (8 marks)
- Explain microprogrammed control: control store, control word, microPC and starting-address generator. (8 marks) — asked in IA1
- Compare hardwired and microprogrammed control units. (6 marks)
- Distinguish horizontal and vertical microinstructions and state the width-vs-decode trade-off. (6 marks)

## Unit 9 — Memory Organization

- Explain the memory hierarchy and the principle of locality (temporal and spatial). (6 marks)
- Differentiate SRAM and DRAM; why does DRAM need periodic refresh? (6 marks) — asked in IA1
- Explain direct, fully-associative and set-associative cache mapping. (10 marks) — came in the 2017 paper
- A 32-bit byte-addressable machine has a 32 KB direct-mapped cache with 16-byte blocks. Find the tag, line and offset field widths. (8 marks)
- Compute the average memory access time for hit ratio 0.95, cache access 10 ns and memory access 100 ns. (6 marks)
- What is virtual memory? Explain paging and the role of the TLB. (8 marks)

## Unit 10 — I/O and Pipelining

- Compare programmed I/O, interrupt-driven I/O and DMA. (8 marks)
- Explain the working of DMA and cycle stealing. (6 marks)
- What is an interrupt? Explain the interrupt cycle and how interrupt priority is handled. (8 marks) — asked in IA1
- Explain instruction pipelining and derive the speedup of a k-stage pipeline for n instructions. (10 marks)
- List the pipeline hazards — structural, data and control — with one remedy for each. (8 marks)
- A 4-stage pipeline executes 100 instructions. Find its speedup over a non-pipelined processor. (6 marks)
