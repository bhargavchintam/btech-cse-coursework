# What is NoSQL

**Definition:** **NoSQL** = "Not Only SQL". A class of non-relational databases designed for **large-scale, distributed** data with flexible schema and horizontal scaling. (imp)

- Term became popular ~2009 with Big Data / web-scale apps (Google, Amazon, Facebook).
- Handles **huge volume**, **variety** (semi/unstructured) and **velocity** — the 3 V's — that RDBMS struggles with.
- Schema-less or flexible schema — no fixed table structure needed up front.

## Why NoSQL (need)
- RDBMS scales **vertically** (bigger machine) → costly, has a ceiling.
- NoSQL scales **horizontally** (add commodity nodes) → cheap, elastic.
- Web apps generate unstructured data (JSON, logs, social posts) — hard to fit rigid tables.
- Need high **availability** and low latency at scale.

## Characteristics
- **Non-relational** — no strict tables/joins.
- **Distributed** — data partitioned (**sharding**) + replicated across nodes.
- **Horizontally scalable** — scale out on commodity hardware.
- **Schema flexible** — different records can have different fields.
- **BASE** model instead of ACID (see below).
- **High availability**, fault tolerant.

## ACID vs BASE (asked prev year)
| ACID (RDBMS) | BASE (NoSQL) |
|---|---|
| Atomicity | **Basically Available** |
| Consistency | **Soft state** |
| Isolation | **Eventual consistency** |
| Durability | (favours availability over strict consistency) |

- ACID = strict, immediate consistency.
- BASE = relaxed; system stays available, becomes consistent **eventually**.

## The 4 types (one-liner, detail in types_of_nosql.md)
1. **Key-Value** — Redis, DynamoDB.
2. **Document** — MongoDB, CouchDB.
3. **Column-family** — Cassandra, HBase.
4. **Graph** — Neo4j.

## When NOT to use NoSQL
- Strong transactional consistency needed (banking) → prefer RDBMS.
- Complex joins / ad-hoc SQL reporting.
