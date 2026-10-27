# P, NP, and coping with hard problems

The last unit. So far every paradigm gave a polynomial algorithm. This unit is about the
problems where nobody has found one - and probably nobody can - and what you do anyway.

## Decision problems
The theory is stated for DECISION problems: the answer is yes or no, not a number. "Is there a
tour of cost <= k?" instead of "what is the cheapest tour?". Any optimisation problem has a
decision twin, and if you can answer the decision version fast you can binary-search k to get
the optimum. So restricting to yes/no loses nothing and makes the classes clean.

## The classes
- **P** - decision problems SOLVABLE in polynomial time. Sorting, shortest path, matching,
  primality. The "tractable" problems.
- **NP** - problems VERIFIABLE in polynomial time. If someone hands you a proposed solution (a
  "certificate"), you can check it is valid in polynomial time. NP does not mean
  "non-polynomial" - it is *nondeterministic polynomial*: a machine that could guess the
  certificate would solve it in polynomial time.
- **NP-hard** - at least as hard as everything in NP. Every NP problem reduces to it in
  polynomial time. An NP-hard problem need not be in NP itself (need not even be a decision
  problem).
- **NP-complete** - the intersection: in NP AND NP-hard. The hardest problems that are still
  in NP. If any one NP-complete problem has a polynomial algorithm, then P = NP and all of them do.

```
        NP-hard
       /       \
   NP-complete   (harder things, halting problem...)
       |
      NP
       |
       P
```

## Verifier vs solver
This is the whole intuition for NP. SOLVING sudoku is hard; CHECKING a filled sudoku is trivial.
Finding a Hamiltonian cycle is hard; given a cycle, confirming it visits every vertex once is a
linear scan. NP is the class where checking is easy even if finding is not. The open question -
the famous P vs NP - is whether easy-to-check always means easy-to-solve. Almost everyone
believes P != NP, nobody has proved it, and there is a million-dollar prize either way.

> "You don't prove a problem is hard by failing to solve it. You prove it by reducing a known
> hard problem TO it." - lecturer, and this is the part people get wrong in the exam.

## Reductions
A reduction turns problem A into problem B: transform any instance of A, in polynomial time,
into an instance of B whose answer is the same. Written A <=p B, and it means B is at least as
hard as A. This is how NP-completeness spreads:

1. Cook (1971) proved SAT is NP-complete directly (every NP problem reduces to SAT).
2. After that, to show a NEW problem X is NP-complete you only: (a) show X is in NP, and
   (b) reduce a KNOWN NP-complete problem to X. Done - no need to argue about all of NP again.

Direction matters and trips everyone: to prove X hard you reduce the known-hard problem TO X,
not X to something. Get the arrow backwards and you have proved nothing.

## The classic NP-complete problems
Worth knowing by name - the exam asks to list a few:

- **SAT / 3-SAT** - is there an assignment making a boolean formula true? The original.
- **Clique** - does the graph contain a complete subgraph of k vertices?
- **Vertex cover** - is there a set of k vertices touching every edge? (complement of independent set)
- **Hamiltonian cycle** - is there a cycle visiting every vertex exactly once?
- **Travelling salesman (TSP)** - Hamiltonian cycle of total cost <= k?
- **Subset sum / partition** - does some subset add up to a target?
- **Graph colouring** - can the graph be coloured with k colours, no two adjacent alike?

They are all NP-complete, so they are all reducible to each other. Different masks on the same
hard face.

## Coping strategies
The problem does not go away because it is NP-complete - you still need an answer. Options:

- **Exact exponential** - just pay the cost. Backtracking, branch-and-bound (units 09, 10).
  Fine when n is small or good pruning cuts the tree.
- **Approximation algorithms** - polynomial, and provably within a factor of optimal. The best
  compromise when you can bound the error. Examples in this folder:
    - `03_vertex_cover_approx` - repeatedly pick any uncovered edge, take BOTH endpoints. At most
      2x the optimal cover, guaranteed. A clean 2-approximation.
    - `02_knapsack_approximation` - greedy by value/weight ratio. Fast, usually good, no tight
      bound for plain 0/1 (a proper FPTAS exists but is heavier).
- **Heuristics** - polynomial, often good, NO guarantee. `01_tsp_nearest_neighbor` - always walk
  to the nearest unvisited city. Can be tricked into a bad tour, but simple and fast.
- **Special cases / parameterisation** - the general problem is hard but a restricted input is
  easy (2-colouring is P, 2-SAT is P, a tree instead of a graph).

## Approximation ratio
For a minimisation problem, an algorithm is a c-approximation if its answer is always <= c times
the optimum (c >= 1). The vertex-cover algorithm above is a 2-approximation: a proof, not a hope.
That is the difference between an approximation algorithm and a heuristic - the heuristic just
tries, the approximation comes with a bound.

```
approach          time            quality
--------------------------------------------------------
exact (B&B)       exponential     optimal
approximation     polynomial      within a proven factor
heuristic         polynomial      no guarantee, often fine
```
