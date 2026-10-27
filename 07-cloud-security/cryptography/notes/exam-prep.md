# Exam prep — question bank

Grouped by unit. Short questions carry no tag; longer ones carry a marks tag.
Numbers match the vectors used in the lab programs.

## Unit 1 — Introduction / security services
- Define computer, network and internetwork security.
- State the CIA triad and give one attack that breaks each goal.
- Distinguish passive and active attacks; give two examples of each. **(8 marks)**
- List the X.800 security services and match each to a mechanism. **(10 marks)**
- What is the difference between a security service and a security mechanism?
- Draw and explain the model for network security (sender, opponent, TTP, key). **(10 marks)**
- Classify: (a) replaying a captured login packet, (b) measuring message frequency.
  **Ans:** (a) replay = active, (b) traffic analysis = passive.

## Unit 2 — Classical ciphers
- Substitution vs transposition — what does each change, and how is each broken?
- Monoalphabetic vs polyalphabetic; why does polyalphabetic resist frequency analysis?
- Encrypt HELLO with a Caesar shift of 3. **Ans: KHOOR.**
- Encrypt HELLO with Vigenere key KEY. **Ans: RIJVS.**
- Encrypt HELLO with the affine cipher a=5, b=8, and state the decrypt rule. **(6 marks)**
  **Ans: RCLLA**, decrypt p = 21·(c−8) mod 26 since 5⁻¹ = 21.
- Explain the Playfair rules (I/J merge, same row/column, X padding) with an example. **(10 marks)**
- Encrypt with a 2×2 Hill cipher and show how the key matrix is inverted mod 26. **(10 marks)**
- Why must `a` in the affine cipher be coprime to 26? Which values are barred?
  **Ans:** decryption needs a⁻¹, which exists iff gcd(a,26)=1 — bars 2, 13 and their multiples.
- Describe rail-fence and columnar transposition; encrypt one sample each. **(8 marks)**
- Why is a one-time pad (Vernam) unbreakable, and why is it impractical?

## Unit 3 — Block ciphers, DES, AES
- Block vs stream cipher. State DES and AES block/key/round sizes.
- Draw one DES round and explain why decryption reuses the same network. **(10 marks)**
- List the four AES round steps and say which gives confusion, which diffusion. **(8 marks)**
- Define confusion and diffusion (Shannon) and the avalanche effect. **(6 marks)**
- Why is DES considered insecure today, and what does 3DES change?
- Compare ECB and CBC; why does ECB leak patterns (the "ECB penguin")? **(8 marks)**
- What is an IV, must it be secret, and must it be unpredictable?
  **Ans:** not secret (shipped with ciphertext) but must be unpredictable/fresh per message.
- AES-128-ECB, key 000102…0f, plaintext 00112233…ff → ? **Ans: 69c4e0d86a7b0430d8cdb78070b4c55a.**

## Unit 4 — Number theory
- Compute gcd(1071, 462) by Euclid. **Ans: 21.**
- Find 17⁻¹ mod 3120 by extended Euclid. **Ans: 2753.**
- State Fermat's little theorem and Euler's theorem; how is one a special case of the other?
- Compute phi(3233). **Ans: 3120.**
- Evaluate 65^17 mod 3233 by square-and-multiply, showing the intermediates. **Ans: 2790.** **(8 marks)**
- State and apply the CRT: solve x≡2(3), x≡3(5), x≡2(7). **Ans: 23 (mod 105).** **(10 marks)**
- Why does trial division fail for large primes? Outline Miller-Rabin. **(8 marks)**
- What is a Carmichael number, and why does it defeat the Fermat test? **Ans:** e.g. 561, composite but passes a^(n−1)≡1 for coprime a.

## Unit 5 — RSA, Diffie-Hellman, ElGamal
- Compare symmetric and public-key crypto (keys, distribution, speed, use). **(8 marks)**
- Full RSA keygen + encrypt/decrypt for p=61, q=53, e=17, m=65. **(10 marks)**
  **Ans:** n=3233, phi=3120, d=2753, c=2790, back to 65.
- Why does RSA work? Prove m^(ed) ≡ m (mod n) from Euler's theorem. **(6 marks)**
- Diffie-Hellman with p=23, g=5, a=6, b=15 — find the shared secret. **Ans: 2.** **(8 marks)**
- What hard problem secures DH, and what attack does a plain (unauthenticated) DH face?
  **Ans:** discrete log; vulnerable to man-in-the-middle without authentication.
- ElGamal encrypt/decrypt for a small prime; why must k never be reused? **(8 marks)**
- What is a hybrid cryptosystem, and why is it used? **Ans:** public-key agrees a session key, symmetric encrypts the bulk data.

## Unit 6 — Hash functions
- Define the three security properties (preimage, 2nd-preimage, collision). **(6 marks)**
- Why does an n-bit hash give only n/2 bits of collision strength (birthday bound)?
- Compare MD5, SHA-1 and the SHA-2 family (digest size, status). **(8 marks)**
- What does "MD5 is broken" mean — is it reversible? **Ans:** no; broken only for collisions, not preimage.
- Explain the avalanche effect and why it matters for a digest.
- SHA-256("abc") = ? **Ans: ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad.**
- MD5("abc") = ? **Ans: 900150983cd24fb0d6963f7d28e17f72.**

## Unit 7 — Message authentication, MAC, signatures
- Contrast hash, MAC and digital signature on integrity, authenticity, non-repudiation. **(8 marks)**
- Why does a bare hash not authenticate a message?
- Write the HMAC construction and explain why the nested hash defeats length extension. **(8 marks)**
- Why does a MAC give no non-repudiation but a signature does?
  **Ans:** MAC key is shared (either party could forge); a signature uses the sender's private key alone.
- RSA signature for the digest value 65 with d=2753, verify with e=17. **Ans: s=588, verify → 65.** **(6 marks)**
- Why sign the hash of a message rather than the whole message?

## Unit 8 — Key management and distribution
- Why does pairwise symmetric keying not scale? **Ans:** n users need n(n−1)/2 keys.
- Master key vs session key — why use a fresh session key per connection? **(6 marks)**
- Describe a KDC and a Needham-Schroeder key exchange; where do nonces help? **(10 marks)**
- Rank the four public-key distribution schemes and give each one's weakness. **(8 marks)**
- What does an X.509 certificate bind, and what stops an attacker editing the public key in it?
  **Ans:** binds identity to public key; the CA signature covers a hash of the whole cert.
- Define PKI and name the roles (CA, RA, repository, end entity). **(8 marks)**
- Outline Kerberos: AS, TGS, TGT and service tickets; why are timestamps needed? **(10 marks)**

## Unit 9 — Network security
- Compare IPSec AH and ESP (what each provides, what it does not). **(6 marks)**
- Transport vs tunnel mode — which hides the inner addresses, and when is each used? **(8 marks)**
- Which IPSec protocol + mode links two branch offices and hides internal IPs?
  **Ans:** ESP in tunnel mode.
- Outline the TLS handshake up to session-key derivation. **(10 marks)**
- How does PGP provide confidentiality and authentication for email? **(8 marks)**
- PGP vs S/MIME — trust model and certificate type.
- Compare packet-filter, stateful, and application-gateway firewalls. **(8 marks)**
- Why can a stateless packet filter be fooled by a spoofed internal source address?
  **Ans:** it judges each packet alone with no connection state, so a forged IP matching an allow rule passes.
- Signature vs anomaly intrusion detection; strength and weakness of each. **(6 marks)**
