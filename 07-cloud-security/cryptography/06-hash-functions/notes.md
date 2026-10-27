# Unit 6 — Hash Functions

A cryptographic hash `H` maps a message of any length to a fixed-length digest.
Same input always gives the same digest; the output looks random and reveals
nothing about the input. It is a one-way, many-to-one function — collisions
must exist (infinite inputs, finite outputs) but must be infeasible to find.

Used for: integrity checks, password storage, digital signatures (sign the
digest, not the whole message), MACs, commitment schemes.

## The three security properties

| Property | Given | Hard to find | Also called |
|---|---|---|---|
| Preimage resistance | digest `h` | any `m` with `H(m)=h` | one-way |
| Second-preimage resistance | `m1` | `m2 != m1` with `H(m2)=H(m1)` | weak collision |
| Collision resistance | nothing | any `m1 != m2` with `H(m1)=H(m2)` | strong collision |

Collision resistance is the hardest to meet. Because of the birthday paradox
an `n`-bit hash gives only `n/2` bits of collision strength: a 128-bit digest
falls to a collision search in about `2^64` tries, not `2^128`.

## The digests

| Algorithm | Digest | Block | State | Status |
|---|---|---|---|---|
| MD5 | 128 bits | 512 bits | 4 x 32-bit | broken — collisions found (2004) |
| SHA-1 | 160 bits | 512 bits | 5 x 32-bit | broken — SHAttered collision (2017) |
| SHA-224 | 224 bits | 512 bits | 32-bit words | SHA-2, ok |
| SHA-256 | 256 bits | 512 bits | 32-bit words | SHA-2, recommended |
| SHA-384 | 384 bits | 1024 bits | 64-bit words | SHA-2, ok |
| SHA-512 | 512 bits | 1024 bits | 64-bit words | SHA-2, ok |

MD5 and SHA-1 both use the Merkle-Damgard construction: pad the message,
split into blocks, and iterate a compression function over a chaining value.
SHA-2 keeps that construction with a larger state and more rounds. MD5 and
SHA-1 still work fine as non-security checksums (file dedup, ETags) but must
NOT be used where an attacker could forge a collision.

> Don't confuse "broken" with "reversible". Nobody inverts MD5. It is broken
> only in the collision sense — two crafted inputs can be made to share a
> digest, which is enough to forge a certificate.

## Avalanche effect

A good hash has the avalanche property: flipping one input bit flips about
half of the output bits, unpredictably. This is why a digest cannot be used
to guess how close a guess was to the real input.

`SHA-256("abc")` and `SHA-256("abd")` differ in one input letter:

```
abc -> ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
abd -> a52d159f262b2c6ddb724a61840befc36eb30c88877a4030b65cbe86298449c9
```

122 of the 256 output bits differ (~48%). One letter, half the digest changed.

## Solved problems

**1. MD5 of "abc".** Feed the 3 bytes to the compression function after
padding to one 512-bit block.

**Ans:** `MD5("abc") = 900150983cd24fb0d6963f7d28e17f72` (128 bits = 32 hex).

**2. SHA-256 of "abc".**

**Ans:** `SHA-256("abc") = ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad`

**3. Birthday bound.** How many hashes before a 50% chance of a collision in
a 128-bit digest? Roughly `sqrt(2^128) = 2^64`.

**Ans:** about `2^64` (~1.8 x 10^19), far less than the `2^128` a preimage
search would need — this is why digest size is chosen at twice the wanted
security level.

## Lab programs
- `md5.c` — MD5 of a string via `EVP_md5()`, verified against the vector above.
- `sha256.c` — SHA-256 of a string via `EVP_sha256()`.
- `sha_family.c` — SHA-1/224/256/384/512 of typed input, one line each.

All three use the OpenSSL EVP digest API
(`EVP_DigestInit_ex` / `Update` / `Final_ex`) and were cross-checked with
`openssl dgst -md5` and `openssl dgst -sha256`.
