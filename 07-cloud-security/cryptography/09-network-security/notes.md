# Unit 9 — Network Security Practice

Applying crypto at real layers: IP (IPSec), transport (SSL/TLS), application
(PGP, S/MIME), and perimeter defence (firewalls, IDS).

## IPSec
Security at the **IP layer**, so it protects *all* traffic above it
transparently (any TCP/UDP app). Used for VPNs, secure branch links, remote
access. Two protocols plus key management (IKE):

| Protocol | Provides | Does NOT |
|----------|----------|----------|
| **AH** (Authentication Header) | Integrity + data-origin authentication + anti-replay | No confidentiality (no encryption) |
| **ESP** (Encapsulating Security Payload) | Confidentiality (+ optional integrity/auth + anti-replay) | — |

- A **Security Association (SA)** is a one-way agreement (algorithms, keys)
  identified by the SPI + destination address; two SAs for two-way traffic.
- **IKE** negotiates SAs and does the Diffie–Hellman key exchange.

### Transport vs Tunnel mode
| | Transport mode | Tunnel mode |
|--|----------------|-------------|
| Protects | IP payload only | The **entire** original IP packet |
| Header | Original IP header kept | New outer IP header added |
| Use | End-to-end, host-to-host | Gateway-to-gateway VPN |
| Hides addresses? | No | Yes (inner header encrypted) |

## SSL / TLS (in brief)
Security at the **transport layer** — sits between TCP and the application
(HTTPS = HTTP over TLS). Sub-protocols: Handshake, Change Cipher Spec, Alert,
and the Record protocol (fragments, compresses, MACs, encrypts data).

**Handshake (simplified):**
1. **ClientHello** — client sends supported versions, cipher suites, a random.
2. **ServerHello** — server picks version + cipher suite, sends its random and
   its **X.509 certificate** (public key).
3. Client verifies the cert, generates a **pre-master secret**, encrypts it
   with the server's public key (or uses DH), sends it.
4. Both sides derive the same **master secret** → session keys.
5. **ChangeCipherSpec + Finished** on each side; encrypted session begins.

Result: server authentication (client too, if it has a cert), a shared secret,
and negotiated ciphers — confidentiality + integrity for the session.

## Email security
Email is store-and-forward, so protection must be **end-to-end** on the message.

### PGP (Pretty Good Privacy)
| Service | How |
|---------|-----|
| Confidentiality | Random one-time session key encrypts message (e.g. CAST/3DES); session key encrypted with recipient's RSA public key |
| Authentication | Hash the message, sign the hash with sender's private key |
| Compression | ZIP after signing, before encryption |
| Email compatibility | Radix-64 (base64) so binary survives mail systems |

Trust model: a decentralised **web of trust** (users sign each other's keys),
not a strict CA hierarchy.

### S/MIME
Adds security to MIME email; same building blocks (digital envelope +
signature) but uses **X.509 certificates** and a CA hierarchy. It is the
industry/enterprise standard (built into Outlook, etc.); PGP is more grassroots.

## Firewalls
A choke point between a trusted internal network and the untrusted Internet;
enforces a policy on what may pass. Cannot stop attacks that bypass it or
insider attacks.

| Type | Works at | Inspects | Notes |
|------|----------|----------|-------|
| **Packet filter** | Network/transport | Src/dst IP, ports, protocol, flags — each packet alone | Fast, cheap; stateless, so weak against spoofing/fragments |
| **Stateful inspection** | Transport | Same + tracks connection state (a table of active TCP sessions) | Only allows packets that fit a known connection |
| **Application gateway (proxy)** | Application | Full app content (HTTP, FTP…) | Most secure, can filter content; slower, one proxy per service |
| **Circuit-level gateway** | Session | Sets up TCP relay, no app inspection | e.g. SOCKS; hides internal hosts |

Common deployments: **bastion host**, screened host, and a **DMZ**
(demilitarised zone) — a subnet between two firewalls for public servers.

## Intrusion detection (in brief)
An **IDS** monitors events and flags likely intrusions; an **IPS** also blocks
them. Two detection styles:
| Approach | Basis | Strength / weakness |
|----------|-------|---------------------|
| **Signature / misuse** | Match known attack patterns | Accurate on known attacks; blind to new (zero-day) ones |
| **Anomaly / statistical** | Deviation from a learned "normal" baseline | Can catch novel attacks; more false positives |

By scope: **HIDS** (host-based — logs, files on one machine) and **NIDS**
(network-based — sensors watching traffic). A **honeypot** is a decoy system to
lure and study attackers.

> Layered ("defence in depth"): firewall filters the perimeter, IDS/IPS watches
> what gets through, crypto protects the data itself. No single layer suffices.

---

## Short-answer / solved

**Q1.** A company links two branch offices over the Internet and wants the
internal IP addresses hidden. Which IPSec protocol and mode?
**Ans:** **ESP in tunnel mode** — ESP encrypts, and tunnel mode wraps the whole
original packet (inner addresses hidden) behind a new outer header.

**Q2.** Why can't a stateless packet filter reliably stop a session where an
outside host spoofs an internal source address?
**Ans:** It judges each packet in isolation on header fields; it keeps no
connection state, so a forged source IP that matches an allow rule passes. A
**stateful** firewall rejects it because there is no matching established
connection.
