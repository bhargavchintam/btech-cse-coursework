# Unit 2 — Classical Encryption Techniques

Classical ciphers work on plaintext letters directly. Two things a cipher can do to a
letter: **replace** it (substitution) or **move** it (transposition). Everything in this
unit is one of those, or a combination.

## Substitution vs transposition

| | Substitution | Transposition |
|---|---|---|
| What changes | the letter's identity | the letter's position |
| Letter frequencies | changed (or hidden) | unchanged |
| Example | Caesar, Vigenere, Playfair | Rail Fence, Columnar |
| Broken by | frequency analysis | anagramming / pattern of periods |

A product cipher chains both (substitution then transposition), which is the idea modern
block ciphers push to many rounds.

## Monoalphabetic vs polyalphabetic

A **monoalphabetic** cipher uses one fixed substitution for the whole message — the letter
E always maps to the same ciphertext letter. That single mapping leaks the frequency
profile of the language, so it falls to frequency analysis.

A **polyalphabetic** cipher changes the mapping as it goes, so one plaintext letter can
encrypt to several different ciphertext letters. This flattens the frequency curve.

| Cipher | Type | Key |
|---|---|---|
| Caesar | monoalphabetic | shift (1 number) |
| Atbash | monoalphabetic | none (fixed reversal) |
| Affine | monoalphabetic | pair (a, b), a coprime to 26 |
| Monoalphabetic (keyword) | monoalphabetic | a permuted alphabet |
| Vigenere | polyalphabetic | a keyword |
| Vernam / OTP | polyalphabetic | random pad, len = message |
| Playfair | polygraphic (digraphs) | 5x5 keyword square |
| Hill | polygraphic (block) | invertible matrix mod 26 |
| Rail Fence, Columnar | transposition | rails / keyword order |

> The Caesar cipher is just the affine cipher with a = 1, and Atbash is the affine cipher
> with a = 25, b = 25. Same machine, different dials.

## Modular inverse — why affine and Hill need it

Encryption multiplies (by `a`, or by the key matrix). To decrypt you must divide, and mod
26 that means multiplying by the **modular inverse**. `a⁻¹` exists only when gcd(a, 26) = 1,
which is why `a` for affine must avoid 2 and 13. For Hill the matrix determinant must be
invertible mod 26. Brute-force search 1..25 is enough at this scale:

```
a⁻¹ = the x in 1..25 with (a*x) mod 26 == 1
```

## Solved problem 1 — Caesar, shift 3

Encrypt `HELLO`. Rule `c = (p + 3) mod 26`, with A=0 … Z=25.

| p | H=7 | E=4 | L=11 | L=11 | O=14 |
|---|---|---|---|---|---|
| +3 | 10 | 7 | 14 | 14 | 17 |
| c | K | H | O | O | R |

**Ans:** HELLO → **KHOOR** (verified in `caesar.c` and with python3).

## Solved problem 2 — Vigenere, key KEY

Encrypt `HELLO`, key repeats as `K E Y K E`. Rule `c = (p + k) mod 26`.

| p | H=7 | E=4 | L=11 | L=11 | O=14 |
|---|---|---|---|---|---|
| k | K=10 | E=4 | Y=24 | K=10 | E=4 |
| sum | 17 | 8 | 35→9 | 21 | 18 |
| c | R | I | J | V | S |

**Ans:** HELLO → **RIJVS** (verified in `vigenere.c` and with python3).

## Solved problem 3 — Affine, a=5 b=8

Rule `c = (5p + 8) mod 26`. Decrypt uses `5⁻¹ = 21` mod 26, `p = 21·(c − 8) mod 26`.

| p | H=7 | E=4 | L=11 | L=11 | O=14 |
|---|---|---|---|---|---|
| 5p+8 | 43→17 | 28→2 | 63→11 | 11 | 78→0 |
| c | R | C | L | L | A |

**Ans:** HELLO → **RCLLA**, and 21·(17−8) mod 26 = 189 mod 26 = 7 = H recovers the plaintext.

## Programs in this folder

All ten carry both `encrypt` and `decrypt` and a demo `main()`; each round-trips.

| File | Note |
|---|---|
| `caesar.c` | HELLO → KHOOR |
| `monoalphabetic.c` | keyword-permuted alphabet |
| `affine.c` | needs modular inverse of `a` |
| `atbash.c` | self-inverse (A↔Z) |
| `vigenere.c` | key KEY on HELLO → RIJVS |
| `vernam.c` | XOR one-time pad, key as long as message |
| `playfair.c` | 5x5 square, I/J merged, X splits doubles |
| `hill_cipher.c` | 2x2 key, inverse matrix mod 26 |
| `rail_fence.c` | zigzag over 3 rails |
| `row_column_transposition.c` | columnar, keyword ZEBRAS sets column order |

> Playfair and the transposition ciphers pad with X to complete a digraph or fill the grid,
> so a decrypted message can end in an extra X — that padding is expected, not a bug.
