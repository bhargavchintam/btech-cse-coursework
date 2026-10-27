# Data Serialization Formats (Avro, Parquet, ORC)

**Definition:** **Serialization** = converting a data structure / object into a byte stream for **storage** or **transfer over network**, and back (deserialization). In Hadoop, efficient formats save space and speed up jobs. (imp)

## Why special formats in Big Data
- Plain text/CSV/JSON = bulky, slow to parse, no schema.
- Big Data needs **compact**, **splittable**, **schema-aware**, **compressible** formats.

## Row vs Column storage (key idea)
- **Row-oriented** — stores whole record together. Good for writing / reading full rows (OLTP-like).
- **Column-oriented** — stores each column together. Good for reading a **few columns** over many rows (analytics/OLAP). Better compression (similar values together). (asked prev year)

## 1. Avro
- **Row-based** serialization system (from Hadoop, by Doug Cutting).
- Schema stored **with** the data (as JSON) → self-describing.
- Great for **schema evolution** (add/remove fields safely).
- Compact binary, splittable, language-neutral.
- **Use:** write-heavy, streaming, message payloads (Kafka), data exchange.

## 2. Parquet
- **Columnar** storage format (Cloudera + Twitter).
- Excellent compression + encoding, reads only needed columns → less I/O.
- Best for **analytical / read-heavy** queries (Hive, Spark, Impala).
- Supports nested data.

## 3. ORC (Optimized Row Columnar)
- **Columnar** format, from the **Hive** side (Hortonworks).
- Stores data in **stripes**, keeps **indexes** + min/max stats → predicate pushdown (skip blocks).
- High compression, best with **Hive**.

## Comparison table
| Format | Layout | Schema | Best for | Ecosystem |
|---|---|---|---|---|
| Avro | row | stored (JSON) | write/stream, schema evolution | Kafka, Sqoop |
| Parquet | columnar | yes | read/analytics, few columns | Spark, Impala |
| ORC | columnar | yes | read/analytics, Hive | Hive |

## Rule of thumb
- **Write / streaming / evolving schema** → Avro.
- **Read-heavy analytics** → Parquet or ORC (columnar).
- All three are **compressible + splittable** → good for MapReduce/Spark. (2 marks)
