# Number Theory — quick reference

One sheet for the arithmetic behind RSA, Diffie-Hellman and ElGamal. All work is
mod n, so nothing grows without bound. Small textbook numbers throughout.

## GCD — Euclid
gcd(a,b) = gcd(b, a mod b), stop when the second number is 0.

```
gcd(1071,462) = gcd(462,147) = gcd(147,21) = gcd(21,0) = 21
```

gcd(a,b) = 1 ⇒ a, b are **coprime**. This is the condition RSA needs between e and phi.

## Extended Euclid — Bezout + modular inverse
Returns x, y with

```
a*x + b*y = gcd(a,b)          (Bezout's identity)
```

When gcd(a,m) = 1, reduce mod m: `a*x ≡ 1 (mod m)`, so **x mod m = a⁻¹**. The inverse
exists **iff** gcd(a,m) = 1. This is how RSA gets d from e.

```
17*(−367) + 3120*2 = 1   →   17⁻¹ mod 3120 = −367 mod 3120 = 2753
```

## Modular exponentiation — square-and-multiply
Never form b^e first (overflow). Keep every partial below n:

```
result = 1
b = b mod n
while e > 0:
    if e & 1: result = result*b mod n
    b = b*b mod n
    e >>= 1
```

Cost ≈ log₂(e) multiplications. `65^17 mod 3233 = 2790`.

## Fermat's little theorem
p prime, gcd(a,p) = 1:

```
a^(p−1) ≡ 1 (mod p)          equivalently   a^p ≡ a (mod p)
```

Uses: inverse mod a prime is `a^(p−2) mod p`; quick (but fallible) primality screen.

## Euler's totient phi(n)
Count of 1..n coprime to n.

```
p prime:            phi(p) = p − 1
prime power:        phi(p^k) = p^k − p^(k−1)
multiplicative:     phi(a*b) = phi(a)*phi(b)   when gcd(a,b)=1
so n = p*q:         phi(n) = (p−1)(q−1)
```

`phi(3233) = phi(61)·phi(53) = 60·52 = 3120`.

## Euler's theorem
gcd(a,n) = 1:

```
a^phi(n) ≡ 1 (mod n)
```

Why RSA works: e·d ≡ 1 (mod phi(n)) ⇒ m^(ed) = m^(1+k·phi(n)) ≡ m (mod n).
Fermat is Euler with n prime, since phi(p) = p−1.

## Chinese Remainder Theorem
Moduli m₁…mₖ pairwise coprime. The system `x ≡ aᵢ (mod mᵢ)` has a unique solution
mod M = m₁·…·mₖ:

```
Mᵢ = M/mᵢ,   yᵢ = Mᵢ⁻¹ mod mᵢ,   x = ( Σ aᵢ·Mᵢ·yᵢ ) mod M
```

`x≡2(3), x≡3(5), x≡2(7)  →  x = 23 (mod 105)`. CRT speeds RSA decrypt ~4×.

---

## Public-key formulas

### RSA
```
keygen:  n = p*q,  phi = (p−1)(q−1),  choose e with gcd(e,phi)=1,  d = e⁻¹ mod phi
encrypt: c = m^e mod n
decrypt: m = c^d mod n
sign:    s = H(m)^d mod n          verify: H(m) == s^e mod n
```
**Ans (p=61,q=53,e=17):** n=3233, phi=3120, d=2753, enc(65)=2790, dec(2790)=65, sign(65)=588.

### Diffie-Hellman
Public prime p, generator g. Private a, b.
```
A = g^a mod p,   B = g^b mod p
shared s = B^a mod p = A^b mod p = g^(ab) mod p
```
**Ans (p=23,g=5,a=6,b=15):** A=8, B=19, s=2. Security = discrete log problem.

### ElGamal
Private x, public y = g^x mod p. Random ephemeral k per message (never reuse).
```
encrypt m:  c1 = g^k mod p,   c2 = m·y^k mod p        ciphertext (c1,c2)
decrypt:    s = c1^x mod p,   m = c2·s⁻¹ mod p
```
**Ans (p=23,g=5,x=6,m=10):** (c1=10, c2=14), decrypt = 10.

> RSA rests on factoring n = p·q; DH and ElGamal rest on the discrete log of g^a mod p.
> Both are one-way (trapdoor) functions — easy forward, hard to reverse without the key.
