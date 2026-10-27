# Unit 2 — Network Theorems

All of these apply to linear networks. They save work on circuits that would be ugly to
solve by plain mesh/nodal analysis, especially when only one branch or one load matters.

## Thevenin's theorem
Any linear two-terminal network can be replaced by a single voltage source $V_{th}$ in
series with a resistance $R_{th}$.

Steps:
1. Remove the load from the two terminals A–B.
2. Find $V_{th}$ = open-circuit voltage across A–B.
3. Deactivate all independent sources (short voltage sources, open current sources) and
   find $R_{th}$ = resistance looking into A–B.
4. Reconnect the load to $V_{th}$ in series with $R_{th}$.

Load current: $I_L = \dfrac{V_{th}}{R_{th} + R_L}$

## Norton's theorem
Any linear two-terminal network can be replaced by a single current source $I_N$ in
parallel with a resistance $R_N$.

Steps:
1. Remove the load.
2. Short A–B and find $I_N$ = short-circuit current.
3. $R_N = R_{th}$ (same as Thevenin — sources deactivated).
4. Reconnect the load across $I_N \parallel R_N$.

Thevenin and Norton are source transformations of each other:

$V_{th} = I_N R_N, \qquad R_{th} = R_N$

## Superposition theorem
In a linear network with more than one independent source, the current (or voltage) in any
branch equals the algebraic sum of the responses caused by each source acting alone.

Steps:
1. Keep one source active, deactivate the rest (short voltage sources, open current sources).
2. Find the branch response due to that source.
3. Repeat for every source.
4. Add the responses algebraically (mind the signs).

Only works for current and voltage — not power, since power is not linear in the source.

## Maximum power transfer theorem
A source delivers maximum power to a load when the load resistance equals the Thevenin
resistance of the source network.

$R_L = R_{th} \Rightarrow P_{max} = \dfrac{V_{th}^{2}}{4R_{th}}$

At this point efficiency is only 50% — half the power is lost in $R_{th}$. Matching is for
maximum *power*, not maximum efficiency.

> For maximum power you deliberately mismatch efficiency. Fine for signals, terrible for a
> power system.

## Reciprocity theorem
In a linear bilateral network with a single source, if the source in branch X produces a
current in branch Y, then moving that same source to branch Y produces the same current in
branch X. The ratio of excitation to response is unchanged when the two are interchanged.

Only for a single source, and the network must be bilateral (ordinary R, L, C — no
transistors, no dependent sources).

---

## Solved numerical 1 — Thevenin's theorem
Find the Thevenin equivalent across A–B, then the current in $R_L = 2$ kΩ.
$V_1 = 12$ V, $R_1 = 3$ kΩ (source to A), $R_2 = 6$ kΩ (A to B/ground).

Open-circuit voltage (load removed, no current in $R_1$ ... $R_1$ and $R_2$ form a divider):

$V_{th} = V_1 \cdot \dfrac{R_2}{R_1 + R_2} = 12 \cdot \dfrac{6k}{9k} = 8\ \text{V}$

Thevenin resistance (short $V_1$, so $R_1 \parallel R_2$):

$R_{th} = \dfrac{R_1 R_2}{R_1 + R_2} = \dfrac{3k \cdot 6k}{9k} = 2\ \text{kΩ}$

Load current:

$I_L = \dfrac{V_{th}}{R_{th} + R_L} = \dfrac{8}{2k + 2k} = 2\ \text{mA}, \quad V_L = I_L R_L = 4\ \text{V}$

**Ans:** $V_{th} = 8$ V, $R_{th} = 2$ kΩ, $I_L = 2$ mA, $V_L = 4$ V.

## Solved numerical 2 — Maximum power transfer
For the same source ($V_{th} = 8$ V, $R_{th} = 2$ kΩ), find $R_L$ for maximum power and the
power delivered.

Maximum power when $R_L = R_{th} = 2$ kΩ.

$P_{max} = \dfrac{V_{th}^{2}}{4R_{th}} = \dfrac{8^{2}}{4 \cdot 2000} = \dfrac{64}{8000} = 8\ \text{mW}$

Check: at $R_L = 2$ kΩ, $I_L = 8/4k = 2$ mA, $P = I_L^{2}R_L = (2\text{mA})^2 \cdot 2k = 8$ mW ✓

**Ans:** $R_L = 2$ kΩ, $P_{max} = 8$ mW.
