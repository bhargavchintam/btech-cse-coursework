# Experiment 9 — Open-Circuit and Short-Circuit Test on a Single Phase Transformer

**Date:** 11/04/2018

## Aim
To perform OC and SC tests on a 1 kVA, 230/115 V single phase transformer and from the readings
find the equivalent circuit parameters, and predict the efficiency and regulation.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| 1-φ transformer | 1 kVA, 230/115 V | 1 |
| Autotransformer (variac) | 1-φ, 0–270 V, 15 A | 1 |
| Voltmeter, MI | 0–150 V | 1 |
| Voltmeter, MI | 0–30 V | 1 |
| Ammeter, MI | 0–2 A | 1 |
| Ammeter, MI | 0–5 A | 1 |
| Wattmeter, LPF | 150 V, 2 A | 1 |
| Wattmeter, UPF | 75 V, 5 A | 1 |
| Connecting wires | — | — |

HV = 230 V side, LV = 115 V side.
Rated HV current = 1000/230 = 4.35 A. Rated LV current = 1000/115 = 8.70 A.

## Circuit
OC test — supply the LV winding at rated voltage, HV winding open:

```
   variac    A (0-2A)   W(cc)
 o---/---o----(A)------[   ]--------+-------o
 230V              +---[ W ]---+    |       |
 50Hz             (V)  (pc)   LV winding   HV winding
                   |           |    |     (open)
 o-----------------+-----------+----+-------o
```

SC test — short the LV winding, apply reduced voltage to the HV winding:

```
   variac    A (0-5A)   W(cc)
 o---/---o----(A)------[   ]--------+-------o
 230V              +---[ W ]---+    |       |
 50Hz             (V)  (pc)   HV winding   LV winding
                   |           |    |     (shorted)
 o-----------------+-----------+----+---o---o
```

## Theory
In the OC test rated voltage is applied to one winding with the other open. The current drawn is
only the no-load (exciting) current, so the wattmeter reads the iron loss $W_0$ and the shunt-branch
parameters $R_0$, $X_0$ are found. Copper loss at no load is negligible.

In the SC test a reduced voltage is applied with the other winding shorted so that rated current
flows. The wattmeter then reads the full-load copper loss $W_{sc}$ and the series parameters
$R_{01}$, $X_{01}$, $Z_{01}$ (referred to the side of measurement) are found.

$$Z_{01}^2 = R_{01}^2 + X_{01}^2$$

The two losses together give the efficiency at any load, and $R_{01}$, $X_{01}$ give the regulation.

## Procedure
1. Connect the OC test circuit with the instruments on the LV side and the HV side left open.
2. Slowly raise the variac until the LV voltmeter reads rated 115 V.
3. Record the voltmeter, ammeter and wattmeter readings ($V_0$, $I_0$, $W_0$). Switch off.
4. Connect the SC test circuit with the instruments on the HV side and the LV side shorted.
5. Raise the variac from zero carefully until the HV ammeter reads rated 4.35 A.
6. Record $V_{sc}$, $I_{sc}$, $W_{sc}$. Switch off and bring the variac back to zero.

## Observations

OC test (instruments on LV side, HV open):

| $V_0$ (V) | $I_0$ (A) | $W_0$ (W) |
|-----------|-----------|-----------|
| 115 | 0.6 | 18 |

SC test (instruments on HV side, LV shorted):

| $V_{sc}$ (V) | $I_{sc}$ (A) | $W_{sc}$ (W) |
|--------------|--------------|--------------|
| 12 | 4.35 | 35 |

## Calculations

**From the OC test (shunt branch, referred to LV side):**

$$\cos\phi_0 = \frac{W_0}{V_0 I_0} = \frac{18}{115 \times 0.6} = 0.261$$

$$I_w = I_0\cos\phi_0 = 0.6 \times 0.261 = 0.157\ \text{A}, \qquad
  I_\mu = I_0\sin\phi_0 = 0.6 \times 0.965 = 0.579\ \text{A}$$

$$R_0 = \frac{V_0}{I_w} = \frac{115}{0.157} = 734.7\ \Omega, \qquad
  X_0 = \frac{V_0}{I_\mu} = \frac{115}{0.579} = 198.5\ \Omega$$

**From the SC test (series branch, referred to HV side):**

$$Z_{01} = \frac{V_{sc}}{I_{sc}} = \frac{12}{4.35} = 2.759\ \Omega$$

$$R_{01} = \frac{W_{sc}}{I_{sc}^2} = \frac{35}{4.35^2} = 1.850\ \Omega$$

$$X_{01} = \sqrt{Z_{01}^2 - R_{01}^2} = \sqrt{2.759^2 - 1.850^2} = \sqrt{4.189} = 2.047\ \Omega$$

Check: $R_{01}^2 + X_{01}^2 = 3.422 + 4.190 = 7.612 = Z_{01}^2$. ✓

**Iron loss** $W_i = W_0 = 18$ W (constant). **Full-load copper loss** $W_{cu} = W_{sc} = 35$ W.

**Efficiency at 0.8 pf lagging** — at load fraction $x$, output $= x\,S\cos\phi$, copper loss $= x^2 W_{cu}$:

| Load | Output (W) | Iron loss (W) | Cu loss (W) | Total loss (W) | Efficiency |
|------|-----------|---------------|-------------|----------------|------------|
| Half (x = 0.5) | 400 | 18 | 8.75 | 26.75 | 93.73 % |
| Full (x = 1.0) | 800 | 18 | 35.00 | 53.00 | 93.79 % |

$$\eta_{half} = \frac{400}{400 + 26.75} = 93.73\%, \qquad
  \eta_{full} = \frac{800}{800 + 53} = 93.79\%$$

(Maximum efficiency is at $x = \sqrt{W_i/W_{cu}} = \sqrt{18/35} = 0.72$, i.e. about 72 % load, which
is why the half-load and full-load figures come out so close.)

**Voltage regulation at full load, 0.8 pf lagging** ($\cos\phi = 0.8$, $\sin\phi = 0.6$, HV side):

$$\%VR = \frac{I_1(R_{01}\cos\phi + X_{01}\sin\phi)}{V_1}\times 100
  = \frac{4.35\,(1.850\times 0.8 + 2.047\times 0.6)}{230}\times 100$$

$$= \frac{4.35 \times 2.708}{230}\times 100 = \frac{11.78}{230}\times 100 = 5.12\%$$

## Result
OC and SC tests performed. Equivalent circuit parameters:
$R_0 = 734.7\ \Omega$, $X_0 = 198.5\ \Omega$ (LV side);
$Z_{01} = 2.759\ \Omega$, $R_{01} = 1.850\ \Omega$, $X_{01} = 2.047\ \Omega$ (HV side).
Predicted efficiency at 0.8 pf lagging = 93.73 % (half load) and 93.79 % (full load).
Voltage regulation at full load, 0.8 pf lagging = 5.12 %.
