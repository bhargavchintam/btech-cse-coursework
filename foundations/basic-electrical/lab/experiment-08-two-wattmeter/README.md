# Experiment 8 — Measurement of Three-Phase Power by the Two-Wattmeter Method

**Date:** 04/04/2018

## Aim
To measure the total power of a balanced three-phase load using two wattmeters, to verify that
the total power is W1 + W2, and to recover the load power factor from the two readings —
including the case where the power factor is below 0.5 and one wattmeter reads negative.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Three-phase AC supply | 415 V, 50 Hz | 1 |
| Dynamometer wattmeter | 600 V, 10 A | 2 |
| Three-phase variable load (inductive) | — | 1 |
| AC voltmeter (line) | 0–600 V | 1 |
| AC ammeter (line) | 0–10 A | 1 |
| Connecting wires | — | as reqd |

## Circuit
Balanced star (or delta) load fed from the 3-phase supply. The current coils of the two
wattmeters go in lines R and B; both pressure coils are referenced to line Y.

```
   R o----[W1 c.c.]----+--------------------o  |
                       |                    | load
   Y o------------------------+-------------o  (balanced,
                       |      |             |   3-phase)
   B o----[W2 c.c.]----|------|-------------o  |
                       |      |
              W1 p.c. --+     +-- W2 p.c.  (both to Y)
```

## Theory
For a balanced three-phase load with phase angle φ, the two wattmeters read
$W_1 = V_L I_L\cos(30^\circ - \varphi)$ and $W_2 = V_L I_L\cos(30^\circ + \varphi)$.
Adding, $W_1 + W_2 = \sqrt3\,V_L I_L\cos\varphi$ — the total three-phase power. Subtracting,
$W_1 - W_2 = V_L I_L\sin\varphi$, so

$\tan\varphi = \sqrt3\,\dfrac{W_1 - W_2}{W_1 + W_2}$

When $\varphi > 60^\circ$ (power factor below 0.5), $30^\circ + \varphi > 90^\circ$ and $W_2$
goes **negative**: that wattmeter reads backward and its connection must be reversed, the
reading being entered as a negative number. This low-pf case is the one that proves the method —
the total is still $W_1 + W_2$ with $W_2$ taken as negative.

## Procedure
1. Connect the two wattmeters in the standard configuration (current coils in R and B, pressure
   coils to Y) and apply balanced 415 V.
2. Switch on the three-phase load and adjust it to a chosen power factor at IL = 10 A.
3. Record W1, W2, the line voltage and the line current.
4. Reduce the power factor in steps. When a wattmeter tries to read backward, reverse its
   current-coil connection and record that reading as negative.
5. For each setting compute P = W1 + W2 and $\tan\varphi = \sqrt3(W_1-W_2)/(W_1+W_2)$, hence pf.

## Observations
Line voltage VL = 415 V, line current IL = 10 A (held constant), so
$\sqrt3\,V_L I_L = 7188.01$ VA. Measured readings are the theoretical values with a 1–3%
wattmeter error.

| S.No | pf (load) | φ (°) | W1 theo (W) | W1 meas (W) | W2 theo (W) | W2 meas (W) |
|:----:|:---------:|:-----:|------------:|------------:|------------:|------------:|
| 1 | 1.0000 | 0.00  | 3594.01 | 3658.70 | 3594.01 | 3536.50 |
| 2 | 0.8660 | 30.00 | 4150.00 | 4199.80 | 2074.82 | 2029.17 |
| 3 | 0.7071 | 45.00 | 4008.58 | 3948.45 | 1074.06 | 1096.62 |
| 4 | 0.5000 | 60.00 | 3594.01 | 3651.51 |    0.00 |    0.00 |
| 5 | 0.3000 | 72.54 | 3057.63 | 3027.05 | −901.22 | −921.05 |

At pf = 0.5 (row 4) the second wattmeter reads zero. At pf = 0.3 (row 5), φ = 72.54° > 60°, so
W2 is **negative** — the wattmeter is reversed and −921 W is recorded. This is the interesting
case: without treating W2 as negative the total would be wrong.

## Calculations
Total power (from the measured readings) against the theoretical $\sqrt3\,V_L I_L\cos\varphi$,
and the power factor recovered from $\tan\varphi = \sqrt3(W_1-W_2)/(W_1+W_2)$:

| S.No | P = W1 + W2 (W) | P theoretical (W) | % Error | tanφ = √3(W1−W2)/(W1+W2) | φ (°) | pf = cosφ |
|:----:|----------------:|------------------:|--------:|-------------------------:|------:|----------:|
| 1 | 7195.20 | 7188.01 | +0.10 | 0.0294 |  1.68 | 0.9996 |
| 2 | 6228.97 | 6224.82 | +0.07 | 0.6036 | 31.11 | 0.8561 |
| 3 | 5045.07 | 5082.64 | −0.74 | 0.9791 | 44.39 | 0.7145 |
| 4 | 3651.51 | 3594.01 | +1.60 | 1.7321 | 60.00 | 0.5000 |
| 5 | 2106.00 | 2156.40 | −2.34 | 3.2471 | 72.88 | 0.2943 |

Worked example, row 5 (the negative-W2 case), using the measured readings:

$P = W_1 + W_2 = 3027.05 + (-921.05) = 2106.00\ \text{W}$

$\tan\varphi = \sqrt3\,\dfrac{3027.05-(-921.05)}{3027.05+(-921.05)}
= 1.732\times\dfrac{3948.10}{2106.00} = 3.2471
\;\Rightarrow\; \varphi = 72.88^\circ,\; \text{pf} = \cos72.88^\circ = 0.294$

The recovered pf (0.294) matches the load pf (0.30) to within the meter error, and the round
trip $\tan\varphi = \sqrt3(W_1-W_2)/(W_1+W_2)$ closes on every row, negative W2 included.

## Result
The two-wattmeter method is verified. The total three-phase power equals W1 + W2 at every power
factor (within 2.3% of $\sqrt3\,V_L I_L\cos\varphi$), and $\tan\varphi = \sqrt3(W_1-W_2)/(W_1+W_2)$
recovers the power factor. For pf = 0.3 (< 0.5) the second wattmeter reads negative (−921 W);
entered as negative it still yields the correct total (2106 W) and power factor (0.294).
