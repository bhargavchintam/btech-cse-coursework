# Experiment 2 — Verification of Kirchhoff's Voltage and Current Laws

**Date:** 07/02/2018

## Aim
To verify Kirchhoff's voltage law round each loop and Kirchhoff's current law at
the common node of a two-loop network.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Regulated DC power supply | 0–30 V | 2 |
| Resistor 100 Ω, ¼ W | 100 Ω | 1 |
| Resistor 150 Ω, ¼ W | 150 Ω | 1 |
| Resistor 47 Ω, ½ W | 47 Ω | 1 |
| Digital multimeter (V and mA) | 0–20 V / 0–200 mA | 1 |
| Breadboard and connecting wires | — | 1 set |

## Circuit
```
   V1 = 10 V            node A            V2 = 6 V
     +---[R1 100]---+------+------+---[R3 150]---+
     |              |      |      |              |
   (V1)          I1 v      |      ^ I3         (V2)
     |              |   [R2 47]   |              |
     |              |      |      |              |
     +--------------+------+------+--------------+
                          GND
```
Node A is the junction of R1, R2 and R3. Left loop: V1–R1–R2. Right loop:
V2–R3–R2. R2 is the shared branch to ground.

## Theory
KVL: the algebraic sum of voltages round any closed loop is zero. KCL: the
algebraic sum of currents at any node is zero. Here the currents in R1 and R3
flow into node A and their sum leaves through R2, while each source voltage
equals the sum of the two resistor drops in its loop.

## Procedure
1. Wire the network with V1 = 10 V and V2 = 6 V.
2. Measure the voltage across R1, R2 and R3 with the multimeter.
3. Break each branch in turn and measure the currents I1, I2 and I3.
4. Add the drops round each loop and compare with the source voltage (KVL).
5. Add the branch currents at node A and check they cancel (KCL).

## Observations
| Quantity | Theoretical | Measured | % Error |
|----------|-------------|----------|---------|
| I1 through R1 (mA) | 63.1028 | 62.28 | −1.30 |
| I2 through R2 (mA) | 78.5047 | 77.02 | −1.89 |
| I3 through R3 (mA) | 15.4019 | 15.09 | −2.02 |
| V across R1 (V) | 6.3103 | 6.42 | +1.74 |
| V across R2 (V) | 3.6897 | 3.75 | +1.63 |
| V across R3 (V) | 2.3103 | 2.35 | +1.72 |

Verification from the measured readings:
| Check | Ideal | From measurements |
|-------|-------|-------------------|
| KVL loop 1: V1 − V_R1 − V_R2 | 0 | 10 − 6.42 − 3.75 = −0.17 V |
| KVL loop 2: V2 − V_R3 − V_R2 | 0 | 6 − 2.35 − 3.75 = −0.10 V |
| KCL node A: I1 + I3 − I2 | 0 | 62.28 + 15.09 − 77.02 = +0.35 mA |

## Calculations
Node A voltage by nodal analysis:

$$V_A\left(\tfrac{1}{100}+\tfrac{1}{47}+\tfrac{1}{150}\right)=\tfrac{10}{100}+\tfrac{6}{150}$$

$$V_A = \frac{0.14}{0.037943} = 3.6897\ \text{V}$$

Branch currents:

$$I_1 = \frac{10 - 3.6897}{100} = 63.103\ \text{mA}, \quad
I_3 = \frac{6 - 3.6897}{150} = 15.402\ \text{mA}$$

$$I_2 = \frac{3.6897}{47} = 78.505\ \text{mA}$$

KCL: $I_1 + I_3 = 63.103 + 15.402 = 78.505\ \text{mA} = I_2$.

KVL loop 1: $I_1R_1 + I_2R_2 = 6.310 + 3.690 = 10\ \text{V} = V_1$.
KVL loop 2: $I_3R_3 + I_2R_2 = 2.310 + 3.690 = 6\ \text{V} = V_2$.

## Result
KVL and KCL are verified. The loop voltage sums close to within 0.17 V and the
node current sum to within 0.35 mA of zero, the residuals being instrument error.
Theoretical I1 = 63.10 mA, I2 = 78.50 mA, I3 = 15.40 mA against measured 62.28,
77.02 and 15.09 mA.
