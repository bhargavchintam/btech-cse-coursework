# Cloud storage and security

Storage is where most of the cloud bill goes and where all the data you actually care about lives, so
this topic is half "how do they store it" and half "how do they keep it safe". The storage side is the
same distributed-systems ideas from 03 (replication, consistency) wearing storage names. The security
side is new.

## Three kinds of storage

The provider sells storage in three shapes and they are not interchangeable:

| type   | unit         | how you reach it        | good for                        | example      |
|--------|--------------|-------------------------|---------------------------------|--------------|
| object | whole object | HTTP API (PUT/GET key)  | files, backups, media, big blobs| S3, GCS      |
| block  | fixed blocks | attached as a disk      | a VM's boot/data volume, a DB   | EBS, Persistent Disk |
| file   | files+dirs   | mounted (NFS/SMB)       | shared folders, legacy apps     | EFS, Filestore |

Block storage looks like a raw disk to the VM - you put a filesystem on it yourself. File storage is a
network share many VMs mount at once. Object storage has no filesystem and no partial writes: you PUT a
whole object and GET a whole object, addressed by a key. That flat model is what lets it scale to
petabytes, so it's the one this folder simulates.

## Object storage (S3 style)

- bucket - a named container. Globally unique name, holds any number of objects.
- key - the object's name inside the bucket, e.g. `photos/cat.jpg`. Looks like a path but it's just a
  string; there are no real folders, the `/` is a convention.
- object - the bytes plus metadata (size, content-type, timestamps) plus an etag.
- etag - a hash of the content, md5 for a single-part upload. GET it twice, same etag = same bytes. This
  is how a client checks its download wasn't corrupted. 01_object_store.py builds the whole thing:
  make_bucket, put, get, list, delete, with an md5 etag per object.

## Replication and consistency

An object is never kept on one disk. It's copied to N nodes (replication factor). More copies = survives
more failures but costs more and is harder to keep in sync. The classic trick is quorums:

- W = how many replicas must ack a write before it's "done"
- R = how many replicas you read from and take the newest of
- N = total replicas

If **W + R > N** the write set and any read set must overlap on at least one node (pigeonhole), so a read
always sees the latest write - strong consistency. If W + R <= N a read can land entirely on stale
replicas and you get eventual consistency. S3 today is strongly consistent; older/Dynamo-style stores let
you tune W and R per request. 02_data_replication.py shows a write that only reached 3 of 5 nodes still
getting read back correctly because 3+3 > 5.

> Consistency, availability, partition tolerance - pick two. Quorums are how you slide along the C/A line
> instead of picking a corner.  -- lab notes

I got W+R burned into me after the internal - I wrote "W+R>=N" and lost the mark. It's strictly greater
than, `>`, because you need the sets to actually share a node, not just touch.

## Erasure coding

Full replication is simple but 3x copies means you pay for 3x the disk to store 1x the data. Erasure
coding is cheaper: split the object into k data blocks, compute m parity blocks, spread all k+m across
different disks. Any k of the k+m are enough to rebuild the object, so you survive m losses while only
paying (k+m)/k overhead instead of 2x or 3x.

The simplest case is one parity block by XOR (this is basically RAID-5). parity = b0 ^ b1 ^ ... ^ b(k-1).
Lose any one block and you recover it by XOR-ing the parity with all the survivors, because XOR undoes
itself. That only tolerates a single loss; real systems (Reed-Solomon, e.g. 6+3) tolerate more but the
idea is the same. 05_erasure_coding.py does the k-blocks-plus-XOR-parity version and rebuilds a lost
block exactly.

## Security: encryption

Two different places you encrypt, and they solve different problems:

- **in transit** - data moving over the network. TLS/HTTPS. Stops someone sniffing the wire between the
  client and the bucket.
- **at rest** - data sitting on the disk. Symmetric encryption (AES in real life). Stops someone who
  steals the physical drive or dumps the storage from reading it.

You want both - TLS doesn't help if the disk walks out the door, and disk encryption doesn't help if the
connection is plaintext. 03_encryption.py does the at-rest half with a stream cipher: a keystream derived
from the key with sha256 (counter mode), XORed with the bytes. Same key decrypts, wrong key gives garbage,
and decrypt(encrypt(x)) == x.

## Security: access control (IAM)

Who is allowed to do what to which object. IAM policies are a list of statements, each an Allow or Deny
over (principal, action, resource). The evaluation rule that trips people up:

- default is **deny** - if nothing matches, the answer is no.
- an explicit **Deny always wins** - one matching Deny overrides every Allow.

So the order is: any matching Deny -> denied; else any matching Allow -> allowed; else denied.
04_access_control.py evaluates a small policy this way, including a Deny that blocks one secret object even
though a broad Allow would otherwise permit it.

## Shared responsibility and key management

- **shared responsibility** - the provider secures the cloud (hardware, hypervisor, physical building);
  you secure what's in the cloud (your data, your access policies, your keys, patching your VMs). Most
  breaches are the customer's half - a public bucket, a leaked key - not the provider's.
- **key management** - the encryption is only as safe as the key. A KMS (key management service) generates,
  stores, rotates and controls access to keys so they never sit next to the data in plaintext. Rotating
  keys limits the blast radius if one leaks.

## The files

- 01_object_store.py     - in-memory S3-like store: bucket, put, get, list, delete, md5 etag
- 02_data_replication.py - replicate across N nodes, quorum W/R, W+R>N returns the latest
- 03_encryption.py       - stream cipher (sha256 keystream + XOR), decrypt(encrypt(x)) == x
- 04_access_control.py   - IAM policy eval, explicit Deny beats Allow, default deny
- 05_erasure_coding.py   - k blocks + XOR parity, lose a block and rebuild it

All standard library, simulated in memory - no boto3, no real S3. The hashing is real, the cloud is fake.
