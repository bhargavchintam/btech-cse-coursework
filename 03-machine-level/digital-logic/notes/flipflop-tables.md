# Flip-flop characteristic & excitation tables

## Characteristic tables (Q⁺ = next state)

**SR**  | S R | Q⁺  → 00:Q, 01:0, 10:1, 11:invalid
**JK**  | J K | Q⁺  → 00:Q, 01:0, 10:1, 11:Q'
**D**   | D   | Q⁺  → 0:0, 1:1
**T**   | T   | Q⁺  → 0:Q, 1:Q'

## Characteristic equations
- SR: Q⁺ = S + R'Q      (with SR = 0)
- JK: Q⁺ = JQ' + K'Q
- D:  Q⁺ = D
- T:  Q⁺ = T ⊕ Q = TQ' + T'Q

## Excitation tables (input needed for Q → Q⁺; × = don't care)

| Q → Q⁺ | S R | J K | D | T |
|--------|-----|-----|---|---|
| 0 → 0  | 0 × | 0 × | 0 | 0 |
| 0 → 1  | 1 0 | 1 × | 1 | 1 |
| 1 → 0  | 0 1 | × 1 | 0 | 1 |
| 1 → 1  | × 0 | × 0 | 1 | 0 |

These four rows are what you use for counter/FF-conversion design — read off the input for each required transition, then K-map it.
