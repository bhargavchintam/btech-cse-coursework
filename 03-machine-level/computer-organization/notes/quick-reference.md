# Quick reference — Computer Organization and Architecture

The night-before one-pager. Everything terse. Formulas and tables, look up the
worked examples in the unit notes.

## Base conversion

- 1 hex digit = 4 bits, 1 octal digit = 3 bits. Group binary from the point outward.
- Integer → base: repeated division, read remainders **bottom to top**.
- Fraction → base: repeated multiplication, read integer parts **top to bottom**.
- Back to decimal: multiply each digit by its positional weight r^k.

## Signed number ranges (n bits)

| n  | unsigned      | sign-magnitude   | 1's complement   | 2's complement          |
|----|---------------|------------------|------------------|-------------------------|
| 4  | 0 .. 15       | −7 .. +7         | −7 .. +7         | −8 .. +7                |
| 8  | 0 .. 255      | −127 .. +127     | −127 .. +127     | −128 .. +127            |
| 16 | 0 .. 65535    | −32767 .. +32767 | −32767 .. +32767 | −32768 .. +32767        |
| 32 | 0 .. 2³²−1    | ±(2³¹−1)         | ±(2³¹−1)         | −2³¹ .. 2³¹−1           |

2's complement: **−2ⁿ⁻¹ to 2ⁿ⁻¹−1** (asymmetric, one extra negative, single zero).
Sign-mag and 1's comp: **±(2ⁿ⁻¹−1)**, two zeros (+0 and −0).
Negate in 2's comp = invert all bits + 1. Subtract: A − B = A + (2's comp of B),
carry out of MSB = 1 → positive, discard carry; carry 0 → negative, answer in 2's comp.

## Codes

| code       | rule                                                        |
|------------|-------------------------------------------------------------|
| BCD        | each digit in 4 bits (0000–1001); if sum > 9 or carry, **+0110** |
| Excess-3   | code = d + 3; self-complementing (flip bits → code of 9−d)  |
| Gray       | g = b ⊕ (b ≫ 1); i.e. gᵢ = bᵢ ⊕ bᵢ₊₁, MSB copied            |
| Gray→bin   | bᵢ = bᵢ₊₁ ⊕ gᵢ, MSB copied                                  |
| Parity     | append bit for even/odd count of 1s; detects 1-bit error only |
| Hamming(7,4)| parity at positions 1,2,4; syndrome read as **s4 s2 s1**   |

## Gate truth tables (compact)

| A | B | AND | OR | NAND | NOR | XOR | XNOR |
|---|---|-----|----|------|-----|-----|------|
| 0 | 0 | 0   | 0  | 1    | 1   | 0   | 1    |
| 0 | 1 | 0   | 1  | 1    | 0   | 1   | 0    |
| 1 | 0 | 0   | 1  | 1    | 0   | 1   | 0    |
| 1 | 1 | 1   | 1  | 0    | 0   | 0   | 1    |

NOT: 0→1, 1→0. NAND and NOR are universal. XOR = 1 when inputs differ.

## Boolean algebra

De Morgan: (A·B)' = A' + B', (A + B)' = A'·B'.
Identities: A + 0 = A, A · 1 = A, A + A' = 1, A · A' = 0, A + AB = A, A + A'B = A + B.
K-map: group 1s in powers of 2 (1,2,4,8), wrap edges, biggest groups win, a cell
may be reused. n vars → 2ⁿ cells. SOP from 1s, POS from 0s.

## Flip-flop characteristic equations

| FF | equation             | note                     |
|----|----------------------|--------------------------|
| SR | Q⁺ = S + R'Q  (SR=0) | S=R=1 forbidden          |
| D  | Q⁺ = D               | no invalid state         |
| JK | Q⁺ = JQ' + K'Q       | J=K=1 → toggle           |
| T  | Q⁺ = T ⊕ Q = TQ' + T'Q | T=1 toggles (÷2)       |

## Excitation table

| Q | Q⁺ | S | R | J | K | D | T |
|---|----|---|---|---|---|---|---|
| 0 | 0  | 0 | x | 0 | x | 0 | 0 |
| 0 | 1  | 1 | 0 | 1 | x | 1 | 1 |
| 1 | 0  | 0 | 1 | x | 1 | 0 | 1 |
| 1 | 1  | x | 0 | x | 0 | 1 | 0 |

> Syndrome is s4 s2 s1, excitation is read Q→Q⁺ backwards. Both burned me once.

## Counters

- mod-N needs n flip-flops where **2ⁿ ≥ N**, i.e. n = ⌈log₂N⌉.
- Max modulus with n flip-flops = **2ⁿ**.
- Ripple (async) worst-case delay = **n × t_pd**; f_max = 1 / (n × t_pd).
- Synchronous delay = one t_pd + gate delay, independent of n.
- Ring counter: n flip-flops → **n states** (one-hot, no decode).
- Johnson (twisted ring): n flip-flops → **2n states**.

