# Experiment 1 — Verification of Ohm's Law

**Date:** 31/01/2018

## Aim
To verify Ohm's law for a 470 Ω resistor and obtain its resistance from the slope of the V-I graph.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Regulated DC power supply | 0–30 V | 1 |
| Resistor (carbon film, ¼ W) | 470 Ω | 1 |
| Digital ammeter | 0–200 mA | 1 |
| Digital voltmeter | 0–20 V | 1 |
| Breadboard and connecting wires | — | 1 set |

## Circuit
```
      +----[ A ]----+
      |             |
   (V1) +         [R1] 470 ohm
   supply         |
      |           (V) voltmeter across R1
      +-----------+
                  |
                 GND
```
Ammeter A in series with R1, voltmeter V across R1. Node 1 is the supply
terminal, R1 returns to ground through the ammeter.

## Theory
Ohm's law states that the current through a resistor is proportional to the
voltage across it: $V = IR$. At constant R the plot of I against V is a straight
line through the origin, and its slope is the conductance $1/R$. So R can be read
back as the reciprocal of the graph slope.

## Procedure
1. Connect R1 to the supply through the ammeter; connect the voltmeter across R1.
2. Set the supply to 0 V and note the ammeter reading.
3. Raise the supply in 2 V steps up to 10 V, recording the current at each step.
4. Plot I (mA) against V (V) and measure the slope of the line.
5. Compute R as the reciprocal of the slope and compare with the marked value.

## Observations
| V set (V) | I theoretical (mA) | I measured (mA) | % Error |
|-----------|--------------------|-----------------|---------|
| 0  | 0.0000  | 0.00  | —      |
| 2  | 4.2553  | 4.20  | −1.30  |
| 4  | 8.5106  | 8.61  | +1.17  |
| 6  | 12.7660 | 12.55 | −1.69  |
| 8  | 17.0213 | 16.71 | −1.83  |
| 10 | 21.2766 | 20.94 | −1.58  |

## Calculations
Theoretical current, $I = V/R$ with $R = 470\ \Omega$:

$$I_{6V} = \frac{6}{470} = 0.012766\ \text{A} = 12.766\ \text{mA}$$

The theoretical line has slope $1/R = 1/470 = 2.128\ \text{mA/V}$.

Slope from the measured graph, using the points (0 V, 0 mA) and (10 V, 20.94 mA):

$$\text{slope} = \frac{20.94 - 0}{10 - 0} = 2.094\ \text{mA/V}$$

$$R_{measured} = \frac{1}{\text{slope}} = \frac{1}{2.094\times10^{-3}} = 477.6\ \Omega$$

Error in R against the 470 Ω marking = +1.61 %.

## Result
Ohm's law is verified: the V-I plot is a straight line through the origin. The
resistance from the graph slope is 477.6 Ω against the nominal 470 Ω (+1.61 %),
within the resistor's tolerance.
