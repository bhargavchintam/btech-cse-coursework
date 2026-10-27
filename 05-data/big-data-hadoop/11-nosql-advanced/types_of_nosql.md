# Types of NoSQL Databases

Four main types. Differentiate them — common 8-mark question. (imp)

## 1. Key-Value store
- **Definition:** data stored as a simple **(key, value)** pair, like a big hash map / dictionary.
- Value is opaque (blob) — DB does not look inside.
- Fast lookups by key. No complex queries.
- **Use:** caching, session store, shopping carts, user preferences.
- **Examples:** Redis, Amazon DynamoDB, Riak, Memcached.

## 2. Document store
- **Definition:** stores data as **documents** (JSON / BSON / XML). Each document = self-describing, nested fields.
- Documents grouped into **collections**. Schema flexible — docs in a collection can differ.
- Can query on fields inside the document (unlike key-value).
- **Use:** content management, catalogs, user profiles, web/mobile apps.
- **Examples:** **MongoDB**, CouchDB.

```json
{ "id": 1, "name": "raj", "dept": "cse", "marks": [78, 85, 90] }
```

## 3. Column-family (wide-column) store
- **Definition:** data stored in **column families** — rows keyed by a row key, each row can have different columns. Column-oriented on disk.
- Good for sparse data + huge write throughput.
- **Use:** time-series, logging, IoT, recommendation, analytics.
- **Examples:** **Apache Cassandra**, **HBase** (on HDFS), Google Bigtable.

## 4. Graph database
- **Definition:** data as **nodes** (entities) and **edges** (relationships), with properties on both.
- Best for highly connected data + relationship queries (traversals).
- **Use:** social networks, fraud detection, recommendation, network/IT maps.
- **Examples:** **Neo4j**, OrientDB.

## Comparison table
| Type | Data model | Query by | Example |
|---|---|---|---|
| Key-Value | key -> value (blob) | key only | Redis, DynamoDB |
| Document | JSON/BSON docs | any field | MongoDB, CouchDB |
| Column-family | column families | row key + column | Cassandra, HBase |
| Graph | nodes + edges | relationships | Neo4j |

- Pick type by **access pattern**, not by habit. (2 marks)
