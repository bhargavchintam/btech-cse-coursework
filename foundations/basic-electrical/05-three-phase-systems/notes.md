# Unit 5 — Three-Phase Systems

## Generation

Three coils fixed 120° apart on the stator, one rotor field turning inside.
Each coil gets the same EMF but delayed by 120° in time. That is a three-phase supply.

$$v_R = V_m \sin\omega t$$
$$v_Y = V_m \sin(\omega t - 120°)$$
$$v_B = V_m \sin(\omega t - 240°)$$

All three have the same amplitude and frequency, only the phase differs.
At every instant the three add to zero:

$$v_R + v_Y + v_B = 0$$

This is why the neutral of a *balanced* system carries no current.

## Phase sequence

The order in which the voltages reach their positive peak.
- **RYB** — R peaks, then Y (120° later), then B. Positive sequence.
- **RBY** — reverse order. Negative sequence.

Sequence matters: swapping any two lines of a three-phase motor reverses its direction.
It is set by the direction the rotor spins, nothing else.

## Star (Y) connection

The three coil ends (R', Y', B') are joined to one point — the neutral N.
Line is taken from the other end of each coil.

- Line current = phase current: $I_L = I_{ph}$
- Line voltage is the phasor difference of two phase voltages, 120° apart:

$$V_L = \sqrt{3}\, V_{ph}$$

Derivation of the $\sqrt3$: $V_{RY} = V_R - V_Y$, two equal phasors 120° apart, so
$|V_{RY}| = 2 V_{ph}\cos(30°) = 2 V_{ph}\cdot\frac{\sqrt3}{2} = \sqrt3\,V_{ph}$.

## Delta (Δ) connection

End of one coil to the start of the next, closed loop. Lines tapped at the junctions.

- Line voltage = phase voltage: $V_L = V_{ph}$
- Line current is the phasor difference of two phase currents:

$$I_L = \sqrt{3}\, I_{ph}$$

Same triangle-of-phasors argument as the star voltage, applied to currents.

> Sir's one-liner: "In star the **voltages** get the root-three, in delta the **currents** do."

Remember: there is no neutral in delta. A three-wire system.

## Power in a balanced load

Per phase $P_{ph} = V_{ph} I_{ph}\cos\varphi$, three phases total:

$$P = 3\,V_{ph} I_{ph}\cos\varphi = \sqrt{3}\, V_L I_L \cos\varphi$$

The $\sqrt3$ form is the useful one — line quantities are what you measure.
Same expression for star and delta. Reactive power $Q = \sqrt3\,V_L I_L \sin\varphi$,
apparent power $S = \sqrt3\,V_L I_L$.

## Two-wattmeter method

Two wattmeters, current coils in any two lines (say R and B), voltage coils to the third (Y).
Total power for any balanced or unbalanced three-wire load is $W_1 + W_2$.

For a balanced load the two readings are:

$$W_1 = V_L I_L \cos(30° - \varphi)$$
$$W_2 = V_L I_L \cos(30° + \varphi)$$

Add them:
$$W_1 + W_2 = V_L I_L[\cos(30°-\varphi)+\cos(30°+\varphi)] = V_L I_L\,(2\cos30°\cos\varphi) = \sqrt3\,V_L I_L\cos\varphi = P$$

Subtract them:
$$W_1 - W_2 = V_L I_L[\cos(30°-\varphi)-\cos(30°+\varphi)] = V_L I_L\,(2\sin30°\sin\varphi) = V_L I_L\sin\varphi$$

Divide:
$$\frac{W_1 - W_2}{W_1 + W_2} = \frac{V_L I_L\sin\varphi}{\sqrt3\,V_L I_L\cos\varphi} = \frac{\tan\varphi}{\sqrt3}$$

$$\boxed{\tan\varphi = \sqrt{3}\,\frac{W_1 - W_2}{W_1 + W_2}}$$

So two wattmeters give the total power *and* the power factor. Notes on the readings:
- pf = 1 (φ = 0): both equal, $W_1 = W_2$.
- pf = 0.5 (φ = 60°): $W_2 = 0$.
- pf < 0.5 (φ > 60°): $W_2$ goes negative — reverse its connection and subtract.

## Advantages of three-phase over single-phase

- More power for the same conductor material — three-phase transmission is cheaper.
- Constant instantaneous power (single-phase pulses at $2f$); three-phase runs smooth.
- Three-phase induction motors are self-starting; single-phase ones are not.
- A rotating magnetic field comes for free from the three windings.
- Can supply both $V_L$ and $V_{ph}$ (e.g. 400 V and 230 V) from one four-wire system.

---

## Solved numericals

### 1. Balanced star load

A balanced star-connected load of $(8 + j6)\,\Omega$ per phase is fed from a 400 V,
50 Hz, three-phase supply. Find the phase voltage, line current and total power.

Impedance per phase $|Z| = \sqrt{8^2+6^2} = 10\,\Omega$, $\cos\varphi = 8/10 = 0.8$ lagging.

Star, so $V_{ph} = V_L/\sqrt3 = 400/\sqrt3 = 230.94\,$V.

$$I_{ph} = \frac{V_{ph}}{|Z|} = \frac{230.94}{10} = 23.09\,\text{A}, \quad I_L = I_{ph} = 23.09\,\text{A}$$

$$P = \sqrt3\,V_L I_L\cos\varphi = \sqrt3 \times 400 \times 23.09 \times 0.8 = 12800\,\text{W}$$

**Ans:** $V_{ph} = 230.94$ V, $I_L = 23.09$ A, $P = 12.8$ kW at 0.8 pf lag.

### 2. Two-wattmeter readings

The two wattmeters in a three-phase load read $W_1 = 8$ kW and $W_2 = 4$ kW.
Find the total power and the power factor.

$$P = W_1 + W_2 = 8 + 4 = 12\,\text{kW}$$

$$\tan\varphi = \sqrt3\,\frac{W_1 - W_2}{W_1 + W_2} = \sqrt3\,\frac{8-4}{8+4} = \frac{\sqrt3}{3} = 0.5774$$

$$\varphi = \tan^{-1}(0.5774) = 30°, \quad \cos\varphi = \cos30° = 0.866$$

**Ans:** $P = 12$ kW, power factor $= 0.866$ lagging.
