# Unit 7 — Message Authentication

Encryption hides a message. It does NOT prove who sent it or that it arrived
unchanged. Message authentication answers two more questions: is the message
intact (integrity), and did it really come from the claimed sender
(authenticity). A bare hash is not enough — an attacker who alters the message
can just recompute the hash. The fix is to bind a secret, or a private key,
into the check.

## Hash vs MAC vs signature

| | Uses | Integrity | Authenticity | Non-repudiation |
|---|---|---|---|---|
| Hash | nothing (public) | yes | no | no |
| MAC / HMAC | shared secret key | yes | yes | no |
| Digital signature | sender's private key | yes | yes | yes |

A MAC gives no non-repudiation: sender and receiver share the same key, so
either could have produced the tag — a judge cannot tell which. A signature
uses the sender's private key that nobody else holds, so the sender cannot
later deny it.

## MAC

A MAC (Message Authentication Code) takes `(key, message)` and outputs a short
tag `T = MAC(K, m)`. The sender appends `T`; the receiver recomputes it with
the shared `K` and compares. A wrong key or an altered message gives a
different tag. Tags are compared in constant time to avoid timing leaks.

## HMAC construction

HMAC builds a MAC out of any hash `H` (MD5, SHA-256, ...) without needing a
new keyed primitive. With block size `B` and two fixed pads
(`ipad = 0x36` repeated, `opad = 0x5c` repeated):

```
HMAC(K, m) = H( (K' xor opad) || H( (K' xor ipad) || m ) )
```

`K'` is the key padded (or hashed then padded) to `B` bytes. The nested,
double-hash shape defends against length-extension attacks that a naive
`H(K || m)` would suffer. HMAC-SHA256 is the workhorse — TLS, JWT, AWS
request signing all use it.

## Digital signatures

Signing reverses the public-key roles used for encryption:

| | Key to produce | Key to check | Goal |
|---|---|---|---|
| RSA encryption | receiver's PUBLIC key | receiver's PRIVATE key | confidentiality |
| RSA signature | sender's PRIVATE key | sender's PUBLIC key | authenticity + non-repudiation |

You never sign the whole message — you sign its hash. So the real steps are:

```
sign:   h = H(m);  s = h^d mod n        (private key d)
verify: h' = s^e mod n;  accept if h' == H(m)   (public key e)
```

Only the private-key holder can produce `s`; anyone with the public key can
verify. Because the digest is signed, tampering with even one byte of `m`
changes `H(m)` and the check fails.

> RSA "sign = decrypt with the private key" is a textbook slogan. Real
> signatures pad the digest (PKCS#1 v1.5 or PSS) before the exponentiation;
> raw RSA on the bare hash is forgeable.

## Solved problem

RSA with `p=61, q=53` -> `n=3233`, `e=17`, `d=2753`. Sign the digest value
`m = 65`.

```
sign:   s = 65^2753 mod 3233 = 588
verify: 588^17 mod 3233     = 65   -> matches, signature valid
```

**Ans:** signature `s = 588`; verifier recovers `65`, so it is accepted.
Note the exponents are swapped versus encryption of the same key, where
`enc(65) = 65^17 mod 3233 = 2790`.

## Lab programs
- `hmac.c` — HMAC-SHA256 of a message under a key via OpenSSL `HMAC()`,
  cross-checked with `openssl dgst -sha256 -hmac "secretkey"`.
- `digital_signature.c` — generate a 2048-bit RSA key with `EVP_RSA_gen`,
  sign with `EVP_DigestSign` (SHA-256) and verify with `EVP_DigestVerify`;
  prints `signature valid`, then flips one byte to show verification rejects
  the tampered message.
