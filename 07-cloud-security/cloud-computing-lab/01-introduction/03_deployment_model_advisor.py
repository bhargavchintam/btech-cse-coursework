#!/usr/bin/env python3

def advise(sens, budget, scale, control):
    if sens == "high" and control == "high":
        if budget == "low" or scale == "high":
            return "hybrid", "keep sensitive data private, burst the rest to public cloud"
        return "private", "full control and isolation, budget covers own hardware"
    if sens == "low":
        return "public", "no sensitivity worry, pay-as-you-go scales cheapest"
    return "hybrid", "some data is sensitive but you still want public-cloud scale"


cases = [
    ("startup web app",  "low",  "low",  "high", "low"),
    ("bank core system", "high", "high", "low",  "high"),
    ("hospital portal",  "high", "high", "high", "high"),
    ("research batch",   "low",  "low",  "high", "low"),
    ("gov records",      "high", "low",  "low",  "high"),
]

print(f"{'workload':<18}{'sens':<6}{'budget':<8}{'scale':<7}{'control':<9}-> recommend")
print("-" * 78)
for name, sens, budget, scale, control in cases:
    pick, why = advise(sens, budget, scale, control)
    print(f"{name:<18}{sens:<6}{budget:<8}{scale:<7}{control:<9}-> {pick:<8} ({why})")
