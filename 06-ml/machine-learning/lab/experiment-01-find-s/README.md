# Experiment 1 — FIND-S Algorithm

**Date:** 25/09/2020

## Aim
Implement the FIND-S algorithm to find the most-specific hypothesis consistent with the positive training examples in the EnjoySport data.

## Dataset
`enjoysport.csv` — the classic 4-row EnjoySport table (Sky, AirTemp, Humidity, Wind, Water, Forecast → EnjoySport).

## Program
`find_s.py` — starts from the maximally specific hypothesis `<0,0,0,0,0,0>`, ignores every negative example, and generalises an attribute to `?` whenever a positive example disagrees with the current hypothesis.

## Output
```
Attributes: ['Sky', 'AirTemp', 'Humidity', 'Wind', 'Water', 'Forecast']
Initial h = ['0', '0', '0', '0', '0', '0']

after +ve #1   ['Sunny', 'Warm', 'Normal', 'Strong', 'Warm', 'Same']
    h = ['Sunny', 'Warm', 'Normal', 'Strong', 'Warm', 'Same']

after +ve #2   ['Sunny', 'Warm', 'High', 'Strong', 'Warm', 'Same']
    h = ['Sunny', 'Warm', '?', 'Strong', 'Warm', 'Same']

skip (negative)  ['Rainy', 'Cold', 'High', 'Strong', 'Warm', 'Change']  -> No
after +ve #3   ['Sunny', 'Warm', 'High', 'Strong', 'Cool', 'Change']
    h = ['Sunny', 'Warm', '?', 'Strong', '?', '?']

Final hypothesis:
  <Sunny, Warm, ?, Strong, ?, ?>
```

## Result
FIND-S converges to `<Sunny, Warm, ?, Strong, ?, ?>` — the most-specific hypothesis consistent with the positive examples. It never consults the negatives, so it cannot detect noise or report the full version space.
