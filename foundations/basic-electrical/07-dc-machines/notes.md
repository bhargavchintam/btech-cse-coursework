# Unit 7 — DC Machines

A DC machine is reversible: the same machine works as a generator (mechanical → electrical)
or as a motor (electrical → mechanical). The construction is identical for both.

## Construction
- **Yoke (frame):** outer cast-steel body. Carries the flux between poles and protects the machine.
- **Poles + pole shoes:** bolted to the yoke, spread the flux over the armature. Laminated.
- **Field winding:** copper coils on the poles. Carries the field current, sets up the flux Φ.
- **Armature core:** laminated silicon-steel cylinder on the shaft, slotted to hold the winding.
  Laminated to cut eddy currents.
- **Armature winding:** the coils in which EMF is induced (generator) or which carry the current
  that makes torque (motor).
- **Commutator:** copper segments — converts the AC in the armature to DC at the brushes
  (a mechanical rectifier). In a motor it feeds current to the right coils to keep the torque one way.
- **Brushes:** carbon, ride on the commutator, connect the rotating winding to the outside circuit.

> Lecturer: "The commutator is the whole trick — no commutator, no DC machine."

## Working principle
**Generator** — a conductor moved through a magnetic field has an EMF induced in it
(Faraday's law). Direction from Fleming's right-hand rule. The commutator makes the output DC.

**Motor** — a current-carrying conductor in a magnetic field feels a force

$$F = B I l$$

Direction from Fleming's left-hand rule. That force turns the armature.

### Fleming's rules
- **Right hand → generators.** Thumb = Motion, First finger = Field, seCond finger = Current.
- **Left hand → motors.** Same three fingers, but now the current is the input and the
  thuMb gives the Motion (force).

## EMF equation
Flux cut by one conductor per revolution = $P\Phi$.
Time for one revolution = $60/N$ s.
So EMF per conductor = $P\Phi N/60$.
Conductors in series per path = $Z/A$.

$$E = \frac{P\Phi Z N}{60A}$$

P = poles, Φ = flux/pole (Wb), Z = total armature conductors, N = rpm, A = parallel paths.
**Lap winding:** A = P. **Wave winding:** A = 2.

## Types of excitation
How the field winding gets its current:
- **Separately excited** — field fed from a separate DC source.
- **Self-excited** — field fed from the machine's own armature. Three kinds:
  - **Shunt:** field across the armature. Many turns of thin wire, high resistance.
    $I_a = I_L + I_{sh}$.
  - **Series:** field in series with the armature. Few turns of thick wire, carries full load
    current. $I_a = I_{se} = I_L$.
  - **Compound:** both a shunt and a series field. Cumulative (fields aid) or differential
    (fields oppose); long-shunt or short-shunt by where the shunt field is tapped.

## Back EMF
When a motor runs, its armature turns in the field, so it also generates an EMF — one that
opposes the supply. This is the **back EMF** $E_b$.

$$E_b = \frac{P\Phi Z N}{60A}, \qquad E_b = V - I_a R_a$$

Back EMF makes the motor self-regulating: load ↑ → speed ↓ → $E_b$ ↓ →
$I_a = (V - E_b)/R_a$ ↑ → more torque. It draws exactly the current the load needs.

## Torque equation
Mechanical power developed = electrical power converted = $E_b I_a$.
Also $P = T\omega = T \cdot 2\pi N/60$. Equate, and put $E_b = P\Phi ZN/60A$:

$$T_a = \frac{P\Phi Z I_a}{2\pi A} = 0.159\,\Phi Z I_a \frac{P}{A} \;\text{ N·m}$$

So $T_a \propto \Phi I_a$. Shunt motor: Φ ≈ constant → $T \propto I_a$.
Series motor: Φ ∝ $I_a$ → $T \propto I_a^2$ (big starting torque).

## Speed equation
From $E_b = V - I_a R_a$ and $E_b \propto \Phi N$:

$$N \propto \frac{E_b}{\Phi} = \frac{V - I_a R_a}{\Phi}$$

## Speed control
- **Armature (rheostatic) control** — resistance in series with the armature drops the voltage,
  lowers $E_b$, so speed falls. Gives speeds **below** base. Wasteful (I²R lost in the resistor).
- **Field (flux) control** — a rheostat in the shunt field weakens Φ, so speed rises. Gives speeds
  **above** base. Cheap and efficient, but limited (too little flux and it runs unstable).
- **Voltage control** — vary the voltage on the armature itself (Ward-Leonard set). Smooth, wide
  range both ways, but needs extra machines or a converter.

## Starters — why a DC motor needs one
At start N = 0, so $E_b = 0$, so

$$I_{a,\,start} = \frac{V}{R_a}$$

$R_a$ is tiny (~0.5 Ω), so this is 10–20× full-load current — it would burn the winding.
A **starter** puts resistance in series at start and cuts it out step by step as the motor speeds
up and $E_b$ builds. The 3-point starter adds a no-volt coil and an overload trip; the 4-point
starter separates the holding coil so that field-control doesn't drop the starter out.

## Losses and efficiency
- **Copper losses** — $I_a^2 R_a$ plus field loss. Vary with load.
- **Iron (core) losses** — hysteresis + eddy current in the armature core. ≈ constant.
- **Mechanical losses** — friction + windage. ≈ constant.
Iron + mechanical = **rotational (stray) loss**, roughly fixed.

$$\eta = \frac{\text{output}}{\text{input}} = \frac{\text{output}}{\text{output} + \text{losses}}$$

## Applications
- **Shunt** (≈ constant speed): lathes, blowers, centrifugal pumps.
- **Series** (high starting torque): cranes, hoists, electric traction, starter motors.
- **Cumulative compound** (high starting torque and won't run away on no load): rolling mills,
  punches, lifts.

---

## Solved numericals

**1.** A 4-pole, lap-wound DC generator has 500 armature conductors, flux 0.02 Wb per pole, and
runs at 1200 rpm. Find the generated EMF.

Lap → A = P = 4.

$$E = \frac{P\Phi ZN}{60A} = \frac{4 \times 0.02 \times 500 \times 1200}{60 \times 4}
    = \frac{48000}{240}$$

**Ans:** E = 200 V

**2.** A 230 V DC shunt motor takes an armature current of 20 A at 1000 rpm, $R_a = 0.5\,\Omega$.
The load is increased so that $I_a = 30$ A. Find the back EMF in each case and the new speed
(flux constant).

$$E_{b1} = 230 - 20(0.5) = 220\text{ V}, \qquad E_{b2} = 230 - 30(0.5) = 215\text{ V}$$

Flux constant → $N \propto E_b$:

$$N_2 = 1000 \times \frac{215}{220} = 977.3\text{ rpm}$$

**Ans:** $E_{b1} = 220$ V, $E_{b2} = 215$ V, $N_2 = 977.3$ rpm (speed drops as load rises)

**3.** A 4-pole, wave-wound DC motor has 400 conductors, flux 0.025 Wb/pole, and carries an
armature current of 25 A. Find the armature torque.

Wave → A = 2.

$$T_a = 0.159\,\Phi Z I_a \frac{P}{A}
      = 0.159 \times 0.025 \times 400 \times 25 \times \frac{4}{2} = 0.159 \times 500$$

**Ans:** $T_a \approx 79.5$ N·m

Remember: the constant in the torque formula is $1/2\pi = 0.159$ — not 0.318. Lost 2 marks on
this in the internal.
