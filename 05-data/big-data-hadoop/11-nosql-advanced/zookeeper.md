# Apache ZooKeeper

**Definition:** **Apache ZooKeeper** is a centralized, distributed **coordination service** for distributed applications. Provides configuration, naming, synchronization and group services so apps don't reinvent them. (imp)

- "The one who manages the animals in the Hadoop zoo" — coordinates HBase, Kafka, etc.
- Maintains a small, reliable, **in-memory** data tree, replicated across servers.

## Why needed
- Coordinating a distributed system by hand is hard — race conditions, deadlocks, partial failure.
- ZooKeeper gives reliable primitives: **leader election**, config management, locks, membership.

## Data model — znodes
- Namespace = a **hierarchical tree** like a filesystem. Each node = **znode**.
- znode holds small data (KBs) + can have children. Path like `/app/config`.
- Types:
  - **Persistent** — stays until deleted.
  - **Ephemeral** — deleted automatically when the creating session ends (used for membership / liveness).
  - **Sequential** — ZooKeeper appends a monotonically increasing number (used for locks / ordering).

## ZooKeeper ensemble
- Runs as a cluster = **ensemble** of servers. One is **leader**, rest are **followers**.
- Uses **ZAB** (ZooKeeper Atomic Broadcast) protocol for consensus.
- **Quorum** — majority must agree; needs `> n/2` servers up. Hence **odd** number of nodes (3, 5). (asked prev year)
- Writes go through leader; reads served by any server.

## Services it provides
- **Configuration management** — central config for all nodes.
- **Naming service** — like DNS for the cluster.
- **Leader election** — pick a master (e.g. HBase HMaster, Kafka controller).
- **Synchronization / locks** — distributed locks, barriers.
- **Group membership** — who is alive (via ephemeral znodes + **watches**).

## Watches
- Client sets a **watch** on a znode → gets a one-time notification when it changes. Basis of event-driven coordination.

## Who uses it
- **HBase** (region/master coordination), **Kafka** (broker metadata, controller election, pre-KRaft), Hadoop HA (NameNode failover), Solr.

## 2 marks
- ZooKeeper = distributed coordination service; data = tree of znodes; ensemble with a leader; needs a quorum (odd nodes); used for config, leader election, locks, membership.
