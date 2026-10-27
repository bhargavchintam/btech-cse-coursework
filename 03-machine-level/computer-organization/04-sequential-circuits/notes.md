# Unit 4 — Sequential Circuits

A combinational circuit's output depends only on the present inputs. A sequential circuit
also depends on what happened before — it has memory. The memory element is the latch or
flip-flop, and everything in this unit (counters, registers) is built out of them.

## Latch vs flip-flop

- A **latch** is level sensitive. While the enable/clock is high the output follows the
  input (it is "transparent"). The input can change the output many times in one clock.
- A **flip-flop** is edge triggered. The output can change only at the clock edge
  (rising or falling), once per clock. Between edges the inputs are ignored.

Edge triggering is what makes big designs work: every flip-flop in the system samples
its input at the same instant, so the next state is computed from a clean snapshot of
the present state. With transparent latches a value could race through two stages in
one clock. Two timing terms that come with edge triggering:

- **Setup time** — input must be stable *before* the clock edge.
- **Hold time** — input must stay stable *after* the edge.

## SR latch (NOR)

Two cross-coupled NOR gates. Output of each gate feeds back to an input of the other.

```
R ---[NOR]--+--- Q
             \ /
              X     (outputs cross back to the other gate's input)
             / \
S ---[NOR]--+--- Q'
```

| S | R | Q+   | action  |
|---|---|------|---------|
| 0 | 0 | Q    | hold    |
| 0 | 1 | 0    | reset   |
| 1 | 0 | 1    | set     |
| 1 | 1 | 0,0  | invalid |

The invalid state: with S=R=1 both NOR outputs are forced to 0, so Q and Q' are no
longer complements. Worse, when S and R return to 0 together, both gates race and the
final state is unpredictable. This is why S=R=1 is forbidden, and why JK exists.
(NAND version is the same idea with active-low inputs — S'=R'=0 is the invalid one.)

## D, JK, T flip-flops

**D (data/delay):** one input, Q+ = D. Just stores whatever is on D at the clock edge.
No invalid state. This is the flip-flop everything is actually built from in Verilog.

| D | Q+ |
|---|----|
| 0 | 0  |
| 1 | 1  |

**JK:** the SR latch with the invalid state fixed — J=K=1 now means toggle.

| J | K | Q+  | action |
|---|---|-----|--------|
| 0 | 0 | Q   | hold   |
| 0 | 1 | 0   | reset  |
| 1 | 0 | 1   | set    |
| 1 | 1 | Q'  | toggle |

Characteristic equation: **Q+ = JQ' + K'Q**

**T (toggle):** T=1 toggles, T=0 holds. Q+ = T ⊕ Q. Made from JK by tying J=K=T.
With T held at 1 the output is a divide-by-2 of the clock — this is why counters
are chains of T flip-flops.

Characteristic equations in one place: SR: Q+ = S + R'Q (SR=0), D: Q+ = D,
JK: Q+ = JQ' + K'Q, T: Q+ = TQ' + T'Q.

## Excitation tables (combined) — exam favourite

The truth table answers "given the inputs, what is Q+". The excitation table is the
reverse: "I know Q and I want Q+, what must the inputs be". Needed for every counter
design and every conversion problem.

| Q | Q+ | S | R | J | K | D | T |
|---|----|---|---|---|---|---|---|
| 0 | 0  | 0 | x | 0 | x | 0 | 0 |
| 0 | 1  | 1 | 0 | 1 | x | 1 | 1 |
| 1 | 0  | 0 | 1 | x | 1 | 0 | 1 |
| 1 | 1  | x | 0 | x | 0 | 1 | 0 |

> Sir kept repeating this: the excitation table is read backwards from the truth
> table. Half of IA1 section B was just this table. Learn the x's — they are what
> make the K-maps simplify.

The x's have a logic: to go 0→1 with JK, J must be 1 but K can be anything (J=1,K=1
toggles 0 to 1 anyway). That is why JK excitation has the most don't cares and gives
the simplest counter logic.

## Race-around in JK and the master-slave fix

