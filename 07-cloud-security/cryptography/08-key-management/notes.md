# Unit 8 — Key Management and Distribution

The hard part of symmetric crypto is not the cipher, it's getting the key to
both ends secretly. Public-key crypto solves distribution but raises the
question of trusting a public key. This unit covers both.

## Symmetric key distribution
For two parties A and B to talk with a symmetric cipher, they need a shared key
that no one else has. Options:
1. A picks a key, physically delivers it to B.
2. A third party picks a key, physically delivers it to both.
3. If A and B already share a key, one sends a new key encrypted under the old.
4. If A and B each share a key with a trusted third party C, C relays a new
   session key over the encrypted links.

Options 1–2 do not scale: **n** parties needing pairwise keys require
**n(n−1)/2** keys. Option 4 (a central server) scales — this is the KDC.

## Key hierarchy and session keys
| Key type | Lifetime | Use |
|----------|----------|-----|
| **Master key** | Long-lived | Shared between a user and the KDC; distributes session keys |
| **Session key** | One session, then destroyed | Encrypts the actual data traffic |

Using a fresh session key per connection limits exposure: if one session key
leaks, only that session is compromised, and there is less ciphertext under any
one key for an attacker to work on.

## Key Distribution Center (KDC)
A trusted server that shares a permanent master key with every user. To let A
talk to B (Needham–Schroeder style):

1. A → KDC: request + IDa + IDb + nonce N1.
2. KDC → A: E(Ka, [Ks ‖ request ‖ N1 ‖ E(Kb,[Ks ‖ IDa])]).
   A decrypts, recovers session key **Ks**, checks N1.
3. A → B: E(Kb, [Ks ‖ IDa]) — the "ticket" A cannot read but B can.
4. B → A: E(Ks, N2).
5. A → B: E(Ks, f(N2)).  (steps 4–5 confirm B is live and defeat replay)

- **Nonces** (N1, N2) guarantee freshness → defend against replay.
- **Weakness:** the KDC is a single point of trust and failure; the step-3
  ticket is vulnerable to replay of an old compromised Ks (Denning fix: add a
  timestamp).

## Public-key distribution
Public keys are meant to be public, but they must be *authentic* — a forged
public key enables a man-in-the-middle. Approaches, weakest first:
| Scheme | Idea | Weakness |
|--------|------|----------|
| Public announcement | Broadcast your key | Anyone can forge one as you |
| Public directory | Trusted directory lists keys | Directory can be tampered / is a bottleneck |
| Public-key authority | Online authority signs keys on request | Authority is a bottleneck, must be online |
| Public-key certificates | Offline CA signs a certificate once | Best — no online authority needed |

## Public-key certificates
A **certificate** binds an identity to a public key, signed by a Certificate
Authority (CA): `Cert = Sign(PR_CA, [ID ‖ PU_user ‖ validity])`. Anyone holding
the CA's public key can verify it offline. The CA vouches for the binding; it
does not need to be online at use time.

### X.509
The standard certificate format (used by SSL/TLS, S/MIME, IPSec). Fields:
| Field | Contents |
|-------|----------|
| Version | v1 / v2 / v3 |
| Serial number | Unique within the CA |
| Signature algorithm | e.g. sha256WithRSAEncryption |
| Issuer | CA distinguished name |
| Validity | Not-before / not-after dates |
| Subject | Owner's distinguished name |
| Subject public key | Algorithm + the public key |
| Extensions (v3) | Key usage, alt names, CA constraints |
| **CA signature** | Signs the hash of all the above |

Notation `CA<<A>>` = the certificate of A issued by CA. Revocation via a
**Certificate Revocation List (CRL)** or online (OCSP).

## Public Key Infrastructure (PKI)
The whole system of hardware, software, people, and policies to create, manage,
distribute, and revoke certificates. Key roles:
- **CA** — issues and signs certificates, publishes CRLs.
- **RA (Registration Authority)** — verifies identity before a cert is issued.
- **Repository** — stores certs and CRLs.
- **End entity** — user/server that holds a certificate.
CAs form a **hierarchy / chain of trust** up to a self-signed **root CA**.

## Kerberos (in brief)
An authentication service using a **trusted KDC** and symmetric keys (no
public key needed); users prove identity without sending passwords on the wire.
Two servers inside the KDC:
- **AS (Authentication Server)** — verifies the user, issues a
  Ticket-Granting Ticket (TGT).
- **TGS (Ticket-Granting Server)** — takes the TGT, issues service tickets.

Flow: (1) user → AS, gets TGT; (2) user presents TGT → TGS, gets a service
ticket; (3) user presents service ticket → the application server. Tickets and
**authenticators** carry timestamps, so a stolen ticket expires quickly.
Version 4 uses DES; version 5 fixes v4's limits (any cipher, longer lifetimes,
better inter-realm operation). Needs synchronised clocks (replay window).

---

## Short-answer / solved

**Q1.** Why use a session key instead of encrypting all traffic with the master
key? **Ans:** Limits damage and exposure — a leaked session key compromises
only one session, and less data is ever encrypted under the long-lived master.

**Q2.** In X.509, what stops an attacker editing the public key inside a
certificate? **Ans:** The CA's **digital signature** covers a hash of the whole
certificate; any edit breaks verification against the CA's public key.
