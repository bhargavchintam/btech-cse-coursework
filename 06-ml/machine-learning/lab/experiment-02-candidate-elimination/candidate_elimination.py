# Candidate-Elimination: maintain the whole version space as its S and G boundaries
import pandas as pd

df = pd.read_csv("enjoysport.csv")
attrs = list(df.columns[:-1])
target = df.columns[-1]
n = len(attrs)

X = df[attrs].values.tolist()
y = df[target].values.tolist()

S = ["0"] * n                       # most specific
G = [["?"] * n]                     # most general, a single hypothesis for now


def covers(h, x):
    return all(hi == "?" or hi == xi for hi, xi in zip(h, x))


def fmt(h):
    return "<" + ", ".join(h) + ">"


def more_general(a, b):
    # is a >= b, i.e. everything b accepts a also accepts
    for ai, bi in zip(a, b):
        if ai != "?" and (bi == "?" or ai != bi):
            return False
    return True


for i, (x, label) in enumerate(zip(X, y), 1):
    if label == "Yes":
        G = [g for g in G if covers(g, x)]
        for j in range(n):
            if S[j] == "0":
                S[j] = x[j]
            elif S[j] != x[j]:
                S[j] = "?"           # generalise S just enough to include x
    else:
        newG = []
        for g in G:
            if not covers(g, x):
                newG.append(g)
                continue
            # specialise g along each attribute where S has a definite value
            for j in range(n):
                if g[j] != "?":
                    continue
                if S[j] not in ("0", "?") and S[j] != x[j]:
                    h = g.copy()
                    h[j] = S[j]
                    if more_general(h, S):
                        newG.append(h)
        G = newG
    print(f"After example {i} ({label}):")
    print(f"  S = {fmt(S)}")
    print(f"  G = [{', '.join(fmt(g) for g in G)}]\n")

print("Final version space boundaries:")
print(f"  S = {fmt(S)}")
print("  G = [" + ", ".join(fmt(g) for g in G) + "]")
