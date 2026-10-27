# CAP Theorem

**Definition:** In a **distributed** data system you can guarantee only **two** of the following three at the same time — **C**, **A**, **P**. Given by **Eric Brewer** (2000), also called **Brewer's theorem**. (imp)

## The three properties
- **C — Consistency:** every read gets the **most recent write** (all nodes see the same data at the same time).
- **A — Availability:** every request gets a (non-error) response, even if some nodes are down.
- **P — Partition tolerance:** system keeps working even when the **network breaks** between nodes (messages lost/delayed).

## The rule — pick 2 of 3 (asked prev year)
- In a real distributed system a **network partition can always happen**, so **P is mandatory**.
- So the real trade-off is between **C** and **A** during a partition:
  - **CP** — stay consistent, sacrifice availability (reject/parts wait).
  - **AP** — stay available, sacrifice consistency (serve possibly stale data).
- **CA** is only possible on a single node / no partition — not for a true distributed store.

```
             C
            / \
      CP   /   \  CA (single node only)
          /     \
         P-------A
             AP
```

## Categorising databases
| Combo | Guarantees | Sacrifices | Examples |
|---|---|---|---|
| **CP** | Consistency + Partition tol. | Availability | HBase, MongoDB, Redis |
| **AP** | Availability + Partition tol. | Consistency | Cassandra, DynamoDB, CouchDB |
| **CA** | Consistency + Availability | Partition tol. | single-node RDBMS |

- in practice many DBs are **tunable** (e.g. Cassandra consistency level per query) so the label is not absolute.

## Link to BASE
- AP systems favour **availability** → give **eventual consistency** (BASE), opposite of ACID's strict consistency.

## 2 marks
- CAP = Consistency, Availability, Partition tolerance; distributed systems can guarantee only 2; since partitions are unavoidable, choose CP or AP.
