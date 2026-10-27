# Experiment 11 — Staircase Wiring (Two-Way Control of One Lamp)

**Date:** 09/05/2018

## Aim
To wire a single lamp so that it can be switched ON or OFF independently from two different points
using two two-way (SPDT) switches.

## Apparatus
| Item | Range | Qty |
|------|-------|-----|
| Two-way switch (SPDT) | 6 A, 250 V | 2 |
| Lamp with holder (incandescent) | 60 W, 230 V | 1 |
| Wooden wiring board | — | 1 |
| PVC insulated wire | 1.5 mm² | as reqd |
| Single phase supply | 230 V, 50 Hz | 1 |
| Screwdriver and line tester | — | 1 |

## Circuit
Each two-way switch has one **common** terminal (C) and two **way** terminals (1 and 2). The phase
goes to the common of S1; the common of S2 goes to the lamp; the two switches are joined by two
**strapping wires** (strap 1 joins the two "1" terminals, strap 2 joins the two "2" terminals).

```
                          strap 1
                    1 o───────────────o 1
                   /                     \
    L o──────────●C                       C●──────────( Lamp )──────────o N
                 |  S1                 S2  |
                   \                     /
                    2 o───────────────o 2
                          strap 2

    L = phase (line)      N = neutral      C = common (pole)
```

## Theory
A two-way switch connects its common terminal to either way-terminal 1 or way-terminal 2. A complete
path from phase to lamp exists only when **both** switches connect their commons to the **same**
strap. If the two switches select different straps the circuit is broken and the lamp is off.
Operating either switch alone changes which strap its common touches, so either switch alone toggles
the lamp — which is what allows control of the lamp from two separate points (top and bottom of a
staircase).

## Procedure
1. Mount the two two-way switches and the lamp holder on the board.
2. Connect the phase (L) to the common terminal of switch S1.
3. Run strap 1 from terminal 1 of S1 to terminal 1 of S2, and strap 2 from terminal 2 of S1 to
   terminal 2 of S2.
4. Connect the common of S2 to the lamp, and the other lamp terminal to neutral (N).
5. Switch on the supply. Operate S1 and S2 through all four position combinations and record the lamp
   state each time.

## Observations
Switch position 1 = common on strap 1, position 2 = common on strap 2.

| S1 position | S2 position | Path through | Lamp |
|-------------|-------------|--------------|------|
| 1 | 1 | strap 1 | ON |
| 1 | 2 | open | OFF |
| 2 | 1 | open | OFF |
| 2 | 2 | strap 2 | ON |

From any row, changing **either** switch changes the lamp state — the lamp is controlled from both
points.

## Calculations
No numerical calculation for a wiring experiment. The switching logic is: the lamp is ON only when
S1 and S2 select the same strap (both 1 or both 2), and OFF when they differ — i.e. the lamp state is
the logical XNOR of the two switch positions. Flipping any one switch inverts this result, giving
independent two-point control.

## Result
The single lamp was wired for two-way control and could be switched ON or OFF independently from
either switch, exactly as the truth table shows. Staircase (two-way) wiring is verified.
