# Unit 5 — Public-Key Cryptography

Symmetric ciphers need both parties to already share a secret key. For n users who all
want to talk privately that is n(n-1)/2 keys, and there is no safe way to hand out the
first key over an open channel. Public-key cryptography (Diffie & Hellman, 1976) fixes
both problems: each user keeps a **private key** and publishes a matching **public key**.
Anything encrypted with the public key can only be undone with the private one.

The whole idea rests on a **one-way (trapdoor) function** — easy to compute forwards,
hard to reverse without the trapdoor:
- RSA leans on the hardness of factoring a large n = p·q.
- Diffie-Hellman and ElGamal lean on the discrete logarithm problem: given g^a mod p,
  recover a.

| | Symmetric | Public-key |
|---|---|---|
| Keys | one shared secret | public + private pair |
| Key distribution | hard (needs secure channel) | easy (publish the public key) |
| Speed | fast | slow (~1000x) |
| Uses | bulk data encryption | key exchange, digital signatures |
| Examples | AES, DES | RSA, Diffie-Hellman, ElGamal, ECC |

> In practice you use both: RSA/DH to agree a session key, then AES to encrypt the actual
> traffic. This is a hybrid cryptosystem — public-key for the handshake, symmetric for bulk.

## RSA algorithm

Key generation:
1. Pick two large primes p, q.
2. n = p·q  (the modulus, made public).
3. phi(n) = (p-1)(q-1).
4. Choose e with 1 < e < phi and gcd(e, phi) = 1  (public exponent).
5. Compute d = e^-1 mod phi  (private exponent, via extended Euclid).
6. Public key (e, n), private key (d, n). Discard p, q, phi.

Encrypt / decrypt (message m, 0 <= m < n):

```
c = m^e mod n
m = c^d mod n
```

It works because e·d ≡ 1 (mod phi), so by Euler's theorem m^(ed) ≡ m (mod n).

### Solved: RSA key computation

Take p = 61, q = 53, e = 17.

- n = 61 × 53 = 3233
- phi = (61-1)(53-1) = 60 × 52 = 3120
- gcd(17, 3120) = 1, so e = 17 is valid.
- d = 17^-1 mod 3120. Extended Euclid gives 17 × 2753 = 46801 = 15×3120 + 1, so d = 2753.

Encrypt m = 65:  c = 65^17 mod 3233 = 2790.
Decrypt:         m = 2790^2753 mod 3233 = 65.

**Ans:** n = 3233, d = 2753, enc(65) = 2790, dec(2790) = 65.

## Diffie-Hellman key exchange

Two parties agree a shared secret over a public channel without ever sending it. Public
parameters: a prime p and a generator g.

| Step | Alice | Bob |
|---|---|---|
| private | a | b |
| send | A = g^a mod p | B = g^b mod p |
| compute | s = B^a mod p | s = A^b mod p |

Both land on the same s = g^(ab) mod p. An eavesdropper sees p, g, A, B but must solve
the discrete log to get a or b.

### Solved: DH

p = 23, g = 5, a = 6, b = 15.
- A = 5^6 mod 23 = 8
- B = 5^15 mod 23 = 19
- Alice: 19^6 mod 23 = 2;  Bob: 8^15 mod 23 = 2.

**Ans:** shared secret = 2 on both sides.

## ElGamal

Public-key encryption built directly on discrete logs. Keys: private x, public
y = g^x mod p (with p prime and g a generator).

```
Encrypt m (m < p), pick random ephemeral k:
    c1 = g^k mod p
    c2 = m · y^k mod p        ciphertext is the pair (c1, c2)

Decrypt:
    s = c1^x mod p
    m = c2 · s^-1 mod p
```

A fresh k every message means the same plaintext encrypts differently each time
(randomised encryption). Reusing k leaks the key relationship, so never repeat it.

**Ans (from elgamal.c):** p=23, g=5, x=6, m=10 → (c1=10, c2=14), decrypt = 10. ✓

## Key sizes

Security depends on the size of the hard problem, so public-key numbers are far larger
than symmetric keys for the same strength.

| Symmetric | RSA / DH modulus | ECC | Rough status |
|---|---|---|---|
| 80-bit | 1024 | 160 | broken / deprecated |
| 112-bit | 2048 | 224 | current minimum |
| 128-bit | 3072 | 256 | recommended |
| 256-bit | 15360 | 512 | long-term |

> ECC gets equal security from much smaller keys because no sub-exponential attack on the
> elliptic-curve discrete log is known — that is why phones and TLS lean on it.
