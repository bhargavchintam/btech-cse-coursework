# Network Security

Security added on top of the plain protocols we've done so far - nothing in TCP/IP itself hides or
protects the data, so this sits over it.

## The goals
- **Confidentiality** - only the intended receiver can read it (encryption)
- **Integrity** - the message wasn't changed on the way (hashes, MAC)
- **Availability** - the service stays up (against DoS)
- **Authentication** - you are who you say you are
- **Non-repudiation** - the sender can't later deny sending it (digital signatures)

CIA is the usual short form for the first three.

## Symmetric vs asymmetric
- **Symmetric** - one shared key for both encrypt and decrypt. Fast. Problem: how do both sides get the
  same key without someone snooping. Examples: DES, 3DES, AES.
- **Asymmetric** (public key) - a key PAIR: public key encrypts, private key decrypts. No shared secret to
  ship around, but slow. Examples: RSA, ECC. Usually used just to exchange a symmetric key, then switch.

## Classical ciphers (the lab ones)
- **Caesar** - shift every letter by a fixed k. 25 possible keys, breakable by hand.
- **Vigenere** - a keyword gives a different shift per position (polyalphabetic), harder than Caesar.
- **Rail fence** - a transposition cipher: write the text in a zigzag over r rails, read off row by row.
  The letters are the same, only the order changes.

Substitution changes the letters, transposition changes the order. Real ciphers do rounds of both.

## RSA
1. pick two primes p, q; n = p·q
2. phi = (p-1)(q-1)
3. pick e coprime to phi -> public key (e, n)
4. d = e⁻¹ mod phi -> private key (d, n)
5. encrypt: c = mᵉ mod n,  decrypt: m = cᵈ mod n

With p=61, q=53: n=3233, phi=3120, e=17, d=2753. Encrypting 65 gives 2790, and 2790²⁷⁵³ mod 3233 = 65 back.
The security rests on factoring n being hard for big primes. Our primes are tiny (so it runs), real RSA
uses 2048-bit ones.

> The whole trick is that (mᵉ)ᵈ = m mod n by Euler's theorem, since ed ≡ 1 mod phi. - lecturer

## Diffie-Hellman
Two people agree on a shared secret over an open line without ever sending it:
- public: prime p, base g
- Alice picks a, sends A = gᵃ mod p; Bob picks b, sends B = gᵇ mod p
- Alice computes Bᵃ mod p, Bob computes Aᵇ mod p - both equal g^(ab) mod p

An eavesdropper sees g, p, A, B but can't get g^(ab) without solving the discrete log. With p=23, g=5,
a=6, b=15 both sides land on 2.

## Hashing
A one-way fingerprint of the data - fixed length, can't be reversed, and one bit changed flips about half
the output (avalanche). MD5 (128-bit, broken now) and SHA-256 (256-bit). Used for integrity and to store
passwords. `06_sha_demo.py` shows the avalanche - flip one bit and ~half the hex digits change.

## Small table

| Scheme | Type | Key | Use |
|---|---|---|---|
| Caesar / Vigenere / Rail fence | classical | shared | teaching, weak |
| DES / AES | symmetric | shared | bulk encryption |
| RSA | asymmetric | key pair | key exchange, signatures |
| Diffie-Hellman | key exchange | - | agree a shared key |
| MD5 / SHA | hash | none | integrity, passwords |
