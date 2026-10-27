# Unit 9 — Measuring Instruments

## Classification
Absolute instruments give the quantity from their own constants (tangent galvanometer); no
calibration, but slow — used in standards labs. Secondary instruments are pre-calibrated and read
straight off a scale; everything in the lab is secondary. They split by what they do:
- **Indicating** — pointer on a scale, shows the value *now*. Ammeter, voltmeter, wattmeter.
- **Integrating** — totals the quantity over time. Energy meter (kWh), ampere-hour meter.
- **Recording** — draws value vs time on a chart (pen on a moving strip), e.g. logging supply V.

By principle: PMMC, moving iron, dynamometer, induction, thermal, electrostatic, rectifier.

## The three torques
Every indicating instrument needs all three.

1. **Deflecting torque** $T_d$ — moves the pointer, produced by the quantity being measured.
2. **Controlling torque** $T_c$ — opposes $T_d$ and grows with deflection, so the pointer settles
   where $T_d = T_c$ and returns to zero on removal. Spring ($T_c \propto \theta$) or gravity control.
3. **Damping torque** — acts only while the pointer moves, kills the swing so it settles fast; it
   is zero at rest, so it does not affect the reading. Air-friction, eddy-current or fluid damping.
   *Under-damped* overshoots, *over-damped* crawls in, *critically damped* settles fastest.

## Permanent-Magnet Moving-Coil (PMMC)
A light coil of many turns pivots in the field of a permanent magnet; current in it makes a torque
against a hairspring (which also feeds the current in).

$$T_d = N B I A = G\,I \quad (G = N B A), \qquad G I = k\theta \;\Rightarrow\; \theta = \frac{G}{k}\,I \;\propto\; I$$

Deflection $\propto$ current — **uniform scale**. Damping by eddy currents in the aluminium former.
Very sensitive, low power draw, good accuracy.

**Why PMMC reads DC only:** the magnet's field is fixed, so on AC the torque reverses every half
cycle; at 50 Hz the coil's inertia cannot follow and it sits at zero (average torque = 0). For AC
it needs a rectifier (as in a multimeter), then it reads the average scaled to show rms.

## Moving Iron (MI)
Soft iron moved by the field of a fixed current-carrying coil.
- **Attraction type** — the coil pulls an iron disc into it.
- **Repulsion type** — two iron pieces inside the coil magnetise alike and repel.

Either way the force depends on $I^2$:

$$T_d = \tfrac{1}{2} I^2 \frac{dL}{d\theta}, \qquad \theta \propto I^2$$

**Non-uniform scale** — crowded near zero. Because torque $\propto I^2$, reversing the current
reverses field and induced magnetism together, so the torque keeps its direction — **MI reads AC
and DC**, the **true rms** on AC. Cheap and robust, but less accurate and heavier on power than PMMC.

`Remember: MI scale is non-uniform because θ ∝ I². Marked it uniform in the internal, lost the mark.`

## PMMC vs MI

| | PMMC | Moving Iron |
|---|---|---|
| Field from | permanent magnet | the coil current |
| Deflection | $\theta \propto I$ | $\theta \propto I^2$ |
| Scale | uniform | non-uniform (crowded at start) |
| Reads | **DC only** | **AC and DC (rms)** |
| Accuracy | high | moderate |
| Power / cost | low power, dearer | higher power, cheap |

## Extension of range
**Ammeter — shunt.** A small $R_{sh}$ in parallel bypasses most of the current; both see the same
voltage:

$$I_g R_g = (I - I_g) R_{sh} \;\Rightarrow\; R_{sh} = \frac{I_g R_g}{I - I_g}, \qquad
n = \frac{I}{I_g} = 1 + \frac{R_g}{R_{sh}}$$

**Voltmeter — multiplier.** A large $R_s$ in series drops most of the voltage; same $I_g$ in both:

$$V = I_g(R_g + R_s) \;\Rightarrow\; R_s = \frac{V}{I_g} - R_g = R_g(m-1), \qquad
m = \frac{V}{I_g R_g} = 1 + \frac{R_s}{R_g}$$

## Wattmeter — dynamometer type
Two coils: a fixed **current coil** (thick, in series with the load) carries $I$; a moving
**pressure coil** (fine, across the load) carries current $\propto V$. The torque follows the
product of the two fluxes averaged over a cycle:

