# Experiment 3 — Verification of Thevenin's Theorem

**Date:** 14/02/2018

## Aim
To find the Thevenin equivalent (Vth, Rth) of a bridge network across a 470 Ω
load and show that the equivalent delivers the same load current as the original.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Regulated DC power supply | 0–30 V | 1 |
| Resistor 100 Ω, ¼ W | 100 Ω | 2 |
| Resistor 200 Ω, ¼ W | 200 Ω | 1 |
| Resistor 300 Ω, ¼ W | 300 Ω | 1 |
| Resistor 470 Ω, ¼ W (load) | 470 Ω | 1 |
| Digital multimeter (V and mA) | 0–20 V / 0–200 mA | 1 |
| Decade resistance box (for Rth) | 0–999 Ω | 1 |
| Breadboard and connecting wires | — | 1 set |

## Circuit
```
              Vs = 12 V (node 1)
        +---------+---------+
        |                   |
     [R1 100]            [R3 300]
        |                   |
     node A ----[RL 470]---- node C
        |                   |
     [R2 200]            [R4 100]
        |                   |
        +---------+---------+
                 GND
```
Left divider R1–R2, right divider R3–R4, load RL between the midpoints A and C.
The bridge is unbalanced, so a current flows in RL.

## Theory
Thevenin's theorem: any linear two-terminal network reduces to a single source
Vth in series with a resistance Rth. Vth is the open-circuit voltage at the load
terminals; Rth is the resistance seen there with all sources replaced by their
internal resistance (the 12 V source shorted). The load current must then be the
same whether fed by the original network or by Vth in series with Rth.

## Procedure
1. Build the bridge with Vs = 12 V and RL = 470 Ω across A–C.
2. Measure the current through RL in the full network.
3. Remove RL and measure the open-circuit voltage across A–C; this is Vth.
4. Switch off and short the supply; measure the resistance across A–C for Rth.
5. Set the decade box to Rth, feed it from Vth, connect RL, and measure the
   load current of the equivalent. Compare the two load currents.

## Observations
| Quantity | Theoretical | Measured | % Error |
|----------|-------------|----------|---------|
| Thevenin voltage Vth (V) | 5.0000 | 4.91 | −1.80 |
| Thevenin resistance Rth (Ω) | 141.6667 | 144.6 | +2.07 |
| Load current, original network (mA) | 8.1744 | 8.03 | −1.77 |
| Load current, Thevenin equivalent (mA) | 8.1744 | 8.06 | −1.40 |

## Calculations
Open-circuit voltage (load removed), from the two dividers:

$$V_A = 12\cdot\frac{200}{100+200} = 8.000\ \text{V}, \quad
V_C = 12\cdot\frac{100}{300+100} = 3.000\ \text{V}$$

$$V_{th} = V_A - V_C = 8.000 - 3.000 = 5.000\ \text{V}$$

Thevenin resistance (source shorted), each divider becoming a parallel pair:

$$R_{th} = (100\parallel200) + (300\parallel100)
= 66.667 + 75.000 = 141.667\ \Omega$$

Load current from the equivalent:

$$I_L = \frac{V_{th}}{R_{th}+R_L} = \frac{5.000}{141.667 + 470} = 8.1744\ \text{mA}$$

Load current from the original network (solving the two node voltages with RL in
place gives $V_A = 7.4550$ V, $V_C = 3.6131$ V):

$$I_L = \frac{V_A - V_C}{R_L} = \frac{7.4550 - 3.6131}{470} = 8.1744\ \text{mA}$$

Both routes give 8.174 mA to 3 significant figures.

## Result
Thevenin's theorem is verified. Vth = 5.00 V and Rth = 141.67 Ω against measured
4.91 V and 144.6 Ω. The load current is 8.17 mA from the original network and the
identical 8.17 mA from the Thevenin equivalent (measured 8.03 mA and 8.06 mA).
