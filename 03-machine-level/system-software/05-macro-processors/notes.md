# Unit 5 — Macro Processors

## What a macro is
A **macro** names a sequence of statements. A single macro **invocation** is replaced by the whole body — **expansion** — before assembly. Unlike a subroutine, the code is inserted in line every time (no call/return).

## Definition and expansion
- `MACRO` … `MEND` delimit a definition.
- Parameters begin with `&`. On expansion each parameter is replaced by the corresponding argument.

```
M1  MACRO  &A,&B
    LDA    &A
    ADD    &B
    STA    &A
    MEND
```
`M1  DATA1,DATA2` expands to `LDA DATA1 / ADD DATA2 / STA DATA1`. (`lab/c/macro_processor.c`)

## One-pass processor data structures
- **DEFTAB** — stores the macro definitions (body lines).
- **NAMTAB** — macro names, with pointers into DEFTAB.
- **ARGTAB** — the arguments of the current invocation, by position.

A one-pass processor works if every macro is **defined before it is used**.

## Machine-independent features
- **Concatenation** of parameters with the rest of a token (`&ID→1`).
- **Generation of unique labels** ($-labels) so an expanded body used twice doesn't create duplicate labels.
- **Conditional macro expansion** (IF-ELSE-ENDIF, SET symbols) — expansion depends on the arguments.
- **Keyword macro parameters** — arguments given as `name=value`, in any order, with defaults.

## Solved
**1. Macro vs subroutine?** A macro's body is inserted at every call (bigger code, no call overhead); a subroutine exists once and is called (smaller code, call/return overhead).

**2. Purpose of NAMTAB?** To hold macro names and point to where each definition starts and ends in DEFTAB.
