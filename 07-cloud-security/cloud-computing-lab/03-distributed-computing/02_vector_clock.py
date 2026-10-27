#!/usr/bin/env python3

n = 3

class Proc:
    def __init__(self, i):
        self.i = i
        self.vc = [0] * n

    def event(self, name):
        self.vc[self.i] += 1
        v = list(self.vc)
        print(f"p{self.i}  {name:<4} {v}")
        return v

    def send(self, name):
        self.vc[self.i] += 1
        print(f"p{self.i}  {name:<4} {list(self.vc)}  send")
        return list(self.vc)

    def recv(self, name, ts):
        for k in range(n):
            self.vc[k] = max(self.vc[k], ts[k])
        self.vc[self.i] += 1
        v = list(self.vc)
        print(f"p{self.i}  {name:<4} {v}  recv")
        return v


def order(a, b):
    le = all(x <= y for x, y in zip(a, b))
    ge = all(x >= y for x, y in zip(a, b))
    if le and ge:
        return "equal"
    if le:
        return "a -> b"
    if ge:
        return "b -> a"
    return "concurrent"


p0, p1, p2 = Proc(0), Proc(1), Proc(2)

e1 = p0.event("e1")
m1 = p0.send("s1")
e2 = p1.recv("e2", m1)
e3 = p1.event("e3")
e4 = p2.event("e4")
m2 = p2.send("s2")
e5 = p1.recv("e5", m2)

print("\ncompare a pair:")
print(f"  e2 {e2} vs e3 {e3}: {order(e2, e3)}")
print(f"  e1 {e1} vs e4 {e4}: {order(e1, e4)}")
print(f"  e2 {e2} vs e4 {e4}: {order(e2, e4)}")
