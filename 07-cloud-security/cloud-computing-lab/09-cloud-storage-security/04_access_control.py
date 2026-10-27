#!/usr/bin/env python3
# IAM-style policy check. explicit Deny beats Allow, default is Deny.

policy = [
    {"effect": "Allow", "principal": "alice", "action": "s3:GetObject", "resource": "photos/*"},
    {"effect": "Allow", "principal": "alice", "action": "s3:PutObject", "resource": "photos/*"},
    {"effect": "Deny",  "principal": "alice", "action": "s3:*",         "resource": "photos/secret.jpg"},
    {"effect": "Allow", "principal": "bob",   "action": "s3:GetObject", "resource": "photos/*"},
]


def match(pat, val):
    if pat.endswith("*"):
        return val.startswith(pat[:-1])
    return pat == val


def applies(s, req):
    return (s["principal"] == req["principal"]
            and match(s["action"], req["action"])
            and match(s["resource"], req["resource"]))


def evaluate(req):
    allow = False
    for s in policy:
        if applies(s, req):
            if s["effect"] == "Deny":
                return "Deny"        # one deny is enough, stop
            allow = True
    return "Allow" if allow else "Deny"


reqs = [
    {"principal": "alice", "action": "s3:GetObject",    "resource": "photos/cat.jpg"},
    {"principal": "alice", "action": "s3:GetObject",    "resource": "photos/secret.jpg"},
    {"principal": "alice", "action": "s3:DeleteObject", "resource": "photos/cat.jpg"},
    {"principal": "bob",   "action": "s3:GetObject",    "resource": "photos/cat.jpg"},
    {"principal": "bob",   "action": "s3:PutObject",    "resource": "photos/cat.jpg"},
    {"principal": "eve",   "action": "s3:GetObject",    "resource": "photos/cat.jpg"},
]

for req in reqs:
    print(f"{req['principal']:6} {req['action']:15} {req['resource']:18} -> {evaluate(req)}")
