# Unit 1 — Introduction to System Software

## System software vs application software
- **System software** supports the operation and use of the computer itself — it is tied to the machine architecture (assemblers, loaders, compilers, operating systems).
- **Application software** solves a user's problem (payroll, games) and is largely machine-independent.

System software is *machine-dependent* because it deals with the actual instruction set, registers and memory of the machine.

## The components
| Software | Job |
|---|---|
| **Assembler** | translates assembly language → machine code (object program) |
| **Loader / Linker** | brings the object program into memory and prepares it to run |
| **Macro processor** | expands macros before assembly |
| **Compiler** | translates a high-level language → machine/assembly code |
| **Interpreter** | executes a high-level program statement by statement |
| **Editor** | creates and modifies source programs |
| **Debugger** | helps find and fix errors at run time |
| **Operating system** | manages all resources; the most important system software |

## Why study SIC
Real machines have messy instruction sets. The book uses **SIC** (Simplified Instructional Computer) and **SIC/XE** (eXtra Equipment) — hypothetical machines simple enough to learn on, but with the same problems (addressing, relocation, linking) as real hardware.

## Solved
**1. Is a text editor system or application software?** System software — it is a tool that supports program development, independent of any one user problem.

**2. Name the two passes of an assembler and their jobs.** Pass 1 assigns addresses (LOCCTR) and builds the symbol table; Pass 2 generates the object code.
