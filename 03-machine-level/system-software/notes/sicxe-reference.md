# SIC/XE quick reference

## Registers
| Reg | No. | Use |
|---|---|---|
| A | 0 | accumulator |
| X | 1 | index |
| L | 2 | linkage (RSUB return) |
| B | 3 | base (base-relative) |
| S | 4 | general |
| T | 5 | general |
| F | 6 | floating point (48-bit) |
| PC | 8 | program counter |
| SW | 9 | status word |

## Instruction formats
| Fmt | Bits | Fields |
|---|---|---|
| 1 | 8 | op |
| 2 | 16 | op, r1, r2 |
| 3 | 24 | op(6) n i x b p e disp(12) |
| 4 | 32 | op(6) n i x b p e address(20) |

## Flag bits (format 3/4)
- n i = addressing: 01 immediate (#), 10 indirect (@), 11 simple
- x = indexed (add X)
- b p = 01 PC-relative, 10 base-relative, 00 direct
- e = 0 format 3, 1 format 4

## Target address
- PC-relative: TA = (PC) + disp, disp −2048…2047
- Base-relative: TA = (B) + disp, disp 0…4095
- Indexed adds (X) to TA.

## Common opcodes (hex)
LDA 00 · LDX 04 · LDL 08 · STA 0C · STX 10 · STL 14 · ADD 18 · SUB 1C · MUL 20 · DIV 24 · COMP 28 · J 3C · JEQ 30 · JLT 38 · JSUB 48 · RSUB 4C · LDCH 50 · STCH 54 · TIX 2C

## Assembler directives
START, END, WORD, RESW, RESB, BYTE, EQU, ORG, LTORG, USE, CSECT, EXTDEF, EXTREF
