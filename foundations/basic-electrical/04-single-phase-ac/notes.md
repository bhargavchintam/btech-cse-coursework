# Unit 4 — Single-Phase AC Circuits

Convention: all voltages and currents are RMS unless a peak $V_m, I_m$ is written.
$\omega = 2\pi f$, $X_L = \omega L$, $X_C = \dfrac{1}{\omega C}$.

## Pure resistance
$v = V_m\sin\omega t \Rightarrow i = \dfrac{V_m}{R}\sin\omega t$.
Current is **in phase** with voltage, $\phi = 0$.
Power $P = VI$, all of it dissipated.

## Pure inductance
$v = V_m\sin\omega t \Rightarrow i = \dfrac{V_m}{X_L}\sin(\omega t - 90°)$.
Current **lags** voltage by 90°. $X_L = \omega L$ (ohms).
Average power over a cycle $= 0$ — the inductor only stores and returns energy.

## Pure capacitance
$i = \dfrac{V_m}{X_C}\sin(\omega t + 90°)$.
Current **leads** voltage by 90°. $X_C = \dfrac{1}{\omega C}$.
Average power $= 0$ again.

> "Voltage and current in R are handshaking, in L the current is late, in C the current is early." — how the lecturer made us remember ELI the ICE man.

Remember: P.F. is **leading** for a capacitive load — lost a mark on this in the internal.

## RL series
$Z = R + jX_L$, $\quad |Z| = \sqrt{R^2 + X_L^2}$, $\quad \phi = \tan^{-1}\dfrac{X_L}{R}$ (current lags).

## RC series
$Z = R - jX_C$, $\quad |Z| = \sqrt{R^2 + X_C^2}$, $\quad \phi = \tan^{-1}\dfrac{X_C}{R}$ (current leads).

## RLC series
$$Z = R + j(X_L - X_C), \qquad |Z| = \sqrt{R^2 + (X_L - X_C)^2}$$

- $X_L > X_C$: net inductive, current lags.
- $X_L < X_C$: net capacitive, current leads.
- $X_L = X_C$: resonance, $Z = R$, current in phase.

$I = \dfrac{V}{|Z|}$, and the phase angle is $\phi = \tan^{-1}\dfrac{X_L - X_C}{R}$.

## Impedance triangle
A right triangle with $R$ (base), $X = X_L - X_C$ (perpendicular), $|Z|$ (hypotenuse).

$$\cos\phi = \dfrac{R}{Z}, \qquad \sin\phi = \dfrac{X}{Z}, \qquad \tan\phi = \dfrac{X}{R}$$

## Power in AC — the power triangle
Multiply every side of the impedance triangle by $I^2$ (or work from $V, I$):

$$P = VI\cos\phi \;\text{(W, real/active)} \qquad Q = VI\sin\phi \;\text{(VAR, reactive)} \qquad S = VI \;\text{(VA, apparent)}$$

$$S^2 = P^2 + Q^2, \qquad \text{power factor} = \cos\phi = \dfrac{P}{S} = \dfrac{R}{Z}$$

$Q$ is positive for a lagging (inductive) load, negative for a leading (capacitive) load.
Only $P$ does useful work; $Q$ shuttles back and forth but still loads the cables.

## Parallel circuits
Add **admittances**, not impedances. $Y = \dfrac{1}{Z} = G + jB$ (siemens),
$G$ = conductance, $B$ = susceptance. Branch currents add as phasors:
$I = V\,Y$. Easier than a common denominator when there are three or more branches.

## Series resonance
Occurs when $X_L = X_C$:

$$\omega_0 L = \dfrac{1}{\omega_0 C} \;\Rightarrow\; \omega_0 = \dfrac{1}{\sqrt{LC}} \;\Rightarrow\; f_0 = \dfrac{1}{2\pi\sqrt{LC}}$$

At $f_0$: impedance is minimum $= R$, current is maximum $= V/R$, power factor $= 1$.
The coil and capacitor voltages are equal and opposite, each $= Q$ times the supply voltage
(**voltage magnification**), so a series RLC is an *acceptor* circuit.

### Quality factor and bandwidth
$$Q = \dfrac{\omega_0 L}{R} = \dfrac{1}{\omega_0 C R} = \dfrac{1}{R}\sqrt{\dfrac{L}{C}}$$

