#!/usr/bin/env python3
# base64 encode/decode written out by hand - this is what HTTP Basic auth and MIME use
import base64

TBL = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"


def encode(data):
    out = ""
    for i in range(0, len(data), 3):
        chunk = data[i:i+3]
        n = len(chunk)
        val = chunk[0] << 16                 # pack up to 3 bytes into 24 bits
        if n > 1:
            val |= chunk[1] << 8
        if n > 2:
            val |= chunk[2]
        out += TBL[(val >> 18) & 63]         # then read off four 6-bit groups
        out += TBL[(val >> 12) & 63]
        out += TBL[(val >> 6) & 63] if n > 1 else "="
        out += TBL[val & 63] if n > 2 else "="
    return out


def decode(s):
    s = s.rstrip("=")
    bits = ""
    for c in s:
        bits += format(TBL.index(c), "06b")
    out = bytearray()
    for i in range(0, len(bits) - 7, 8):
        out.append(int(bits[i:i+8], 2))
    return bytes(out)


msg = b"Bhargav:secret"                      # user:password, the Basic auth case
enc = encode(msg)
print("input  :", msg)
print("base64 :", enc)
print("decoded:", decode(enc))

# check mine against the stdlib so I know it's right
print("stdlib :", base64.b64encode(msg).decode())
assert enc == base64.b64encode(msg).decode()
assert decode(enc) == msg
print("matches stdlib: ok")

print("Authorization: Basic " + enc)
