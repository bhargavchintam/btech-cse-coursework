# Unit 10 — Domestic Wiring and Safety

## Types of domestic wiring
- **Cleat wiring** — VIR/PVC wires held on porcelain cleats screwed to the wall. Cheap and
  temporary; wires are exposed, so only for sheds and test wiring.
- **Casing-capping** — wires run inside a rectangular wooden/PVC casing closed by a capping.
  Neat, cheap, protects from dust; the wood type is a fire risk if it gets damp.
- **Conduit wiring** — wires drawn through metal or PVC pipes (conduit). *Surface conduit* on
  the wall, *concealed conduit* buried in plaster (most modern houses). Best mechanical and fire
  protection, metal conduit must itself be earthed. Costliest and slowest to install.

Choice depends on cost, appearance, safety and the building. Concealed conduit is the standard.

## Switching
A switch always goes in the **live (phase) wire**, never the neutral — so the appliance is dead
when off.

**One-way** — a single SPST switch controls a lamp from one place. Live → switch → lamp → neutral.

**Two-way** — two SPDT (two-way) switches so a lamp can be turned on or off from *either* place.
Each switch has a common and two travelers; the two travelers link the switches. Flipping either
switch changes the state of the lamp.

**Staircase wiring** — the classic use of two-way switching: one switch downstairs, one upstairs,
the same stair light controlled from both. Walk up, switch on at the bottom, switch off at the top.

## Tube light (fluorescent lamp)
A glass tube coated with phosphor, filled with argon and a little mercury vapour, filaments at
each end. Two extra parts: a **choke** (an iron-cored inductor, the ballast) in series, and a
**glow-starter** (a bimetal strip in a small neon bulb) across the tube.

Sequence at switch-on:
1. Full mains appears across the starter; its neon glows, heating the bimetal, which bends and
   **closes**. Current now flows through the choke and both filaments, heating them so they emit
   electrons (thermionic emission).
2. With the starter closed its neon goes out, the bimetal cools and the contacts **open suddenly**.
3. Breaking that current makes the choke throw a large induced EMF ($e = -L\,di/dt$, a few hundred
   volts) that **strikes the arc** through the mercury vapour. UV from the arc hits the phosphor,
   which glows white.
4. Running, the tube voltage is low (~110 V); the choke now **limits the current** (ballast). The
   voltage is too low to re-fire the starter, so it stays open.

The choke makes the p.f. poor (~0.5 lagging) — a **capacitor across the input** corrects it.

> "The tube lights on the *inductive kick* when the starter opens — no choke, no strike." — sir

## Fuse and fuse rating
A fuse is a thin wire (low melting point) in series with the load — the deliberate weakest link.
On overload or short circuit it melts ($I^2 R t$ heating) and breaks the circuit.
- **Rated / current rating** — the current it carries indefinitely without melting.
- **Fusing current** — the current at which it actually melts (higher than rated).
- **Fusing factor** $= \dfrac{\text{fusing current}}{\text{rated current}} > 1$.
Rewirable "kit-kat" fuses are cheap but imprecise; **HRC** (high rupturing capacity) fuses clear
heavy faults safely. Fuse the **live** wire only.

## MCB (Miniature Circuit Breaker)
A resettable switch that trips on overcurrent by two mechanisms:
- a **bimetal strip** — bends on a sustained overload (thermal, inverse-time),
- an **electromagnet** — snaps open instantly on a short-circuit (magnetic).
Reset by flipping the lever; no wire to replace. Trip curves B/C/D suit lighting/general/motor
loads. Preferred over rewirable fuses: precise, resettable, safer.

## ELCB / RCCB — earth-leakage protection
An **RCCB** passes live and neutral through a toroidal current transformer. Normally the go and
return currents are equal and their fluxes cancel. If some current leaks to earth (through a
faulty appliance or a person), live no longer equals neutral; the **residual** flux induces a
current in a sensing coil that trips the breaker — typically at **30 mA within ~30 ms**, fast
enough to save a life. The older voltage-operated **ELCB** sensed voltage on the earth wire
instead. An MCB protects the *wiring* from overload; an RCCB protects the *person* from leakage.

## Earthing
Connect all metal appliance bodies to the general mass of earth by a low-resistance path, so a
fault current goes to earth (and trips the fuse/MCB) instead of through a person.
- **Plate earthing** — a 60×60 cm GI/copper plate buried ~3 m down in alternating layers of
  charcoal and salt, kept moist by a watering pipe.
- **Pipe earthing** — a ~40 mm GI pipe, 2.5–3 m long, driven vertically, surrounded by charcoal
  and salt. Cheaper and common. (Earth resistance from `earthing_resistance.m`.)
Charcoal + salt and watering keep the soil conductive so the earth resistance stays low.

## Why the third pin is longer and thicker
- **Longer** — it makes contact **first** when you plug in and breaks **last** when you pull out,
  so the body is earthed before live is applied and stays earthed until after live is removed.
- **Thicker** — it must carry a heavy fault current at low resistance, and its size mechanically
  keys the plug and opens the shutters over the live/neutral holes in a shuttered socket.

## Electric shock and safety
Shock severity depends on the **current** through the body, its path, and the duration. Rough 50 Hz
figures: ~1 mA just perceptible, 10–15 mA "can't let go", >50 mA risks ventricular fibrillation.
Wet skin lowers body resistance and makes it worse.
Precautions: proper earthing, correct fuse/MCB, an RCCB, sound insulation, never work on a live
circuit, isolate first, rubber mat and dry hands, don't overload sockets.
First aid: **switch off the supply first**; if you can't, push the victim clear with a dry
insulator (never bare hands); then give CPR and call for help.

`Remember: RCCB trips on the L–N imbalance, not on overload. Mixed it up with the MCB once.`

## Energy tariff and the bill
Energy billed in **units**, 1 unit = 1 kWh. A **two-part tariff** charges a **fixed charge**
(from the sanctioned load, ₹/kW) plus an **energy charge** per unit, usually on a rising **slab**
(the first block cheap, later blocks dearer). Taxes and a fuel surcharge are added on top.

$$\text{units} = \frac{\sum (\text{watt} \times \text{hours/day} \times \text{qty}) \times \text{days}}{1000}$$

## Solved numericals

### 1. Fuse / cable sizing
A 230 V kitchen circuit feeds a 2000 W microwave, a 1000 W toaster and an 800 W mixer (unity p.f.).
Find the current and select a fuse/MCB.

$$P = 2000 + 1000 + 800 = 3800\ \text{W}, \qquad
I = \frac{P}{V} = \frac{3800}{230} = 16.52\ \text{A}$$

Standard ratings 6, 10, 16, 20, 25, 32 A — the next rating **above** 16.52 A is **20 A** (a 16 A
would run overloaded). The cable must be rated to carry at least 20 A.

**Ans:** $I = 16.52$ A, use a **20 A** fuse/MCB with cable rated $\ge 20$ A.

### 2. Monthly energy bill
A house runs 5 lamps of 60 W for 5 h, 2 fans of 80 W for 10 h, and a 1000 W heater for 2 h each
day. Tariff: first 100 units ₹4.50, above 100 units ₹6.00. Find the monthly bill (30 days).

Daily energy $= 5(60)(5) + 2(80)(10) + 1000(2) = 1500 + 1600 + 2000 = 5100\ \text{Wh} = 5.1\ \text{kWh}$

$$\text{units/month} = 5.1 \times 30 = 153\ \text{units}$$

Slab: first 100 units @ ₹4.50 $= ₹450$; next 53 units @ ₹6.00 $= ₹318$.

**Ans:** 153 units, bill $= 450 + 318 = ₹768$.
