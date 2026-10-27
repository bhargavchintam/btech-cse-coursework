#!/usr/bin/env python3

class Proc:
    def __init__(self, name):
        self.name = name
        self.clk = 0

    def tick(self):
        self.clk += 1
        return self.clk

    def local(self, what):
        t = self.tick()
        print(f"{self.name}  {what:<10} clk={t}")

    def send(self, msg):
        t = self.tick()
        print(f"{self.name}  send {msg:<5} clk={t}")
        return t

    def recv(self, msg, ts):
        self.clk = max(self.clk, ts) + 1     # move past the sender's stamp
        print(f"{self.name}  recv {msg:<5} clk={self.clk}  (sent at {ts})")
        return self.clk


p1, p2, p3 = Proc("p1"), Proc("p2"), Proc("p3")
sent = {}
pairs = []

p1.local("a")
sent["m1"] = p1.send("m1")
pairs.append(("m1", sent["m1"], p2.recv("m1", sent["m1"])))
p2.local("b")
sent["m2"] = p2.send("m2")
pairs.append(("m2", sent["m2"], p3.recv("m2", sent["m2"])))
sent["m3"] = p3.send("m3")
pairs.append(("m3", sent["m3"], p1.recv("m3", sent["m3"])))

print("\ncheck send < recv:")
for msg, s, r in pairs:
    ok = "ok" if s < r else "BROKEN"
    print(f"  {msg}: send={s} recv={r}  {ok}")
