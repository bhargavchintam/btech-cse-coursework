#!/usr/bin/env python3
# cookie parser - split a Set-Cookie response header and a Cookie request header

def parse_set_cookie(header):
    parts = [p.strip() for p in header.split(";")]
    name, _, value = parts[0].partition("=")
    cookie = {"name": name, "value": value, "attributes": {}}
    for p in parts[1:]:
        if "=" in p:
            k, _, v = p.partition("=")
            cookie["attributes"][k.strip()] = v.strip()
        else:
            cookie["attributes"][p] = True        # flag attribute, e.g. HttpOnly / Secure
    return cookie


def parse_cookie(header):
    jar = {}
    for p in header.split(";"):
        p = p.strip()
        if not p:
            continue
        k, _, v = p.partition("=")
        jar[k.strip()] = v.strip()
    return jar


sc = "sessionid=abc123XYZ; Path=/; Domain=example.com; Max-Age=3600; HttpOnly; Secure; SameSite=Lax"
print("Set-Cookie:", sc)
c = parse_set_cookie(sc)
print("  name  =", c["name"])
print("  value =", c["value"])
for k, v in c["attributes"].items():
    print("  attr  = %s -> %s" % (k, v))

print()

req = "sessionid=abc123XYZ; theme=dark; lang=en"
print("Cookie:", req)
for k, v in parse_cookie(req).items():
    print("  %-10s = %s" % (k, v))
