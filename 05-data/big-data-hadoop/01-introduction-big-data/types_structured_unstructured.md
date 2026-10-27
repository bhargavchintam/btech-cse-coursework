# Types of Data - Structured, Semi-structured, Unstructured

Data is classified into three types based on how organised it is (imp).

## 1. Structured data
- Has a **fixed schema** - rows and columns.
- Stored in RDBMS tables.
- Easy to store, query (SQL) and analyse.
- e.g. employee table, bank records, spreadsheets.

## 2. Semi-structured data
- Does not fit a strict table but has **tags / markers** to separate elements.
- Self-describing structure.
- e.g. **XML, JSON**, CSV, email headers.

## 3. Unstructured data
- **No predefined schema or format.**
- Hardest to store and analyse.
- Makes up approx **80%** of Big Data.
- e.g. images, audio, video, text documents, social media posts.

## Comparison
| Feature | Structured | Semi-structured | Unstructured |
|---------|-----------|-----------------|--------------|
| Schema | fixed | flexible / self-describing | none |
| Storage | RDBMS | NoSQL / files | files, HDFS, blob |
| Example | tables | XML, JSON | video, images, text |
| Query | easy (SQL) | medium | hard |
| % of big data | ~10% | ~10% | ~80% |

## Note
- Traditional RDBMS handles only structured data well.
- Hadoop / HDFS can store **all three** types (schema-on-read).
