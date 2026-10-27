# Hive Data Types

Two categories: **primitive** and **complex (collection)** types. (imp)

## Primitive types

| Category | Types |
|----------|-------|
| Numeric | TINYINT, SMALLINT, INT, BIGINT, FLOAT, DOUBLE, DECIMAL |
| String | STRING, VARCHAR, CHAR |
| Date/Time | TIMESTAMP, DATE, INTERVAL |
| Boolean | BOOLEAN |
| Binary | BINARY |

- **TINYINT** 1 byte, **SMALLINT** 2, **INT** 4, **BIGINT** 8 byte integers.
- **STRING** most used for text; no fixed length. VARCHAR/CHAR added later (Hive 0.12+).
- **DECIMAL** for exact values like money (e.g. `DECIMAL(10,2)`).

## Complex (collection) types (asked prev year)

| Type | Meaning | Example |
|------|---------|---------|
| ARRAY | ordered list of same type | `ARRAY<STRING>` -> ['a','b'] |
| MAP | key-value pairs | `MAP<STRING,INT>` -> {'age':25} |
| STRUCT | group of named fields | `STRUCT<name:STRING, age:INT>` |
| UNIONTYPE | one value from many types | `UNIONTYPE<INT,STRING>` |

## Example with complex types
```sql
CREATE TABLE student (
  id INT,
  name STRING,
  marks ARRAY<INT>,
  address STRUCT<city:STRING, pin:INT>,
  phones MAP<STRING,STRING>
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
COLLECTION ITEMS TERMINATED BY ':'
MAP KEYS TERMINATED BY '#';
```

- Access array by index `marks[0]`, struct by dot `address.city`, map by key `phones['home']`.
- Because Hive supports complex types it can hold **semi-structured** data, unlike a plain RDBMS. (imp)
