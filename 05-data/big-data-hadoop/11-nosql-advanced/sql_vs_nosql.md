# SQL vs NoSQL

Differentiate relational (SQL) and non-relational (NoSQL) databases. (imp, asked prev year)

## Comparison table
| Point | SQL (RDBMS) | NoSQL |
|---|---|---|
| Data model | tables (rows, columns) | key-value / document / column / graph |
| Schema | **fixed**, defined up front | **flexible** / schema-less |
| Scaling | **vertical** (bigger server) | **horizontal** (add nodes) |
| Consistency | **ACID**, strong | **BASE**, eventual |
| Query language | **SQL** (standard) | varies per DB, no single standard |
| Joins | supported | usually not (denormalize instead) |
| Data type | structured | structured + semi/unstructured |
| Transactions | strong multi-row | limited (improving) |
| Examples | MySQL, Oracle, PostgreSQL | MongoDB, Cassandra, HBase, Redis, Neo4j |

## When to use SQL
- Structured data with clear relations.
- Strong consistency / transactions (banking, billing).
- Complex queries, joins, reporting.
- Data volume fits vertical scaling.

## When to use NoSQL
- Huge volume + high velocity (Big Data, web scale).
- Semi/unstructured or rapidly changing schema.
- Need horizontal scale-out on commodity hardware.
- High availability + low latency more important than strict consistency.

## Key point
- Not "better vs worse" — different tools. **Polyglot persistence** = use the right store per use-case in one app. (2 marks)
- NoSQL trades strict consistency for **scalability + availability**.