$$T_d \propto V I \cos\phi = P$$

So it reads **true (active) power** directly, AC or DC, with a nearly uniform scale. On a purely
reactive load $\phi = 90^\circ$, $\cos\phi = 0$, so it reads **zero** even though current flows.

> "The wattmeter multiplies V and I and takes the average itself — that's why it reads real power,
> not VA." — sir, in class

## Energy meter — single-phase induction type
Integrating instrument. An aluminium disc sits between a shunt (pressure) magnet fed by $V$ and a
series (current) magnet fed by $I$; their out-of-phase fluxes induce eddy currents and a driving
torque $\propto V I \cos\phi = P$. A permanent **braking magnet** gives a retarding torque
$\propto N$ (disc speed). At steady speed:

$$N \propto P \;\Rightarrow\; \text{revolutions} = \int N\,dt \propto \int P\,dt = \text{energy}$$

Dial gears count revolutions and show **kWh (units)**; the **meter constant** is in rev/kWh.
*Creeping* (disc turning at no load) is stopped by two holes in the disc; a shading band makes the
pressure-coil flux lag $90^\circ$ so the reading holds at all power factors.

## Multimeter
A PMMC movement plus switched shunts, multipliers and a rectifier — one instrument for DC/AC volts,
DC/AC current and resistance (VOM). The ohms range uses an **internal battery**, so its scale is
reversed and non-uniform (zero ohms = full-scale current). A **digital multimeter** uses an ADC and
display: high input resistance (~10 MΩ, loads the circuit less), no parallax.

## Errors in measurement
- **Gross** — human mistakes: misreading, wrong record, wrong range. Avoided by care.
- **Systematic** — repeatable, one-sided: *instrumental* (friction, wrong calibration),
  *environmental* (temperature, stray fields), *observational* (parallax — read square-on).
- **Random** — small unpredictable scatter; reduced by averaging many readings.

For a measured value $A_m$ against true value $A_t$:

$$e = A_m - A_t \;\text{(absolute)}, \qquad \varepsilon_r = \frac{|e|}{A_t} \;\text{(relative)},
\qquad \%\,\text{error} = \varepsilon_r \times 100$$

**Accuracy** = closeness to the true value; **precision** = closeness of repeated readings to each
other. A stuck-offset instrument is precise but not accurate. Accuracy is quoted as a class, e.g.
class 1.0 = ±1 % of FSD — so read near full scale for the smallest percentage error.

## Solved numericals

### 1. Ammeter shunt
A moving-coil movement has $R_g = 1\ \Omega$ and full-scale deflection at $I_g = 50\ \text{mA}$.
Convert it to read $0$–$5$ A.

$$R_{sh} = \frac{I_g R_g}{I - I_g} = \frac{0.05 \times 1}{5 - 0.05} = \frac{0.05}{4.95}
        = 0.01010\ \Omega = 10.10\ \text{m}\Omega$$

$$n = \frac{I}{I_g} = \frac{5}{0.05} = 100 = 1 + \frac{R_g}{R_{sh}} = 1 + \frac{1}{0.01010}
   = 1 + 99 = 100 \checkmark$$

**Ans:** shunt $R_{sh} = 0.01010\ \Omega\;(10.10\ \text{m}\Omega)$, multiplying power $n = 100$.

### 2. Voltmeter multiplier
A PMMC movement of $R_g = 100\ \Omega$ reads full scale at $I_g = 1\ \text{mA}$. Find the series
multiplier for a $0$–$150$ V voltmeter.

Drop across the movement at FSD: $v_g = I_g R_g = 0.001 \times 100 = 0.1\ \text{V}$.

$$R_s = \frac{V}{I_g} - R_g = \frac{150}{0.001} - 100 = 150000 - 100 = 149900\ \Omega = 149.9\ \text{k}\Omega$$

$$m = \frac{V}{I_g R_g} = \frac{150}{0.1} = 1500 = 1 + \frac{R_s}{R_g} = 1 + \frac{149900}{100}
   = 1 + 1499 = 1500 \checkmark$$

**Ans:** multiplier $R_s = 149.9\ \text{k}\Omega$, multiplying factor $m = 1500$.
