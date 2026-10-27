#!/usr/bin/env python3
# url parser - break a url into its parts by hand, no urllib

def parse(url):
    parts = {"scheme": "", "host": "", "port": "", "path": "", "query": "", "fragment": ""}

    if "://" in url:
        parts["scheme"], url = url.split("://", 1)

    # fragment comes off the very end, then the query
    if "#" in url:
        url, parts["fragment"] = url.split("#", 1)
    if "?" in url:
        url, parts["query"] = url.split("?", 1)

    # what's left is host[:port] then /path
    if "/" in url:
        authority, rest = url.split("/", 1)
        parts["path"] = "/" + rest
    else:
        authority, parts["path"] = url, "/"

    if ":" in authority:
        parts["host"], parts["port"] = authority.split(":", 1)
    else:
        parts["host"] = authority
        # fall back to the well known port for the scheme
        parts["port"] = {"http": "80", "https": "443", "ftp": "21"}.get(parts["scheme"], "")

    return parts


tests = [
    "http://example.com/index.html",
    "https://www.reva.edu.in:8080/admissions/apply?course=cse&year=2019#form",
    "ftp://files.example.org/pub/readme.txt",
    "http://localhost/",
]

for u in tests:
    print(u)
    for k, v in parse(u).items():
        print("  %-9s %s" % (k, v))
    print()
