# Hadoop vs RDBMS

Differentiate Hadoop and RDBMS (imp - table question, asked prev year).

| Point | RDBMS | Hadoop |
|-------|-------|--------|
| Data size | GB (limited) | TB, PB (very large) |
| Data type | structured only | structured + semi + unstructured |
| Schema | schema-on-write | schema-on-read |
| Scaling | vertical (scale up) | horizontal (scale out) |
| Throughput vs latency | low latency, low throughput | high throughput, high latency |
| Read/write | many reads + writes (OLTP) | write once, read many |
| Processing | interactive, real-time | batch |
| Data integrity | high (ACID) | relaxed / eventual |
| Cost | costly (licensed, high-end HW) | cheap (open source, commodity HW) |
| Language | SQL | MapReduce / HiveQL / Pig |
| Best for | transactional apps | analytics on huge data |

## Key points in words
- RDBMS is good for **transactions** on small structured data with fast updates.
- Hadoop is good for **analytics** (batch) on huge, varied data.
- RDBMS uses **schema-on-write** (structure fixed before loading); Hadoop uses **schema-on-read** (structure applied when reading).
- Hadoop follows **write once, read many** (WORM); it is not meant for frequent record updates.

## Note
- They are **complementary**, not replacements. Sqoop moves data between RDBMS and Hadoop.
