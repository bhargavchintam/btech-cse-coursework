# Experiment 4 — Verification of the Superposition Theorem

**Date:** 21/02/2018

## Aim
To verify the superposition theorem by showing that the current in a load
resistor equals the sum of the currents produced by each source acting alone.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Regulated DC power supply | 0–30 V | 2 |
| Resistor 100 Ω, ¼ W | 100 Ω | 1 |
| Resistor 200 Ω, ¼ W | 200 Ω | 1 |
| Resistor 300 Ω, ¼ W (load) | 300 Ω | 1 |
| Digital multimeter (mA) | 0–200 mA | 1 |
| Breadboard and connecting wires | — | 1 set |

## Circuit
```
   V1 = 12 V           node A            V2 = 6 V
     +---[R1 100]---+------+------+---[R3 200]---+
     |              |      |      |              |
   (V1)             |   [R2 300]  |            (V2)
     |              |      |      |              |
     +--------------+------+------+--------------+
                          GND
```
R2 is the load. The current through R2 is the response. When one source is
removed it is replaced by its internal resistance — a voltage source becomes a
short circuit.

## Theory
Superposition theorem: in a linear network with several independent sources, the
current in any branch is the algebraic sum of the currents produced by each
source acting alone, all other sources replaced by their internal resistance.
Here the response is the current in R2; it is found with both sources on, then
with V1 alone (V2 shorted) and V2 alone (V1 shorted).

## Procedure
1. Wire the network with V1 = 12 V and V2 = 6 V. Measure the current in R2.
2. Switch off V2 and replace it by a short. Measure the current in R2 (V1 alone).
3. Restore V2, switch off V1 and short it. Measure the current in R2 (V2 alone).
4. Add the two single-source currents and compare with the both-on reading.

## Observations
| Condition | Theoretical I(R2) (mA) | Measured I(R2) (mA) | % Error |
|-----------|------------------------|---------------------|---------|
| V1 alone (V2 shorted) | 21.8182 | 22.15 | +1.52 |
| V2 alone (V1 shorted) | 5.4545  | 5.36  | −1.73 |
| Both sources | 27.2727 | 27.79 | +1.90 |

Superposition check: sum of the single-source currents = 21.8182 + 5.4545 =
27.2727 mA, exactly equal to the both-sources theoretical value. From the
measured columns, 22.15 + 5.36 = 27.51 mA against the both-on reading of
27.79 mA, agreeing to about 1 %.

## Calculations
Both sources active, node A by nodal analysis:

$$V_A\left(\tfrac{1}{100}+\tfrac{1}{300}+\tfrac{1}{200}\right)=\tfrac{12}{100}+\tfrac{6}{200}$$

$$V_A = \frac{0.15}{0.018333} = 8.1818\ \text{V}, \quad
I_{R2} = \frac{8.1818}{300} = 27.273\ \text{mA}$$

V1 alone (V2 shorted), R2∥R3 seen from A:

$$R_2\parallel R_3 = \frac{300\cdot200}{500} = 120\ \Omega, \quad
V_A = 12\cdot\frac{120}{100+120} = 6.5455\ \text{V}$$

$$I' = \frac{6.5455}{300} = 21.818\ \text{mA}$$

V2 alone (V1 shorted), R1∥R2 seen from A:

$$R_1\parallel R_2 = \frac{100\cdot300}{400} = 75\ \Omega, \quad
V_A = 6\cdot\frac{75}{200+75} = 1.6364\ \text{V}$$

$$I'' = \frac{1.6364}{300} = 5.455\ \text{mA}$$

Sum: $I' + I'' = 21.818 + 5.455 = 27.273\ \text{mA} = I_{R2}$ (both on).

## Result
The superposition theorem is verified. The single-source currents 21.82 mA and
5.45 mA add to 27.27 mA, equal to the both-sources current of 27.27 mA. Measured
values 22.15 mA and 5.36 mA sum to 27.51 mA against the 27.79 mA both-on reading.
