# shared loader for the whole project so every script works off the exact same split.
# malignant = 1 (the class we care about catching), benign = 0.

import pandas as pd
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split

RANDOM_STATE = 1
TEST_SIZE = 0.2
TARGET_NAMES = ["benign", "malignant"]


def load_frame():
    data = load_breast_cancer()
    df = pd.DataFrame(data.data, columns=data.feature_names)
    # sklearn codes malignant=0, benign=1; flip it so 1 means malignant
    df["diagnosis"] = 1 - data.target
    return df, list(data.feature_names)


def get_split():
    df, features = load_frame()
    X = df[features].values
    y = df["diagnosis"].values
    return train_test_split(
        X, y, test_size=TEST_SIZE, random_state=RANDOM_STATE, stratify=y)
