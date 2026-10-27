#!/usr/bin/env python3

services = [
    ("EC2",             "IaaS", "raw virtual machines, you manage the OS and up"),
    ("Compute Engine",  "IaaS", "GCP virtual machines, same idea as EC2"),
    ("S3",              "IaaS", "object storage you provision, infra layer"),
    ("AWS Lambda",      "PaaS", "serverless functions, you push code not servers"),
    ("Heroku",          "PaaS", "git push and it builds/runs the app for you"),
    ("Google App Engine","PaaS","deploy the app, platform handles OS and scaling"),
    ("DynamoDB",        "PaaS", "managed database, no servers to run or patch"),
    ("Gmail",           "SaaS", "finished email app, you just log in"),
    ("Salesforce",      "SaaS", "CRM software delivered over the browser"),
    ("Google Docs",     "SaaS", "ready-made office suite, nothing to install"),
    ("Dropbox",         "SaaS", "file storage app for end users"),
]


def classify(model):
    who = {
        "IaaS": "you: OS, runtime, app, data",
        "PaaS": "you: app and data only",
        "SaaS": "you: nothing, just use it",
    }
    return who[model]


print(f"{'service':<20}{'model':<7}reason")
print("-" * 70)
for name, model, reason in services:
    print(f"{name:<20}{model:<7}{reason}")

print("\ncount by model")
for m in ("IaaS", "PaaS", "SaaS"):
    n = sum(1 for _, model, _ in services if model == m)
    print(f"  {m}: {n}   ({classify(m)})")
