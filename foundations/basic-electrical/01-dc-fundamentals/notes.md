# Unit 1 — DC Circuit Fundamentals

## Ohm's law
Voltage across a resistor is proportional to the current through it, temperature constant.

$V = I R$

$R$ in ohms (Ω), $V$ in volts, $I$ in amperes. Also $I = V/R$ and $R = V/I$.

## Resistivity
Resistance of a uniform conductor:

$R = \dfrac{\rho L}{A}$

$\rho$ = resistivity (Ω·m), $L$ = length (m), $A$ = cross-section area (m²).
Copper wire, $\rho = 1.72\times10^{-8}$ Ω·m, $L = 100$ m, $A = 1$ mm² $= 1\times10^{-6}$ m²:
$R = 1.72\times10^{-8}\times100 / 1\times10^{-6} = 1.72$ Ω.

Conductance $G = 1/R$, unit siemens (S).

## Series resistance
Same current through each. Resistances add.

$R_{eq} = R_1 + R_2 + R_3 + \dots$

## Parallel resistance
Same voltage across each. Reciprocals add.

$\dfrac{1}{R_{eq}} = \dfrac{1}{R_1} + \dfrac{1}{R_2} + \dots$

Two in parallel (use this all the time):

$R_{eq} = \dfrac{R_1 R_2}{R_1 + R_2}$

## Voltage division
Series resistors share the source voltage in proportion to their value.

$V_k = V \cdot \dfrac{R_k}{R_1 + R_2 + \dots}$

For two resistors, $V_2 = V \cdot \dfrac{R_2}{R_1 + R_2}$.

## Current division
Parallel resistors share the total current in inverse proportion to their value.
For two resistors carrying total $I$:

$I_1 = I \cdot \dfrac{R_2}{R_1 + R_2}, \qquad I_2 = I \cdot \dfrac{R_1}{R_1 + R_2}$

> The branch current takes the *other* resistor on top. Larger resistor → smaller current.

Remember: current-divider numerator is the opposite branch — got this wrong in the internal.

## Kirchhoff's laws
KCL — at any node, currents in = currents out. Sum of currents at a node is zero.

$\sum I = 0 \ \text{(at a node)}$

KVL — around any closed loop, the sum of voltage rises equals the sum of drops.

$\sum V = 0 \ \text{(around a loop)}$

KCL comes from conservation of charge, KVL from conservation of energy.

## Mesh analysis
Assign a loop (mesh) current to each independent loop, all clockwise.
Write KVL for each mesh in terms of the mesh currents. A shared branch carries the
difference of the two mesh currents. Solve the simultaneous equations.

Matrix form for a two-mesh circuit:

$\begin{bmatrix} R_{11} & -R_{12} \\ -R_{21} & R_{22} \end{bmatrix}\begin{bmatrix} I_1 \\ I_2 \end{bmatrix} = \begin{bmatrix} V_1 \\ V_2 \end{bmatrix}$

$R_{11}$ = total resistance in mesh 1, $R_{12}$ = shared resistance.

## Nodal analysis
Pick a reference node (ground). For every other node write KCL, expressing each branch
current as (node voltage difference)/resistance. Solve for the node voltages.

At a node with voltage $V_n$: $\sum \dfrac{V_n - V_{adjacent}}{R} = I_{source\ into\ node}$

## Star-delta transformation
Convert a 3-terminal star (Y) to an equivalent delta (Δ) and back.
Star arms $R_a, R_b, R_c$ meet at a common point; delta sides $R_{ab}, R_{bc}, R_{ca}$.

Star → Delta (let $P = R_aR_b + R_bR_c + R_cR_a$):

$R_{ab} = \dfrac{P}{R_c}, \quad R_{bc} = \dfrac{P}{R_a}, \quad R_{ca} = \dfrac{P}{R_b}$

Delta → Star (let $S = R_{ab} + R_{bc} + R_{ca}$):

$R_a = \dfrac{R_{ab}R_{ca}}{S}, \quad R_b = \dfrac{R_{ab}R_{bc}}{S}, \quad R_c = \dfrac{R_{bc}R_{ca}}{S}$

Used to simplify unbalanced bridges that are not pure series/parallel.

---

## Solved numerical 1 — Mesh analysis
Two meshes share the middle branch $R_3$. $V_1 = 10$ V, $V_2 = 5$ V,
$R_1 = 1$ kΩ, $R_2 = 1$ kΩ, $R_3 = 2$ kΩ.

```
      R1          R2
  1--/\/\--2--/\/\--3
  +        |        +
 V1=10   R3=2k    V2=5
  -        |        -
  0--------+--------0
```

Both mesh currents clockwise. KVL:

Mesh 1: $R_1 I_1 + R_3(I_1 - I_2) = V_1 \Rightarrow 3k\,I_1 - 2k\,I_2 = 10$
Mesh 2: $R_2 I_2 + R_3(I_2 - I_1) = -V_2 \Rightarrow -2k\,I_1 + 3k\,I_2 = -5$

$V_2$ crosses as a drop in mesh 2, so it lands on the right side as $-5$.
Determinant $= 3k\cdot3k - (2k)(2k) = 5\times10^{6}$.

$I_1 = \dfrac{10\cdot3k - (-5)(2k)}{5\times10^{6}} = \dfrac{20000}{5\times10^{6}} = 4$ mA

$I_2 = \dfrac{3k(-5) - (2k)(10)}{5\times10^{6}}\cdot(-1)$ … solving directly, $I_2 = 1$ mA

Middle branch $I_{R_3} = I_1 - I_2 = 3$ mA, so node-2 voltage $= 3\text{mA}\times2k = 6$ V.

**Ans:** $I_1 = 4$ mA, $I_2 = 1$ mA, $V_{node2} = 6$ V.

## Solved numerical 2 — Star-delta
A star has $R_a = 10$ Ω, $R_b = 20$ Ω, $R_c = 30$ Ω. Find the equivalent delta.

$P = R_aR_b + R_bR_c + R_cR_a = 200 + 600 + 300 = 1100$

$R_{ab} = P/R_c = 1100/30 = 36.67$ Ω
$R_{bc} = P/R_a = 1100/10 = 110$ Ω
$R_{ca} = P/R_b = 1100/20 = 55$ Ω

Check by converting back, $S = 36.67 + 110 + 55 = 201.67$:
$R_a = R_{ab}R_{ca}/S = 36.67\times55/201.67 = 10$ Ω ✓

**Ans:** $R_{ab} = 36.67$ Ω, $R_{bc} = 110$ Ω, $R_{ca} = 55$ Ω.
