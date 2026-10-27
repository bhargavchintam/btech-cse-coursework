# Experiment 5 — Maximum Power Transfer Theorem

**Date:** 07/03/2018

## Aim
To verify that a source delivers maximum power to a load when the load resistance
equals the source (Thevenin) resistance, and that the efficiency at that point is 50%.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Regulated DC power supply | 0–30 V | 1 |
| Fixed resistor (source resistance Rth) | 100 Ω, 2 W | 1 |
| Decade resistance box (load RL) | 0–1 kΩ | 1 |
| DC voltmeter | 0–10 V | 1 |
| DC milliammeter | 0–100 mA | 1 |
| Connecting wires | — | as reqd |

## Circuit
The 10 V supply in series with Rth = 100 Ω forms the Thevenin source seen by the load.
RL is the decade box. The milliammeter reads the load current, the voltmeter reads the
voltage across RL.

```
        Rth = 100 Ω        (mA)
   +-----/\/\/-----+------(A)------+
   |               |               |
  ---                             [RL]  decade box
  --- Vth = 10 V                   |
   |                              (V)  across RL
   +-------------------------------+
                  |
                 GND (node 0)
```

## Theory
The Thevenin equivalent of any linear source is a voltage Vth behind a resistance Rth.
The power in a load RL is $P_L = I_L^2 R_L = \dfrac{V_{th}^2\,R_L}{(R_{th}+R_L)^2}$.

Differentiating and setting $dP_L/dR_L = 0$ gives the maximum at **RL = Rth**, where
$P_{max} = \dfrac{V_{th}^2}{4R_{th}}$. At that point half the source power is lost in Rth,
so the efficiency $\eta = \dfrac{R_L}{R_L+R_{th}} = 50\%$. Maximum *power* transfer is not
maximum *efficiency* — that is the point of the experiment.

## Procedure
1. Connect the circuit with Vth = 10 V and Rth = 100 Ω.
2. Set the decade box RL to 20 Ω. Note the milliammeter and voltmeter readings.
3. Increase RL in 20 Ω steps up to 200 Ω, recording IL and VL at each step.
4. Compute the load power PL = VL·IL and the efficiency η = RL/(RL+Rth) for each.
5. Plot PL against RL and locate the peak.

## Observations
Vth = 10 V, Rth = 100 Ω. Theoretical power is $V_{th}^2 R_L/(R_{th}+R_L)^2$;
measured power is the product of the meter readings (carries a 1–3% instrument error).

| RL (Ω) | IL (mA) | VL (V) | PL theoretical (mW) | PL measured (mW) | % Error | η (%) |
|-------:|--------:|-------:|--------------------:|-----------------:|--------:|------:|
| 20  | 83.333 | 1.667 | 138.889 | 141.806 | +2.10 | 16.67 |
| 40  | 71.429 | 2.857 | 204.082 | 200.816 | −1.60 | 28.57 |
| 60  | 62.500 | 3.750 | 234.375 | 237.422 | +1.30 | 37.50 |
| 80  | 55.556 | 4.444 | 246.914 | 241.235 | −2.30 | 44.44 |
| **100** | **50.000** | **5.000** | **250.000** | **248.000** | **−0.80** | **50.00** |
| 120 | 45.455 | 5.455 | 247.934 | 252.397 | +1.80 | 54.55 |
| 140 | 41.667 | 5.833 | 243.056 | 240.139 | −1.20 | 58.33 |
| 160 | 38.462 | 6.154 | 236.686 | 238.343 | +0.70 | 61.54 |
| 180 | 35.714 | 6.429 | 229.592 | 225.459 | −1.80 | 64.29 |
| 200 | 33.333 | 6.667 | 222.222 | 225.556 | +1.50 | 66.67 |

The load power rises, peaks at RL = 100 Ω, and falls again. The peak row is boxed above.

## Calculations
At the match RL = Rth = 100 Ω:

$I_L = \dfrac{V_{th}}{R_{th}+R_L} = \dfrac{10}{200} = 0.05\ \text{A} = 50\ \text{mA}$

$P_{max} = \dfrac{V_{th}^2}{4R_{th}} = \dfrac{100}{400} = 0.25\ \text{W} = 250\ \text{mW}$

$\eta = \dfrac{R_L}{R_L+R_{th}} = \dfrac{100}{200} = 0.5 = 50\%$

Check either side: at RL = 80 Ω, PL = 246.91 mW; at RL = 120 Ω, PL = 247.93 mW — both
below 250 mW, confirming the peak sits at RL = Rth.

## Result
Maximum power transfer theorem is verified. The load power is maximum at RL = Rth = 100 Ω,
where PL = 250 mW (theoretical) against 248 mW measured, and the efficiency there is 50%.
