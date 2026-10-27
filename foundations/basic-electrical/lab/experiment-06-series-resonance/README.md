# Experiment 6 — Series Resonance in an RLC Circuit

**Date:** 14/03/2018

## Aim
To study series resonance in an RLC circuit fed from a variable-frequency source, to find
the resonant frequency where the current is maximum, and to determine the Q-factor and
bandwidth from the half-power points.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Function generator (sine) | 0.1–20 kHz, 10 V | 1 |
| Resistor R | 10 Ω, 2 W | 1 |
| Inductor L | 10 mH | 1 |
| Capacitor C | 1 µF | 1 |
| AC milliammeter / CRO with series sense R | 0–1 A | 1 |
| Connecting wires | — | as reqd |

## Circuit
R, L and C in series across the function generator. The same current flows through all three;
it is read on the ammeter (or as the voltage across a small sense resistor on the CRO).

```
   o---[ R 10Ω ]---[ L 10mH ]---[ C 1µF ]---o
   |                                         |
  (~) Vs = 10 V, f variable      ammeter in series
   |                                         |
   o-----------------------------------------o
```

## Theory
In a series RLC circuit the reactance is $X = \omega L - \dfrac{1}{\omega C}$. At the resonant
frequency $X = 0$, so the impedance is minimum and purely resistive ($Z = R$) and the current
is maximum. Resonance occurs at

$f_0 = \dfrac{1}{2\pi\sqrt{LC}}$

The sharpness is measured by the quality factor $Q = \dfrac{1}{R}\sqrt{\dfrac{L}{C}}$, and the
bandwidth between the two half-power points (where $I = I_{max}/\sqrt2$ and $|X| = R$) is
$BW = f_2 - f_1 = \dfrac{f_0}{Q}$.

## Procedure
1. Connect R, L, C in series with the function generator set to 10 V sine.
2. Vary the frequency from 1 kHz to 2.2 kHz and record the current at each step.
3. Note the frequency f0 where the current is maximum — here the circuit is purely resistive.
4. Read the two frequencies f1, f2 where the current falls to 0.707 of its peak (half-power).
5. Compute Q = f0/BW and compare with $\tfrac{1}{R}\sqrt{L/C}$.

## Observations
R = 10 Ω, L = 10 mH, C = 1 µF, Vs = 10 V. Theoretical current is $V_s/|Z|$;
measured current carries a 1–3% instrument error.

| f (Hz) | XL (Ω) | XC (Ω) | \|Z\| (Ω) | I theoretical (A) | I measured (A) | % Error |
|-------:|-------:|-------:|----------:|------------------:|---------------:|--------:|
| 1000.00 | 62.832 | 159.155 | 96.841 | 0.10326 | 0.10533 | +2.00 |
| 1200.00 | 75.398 | 132.629 | 58.098 | 0.17212 | 0.16954 | −1.50 |
| 1400.00 | 87.965 | 113.682 | 27.593 | 0.36241 | 0.36748 | +1.40 |
| **1513.96** (f1) | 95.125 | 105.125 | 14.142 | 0.70711 | 0.69155 | −2.20 |
| **1591.55** (f0) | 100.000 | 100.000 | 10.000 | 1.00000 | 0.99400 | −0.60 |
| **1673.12** (f2) | 105.125 | 95.125 | 14.142 | 0.70711 | 0.71913 | +1.70 |
| 1800.00 | 113.097 | 88.419 | 26.627 | 0.37556 | 0.36880 | −1.80 |
| 2000.00 | 125.664 | 79.577 | 47.159 | 0.21205 | 0.21396 | +0.90 |
| 2200.00 | 138.230 | 72.343 | 66.641 | 0.15006 | 0.14826 | −1.20 |

At f0 = 1591.55 Hz the current is maximum (1.0 A) and XL = XC = 100 Ω, so the circuit is
purely resistive. At f1 and f2 the current is 0.70711 A = Imax/√2, and |Z| = R√2 = 14.142 Ω.

## Calculations
$f_0 = \dfrac{1}{2\pi\sqrt{LC}} = \dfrac{1}{2\pi\sqrt{10\times10^{-3}\cdot 1\times10^{-6}}}
= 1591.55\ \text{Hz}$

$Q = \dfrac{1}{R}\sqrt{\dfrac{L}{C}} = \dfrac{1}{10}\sqrt{\dfrac{10\times10^{-3}}{1\times10^{-6}}}
= \dfrac{1}{10}\times 100 = 10$

Half-power points (from the table): f1 = 1513.96 Hz, f2 = 1673.12 Hz.

$BW = f_2 - f_1 = 1673.12 - 1513.96 = 159.16\ \text{Hz}$

$Q = \dfrac{f_0}{BW} = \dfrac{1591.55}{159.16} = 10.00$

Both routes to Q agree: $\tfrac{1}{R}\sqrt{L/C} = 10$ and $f_0/BW = 10$. Also the geometric
mean $\sqrt{f_1 f_2} = 1591.55$ Hz = f0, as it should be.

## Result
Series resonance is verified. The current is maximum (1.0 A) at f0 = 1591.55 Hz where the
circuit is purely resistive. The half-power points give BW = 159.16 Hz and Q = f0/BW = 10.0,
which matches $\tfrac{1}{R}\sqrt{L/C} = 10$.