Bandwidth = spread between the two half-power (0.707 $I_{max}$) frequencies:

$$\text{BW} = f_2 - f_1 = \dfrac{R}{2\pi L} = \dfrac{f_0}{Q}$$

High $Q$ ⇒ sharp, selective curve, narrow bandwidth.

## Parallel resonance
Ideal $L\|C$ (lossless): same $f_0 = \dfrac{1}{2\pi\sqrt{LC}}$, but here the impedance is
**maximum** and the line current is **minimum** — a *rejector* circuit.

Practical tank (coil of $R + j X_L$ in parallel with $C$):

$$f_r = \dfrac{1}{2\pi}\sqrt{\dfrac{1}{LC} - \dfrac{R^2}{L^2}}, \qquad Z_{dynamic} = \dfrac{L}{CR}$$

When $R$ is small this collapses back to $1/(2\pi\sqrt{LC})$.

---

## Solved numericals

### 1. (RLC series) A coil of $R = 12\ \Omega$, $L = 0.15$ H in series with $C = 100\ \mu$F is across a 230 V, 50 Hz supply. Find the impedance, current, power factor and power.

$X_L = 2\pi(50)(0.15) = 47.12\ \Omega, \qquad X_C = \dfrac{1}{2\pi(50)(100\times10^{-6})} = 31.83\ \Omega$

$X = X_L - X_C = 15.29\ \Omega$ (inductive), $\quad Z = \sqrt{12^2 + 15.29^2} = 19.44\ \Omega$

$I = \dfrac{230}{19.44} = 11.83\ \text{A}, \qquad \cos\phi = \dfrac{12}{19.44} = 0.617\ \text{lagging}\ (\phi = 51.9°)$

$P = VI\cos\phi = 230 \times 11.83 \times 0.617 = 1679.9\ \text{W}$

**Ans:** $Z = 19.44\ \Omega$, $I = 11.83$ A, p.f. $= 0.617$ lagging, $P = 1680$ W. ($S = 2721$ VA, $Q = 2141$ VAR.)

### 2. (Power factor correction) A single-phase motor takes 5 kW at 0.75 power factor lagging from a 230 V, 50 Hz supply. Find the capacitor kVAR and capacitance to raise the power factor to 0.9 lagging.

$\phi_1 = \cos^{-1}0.75 = 41.41°, \quad Q_1 = P\tan\phi_1 = 5 \times 0.8819 = 4.410\ \text{kVAR}$

$\phi_2 = \cos^{-1}0.90 = 25.84°, \quad Q_2 = P\tan\phi_2 = 5 \times 0.4843 = 2.422\ \text{kVAR}$

$Q_C = Q_1 - Q_2 = 1.988\ \text{kVAR}$

$C = \dfrac{Q_C}{2\pi f V^2} = \dfrac{1988}{2\pi(50)(230)^2} = 119.6\ \mu\text{F}$

**Ans:** capacitor rating $= 1.99$ kVAR, $C = 119.6\ \mu$F.

### 3. (Resonance) A series RLC circuit has $R = 20\ \Omega$, $L = 100$ mH, $C = 1\ \mu$F, fed from 50 V. Find the resonant frequency, Q factor, bandwidth and the current at resonance.

$f_0 = \dfrac{1}{2\pi\sqrt{LC}} = \dfrac{1}{2\pi\sqrt{0.1\times10^{-6}}} = 503.3\ \text{Hz}$

$Q = \dfrac{1}{R}\sqrt{\dfrac{L}{C}} = \dfrac{1}{20}\sqrt{\dfrac{0.1}{10^{-6}}} = 15.81$

$\text{BW} = \dfrac{f_0}{Q} = \dfrac{503.3}{15.81} = 31.83\ \text{Hz}$

At resonance $Z = R = 20\ \Omega$, so $I = \dfrac{50}{20} = 2.5$ A.

**Ans:** $f_0 = 503.3$ Hz, $Q = 15.81$, BW $= 31.83$ Hz, $I_{res} = 2.5$ A. (Coil/cap voltage $= Q\times50 = 790.6$ V — note the magnification.)