## Fetch cycle RTL

Simple (PC + 1):

| T1 | MAR ← [PC]        |
| T2 | MDR ← M[MAR]      |
| T3 | IR ← [MDR]        |
| T4 | PC ← [PC] + 1     |

Single-bus with Y/Z temporaries (PC + 4, byte-addressable word machine):

| 1 | PCout, MARin, Read, Select4, Add, Zin | MAR ← [PC], Z ← [PC]+4 |
| 2 | Zout, PCin, Yin, WMFC                  | PC ← [Z]               |
| 3 | MDRout, IRin                          | IR ← [MDR]             |

## Addressing modes — effective address

| mode              | EA        | operand   | extra operand fetches |
|-------------------|-----------|-----------|-----------------------|
| Immediate         | —         | A         | 0                     |
| Direct            | A         | M[A]      | 1                     |
| Indirect          | M[A]      | M[M[A]]   | 2                     |
| Register          | —         | R         | 0                     |
| Register indirect | R         | M[R]      | 1                     |
| Indexed / displ.  | A + R     | M[A+R]    | 1                     |
| Relative          | PC + A    | M[PC+A]   | 1 (PC = updated PC)   |
| Stack             | SP        | M[SP]     | 1                     |

Instruction fields: k opcode bits → 2ᵏ operations; r register bits → 2ʳ registers.
Expression X = (A+B)*(C+D): 3-address→3 instr, 2-address→6, 1-address→7, 0-address→8.

## Computer arithmetic

**Booth recoding** — examine current bit Qᵢ and bit to its right Qᵢ₋₁ (start Q₋₁ = 0):

| Qᵢ | Qᵢ₋₁ | operation before arithmetic-shift-right |
|----|------|------------------------------------------|
| 0  | 0    | shift only                               |
| 0  | 1    | A ← A + M, then shift                    |
| 1  | 0    | A ← A − M, then shift                    |
| 1  | 1    | shift only                               |

n-bit × n-bit runs n iterations; recoded digit = Qᵢ₋₁ − Qᵢ (+1 / 0 / −1).

**Division:** restoring — shift, subtract divisor; if remainder < 0 restore (add back),
quotient bit 0, else quotient bit 1. Non-restoring — no restore step: if rem ≥ 0
subtract next, if rem < 0 add next; correct at the end if final rem < 0.

**IEEE 754** value = (−1)ˢ × 1.M × 2^(E−bias) (normalized):

| format | total | sign | exponent | mantissa | bias |
|--------|-------|------|----------|----------|------|
| single | 32    | 1    | 8        | 23       | 127  |
| double | 64    | 1    | 11       | 52       | 1023 |

Exp field all 0s → denormal 0.M × 2^(1−bias); all 1s → ∞ (M=0) or NaN (M≠0).
Example −6.75 single: 110.11 = 1.1011×2², sign 1, exp 127+2 = 129 = 10000001,
mantissa 1011000…0 → `1 10000001 10110000000000000000000`.

## Cache

Main memory address split (byte or word addressable, be consistent):

| mapping         | fields                | number of                     |
|-----------------|-----------------------|-------------------------------|
| direct          | tag + line + offset   | lines = cache/block           |
| set-associative | tag + set + offset    | sets = cache/(block × ways)   |
| fully assoc.    | tag + offset          | no index                      |

- offset bits = log₂(block size); line/set bits = log₂(number of lines/sets).
- tag bits = address bits − index bits − offset bits.
- Example: 32-bit addr, 16-byte block, 32 KB direct → offset 4, lines 2048 → index 11, tag 17.
  Same cache 4-way → sets 512 → index 9, tag 19.

**Average access time** (h = hit ratio, T_c cache, T_m main memory):
- simultaneous: T_avg = h·T_c + (1−h)·T_m
- hierarchical (miss then go on): T_avg = T_c + (1−h)·T_m
- Example h = 0.95, T_c = 10 ns, T_m = 100 ns → 14.5 ns (simultaneous), 15 ns (hierarchical).

Write policies: write-through (every write hits memory, simple, slow) vs
write-back (write cache, flush on eviction using a dirty bit, fast, coherence cost).

## Pipeline

k-stage pipeline, n instructions, clock period τ:

- non-pipelined time = n·k·τ ; pipelined time = (k + n − 1)·τ
- **Speedup S = nk / (k + n − 1)** → k as n → ∞
- Efficiency η = S / k = n / (k + n − 1)
- Throughput = n / [(k + n − 1)·τ] ≈ 1/τ for large n
- Example k = 4, n = 100 → S = 3.88, η = 0.97.

Hazards: **structural** (resource clash), **data** (RAW/WAR/WAW, fix by
forwarding/stall), **control** (branch, fix by flush/predict/delay slot).
