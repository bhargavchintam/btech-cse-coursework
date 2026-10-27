# Data security in cloud

Protecting data stored and processed in the cloud. Covers the **CIA triad** applied to cloud data.

## CIA triad
- **Confidentiality** — only authorised parties can read the data. (encryption, access control)
- **Integrity** — data not altered/tampered without detection. (hashing, checksums)
- **Availability** — data accessible when needed. (redundancy, backups, DDoS protection)

## Data states — protect all three
- **data at rest** — stored on disk/storage → protect with encryption (e.g. AES-256), access control.
- **data in transit** — moving over network → protect with **TLS/SSL**.
- **data in use** — being processed in memory → hardest; enclaves / access control.

## Techniques
- **Encryption** — at rest + in transit (see encryption_in_cloud.md).
- **Access control** — IAM, least privilege, MFA (see identity_and_access_management.md).
- **Backup & replication** — copies across zones/regions for durability.
- **Data masking / tokenisation** — hide sensitive fields.
- **Key management** — protect and rotate keys (e.g. AWS KMS).
- **Monitoring / logging** — track access (e.g. CloudTrail), detect anomalies.
- **Data classification** — label data by sensitivity, protect accordingly.

## Shared responsibility model (key point)
Security is **split** between provider and customer:
- **provider** — secures the cloud (physical, hardware, hypervisor, network infra) — *security OF the cloud*.
- **customer** — secures what they put in it (data, access config, encryption, OS patching in IaaS) — *security IN the cloud*.

Most breaches are the **customer's** fault (misconfiguration), not the provider's. (asked — "explain shared responsibility model")

## Data lifecycle points
create → store → use → share → archive → **destroy** (secure deletion / data sanitisation so data can't be recovered).

Key exam points: CIA triad, three data states, shared responsibility, encryption + IAM as main controls.
