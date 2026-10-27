# Cloud security challenges

The main risks/challenges when moving to cloud. CSA (Cloud Security Alliance) publishes the well-known threat lists — the 2019 one is the **"Egregious Eleven"**. (asked prev year — "list any six security challenges in cloud")

## Main challenges
- **Data breaches** — unauthorised access / leak of sensitive data. Biggest concern.
- **Misconfiguration** — wrong settings (e.g. a public S3 bucket) → most real-world leaks. Customer's fault.
- **Insufficient IAM** — weak credentials, no MFA, over-permissive roles → account takeover.
- **Insecure APIs / interfaces** — cloud is API-driven; a weak API is a way in.
- **Account / service hijacking** — stolen credentials, phishing → attacker uses your account.
- **Insider threats** — malicious or careless employees with access.
- **DoS / DDoS** — flood the service, make it unavailable.
- **Data loss** — accidental deletion, no backup, provider failure.
- **Shared technology vulnerabilities** — one flaw in shared infra (hypervisor) affects many tenants.
- **Loss of control / visibility** — data on third-party infra, limited monitoring.
- **Compliance & legal** — data residency, regulations (GDPR etc.).
- **Vendor lock-in** — hard to leave, data portability issues.

## Grouped by cause

| Cause | Examples |
|-------|----------|
| Customer mistakes | misconfiguration, weak IAM, no MFA |
| External attackers | breaches, DDoS, hijacking, API abuse |
| Multi-tenancy | shared tech flaws, VM escape, side channels |
| Governance | compliance, data residency, lock-in |
| People | insider threats |

## Why cloud is harder than on-prem to secure
- **shared responsibility** — easy to assume "provider handles it" and leave gaps.
- **larger attack surface** — everything reachable over the internet / APIs.
- **less visibility** — you don't own the underlying infra.
- **fast provisioning** — resources spun up faster than security can review (shadow IT).

Key line: most cloud breaches are **misconfiguration by the customer**, not the provider being hacked.
