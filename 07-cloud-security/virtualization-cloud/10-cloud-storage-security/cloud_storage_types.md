# Cloud storage types

**Definition:** cloud storage = storing data on **remote servers accessed over the network**, managed by a provider, instead of on local disks.

## By data model (the three main types)
- **Block storage** — data in fixed-size blocks, like a raw disk. Attach to a VM. e.g. AWS **EBS**.
- **Object storage** — data as objects (data + metadata + id) in a flat namespace. e.g. AWS **S3**.
- **File storage** — data as files in a hierarchy of folders, shared over network (NFS/SMB). e.g. AWS **EFS**.

(detailed compare in block_object_file_storage.md)

## By deployment / who can access
- **Public cloud storage** — provider's storage, multi-tenant. e.g. S3.
- **Private cloud storage** — storage inside org's own private cloud.
- **Hybrid cloud storage** — mix, keep sensitive data private, rest in public.
- **Personal cloud storage** — consumer file sync. e.g. Google Drive, Dropbox.

## Features of cloud storage
- **scalable** — grow as needed, no fixed disk size.
- **durable** — provider replicates copies (e.g. S3 quotes 11 nines durability).
- **available** — reachable anytime over network.
- **pay-per-use** — pay for GB stored + data transfer.
- **managed** — provider handles hardware, replication, backup.

## Storage classes / tiers (cost vs access)
Providers offer tiers by how often you access data:
- **hot** — frequent access, higher cost (e.g. S3 Standard).
- **cool / infrequent** — cheaper, accessed rarely (e.g. S3 Standard-IA).
- **cold / archive** — cheapest, slow retrieval (e.g. S3 Glacier).

## Quick recall table

| Type | Unit | Access | AWS example |
|------|------|--------|-------------|
| Block | blocks | attach to one VM | EBS |
| Object | objects (flat) | HTTP API / REST | S3 |
| File | files/folders | network share (NFS/SMB) | EFS |
