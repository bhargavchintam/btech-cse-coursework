# HBase vs RDBMS

Differentiate HBase and traditional RDBMS (asked prev year).

| Point | HBase | RDBMS |
|-------|-------|-------|
| Type | Column-oriented NoSQL | Row-oriented relational |
| Schema | Schema-less (only CF fixed), columns dynamic | Fixed schema, defined in advance |
| Scale | Horizontal (add region servers) | Vertical (bigger machine) mostly |
| Data size | TB to PB, billions of rows | GB to TB |
| Sparse data | Handles well, no space for empty cells | NULLs still occupy structure |
| Joins | No joins, denormalized | Rich joins |
| Transactions | Row-level atomic only | Full ACID, multi-row transactions |
| SQL | No SQL (shell / API; SQL via Phoenix) | SQL query language |
| Normalization | Denormalized | Normalized (1NF..BCNF) |
| Indexes | Row key only (no secondary by default) | Primary + secondary indexes |
| Versioning | Built-in, multiple versions by timestamp | Single value, no built-in versions |
| Best for | Random real-time R/W on huge sparse data | Structured data, complex queries, integrity |

## Notes
- RDBMS = ACID + structured + joins, but scaling up is expensive and limited.
- HBase = scale out cheaply on commodity hardware, but give up joins and multi-row transactions.
- HBase gives strong consistency per row (not eventual).
- Choose RDBMS for banking / order systems with transactions; choose HBase for huge sparse logs, sensor data, messaging store.

(2 marks) HBase = NoSQL, schema-less, horizontal scale, no joins; RDBMS = relational, fixed schema, ACID, joins.
