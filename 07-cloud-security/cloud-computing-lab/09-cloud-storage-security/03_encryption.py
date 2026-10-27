#!/usr/bin/env python3
# Bindu Bhargava  29-08-20
# at-rest encryption: sha256 keystream in counter mode, XORed with the bytes

import hashlib


def keystream(key, n):
    out = bytearray()
    ctr = 0
    while len(out) < n:
        out.extend(hashlib.sha256(key + ctr.to_bytes(8, "big")).digest())
        ctr += 1
    return bytes(out[:n])


def encrypt(key, pt):
    ks = keystream(key, len(pt))
    return bytes(a ^ b for a, b in zip(pt, ks))


def decrypt(key, ct):
    return encrypt(key, ct)      # XOR stream, same op decrypts


key = hashlib.sha256(b"correct horse battery staple").digest()
pt = b"top secret object data stored in the cloud bucket"

ct = encrypt(key, pt)
back = decrypt(key, ct)

print("plaintext :", pt)
print("ciphertext:", ct.hex())
print("decrypted :", back)
assert back == pt
print("round-trip ok:", back == pt)

bad = hashlib.sha256(b"wrong passphrase").digest()
print("wrong key :", decrypt(bad, ct))
