# Unit 8 — AC Machines

## Rotating magnetic field
Feed a 3-phase winding (coils 120° apart in space) with 3-phase current (120° apart in time)
and the resultant flux comes out **constant in magnitude and rotating** at synchronous speed.
This rotating field is what a 3-phase induction motor runs on — no rotating magnets needed.

$$N_s = \frac{120 f}{P}$$

f = supply frequency (Hz), P = poles. The whole machine is built around this speed.

## Three-phase induction motor — construction
- **Stator:** laminated core with slots carrying the 3-phase winding. Sets up the rotating field.
- **Rotor:** two types —
  - **Squirrel cage:** copper/aluminium bars in the rotor slots, shorted at both ends by end
    rings. No slip rings, no external connection. Rugged, cheap, sealed. Most motors are this.
  - **Slip-ring (wound):** a real 3-phase winding on the rotor, brought out through three slip
    rings so external resistance can be added — for high starting torque and some speed control.

Cage is simpler and needs no maintenance; slip-ring costs more but lets you get at the rotor circuit.

## Slip
The rotor can never quite catch the field. **Slip** is how far it lags:

$$s = \frac{N_s - N}{N_s}, \qquad N = (1-s)N_s$$

Full-load slip is small, typically 2–5%.

### Why an induction motor can never run at synchronous speed
If N = Ns there is no relative motion between the field and the rotor bars, so no flux is cut, so
no rotor EMF, no rotor current, and **no torque**. The rotor would immediately slow down. So it
always runs a little below Ns — the machine is "asynchronous".

## Rotor frequency and rotor EMF
The rotor bars see the field at the *slip* speed, not the full speed:

$$f_r = s f, \qquad E_{2r} = s E_2$$

$E_2$ = standstill (s = 1) rotor EMF per phase. At standstill $f_r = f$; at full load $f_r$ is
only a few Hz.

## Torque–slip characteristic
$$T \propto \frac{s E_2^2 R_2}{R_2^2 + (s X_2)^2}$$

- Low slip (near N = Ns): $sX_2 \ll R_2$, so $T \propto s$ — nearly a straight line.
- High slip (near start): $sX_2 \gg R_2$, so $T \propto 1/s$ — torque tails off.
- Between them sits the **maximum (pull-out) torque**, at

$$s_{maxT} = \frac{R_2}{X_2}$$

Adding rotor resistance (slip-ring motor) pushes the peak toward s = 1 → more starting torque.

## Starting methods
At start s = 1, so the motor pulls 5–7× full-load current. Ways to hold that down:
- **DOL (direct-on-line):** switch straight onto the supply. Small motors only. Full torque,
  full inrush.
- **Star-delta:** start in star (phase voltage = $V_L/\sqrt3$), run in delta. Starting current
  and starting torque both drop to **1/3**.
- **Autotransformer:** apply a reduced voltage through a tapped transformer at start, then full
  voltage. Current and torque fall as the square of the tap ratio.
- **Rotor resistance (slip-ring only):** external resistance in the rotor circuit for high
  starting torque at low current.

## Single-phase induction motor
A single-phase winding makes a **pulsating** field, not a rotating one. By the double-revolving-
field theory it splits into two equal fields turning opposite ways: at standstill their torques
cancel → **zero starting torque**. So the motor is **not self-starting**. Spin it by hand and it
keeps running, but on its own it just hums.

### Making it self-start
Add a second (auxiliary) winding to fake a two-phase supply and get a rotating field at start:
- **Split-phase:** auxiliary winding of higher resistance → its current leads, giving a phase
  split. Modest starting torque.
- **Capacitor-start:** a capacitor in series with the auxiliary winding pushes the split close to
  90° → much better starting torque. A centrifugal switch cuts the auxiliary out once running.

## Alternator (synchronous generator) basics
Field on the rotor (fed DC through slip rings), 3-phase armature on the stator. The rotor is
driven at Ns; its field sweeps the stator coils and induces a 3-phase EMF. It runs at exactly Ns —
that is why it is "synchronous". EMF per phase:

$$E = 4.44\, f\, \Phi\, T\, K_p K_d$$

f = frequency, Φ = flux/pole, T = turns/phase, $K_p$ = pitch factor, $K_d$ = distribution factor.

---

## Solved numericals

**1.** A 4-pole, 3-phase induction motor on a 50 Hz supply runs at 1440 rpm. Find the synchronous
speed and the slip.

$$N_s = \frac{120 \times 50}{4} = 1500\text{ rpm}$$
$$s = \frac{1500 - 1440}{1500} = 0.04 = 4\%$$

**Ans:** $N_s = 1500$ rpm, s = 4%

**2.** A 6-pole, 3-phase, 50 Hz induction motor runs at a slip of 3%. Find the synchronous speed,
the rotor speed and the rotor frequency.

$$N_s = \frac{120 \times 50}{6} = 1000\text{ rpm}$$
$$N = (1-s)N_s = 0.97 \times 1000 = 970\text{ rpm}$$
$$f_r = s f = 0.03 \times 50 = 1.5\text{ Hz}$$

**Ans:** $N_s = 1000$ rpm, N = 970 rpm, $f_r = 1.5$ Hz

**3.** The rotor of a 3-phase induction motor has resistance 0.02 Ω/phase and standstill reactance
0.1 Ω/phase. At what slip is the torque maximum?

$$s_{maxT} = \frac{R_2}{X_2} = \frac{0.02}{0.1} = 0.2 = 20\%$$

**Ans:** maximum torque at s = 0.2 (20%)

Remember: at maximum torque the rotor resistance equals the *slip-adjusted* reactance,
$R_2 = s X_2$. The size of the max torque doesn't depend on $R_2$ — only the slip where it
happens does.
