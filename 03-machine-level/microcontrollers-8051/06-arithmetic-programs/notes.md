# Unit 6 — Arithmetic Programming on the 8051

The 8051 ALU is 8 bits wide. Every ADD, SUBB, MUL and DIV works on a byte at a
time, and anything wider than 8 bits (16-bit sums, 4-digit BCD) has to be built
up byte by byte, propagating the carry yourself. The flags in PSW tie the bytes
together, so most of this unit is really about reading CY, AC and OV correctly.

## The flags that matter (PSW)

| Bit | Name | Set by |
|-----|------|--------|
| PSW.7 | CY  | carry out of bit 7 (ADD/ADDC), borrow (SUBB), also RRC/RLC/DA |
| PSW.6 | AC  | carry out of bit 3 (half-carry) — used only by DA A |
| PSW.2 | OV  | signed overflow (carry into bit 7 XOR carry out of bit 7) |
| PSW.0 | P   | parity of A (even number of 1s → 0) |

CY is the one you copy between bytes. AC you almost never test directly — its
job is to feed DA A. OV is for signed numbers, mostly ignored here.

## 8-bit vs 16-bit addition

An 8-bit add is one instruction:

```
    MOV A, #A5H
    ADD A, #0C7H     ; A = 6CH, CY = 1
```

`ADD` always uses the accumulator as one operand and always writes A. The result
that does not fit (bit 8) lands in CY. To keep the full answer you push the carry
into a second byte:

```
    MOV A, #00H
    ADDC A, #00H     ; A = 00 + 00 + CY = 01H
```

`ADDC` is identical to `ADD` except it adds the current CY as well. That single
difference is the whole trick to multi-byte arithmetic: **add the low bytes with
ADD, add every higher byte with ADDC.** The carry rolls up automatically.

For 16-bit numbers stored low-byte-first in RAM:

```
    MOV A, low1
    ADD A, low2      ; low result, sets CY
    MOV lowRes, A
    MOV A, high1
    ADDC A, high2    ; high result + carry from below
    MOV highRes, A
    MOV A, #00H
    ADDC A, #00H     ; final carry as a third byte
    MOV carryRes, A
```

> Sir said: never use plain ADD on the high byte — you throw away the carry from
> the low byte and the answer is silently wrong. It is always ADD then ADDC.

## Subtraction with SUBB

There is no plain SUB on the 8051. `SUBB A, source` computes `A = A - source - CY`,
so CY here acts as a **borrow-in**. Because it always subtracts the borrow, you
must **clear the carry first** on the lowest byte or you may be off by one:

```
    CLR C            ; no incoming borrow
    MOV A, #32H
    SUBB A, #4EH     ; 32 - 4E = E4H, CY = 1 (borrow, result is negative)
```

After SUBB, CY = 1 means a borrow occurred (the minuend was smaller). For
multi-byte subtraction you do CLR C once, SUBB the low bytes, then SUBB the high
bytes without clearing C — the borrow propagates just like the carry did in
addition.

## MUL AB and DIV AB

These two are the only instructions that use the B register as an operand.

`MUL AB` multiplies the unsigned bytes in A and B. The 16-bit product comes back
split across **B:A** — high byte in B, low byte in A. OV is set if the product
exceeds 255 (B non-zero); CY is always cleared.

```
    MOV A, #0FFH
    MOV B, #0FFH
    MUL AB           ; FF * FF = FE01H -> B = FEH, A = 01H
```

`DIV AB` divides A by B (both unsigned). Afterwards **A holds the quotient and B
holds the remainder**. CY and OV are cleared, except OV is set if you divided by
zero (result then undefined).

```
    MOV A, #95H
    MOV B, #10H
    DIV AB           ; 95H / 10H -> A = 09H (quotient), B = 05H (remainder)
```

Squaring a number is just MUL with both operands equal: load A, copy it to B,
`MUL AB`. For 0DH: 13 x 13 = 169 = 00A9H, so A = A9H and B = 00H.

## BCD addition with DA A

Packed BCD stores two decimal digits in one byte (59 decimal = 59H). A normal
ADD treats the byte as binary and gives the wrong digit whenever a nibble goes
above 9 or carries out of bit 3. `DA A` fixes the accumulator back to valid BCD:

- if the low nibble > 9 **or** AC = 1, it adds 06H;
- if the high nibble > 9 **or** CY = 1, it adds 60H and sets CY.

DA A only works right immediately after an ADD or ADDC (it needs the AC the add
left behind). It never operates on B or a general register — only A.

Multi-digit BCD follows the same low-then-high pattern, with a DA A after each
add:

```
    MOV A, #89H
    ADD A, #67H      ; F0H, AC = 1
    DA A             ; -> 56H, CY = 1   (89 + 67 = 156 decimal)
```

## Solved numericals

**1. Add the 16-bit numbers ABCDH and 7654H, keeping the carry.**

Low bytes: CDH + 54H = 121H → 21H, carry 1.
High bytes: ABH + 76H + 1 = 122H → 22H, carry 1.
So the 17-bit result is 1 2221H.

**Ans:** low = 21H, high = 22H, carry byte = 01H (true sum ABCD + 7654 = 12221H).

**2. Add the packed-BCD numbers 59H and 48H.**

ADD: 59H + 48H = A1H, with AC = 1 (low nibble 9+8 carried).
DA A: low nibble stays (1 ≤ 9) but AC = 1 so +06 → A7H; high nibble A > 9 so
+60 → 07H and CY = 1.

**Ans:** result = 07H with CY = 1, i.e. 107 in decimal (59 + 48 = 107). Correct.
