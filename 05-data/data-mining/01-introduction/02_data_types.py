#!/usr/bin/env python3
import os
import pandas as pd

here = os.path.dirname(os.path.abspath(__file__))
iris = pd.read_csv(os.path.join(here, "..", "datasets", "iris_subset.csv"))
tennis = pd.read_csv(os.path.join(here, "..", "datasets", "play_tennis.csv"))

iris_types = {
    "sepal_length": ("ratio", "length in cm, true zero, ratios make sense"),
    "sepal_width":  ("ratio", "length in cm, true zero"),
    "petal_length": ("ratio", "length in cm, true zero"),
    "petal_width":  ("ratio", "length in cm, true zero"),
    "species":      ("nominal", "names setosa/versicolor, no order"),
}

tennis_types = {
    "Outlook":     ("nominal", "Sunny/Overcast/Rain, categories with no order"),
    "Temperature": ("ordinal", "Hot > Mild > Cool, ordered but gaps not equal"),
    "Humidity":    ("ordinal", "High > Normal, ordered categories"),
    "Wind":        ("nominal", "Weak/Strong, binary label, no magnitude"),
    "PlayTennis":  ("nominal", "the class, Yes/No"),
}


def show(name, df, types):
    print(name)
    for c in df.columns:
        t, why = types[c]
        print(f"  {c:13s} {t:8s} {why}")
    print()


show("iris_subset.csv", iris, iris_types)
show("play_tennis.csv", tennis, tennis_types)
