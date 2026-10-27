#!/usr/bin/env python3

class Part:
    def __init__(self, name, vote):
        self.name = name
        self.vote = vote
        self.state = "init"

    def prepare(self):
        self.state = "ready" if self.vote == "yes" else "abort"
        return self.vote

    def finish(self, decision):
        self.state = "committed" if decision == "commit" else "aborted"
        return self.state


def twopc(parts):
    print("phase 1 - PREPARE")
    votes = []
    for p in parts:
        v = p.prepare()
        print(f"  coord -> PREPARE -> {p.name};  {p.name} votes {v.upper()}")
        votes.append(v)
    decision = "commit" if all(v == "yes" for v in votes) else "abort"
    print(f"coordinator decides: {decision.upper()}")
    print("phase 2 - " + decision.upper())
    for p in parts:
        st = p.finish(decision)
        print(f"  coord -> {decision.upper()} -> {p.name};  {p.name} is {st}")
    print()
    return decision


print("run 1 - everyone votes yes")
twopc([Part("db1", "yes"), Part("db2", "yes"), Part("db3", "yes")])

print("run 2 - db2 votes no")
twopc([Part("db1", "yes"), Part("db2", "no"), Part("db3", "yes")])
