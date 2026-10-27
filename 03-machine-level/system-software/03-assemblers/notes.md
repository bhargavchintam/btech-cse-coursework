# Unit 3 — Assemblers

## Basic functions
Translate mnemonic opcodes to machine code, assign machine addresses to symbolic labels, build the object program. Needs two passes because of **forward references** (a symbol used before it is defined).

## Data structures
- **OPTAB** — opcode → machine code (and instruction format). Static.
- **SYMTAB** — label → address. Built in pass 1, used in pass 2.
- **LOCCTR** — location counter; the address of the next instruction/data.

## Pass 1 (assign addresses, build SYMTAB)
1. Read the START line; set LOCCTR to the starting address.
2. For each line until END:
   - if there is a label, enter (label, LOCCTR) in SYMTAB;
   - look up the opcode: if in OPTAB, add the instruction length; WORD → 3; RESW → 3×n; RESB → n; BYTE → its length.
   - write the line + LOCCTR to the intermediate file.
3. Program length = LOCCTR − starting address.

## Pass 2 (generate object code)
1. For each line, look up the opcode in OPTAB and the operand in SYMTAB, assemble the object code.
2. WORD → the constant; BYTE → the bytes; RESW/RESB → reserve, no object code.
3. Write Header, Text and End records.

`lab/c/pass1.c` and `lab/c/pass2.c` implement this. On the COPY example they give length 000012 and:
```
H^COPY  ^001000^000012
T^001000^0F^031009^18100C^0C100F^000005^000001
E^001000
```

## Object program record format
- **H** — Header: program name, starting address, length.
- **T** — Text: starting address, length, object code (≤ 30 bytes / 0x1E per record).
- **M** — Modification: for relocation / format-4 addresses.
- **E** — End: address of the first executable instruction.

## Machine-independent features
Literals (`=C'EOF'`), symbol-defining statements (EQU, ORG), expressions, **program blocks**, and **control sections** (assembled together but loaded separately; need M records for external references).

## Solved
**1. Why two passes?** Forward references — a symbol may be used before its address is known. Pass 1 fixes all addresses first.

**2. LOCCTR after `ALPHA RESW 2` at 1009?** 1009 + 3×2 = **100F**.
