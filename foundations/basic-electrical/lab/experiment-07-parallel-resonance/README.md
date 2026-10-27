# Experiment 7 — Parallel Resonance (Tank Circuit)

**Date:** 21/03/2018

## Aim
To study parallel resonance in a practical tank circuit (a coil in parallel with a capacitor),
to find the frequency at which the line current is minimum and the impedance maximum, and to
compare it with the ideal $1/(2\pi\sqrt{LC})$.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Function generator (sine) | 0.1–20 kHz, 10 V | 1 |
| Inductor (coil, resistance R) | 10 mH, R = 10 Ω | 1 |
| Capacitor C | 1 µF | 1 |
| AC milliammeter (line current) | 0–100 mA | 1 |
| CRO | — | 1 |
| Connecting wires | — | as reqd |

## Circuit
The coil (its resistance R in series with its inductance L) is connected in parallel with C.
The parallel combination is driven by the generator and the ammeter reads the line current
drawn from the source.

```
              +---[ R 10Ω ]---[ L 10mH ]---+
   o---(A)----+                            +----o
   |          +---------[ C 1µF ]----------+    |
  (~) Vs = 10 V, f variable                     |
   |                                            |
   o--------------------------------------------o
```

## Theory
For a real tank the coil has resistance R, so the admittance is
$Y = \dfrac{1}{R+j\omega L} + j\omega C$. Resonance is the frequency at which Y is purely real
(unity power factor). Setting the imaginary part to zero gives

$f_r = \dfrac{1}{2\pi}\sqrt{\dfrac{1}{LC} - \dfrac{R^2}{L^2}}
     = \dfrac{1}{2\pi\sqrt{LC}}\sqrt{1 - \dfrac{CR^2}{L}}$

so the coil resistance pulls $f_r$ *below* the ideal $1/(2\pi\sqrt{LC})$. At resonance the tank
looks like a pure resistance, the **dynamic resistance** $Z_r = \dfrac{L}{RC}$, which is the
maximum impedance; the line current is therefore minimum, $I_{min} = V/Z_r$.

> Note: the current-magnitude minimum actually sits a few Hz above $f_r$ (nearer the ideal
> LC value), but for Q = 10 the gap is under 0.5% — below the meter error — so within this
> experiment resonance, minimum current and maximum impedance are read at the same point.

## Procedure
1. Connect the coil in parallel with C and drive the combination from the 10 V generator.
2. Vary the frequency from 1.4 kHz to 1.8 kHz and record the line current at each step.
3. Note the frequency fr where the line current is minimum (impedance maximum, unity pf).
4. Compute the ideal $1/(2\pi\sqrt{LC})$ and compare.
5. Compute the dynamic resistance $Z_r = L/(RC)$ and check $I_{min} = V/Z_r$.

## Observations
R = 10 Ω, L = 10 mH, C = 1 µF, Vs = 10 V. Theoretical line current is $V_s\,|Y|$;
measured current carries a 1–3% instrument error.

| f (Hz) | \|Z\| (Ω) | I theoretical (mA) | I measured (mA) | % Error | power factor |
|-------:|----------:|-------------------:|----------------:|--------:|-------------:|
| 1400.00 | 364.74 | 27.4167 | 27.8828 | +1.70 | 0.4654 |
| 1480.00 | 569.78 | 17.5506 | 17.3049 | −1.40 | 0.6514 |
| 1540.00 | 839.58 | 11.9107 | 12.0536 | +1.20 | 0.8873 |
| **1583.57** (fr) | **1000.00** | **10.0000** | **9.9400** | **−0.60** | **1.0000** |
| 1630.00 | 906.70 | 11.0290 | 11.1945 | +1.50 | 0.8563 |
| 1690.00 | 642.66 | 15.5603 | 15.2958 | −1.70 | 0.5650 |
| 1770.00 | 426.79 | 23.4310 | 23.6418 | +0.90 | 0.3423 |

The line current falls to a minimum of 10 mA at fr = 1583.57 Hz, where the impedance is a
maximum of 1000 Ω and the power factor is unity (purely resistive).

## Calculations
Ideal (lossless) resonance:

$f_0 = \dfrac{1}{2\pi\sqrt{LC}} = \dfrac{1}{2\pi\sqrt{10\times10^{-3}\cdot1\times10^{-6}}}
= 1591.55\ \text{Hz}$

Practical resonance with coil resistance:

$f_r = \dfrac{1}{2\pi}\sqrt{\dfrac{1}{LC} - \dfrac{R^2}{L^2}}
= \dfrac{1}{2\pi}\sqrt{10^{8} - 10^{6}} = 1583.57\ \text{Hz}$

Correction factor $\sqrt{1 - CR^2/L} = \sqrt{1 - 0.01} = 0.99499$, i.e. fr is 0.50% below
the ideal — an 8 Hz shift caused entirely by the coil resistance.

Dynamic resistance and minimum current:

$Z_r = \dfrac{L}{RC} = \dfrac{10\times10^{-3}}{10\times1\times10^{-6}} = 1000\ \Omega,
\qquad I_{min} = \dfrac{V}{Z_r} = \dfrac{10}{1000} = 0.01\ \text{A} = 10\ \text{mA}$

## Result
Parallel resonance is verified. The line current is minimum (10 mA) and the impedance maximum
(1000 Ω, resistive) at fr = 1583.57 Hz. This is 0.50% below the ideal $1/(2\pi\sqrt{LC})$ =
1591.55 Hz, the difference being the correction $\sqrt{1 - CR^2/L}$ for the coil resistance.
