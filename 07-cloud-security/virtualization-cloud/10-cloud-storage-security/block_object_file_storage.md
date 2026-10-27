# Block vs object vs file storage

The most-asked storage question. Learn the AWS example for each — **EBS = block, S3 = object, EFS = file**. (imp, don't swap them)

## Block storage
- data split into fixed-size **blocks**, each with an address, no metadata.
- OS sees it as a **raw disk / volume** — you format it, put a filesystem on it.
- attached to **one** VM at a time (like a hard disk).
- fast, low latency → good for databases, OS boot volumes.
- **AWS example: EBS (Elastic Block Store)**.
- others: Azure Managed Disks, GCP Persistent Disk.

## Object storage
- data stored as **objects** = data + **metadata** + a unique **id/key**.
- **flat** namespace (buckets), no folder tree underneath.
- accessed via **HTTP REST API** (GET/PUT), not mounted as a disk.
- massively scalable, cheap, durable → good for backups, images, videos, static websites, big data.
- can't edit part of an object — replace the whole object.
- **AWS example: S3 (Simple Storage Service)**.
- others: Azure Blob Storage, GCP Cloud Storage.

## File storage
- data as **files** in a **hierarchy** of directories (like a normal filesystem).
- accessed over network via **NFS / SMB** protocols, **mounted** as a share.
- can be shared by **many** VMs/clients at once.
- good for shared drives, content management, home directories, lift-and-shift apps expecting a filesystem.
- **AWS example: EFS (Elastic File System)**.
- others: Azure Files, GCP Filestore.

## Differentiate (table)

| Basis | Block | Object | File |
|-------|-------|--------|------|
| Unit | fixed blocks | objects (data+metadata+id) | files in folders |
| Structure | raw volume | flat (buckets) | hierarchical tree |
| Access | attach/mount as disk | HTTP REST API | NFS / SMB mount |
| Shared by | one VM (usually) | many (over API) | many clients |
| Metadata | none | rich, custom | limited (file attrs) |
| Edit part of data | yes | no (rewrite object) | yes |
| Best for | DBs, boot volumes | backups, media, big data | shared drives |
| AWS | **EBS** | **S3** | **EFS** |

Memory line: **B**lock=**B**oot disk (EBS), **O**bject=**O**nline API buckets (S3), **F**ile=**F**older share (EFS).
