# Pig vs Hive

Both run on Hadoop and turn simple code into MapReduce, but they differ. (imp - 5 marks)

| Point | Pig | Hive |
|-------|-----|------|
| Language | Pig Latin (data-flow / scripting) | HiveQL (SQL-like / declarative) |
| Type | procedural — step by step | declarative — say what, not how |
| Made at | Yahoo | Facebook |
| Best user | programmers / ETL developers | analysts who know SQL |
| Data | structured + semi + unstructured | mostly structured |
| Schema | schema optional, given at load | schema stored in metastore |
| Metastore | no (usually) | yes (RDBMS) |
| Main use | ETL, data pipelines, transforms | querying, reporting, warehousing |
| Shell | Grunt shell | Hive CLI / Beeline |

## Points to write
- **Pig is procedural** (you write the flow), **Hive is declarative** (you write SQL and Hive plans it). (asked prev year)
- Pig suits **ETL and transformation**; Hive suits **query and analysis / reporting**.
- Pig can handle messy/unstructured data more easily; Hive prefers structured tables with a schema.
- Both finally produce **MapReduce** jobs, so both are batch and high-latency.
