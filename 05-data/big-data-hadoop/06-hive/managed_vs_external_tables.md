# Managed vs External Tables

Hive has two kinds of tables — **managed (internal)** and **external**. (imp)

## Managed table (internal)
- Hive **owns both the data and the metadata**.
- Data is stored under the Hive warehouse dir (`/user/hive/warehouse/` by default).
- On `DROP TABLE`, Hive deletes **both** the metadata **and the actual data** in HDFS. (imp)
- Default type — if you don't say EXTERNAL, table is managed.

```sql
CREATE TABLE emp (id INT, name STRING, sal INT)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ',';
```

## External table
- Hive owns **only the metadata**, the data lives at a path you give with LOCATION.
- On `DROP TABLE`, Hive removes only the metadata; **the data stays** in HDFS. (imp - asked prev year)
- Use when the same data is shared by other tools (Pig, Spark) or must survive a table drop.

```sql
CREATE EXTERNAL TABLE emp_ext (id INT, name STRING, sal INT)
ROW FORMAT DELIMITED FIELDS TERMINATED BY ','
LOCATION '/user/hadoop/emp_data';
```

## Difference table

| Point | Managed (internal) | External |
|-------|--------------------|----------|
| Keyword | (default) | EXTERNAL |
| Data ownership | Hive | user / other tool |
| Storage | warehouse dir | user-given LOCATION |
| DROP TABLE deletes data? | **Yes** | **No** (only metadata) |
| When to use | Hive fully manages the data | data shared / must not be lost |

## Point to remember
- The real difference shows up on **DROP** — managed loses data, external keeps it. That single line often fetches the marks.
