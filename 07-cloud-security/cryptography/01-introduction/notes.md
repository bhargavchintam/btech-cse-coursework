# Unit 1 — Introduction

Cryptography protects information in transit and at rest. Two broad terms:
- **Computer security** — protecting data on a single system.
- **Network security** — protecting data while it moves across a network.
- **Internetwork security** — the same across interconnected networks.

## Security goals — the CIA triad
| Goal | Meaning | Broken by |
|------|---------|-----------|
| Confidentiality | Only authorised parties read the data | Eavesdropping, disclosure |
| Integrity | Data is not altered without detection | Tampering, modification |
| Availability | Service/data reachable when needed | Denial of service |

Two more often added: **Authenticity** (you are who you claim) and
**Accountability / non-repudiation** (actions traceable, cannot be denied).

## OSI security architecture (ITU-T X.800)
X.800 gives a systematic way to define needs. It has three pieces:
security **attacks**, security **services**, and security **mechanisms**.

### 1. Security attacks
A **threat** is a potential violation; an **attack** is a threat carried out.

**Passive attacks** — read/observe, do not alter. Hard to detect, so the aim
is prevention (encryption). Goal is to obtain information.
- *Release of message contents* — reading the actual data (email, file).
- *Traffic analysis* — even if encrypted, the attacker learns location,
  identity of hosts, frequency and length of messages.

**Active attacks** — modify the stream or create a false one. Hard to prevent
fully, so the aim is detection and recovery.
- *Masquerade* — one entity pretends to be another.
- *Replay* — capture data and retransmit it to produce an effect.
- *Modification of messages* — alter, delay, or reorder a genuine message.
- *Denial of service (DoS)* — prevent normal use of a facility.

| | Passive | Active |
|--|---------|--------|
| Action | Observe only | Alter / inject |
| Detect | Difficult | Feasible |
| Prevent | Feasible (encrypt) | Difficult |
| Emphasis | **Prevention** | **Detection + recovery** |

### 2. Security services (X.800)
| Service | What it provides |
|---------|------------------|
| Authentication | Genuineness of a communicating peer (peer-entity) or of the source of data (data-origin) |
| Access control | Prevents unauthorised use of a resource |
| Data confidentiality | Protects data from disclosure (also traffic-flow confidentiality) |
| Data integrity | Data received = data sent (no modify, insert, delete, replay) |
| Non-repudiation | Sender/receiver cannot deny a sent/received message |
| Availability | Resource is accessible and usable on demand |

### 3. Security mechanisms (X.800)
**Specific** (built into a protocol layer): encipherment, digital signature,
access control, data integrity, authentication exchange, traffic padding,
routing control, notarization.
**Pervasive** (not tied to one service): trusted functionality, security label,
event detection, security audit trail, security recovery.

> Rule of thumb: a *service* is the goal, a *mechanism* is the tool. One service
> may use several mechanisms; encipherment underlies almost everything.

Rough service ↔ mechanism map:
| Service | Main mechanism(s) |
|---------|-------------------|
| Confidentiality | Encipherment, routing control |
| Integrity | Encipherment, digital signature, data integrity |
| Authentication | Encipherment, signature, authentication exchange |
| Non-repudiation | Digital signature, notarization |
| Access control | Access-control mechanism |

## A model for network security
Two parties (sender, receiver) exchange a message over an information channel;
an **opponent** may read or alter it.
- A **security-related transformation** (e.g. encryption) is applied to the message.
- Some **secret information** (a key) is shared, unknown to the opponent.
- A **trusted third party (TTP)** may distribute the secret or arbitrate disputes.

Four basic tasks in designing such a service:
1. Design an algorithm the opponent cannot defeat.
2. Generate the secret information (keys) it uses.
3. Distribute and share that secret information securely.
4. Specify a protocol that uses the algorithm and secret to achieve the service.

**Network access security model** — a *gatekeeper function* (login, firewall)
guards against unwanted access; *internal controls* monitor activity and data.
Threats here: information access (data theft) and service threats (worms,
viruses, that exploit the system).

---

## Short-answer / solved

**Q1.** Classify: (a) an attacker copies a login packet and resends it later,
(b) an attacker measures how often two banks exchange messages.
**Ans:** (a) *Replay* — an **active** attack. (b) *Traffic analysis* — a
**passive** attack.

**Q2.** A bank statement is altered in transit from ₹500 to ₹5000 and the
customer later denies receiving it. Which two services were needed?
**Ans:** **Data integrity** (detect the alteration) and **non-repudiation**
(bind receipt to the customer). Both can be met with a digital signature.
