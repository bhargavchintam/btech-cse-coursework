# Experiment 12 — Wiring of a Fluorescent Lamp and Power-Factor Improvement

**Date:** 16/05/2018

## Aim
To wire a fluorescent tube light with a choke and a glow starter, study its starting sequence, and
find the choke reactance and the power factor before and after adding a shunt capacitor.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Fluorescent tube | 40 W, 230 V | 1 |
| Choke (ballast) | for 40 W tube | 1 |
| Glow starter | 4–65 W | 1 |
| Tube fixture with holders | — | 1 |
| Power-factor capacitor | 4.5 μF, 440 V | 1 |
| Voltmeter, MI | 0–300 V | 1 |
| Ammeter, MI | 0–1 A | 1 |
| Wattmeter | 300 V, 1 A | 1 |
| Single phase supply | 230 V, 50 Hz | 1 |

## Circuit

```
  L o──[ CHOKE ]──o──(fil A)══════ TUBE ══════(fil B)──o── N
                     |                            |
                     +──────────[ STARTER ]───────+

  power-factor capacitor Cpf connected across the L–N input terminals
```

Node connections: phase L → choke → filament A → tube → filament B → neutral N. The glow starter is
connected across the tube (between the free ends of filaments A and B). The correction capacitor is
in parallel with the whole circuit across L–N.

## Theory
**Starting sequence.**
1. On switch-on, almost the full mains voltage appears across the open starter; its neon glows.
2. The glow heats the starter's **bimetallic strip**, which bends and **closes** the starter contacts.
3. Current now flows in the loop choke → filament A → starter → filament B, heating both filaments so
   they emit electrons.
4. With the contacts closed there is no glow, so the strip cools and the contacts **spring open**.
5. Breaking this current makes the choke produce a large **back-emf** ($L\,di/dt$) which appears across
   the tube and, with the filaments already hot, **strikes the arc** through the mercury vapour.
6. The running arc drops the tube voltage to about 100 V. This is too low to restart the starter's
   glow, so the **starter stays open** and the choke now acts as a current-limiting reactance.

**Why the capacitor.** The choke makes the circuit strongly inductive, so the line current lags badly
and the power factor is poor. A capacitor across the supply draws a leading current that cancels most
of the lagging reactive current, raising the power factor and lowering the line current.

## Procedure
1. Wire the tube, choke and starter as in the circuit diagram, with the meters in the supply line.
2. Switch on and watch the starting sequence (starter flicker, then the tube strikes).
3. With the tube running steadily, record the supply voltage, tube voltage, line current and input
   power (capacitor not connected).
4. Connect the power-factor capacitor across the supply and note the new line current.
5. Compute the choke reactance and the power factor before and after correction.

## Observations
Steady-running readings, capacitor **not** connected:

| Supply $V_s$ (V) | Tube voltage $V_{tube}$ (V) | Line current $I$ (A) | Input power $W$ (W) |
|------------------|------------------------------|----------------------|---------------------|
| 230 | 100 | 0.40 | 40 |

## Calculations
The tube arc is essentially resistive and the choke essentially reactive, in series across 230 V.

**Choke reactance** (tube voltage in phase with $I$, choke voltage 90° ahead, so the supply is their
phasor sum):

$$V_{choke} = \sqrt{V_s^2 - V_{tube}^2} = \sqrt{230^2 - 100^2} = 207.1\ \text{V}$$

$$X_L = \frac{V_{choke}}{I} = \frac{207.1}{0.40} = 517.8\ \Omega, \qquad
  L = \frac{X_L}{2\pi f} = \frac{517.8}{2\pi\times 50} = 1.65\ \text{H}$$

**Power factor before correction:**

$$S = V_s I = 230\times 0.40 = 92\ \text{VA}, \qquad
  \cos\phi = \frac{W}{S} = \frac{40}{92} = 0.435\ \text{(lag)}$$

$$Q = \sqrt{S^2 - P^2} = \sqrt{92^2 - 40^2} = 82.85\ \text{VAR (lag)}$$

Check: $Q = I^2 X_L = 0.40^2\times 517.8 = 82.85$ VAR. ✓

**Capacitor to raise the power factor to 0.95 (lag).** Real power stays 40 W:

$$S' = \frac{P}{0.95} = 42.11\ \text{VA}, \qquad Q' = \sqrt{S'^2 - P^2} = \sqrt{42.11^2 - 40^2} = 13.15\ \text{VAR}$$

$$Q_C = Q - Q' = 82.85 - 13.15 = 69.70\ \text{VAR}$$

$$C = \frac{Q_C}{V_s^2\,\omega} = \frac{69.70}{230^2\times 2\pi\times 50} = 4.19\ \mu\text{F}$$

New line current:

$$I' = \frac{S'}{V_s} = \frac{42.11}{230} = 0.183\ \text{A}$$

So a 4.19 μF (use standard 4.5 μF) shunt capacitor raises the power factor from 0.435 to 0.95 and
drops the line current from 0.40 A to 0.18 A, while the tube still takes the same 40 W.

## Result
The fluorescent lamp was wired and its starting sequence observed (starter closes → filaments heat →
starter opens → choke back-emf strikes the arc → starter stays open).
Choke reactance $X_L = 517.8\ \Omega$ ($L = 1.65$ H).
Power factor before correction = 0.435 lag; after a 4.19 μF shunt capacitor = 0.95 lag, with the line
current falling from 0.40 A to 0.18 A.
