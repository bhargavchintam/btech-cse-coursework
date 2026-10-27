#!/usr/bin/env python3
# hashing with hashlib - md5 and sha256, and the avalanche effect
import hashlib

def digests(s):
    b = s.encode()
    return hashlib.md5(b).hexdigest(), hashlib.sha256(b).hexdigest()

msg = input("Enter a string: ")
md5, sha = digests(msg)
print("MD5    :", md5)
print("SHA256 :", sha)

# change one character and watch the digest change completely
if msg:
    flipped = msg[:-1] + chr(ord(msg[-1]) ^ 1)
    _, sha2 = digests(flipped)
    diff = sum(a != b for a, b in zip(sha, sha2))
    print("\none bit changed in the input ->", flipped)
    print("SHA256 :", sha2)
    print("hex chars different:", diff, "of", len(sha))