In a *level-triggered* JK with J=K=1, the output toggles after one propagation delay
tp. But the clock is still high, so it toggles again, and again — the output races
around as long as the clock stays high. Happens when the clock high time > tp.

**Master-slave JK:** two latches in series, master clocked by clk, slave by clk'.

```
J,K --->[ master ]--->[ slave ]---> Q
           clk           clk'
```

While clk is high the master captures (slave is locked, output frozen); when clk
falls the slave copies the master. Output changes exactly once per clock — race
gone. Modern answer: use edge triggering; an edge-triggered JK samples J,K only at
the edge, so there is nothing to race. Remember: race-around needs J=K=1 AND level
triggering. "Edge-triggered JK has race-around" is a trap option in MCQs.

## Flip-flop conversions

Procedure (same every time):
1. Write the truth table of the flip-flop you *want* (its inputs + Q → Q+).
2. For each row, use the excitation table of the flip-flop you *have* to find what
   its inputs must be.
3. K-map the inputs of the available flip-flop → conversion logic.

Results worth memorising: **SR→JK:** S = JQ', R = KQ. **JK→D:** J = D, K = D'.
**JK→T:** J = K = T.

Worked steps for JK→D (want D behaviour, have JK):

| D | Q | Q+ | J | K |
|---|---|----|---|---|
| 0 | 0 | 0  | 0 | x |
| 0 | 1 | 0  | x | 1 |
| 1 | 0 | 1  | 1 | x |
| 1 | 1 | 1  | x | 0 |

K-map for J (x's at Q=1): J = D. K-map for K (x's at Q=0): K = D'.
So a JK plus one inverter behaves as a D flip-flop.

## Asynchronous vs synchronous counters

**Asynchronous (ripple):** only the first flip-flop gets the external clock; each
stage is clocked by the previous stage's output. All T inputs tied to 1.

```
clk -->[T0]--Q0-->[T1]--Q1-->[T2]--Q2-->[T3]--Q3
        T=1        T=1        T=1        T=1
```

Q0 is clk/2, Q1 is clk/4, Q3 is clk/16 — a 4-bit ripple counter is a divide-by-16.
Cheap (no logic at all) but the carry *ripples*: worst case (1111→0000) the change
propagates through all n flip-flops one after another.

Ripple delay = n × tpd. Example: 4 flip-flops, tpd = 25 ns → worst case
4 × 25 = 100 ns, so fmax = 1/100 ns = 10 MHz. During the ripple the counter briefly
shows wrong intermediate counts — glitches if you decode the outputs.

**Synchronous:** all flip-flops get the same clock; combinational logic computes each
J,K (or D) from the present state. Delay is one tpd + gate delay regardless of n, so
it is fast, but it costs the next-state logic. All counter design questions in the
exam are synchronous design with JK.

## Mod-n counters — mod-10 (decade) worked

A mod-N counter has N states, needs n flip-flops where **2^n ≥ N** (n = ceil(log2 N)).
Mod-10: 2^3 = 8 < 10 ≤ 16 = 2^4, so 4 flip-flops, states 0000 to 1001 (0–9).

Ripple version with reset logic: let a 4-bit ripple counter run, detect the first
illegal count 10 = **1010** and clear immediately. Decoding 1010 fully needs
Q3·Q2'·Q1·Q0', but Q3·Q1 alone is enough — checking 0 to 9, no legal state has Q3
and Q1 high together (8 = 1000, 9 = 1001 both have Q1 = 0). So:

```
CLR' = NAND(Q3, Q1)     count: 0 1 2 3 4 5 6 7 8 9 (10 appears for ~ns, cleared) 0 ...
```

This is exactly what the 7490 decade counter IC does. The synchronous version instead
compares for 9 and loads 0 on the next clock (see mod10_counter.v) — no glitch state.

## Ring and Johnson counters

Both are shift registers with feedback, no next-state logic at all.

- **Ring counter:** Q of the last stage feeds D of the first. Initialise with a
  single 1 (say 1000) and it circulates: 1000→0100→0010→0001→1000. n flip-flops
  give only **n states**, but the outputs are one-hot — no decoding gates needed.
