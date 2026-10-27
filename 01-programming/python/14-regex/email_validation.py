# check if an email looks valid
import re

pat = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'

emails = [
    "ravi@gmail.com",
    "john.doe@company.co.in",
    "bad email@x.com",
    "no_at_symbol.com",
    "a@b",
    "test123@sub.domain.org",
]

for e in emails:
    if re.match(pat, e):
        print(e, "-> valid")
    else:
        print(e, "-> invalid")
