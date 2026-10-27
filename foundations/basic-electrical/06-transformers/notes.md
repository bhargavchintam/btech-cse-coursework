# Unit 6 — Single-Phase Transformers

A transformer changes voltage/current levels at constant frequency by mutual induction.
No moving parts. Works only on AC.

## Construction

- **Core** — laminated silicon steel, thin sheets varnished apart to cut eddy currents.
- **Windings** — two coils, primary (input) and secondary (output), wound on the core.
- Core types: **core type** (windings surround the core) and **shell type** (core surrounds the windings).

## Working principle

AC in the primary sets up an alternating flux in the core. The same flux links the secondary
and induces an EMF in it (Faraday's law) — same frequency, only the level changes with the turns.

## EMF equation

Flux is sinusoidal, $\phi = \phi_m\sin\omega t$. Induced EMF in a coil of $N$ turns:

$$e = -N\frac{d\phi}{dt} = -N\phi_m\omega\cos\omega t$$

Peak EMF $E_m = N\omega\phi_m = N(2\pi f)\phi_m$. RMS value is $E_m/\sqrt2$:

$$E = \frac{2\pi f N \phi_m}{\sqrt2} = \frac{2\pi}{\sqrt2}\,f N \phi_m = 4.44\,f N \phi_m$$

$$\boxed{E = 4.44\,f\,N\,\phi_m} \qquad (\phi_m = B_m \times A)$$

So $E_1 = 4.44 f N_1 \phi_m$ and $E_2 = 4.44 f N_2 \phi_m$.

## Turns ratio

Divide the two EMFs — the $4.44 f\phi_m$ cancels:

$$\frac{E_2}{E_1} = \frac{N_2}{N_1} = K$$

For an ideal transformer input VA = output VA, so current goes the other way:

$$\frac{E_2}{E_1} = \frac{N_2}{N_1} = \frac{I_1}{I_2} = K$$

$K>1$ step-up, $K<1$ step-down.

## Ideal vs practical

**Ideal:** no winding resistance, no leakage flux, no core loss, infinite core permeability,
100% efficiency. A convenient fiction.

**Practical:** windings have resistance $R_1,R_2$ (copper loss); leakage flux adds reactance
$X_1,X_2$; the core draws a magnetising current and burns hysteresis + eddy-current power.
Efficiency is high (96–99%) but not 100%.

## Equivalent circuit

Referred to the primary: a series winding branch $R_{01}=R_1+R_2'$, $X_{01}=X_1+X_2'$ (the load
drop), and a shunt magnetising branch — $R_0$ carrying the core-loss current $I_w$, $X_0$ the
magnetising current $I_\mu$, with $I_0=\sqrt{I_w^2+I_\mu^2}$. Refer a secondary quantity across by $1/K^2$.

## Losses

- **Core (iron) loss** $P_i$ — hysteresis + eddy current; *constant* at all loads (V and f fixed).
- **Copper loss** $P_{cu}=I^2R$ in the windings; *varies as (load)²*.

## Open-circuit and short-circuit tests

**OC test** (rated voltage, secondary open, done on LV side): current is only $I_0$, so the
wattmeter reads the **iron loss** $P_i$ (copper loss is negligible). Gives the shunt branch:
$$\cos\varphi_0 = \frac{W_0}{V_0 I_0},\quad I_w = I_0\cos\varphi_0,\quad I_\mu = I_0\sin\varphi_0,\quad R_0 = \frac{V_0}{I_w},\quad X_0 = \frac{V_0}{I_\mu}$$

**SC test** (reduced voltage, secondary shorted, rated current, HV side): flux is tiny so iron
loss is negligible; the wattmeter reads the **full-load copper loss** $P_{cu}$. Series params:
$$Z_{01} = \frac{V_{sc}}{I_{sc}},\quad R_{01} = \frac{W_{sc}}{I_{sc}^2},\quad X_{01} = \sqrt{Z_{01}^2 - R_{01}^2}$$

> Sir: "Open circuit gives you the **iron**, short circuit gives you the **copper**." Never mix them up.

## Efficiency

$$\eta = \frac{\text{output}}{\text{output} + \text{losses}} = \frac{x\,S\cos\varphi}{x\,S\cos\varphi + P_i + x^2 P_{cu}}$$

where $x$ is the fraction of full load and $S$ the rated VA.

**Condition for maximum efficiency:** differentiate and set to zero — max when the *variable*
copper loss equals the *constant* iron loss:

$$x^2 P_{cu} = P_i \quad\Longrightarrow\quad x = \sqrt{\frac{P_i}{P_{cu}}}$$

So the transformer is designed to peak a little below full load, where it runs most of the time.

## Voltage regulation

Drop from no-load to full-load secondary voltage, as a fraction of no-load:

$$\%\,\text{reg} = \frac{I_2(R_{02}\cos\varphi \pm X_{02}\sin\varphi)}{V_2}\times100$$

$+$ for **lagging** pf, $-$ for **leading** pf. For a leading load the regulation can go
**negative** — the output voltage actually rises on load.

Remember: leading pf can give negative regulation — nearly lost a mark on this in the internal.

## All-day efficiency

For distribution transformers, which stay energised 24 h but are loaded only part of the day.
Based on **energy** (kWh), not power:

$$\eta_{all\text{-}day} = \frac{\text{output energy in kWh (24 h)}}{\text{output energy} + \text{losses energy}}$$

Iron loss runs all 24 h, copper loss only while loaded — so a transformer that idles most of the
day can have good ordinary efficiency but poor all-day efficiency (iron loss dominates).

---

## Solved numericals

### 1. EMF equation

A 50 Hz single-phase transformer has a maximum core flux of 0.02 Wb. The primary has 500 turns
and the secondary 100 turns. Find $E_1$, $E_2$ and the turns ratio.

$$E_1 = 4.44\,f N_1\phi_m = 4.44\times50\times500\times0.02 = 2220\,\text{V}$$
$$E_2 = 4.44\,f N_2\phi_m = 4.44\times50\times100\times0.02 = 444\,\text{V}$$
$$K = \frac{N_2}{N_1} = \frac{100}{500} = 0.2 \;=\; \frac{E_2}{E_1} = \frac{444}{2220} = 0.2 \checkmark$$

**Ans:** $E_1 = 2220$ V, $E_2 = 444$ V, $K = 0.2$ (step-down).

### 2. Efficiency

A 20 kVA transformer has iron loss 300 W and full-load copper loss 675 W. Find the full-load
efficiency at 0.8 pf and the load fraction for maximum efficiency.

Full-load output $= 20000\times0.8 = 16000$ W. Losses $= 300 + 675 = 975$ W.
$$\eta_{FL} = \frac{16000}{16000 + 975} = 0.9426 = 94.26\%$$

Maximum efficiency when $x^2 P_{cu} = P_i$:
$$x = \sqrt{\frac{P_i}{P_{cu}}} = \sqrt{\frac{300}{675}} = 0.667$$

At that load Cu loss $= 0.667^2\times675 = 300$ W $= P_i$; output 10666.7 W, loss 600 W, so $\eta_{max} = 10666.7/11266.7 = 94.67\%$.

**Ans:** $\eta_{FL} = 94.26\%$; maximum efficiency at $x = 0.667$ (13.33 kVA), $\eta_{max} = 94.67\%$.

### 3. Voltage regulation

A transformer has $R_{02} = 0.2\,\Omega$ and $X_{02} = 0.4\,\Omega$ referred to the secondary.
With $I_2 = 50$ A and $V_2 = 200$ V, find the regulation at 0.8 lagging, unity and 0.8 leading pf.

Lagging: $\dfrac{50(0.2\times0.8 + 0.4\times0.6)}{200}\times100 = \dfrac{50(0.16+0.24)}{200}\times100 = 10\%$

Unity: $\dfrac{50\times0.2\times1}{200}\times100 = 5\%$

Leading: $\dfrac{50(0.2\times0.8 - 0.4\times0.6)}{200}\times100 = \dfrac{50(0.16-0.24)}{200}\times100 = -2\%$

**Ans:** $+10\%$ (lag), $+5\%$ (unity), $-2\%$ (lead — voltage rises on load).