- **Johnson (twisted ring):** the *complement* of the last Q feeds back.
  n flip-flops give **2n states**. 4-bit sequence (matches johnson_counter_tb output):

  0000 → 1000 → 1100 → 1110 → 1111 → 0111 → 0011 → 0001 → 0000

  Each state is decodable with a single 2-input AND gate. Used for timing signals.

Cost comparison for N states: binary counter ceil(log2 N) flip-flops + logic,
Johnson N/2 flip-flops, ring N flip-flops.

## Shift registers

A register is a group of flip-flops sharing a clock. A shift register moves its
contents one position per clock. Four types, named by how data goes in/out:

| Type | In       | Out      | n-bit data needs        |
|------|----------|----------|-------------------------|
| SISO | serial   | serial   | n clocks in, n out      |
| SIPO | serial   | parallel | n clocks in, read at once |
| PISO | parallel | serial   | load once, n clocks out |
| PIPO | parallel | parallel | 1 clock (plain register) |

SIPO is the receive end of a serial link, PISO the transmit end. Shifting 1011 into
a 4-bit SIPO MSB first (from shift_register_tb): 0000 → 0001 → 0010 → 0101 → 1011.

In Verilog the shift must use nonblocking `<=`. With blocking `=` the new value of
stage 0 would be copied into stage 1 in the same clock and the whole register just
fills with the input bit — made this exact mistake first try at home.

## Solved numericals

**Q1. Convert a D flip-flop into a JK flip-flop.**

Want JK, have D. D excitation is trivial (D = Q+), so just tabulate Q+ for JK:

| J | K | Q | Q+ | D |
|---|---|---|----|---|
| 0 | 0 | 0 | 0  | 0 |
| 0 | 0 | 1 | 1  | 1 |
| 0 | 1 | 0 | 0  | 0 |
| 0 | 1 | 1 | 0  | 0 |
| 1 | 0 | 0 | 1  | 1 |
| 1 | 0 | 1 | 1  | 1 |
| 1 | 1 | 0 | 1  | 1 |
| 1 | 1 | 1 | 0  | 0 |

K-map on D over J,K,Q: pairs (1,0,0)(1,1,0) give JQ', pairs (0,0,1)(1,0,1) give K'Q.
**Ans:** D = JQ' + K'Q — the JK characteristic equation itself, which is a good self-check.

**Q2. Design a mod-6 synchronous counter (0→1→2→3→4→5→0) using JK flip-flops.**

2^2 = 4 < 6 ≤ 8 = 2^3, so 3 flip-flops Q2 Q1 Q0. States 110, 111 unused (don't care).

| Q2Q1Q0 | next | J2 K2 | J1 K1 | J0 K0 |
|--------|------|-------|-------|-------|
| 000    | 001  | 0  x  | 0  x  | 1  x  |
| 001    | 010  | 0  x  | 1  x  | x  1  |
| 010    | 011  | 0  x  | x  0  | 1  x  |
| 011    | 100  | 1  x  | x  1  | x  1  |
| 100    | 101  | x  0  | 0  x  | 1  x  |
| 101    | 000  | x  1  | 0  x  | x  1  |

K-maps (110, 111 as don't cares everywhere):

**Ans:** J0 = K0 = 1, J1 = Q2'Q0, K1 = Q0, J2 = Q1Q0, K2 = Q0.

Checking the unused states with these equations: 110 → 111 → 000 and 111 → 000, so
the counter is self-correcting — it re-enters the main cycle within two clocks even
if it powers up in an illegal state. Always write this check; it carries marks.

**Q3. How many flip-flops for a mod-60 counter (the seconds counter of a digital
clock)? How many states go unused?**

Need 2^n ≥ 60. 2^5 = 32 < 60, 2^6 = 64 ≥ 60. **Ans:** 6 flip-flops, 64 − 60 = 4
unused states. (And the reverse question: max modulus with 6 flip-flops = 2^6 = 64.)
Exam trap: the condition is 2^n ≥ N, not strictly greater — mod-8 needs exactly 3.
