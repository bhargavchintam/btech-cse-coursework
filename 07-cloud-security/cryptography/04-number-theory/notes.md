# Unit 4 — Number Theory for Cryptography

The arithmetic behind RSA, Diffie-Hellman and ElGamal. Everything here is done over the
integers modulo n, so nothing ever grows without bound.

## Divisibility and GCD
`a | b` means a divides b with no remainder. The greatest common divisor gcd(a,b) is the
largest d with d|a and d|b.

Euclid's algorithm: gcd(a,b) = gcd(b, a mod b), stop when the second number hits 0.

```
gcd(1071, 462) = gcd(462, 147) = gcd(147, 21) = gcd(21, 0) = 21
```

If gcd(a,b) = 1 the numbers are **coprime** (relatively prime). This is the condition RSA
needs between e and phi(n).

## Extended Euclid and the modular inverse
Extended Euclid also returns integers x,y with

```
a*x + b*y = gcd(a,b)          (Bezout's identity)
```

When gcd(a,m) = 1, reduce that mod m: `a*x = 1 (mod m)`, so **x mod m is the inverse of a**.
The inverse exists **iff** a and m are coprime. This is exactly how RSA finds d from e.

## Modular arithmetic
Work with remainders mod n. Add, subtract and multiply all commute with `mod`:
`(a+b) mod n = ((a mod n)+(b mod n)) mod n`, same for `*`. And `a ≡ b (mod n)` means n divides
(a−b). Division is **not** defined directly — you multiply by the modular inverse instead.

### Fast modular exponentiation
Never compute m^e first and then reduce (it overflows instantly). Square-and-multiply keeps
every intermediate below n:

```
result = 1
for each bit of e from LSB:
    if bit set: result = result*base mod n
    base = base*base mod n
```

e halves each step, so it costs about log2(e) multiplications.

## Euler's totient phi(n)
phi(n) = count of integers in 1..n that are coprime to n.

- p prime:            phi(p) = p − 1
- p prime, power k:   phi(p^k) = p^k − p^(k−1)
- multiplicative:     phi(a*b) = phi(a)*phi(b) when gcd(a,b)=1

So for n = p·q (the RSA case) phi(n) = (p−1)(q−1).

```
phi(3233) = phi(61)·phi(53) = 60·52 = 3120
```

## Fermat's little theorem
If p is prime and gcd(a,p) = 1:

```
a^(p−1) ≡ 1 (mod p)        equivalently   a^p ≡ a (mod p)
```

Useful for computing inverses mod a prime (a^(p−2)) and as a quick primality screen.

## Euler's theorem
The generalisation to any modulus. If gcd(a,n) = 1:

```
a^phi(n) ≡ 1 (mod n)
```

This is *why* RSA works: e·d ≡ 1 (mod phi(n)) makes (m^e)^d = m^(1+k·phi(n)) ≡ m (mod n).

> Fermat is just Euler with n prime, since phi(p) = p−1.

## Chinese Remainder Theorem (CRT)
If the moduli m1,m2,…,mk are pairwise coprime, the system

```
x ≡ a1 (mod m1),  x ≡ a2 (mod m2),  …
```

has a **unique** solution mod M = m1·m2·…·mk. Construct it with:

```
Mi = M/mi,   yi = Mi^(-1) mod mi,   x = ( Σ ai·Mi·yi ) mod M
```

CRT speeds up RSA decryption ~4× by working mod p and mod q separately.

## Primality testing
Trial division is too slow for big numbers. Probabilistic tests instead:

| Test | Idea | Weakness |
|------|------|----------|
| Fermat | check a^(n−1) ≡ 1 (mod n) | Carmichael numbers (e.g. 561) pass falsely |
| Miller-Rabin | Fermat + check for non-trivial √1 | none, if enough bases used |

Miller-Rabin: write n−1 = 2^s·d. For a base a, either a^d ≡ 1 or some a^(2^r·d) ≡ −1 (mod n),
else n is composite. Using the small prime bases 2..37 makes it deterministic for any 64-bit n.

---

## Solved problems

**1. Find the inverse of 17 mod 3120 (the RSA d for e=17).**
Extended Euclid on (17, 3120):

```
3120 = 183·17 + 9
  17 =   1·9  + 8
   9 =   1·8  + 1     ->  gcd = 1
```

Back-substitute: 1 = 9 − 8 = 9 − (17 − 9) = 2·9 − 17 = 2·(3120 − 183·17) − 17
= 2·3120 − 367·17. So x = −367 ≡ 3120 − 367 = **2753**.

**Ans:** 17^(−1) mod 3120 = 2753  (this is the RSA private exponent d for p=61,q=53,e=17).

**2. Solve x ≡ 2 (mod 3), x ≡ 3 (mod 5), x ≡ 2 (mod 7).**
M = 3·5·7 = 105. M1=35, M2=21, M3=15.
Inverses: 35^(−1) mod 3 = 2, 21^(−1) mod 5 = 1, 15^(−1) mod 7 = 1.
x = (2·35·2 + 3·21·1 + 2·15·1) mod 105 = (140 + 63 + 30) mod 105 = 233 mod 105.

**Ans:** x = 23 (mod 105).
