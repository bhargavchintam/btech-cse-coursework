# Experiment 3 — ID3 Decision Tree

**Date:** 16/10/2020

## Aim
Build a decision tree with the ID3 algorithm (entropy and information gain) on the PlayTennis data, then classify a new sample.

## Dataset
`playtennis.csv` — the classic 14-row PlayTennis table (Outlook, Temperature, Humidity, Wind → PlayTennis), 9 Yes and 5 No.

## Program
`id3.py` — computes entropy and information gain from scratch, recursively splits on the attribute with the highest gain, and stops at pure nodes (or a majority vote when attributes run out).

## Output
```
Entropy(S) = 0.940   (9 Yes, 5 No)
  Gain(Outlook     ) = 0.247
  Gain(Temperature ) = 0.029
  Gain(Humidity    ) = 0.152
  Gain(Wind        ) = 0.048

Decision tree:
Outlook = Sunny
    Humidity = High
        -> No
    Humidity = Normal
        -> Yes
Outlook = Overcast
    -> Yes
Outlook = Rain
    Wind = Weak
        -> Yes
    Wind = Strong
        -> No

Classify {'Outlook': 'Sunny', 'Temperature': 'Cool', 'Humidity': 'High', 'Wind': 'Strong'}
  PlayTennis -> No
```

## Result
Outlook has the highest information gain (0.247), so it becomes the root. The tree matches Quinlan's textbook result — Overcast is a pure Yes leaf, Sunny splits on Humidity, Rain splits on Wind. The new sample `<Sunny, Cool, High, Strong>` is classified **No**.
