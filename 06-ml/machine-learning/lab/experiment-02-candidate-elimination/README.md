# Experiment 2 — Candidate-Elimination Algorithm

**Date:** 02/10/2020

## Aim
Implement the Candidate-Elimination algorithm to obtain the version space (the S and G boundary sets) consistent with the EnjoySport training examples.

## Dataset
`enjoysport.csv` — the same 4-row EnjoySport table used for FIND-S.

## Program
`candidate_elimination.py` — keeps the specific boundary `S` and the general boundary `G`. A positive example generalises `S` and prunes any `G` that fails to cover it; a negative example specialises `G` and prunes any `S` that wrongly covers it.

## Output
```
After example 1 (Yes):
  S = <Sunny, Warm, Normal, Strong, Warm, Same>
  G = [<?, ?, ?, ?, ?, ?>]

After example 2 (Yes):
  S = <Sunny, Warm, ?, Strong, Warm, Same>
  G = [<?, ?, ?, ?, ?, ?>]

After example 3 (No):
  S = <Sunny, Warm, ?, Strong, Warm, Same>
  G = [<Sunny, ?, ?, ?, ?, ?>, <?, Warm, ?, ?, ?, ?>, <?, ?, ?, ?, ?, Same>]

After example 4 (Yes):
  S = <Sunny, Warm, ?, Strong, ?, ?>
  G = [<Sunny, ?, ?, ?, ?, ?>, <?, Warm, ?, ?, ?, ?>]

Final version space boundaries:
  S = <Sunny, Warm, ?, Strong, ?, ?>
  G = [<Sunny, ?, ?, ?, ?, ?>, <?, Warm, ?, ?, ?, ?>]
```

## Result
The version space collapses to `S = <Sunny, Warm, ?, Strong, ?, ?>` and `G = [<Sunny,?,?,?,?,?>, <?,Warm,?,?,?,?>]`. FIND-S's single hypothesis is exactly the S boundary here; Candidate-Elimination additionally reports every general hypothesis still consistent with the data.
