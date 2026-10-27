# Experiment 10 — Speed Control of a DC Shunt Motor

**Date:** 25/04/2018

## Aim
To control the speed of a DC shunt motor by armature voltage control and by field flux control, and
to observe the speed range each method gives.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| DC shunt motor | 220 V, 3 HP, 1500 rpm | 1 |
| Armature rheostat / variable DC supply | 0–220 V, 10 A | 1 |
| Field rheostat | 0–500 Ω, 1.5 A | 1 |
| Voltmeter, MC | 0–300 V | 1 |
| Ammeter, MC (armature) | 0–10 A | 1 |
| Ammeter, MC (field) | 0–2 A | 1 |
| Tachometer | 0–3000 rpm | 1 |
| Connecting wires | — | — |

Base speed (rated armature voltage 220 V, rated field current 1.0 A) = 1500 rpm.
Armature resistance $R_a$ = 1 Ω.

## Circuit

```
  +o---+------------------[ field rheostat Rf ]---+
       |                          (Af)            |
       |                                     ( shunt field )
   [ variable                                     |
     armature                                      |
     supply V ]                                    |
       |        (Aa)                               |
       +--------(A)------[ armature ]--------------+
       |                    ( M )  tacho on shaft   |
  -o---+-------------------------------------------+
```

Field current is read by ammeter Af, armature current by Aa, applied armature voltage by the voltmeter,
speed by the tachometer on the shaft.

## Theory
For a DC shunt motor the speed is

$$N \propto \frac{E_b}{\phi} = \frac{V - I_a R_a}{\phi}$$

**Armature control:** the field (hence $\phi$) is held constant and the armature voltage $V$ is
varied. Then $N \propto (V - I_a R_a)$, so the speed falls as the armature voltage is reduced. This
gives speeds *below* base speed only — the armature voltage cannot be pushed above its rated value.

**Field control:** the armature voltage is held at rated and the field current (hence $\phi$) is
varied with the field rheostat. With $E_b$ nearly constant, $N \propto 1/\phi \propto 1/I_f$, so the
speed rises as the flux is weakened. This gives speeds *above* base speed only — the flux cannot be
raised beyond saturation to go below base speed.

## Procedure
1. Start the motor with the field rheostat at minimum resistance (full field) and bring it to rated
   speed. Note this base point (220 V, $I_f$ = 1.0 A, 1500 rpm).
2. **Armature control:** keep the field current fixed at 1.0 A. Reduce the armature voltage in steps
   and at each step record the armature voltage, armature current and speed.
3. **Field control:** restore rated armature voltage (220 V). Increase the field rheostat resistance in
   steps to weaken the field, and at each step record the field current and speed.
4. Tabulate and compare against the theoretical speed for each method.

## Observations

**Table 1 — Armature voltage control** (field current constant, $I_f$ = 1.0 A). Theory: $N = 1500\,E_b/218$.

| Armature V (V) | $I_a$ (A) | $E_b = V - I_a R_a$ (V) | N theory (rpm) | N measured (rpm) | % Error |
|----------------|-----------|--------------------------|----------------|-------------------|---------|
| 220 | 2.0 | 218 | 1500.00 | 1490 | −0.67 |
| 200 | 2.0 | 198 | 1362.39 | 1355 | −0.54 |
| 180 | 2.0 | 178 | 1224.77 | 1230 | +0.43 |
| 160 | 2.0 | 158 | 1087.16 | 1080 | −0.66 |
| 140 | 2.0 | 138 | 949.54 | 945 | −0.48 |
| 120 | 2.0 | 118 | 811.93 | 815 | +0.38 |

Speed **falls** as the armature voltage is reduced. All speeds are at or below base speed.

**Table 2 — Field flux control** (armature voltage constant, V = 220 V). Theory: $N = 1500/I_f$, with $\phi \propto I_f$.

| $I_f$ (A) | $\phi$ (p.u.) | N theory (rpm) | N measured (rpm) | % Error |
|-----------|---------------|----------------|-------------------|---------|
| 1.0 | 1.00 | 1500.00 | 1490 | −0.67 |
| 0.9 | 0.90 | 1666.67 | 1655 | −0.70 |
| 0.8 | 0.80 | 1875.00 | 1860 | −0.80 |
| 0.7 | 0.70 | 2142.86 | 2160 | +0.80 |
| 0.6 | 0.60 | 2500.00 | 2520 | +0.80 |

Speed **rises** as the field is weakened. All speeds are at or above base speed.

## Calculations
Base point: at V = 220 V, $E_b = 220 - 2.0\times 1 = 218$ V and N = 1500 rpm, so the constant is
$N/E_b = 1500/218 = 6.881$ rpm/V for armature control.

Sample (armature control, V = 160 V):
$$E_b = 160 - 2.0\times 1 = 158\ \text{V}, \qquad N = 6.881 \times 158 = 1087.16\ \text{rpm}$$
Measured 1080 rpm, error $= (1080 - 1087.16)/1087.16 \times 100 = -0.66\%$.

Sample (field control, $I_f$ = 0.7 A):
$$N = \frac{1500}{I_f} = \frac{1500}{0.7} = 2142.86\ \text{rpm}$$
Measured 2160 rpm, error $= (2160 - 2142.86)/2142.86 \times 100 = +0.80\%$.

All measured speeds are within about 1 % of the theoretical values, which is within tachometer error.

## Result
Speed control of the DC shunt motor was carried out by both methods.
Armature voltage control gave 815–1500 rpm — speeds **at or below** the base speed of 1500 rpm, and
the speed fell as the armature voltage was reduced.
Field flux control gave 1490–2520 rpm — speeds **at or above** base speed, and the speed rose as the
flux was weakened. Each method covers only one side of the base speed, as expected.
