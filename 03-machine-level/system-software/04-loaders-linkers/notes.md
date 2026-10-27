# Unit 4 — Loaders and Linkers

## What a loader does
Three jobs: **allocation** (space in memory), **linking** (resolve references between programs), **relocation** (adjust addresses), and **loading** (place the code and start it).

## Types
- **Absolute loader** — object program is loaded at the address the assembler assumed; the loader only places the bytes and jumps. Simple, but the program can't be moved. (`lab/c/absolute_loader.c`)
- **Bootstrap loader** — a tiny loader (in ROM) that loads the OS when the machine is switched on.
- **Relocating loader (relative loader)** — allows the program to be loaded anywhere; uses **modification records** or a relocation bit mask to fix address-dependent parts.
- **Linking loader** — combines several object programs, resolving external symbols, and loads them; does linking at load time.
- **Linkage editor** — produces a linked executable file once; the loader then just loads it (faster for repeated runs).
- **Dynamic linking** — library routines are linked only when first called at run time (shared libraries).

## Program relocation
The problem: the assembler doesn't know where the program will actually be loaded. Direct (format-4) addresses depend on the load address, so each must be adjusted. The assembler flags them with **modification (M) records**; the loader adds the actual load address to each.

## Program linking
- **EXTDEF** — symbols this control section defines for others.
- **EXTREF** — symbols this control section uses from others.
- **D / R records** in the object program carry these; the loader builds an external symbol table (ESTAB) and resolves the references.

## Solved
**1. Absolute vs relocating loader?** Absolute loads at a fixed address and cannot move; relocating adjusts addresses so the program can load anywhere.

**2. What resolves an EXTREF symbol?** The loader looks it up in ESTAB (built from the EXTDEFs of other control sections) and patches the address via the M record.
