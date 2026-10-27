# Unit 3 — AC Fundamentals

## Generation of sinusoidal emf
A coil of N turns rotating in a uniform magnetic field cuts flux.
When the coil plane is along the field the rate of cutting is maximum.

$e = N B A \omega \sin(\omega t) = E_m \sin(\omega t)$

So the emf is sinusoidal, peak $E_m = N B A \omega$, one full cycle per revolution.
$\omega = 2\pi f$ rad/s, $f$ = cycles per second, $T = 1/f$.

> The emf is zero when flux linkage is maximum and maximum when flux linkage is zero — it depends on the *rate of change*, not the flux itself.

## Instantaneous, peak, average, RMS
- Instantaneous value: $v = V_m \sin(\omega t)$, the value at any instant.
- Peak (amplitude): $V_m$.
- Peak-to-peak: $2V_m$.
- Average over a full cycle = 0 (equal positive and negative halves), so average is defined over a half cycle.
- RMS: the DC value that produces the same heating in a resistor.

### RMS of a full sine — derivation
$V_{rms} = \sqrt{\dfrac{1}{T}\displaystyle\int_0^{T} v^2\,dt}$

Over one cycle, with $\theta = \omega t$:

$V_{rms}^2 = \dfrac{1}{2\pi}\displaystyle\int_0^{2\pi} V_m^2 \sin^2\theta \; d\theta$

Use $\sin^2\theta = \dfrac{1-\cos 2\theta}{2}$:

$V_{rms}^2 = \dfrac{V_m^2}{2\pi}\displaystyle\int_0^{2\pi}\dfrac{1-\cos 2\theta}{2}\,d\theta = \dfrac{V_m^2}{2\pi}\cdot\dfrac{2\pi}{2} = \dfrac{V_m^2}{2}$

$$V_{rms} = \dfrac{V_m}{\sqrt 2} = 0.707\,V_m$$

### Average of a full sine (half cycle) — derivation
$V_{avg} = \dfrac{1}{\pi}\displaystyle\int_0^{\pi} V_m \sin\theta\,d\theta = \dfrac{V_m}{\pi}\big[-\cos\theta\big]_0^{\pi} = \dfrac{V_m}{\pi}(1+1)$

$$V_{avg} = \dfrac{2V_m}{\pi} = 0.637\,V_m$$

## Form factor and peak factor
$$\text{Form factor} = \dfrac{V_{rms}}{V_{avg}} = \dfrac{V_m/\sqrt2}{2V_m/\pi} = \dfrac{\pi}{2\sqrt2} = 1.11$$

$$\text{Peak factor (crest)} = \dfrac{V_m}{V_{rms}} = \sqrt2 = 1.414$$

These two numbers (1.11 and 1.414) are only for a **pure sine**. Any other shape has its own.

## Phasor representation
A sinusoid is drawn as a rotating vector (phasor) of length equal to the RMS value,
turning anticlockwise at $\omega$ rad/s. Only the relative phase between phasors matters,
so we freeze them at $t = 0$.

$v = V_m \sin(\omega t + \phi) \;\Rightarrow\; \mathbf{V} = V_{rms}\angle\phi$

Two phasors of the **same frequency** add by the parallelogram / component method.
Different frequencies cannot share one phasor diagram.

## j-operator
$j = \sqrt{-1}$ — an operator that rotates a phasor by $+90°$ without changing length.

$j^2 = -1, \quad j^3 = -j, \quad j^4 = 1, \quad \dfrac{1}{j} = -j$

A phasor is written in rectangular $a + jb$ or polar $r\angle\theta$ form, with
$r = \sqrt{a^2+b^2}$ and $\theta = \tan^{-1}(b/a)$.

## Impedance
Opposition to AC, combining resistance and reactance:

$$Z = R + jX \qquad |Z| = \sqrt{R^2 + X^2}\quad \angle Z = \tan^{-1}\!\dfrac{X}{R}$$

- Resistor: $Z_R = R$ (no phase shift).
- Inductor: $Z_L = jX_L = j\omega L$ (voltage leads current by 90°).
- Capacitor: $Z_C = -jX_C = \dfrac{1}{j\omega C} = -\dfrac{j}{\omega C}$ (current leads voltage by 90°).

Reactance units are ohms: $X_L = \omega L = 2\pi f L$, $X_C = \dfrac{1}{\omega C} = \dfrac{1}{2\pi f C}$.

Remember: $X_L$ grows with frequency, $X_C$ falls with frequency. Mixed these up once in the internal.

---

## Solved numericals

### 1. An alternating voltage is $v = 325\sin(314\,t)$ volts. Find the peak, RMS, frequency, time period, form factor and peak factor.

Compare with $v = V_m\sin(\omega t)$: $V_m = 325$ V, $\omega = 314$ rad/s.

$f = \dfrac{\omega}{2\pi} = \dfrac{314}{2\pi} = 49.97 \approx 50\ \text{Hz}, \qquad T = \dfrac{1}{f} = 20\ \text{ms}$

$V_{rms} = \dfrac{325}{\sqrt2} = 229.8 \approx 230\ \text{V} \qquad V_{avg} = \dfrac{2\times325}{\pi} = 206.9\ \text{V}$

Form factor $= 229.8/206.9 = 1.11$, peak factor $= 325/229.8 = 1.414$.

**Ans:** $V_m = 325$ V, $V_{rms} = 230$ V, $f = 50$ Hz, $T = 20$ ms, form factor $= 1.11$, peak factor $= 1.414$. (This is the ordinary 230 V, 50 Hz mains.)

### 2. Two voltages $v_1 = 100\sin(\omega t)$ and $v_2 = 80\sin(\omega t + 90°)$ act in series. Find the resultant.

Same frequency, so use phasors (RMS not needed, work with amplitudes):

$\mathbf{V_1} = 100\angle0° = 100 + j0, \qquad \mathbf{V_2} = 80\angle90° = 0 + j80$

$\mathbf{V} = \mathbf{V_1}+\mathbf{V_2} = 100 + j80$

$|\mathbf{V}| = \sqrt{100^2 + 80^2} = 128.1\ \text{V}, \qquad \phi = \tan^{-1}\dfrac{80}{100} = 38.66°$

**Ans:** $v = 128.1\sin(\omega t + 38.66°)$ V.
