# Sqoop Import and Export

Two core operations of Sqoop.

## Import (RDBMS -> Hadoop)
- Reads a table (or query) from the database and writes to HDFS.
- Runs a map-only MapReduce job; each mapper handles a range of rows split by primary key.
- Output: files under `--target-dir`, one part file per mapper (part-m-00000 ...).

Basic:
```
sqoop import \
  --connect jdbc:mysql://localhost/testdb \
  --username root --password root \
  --table emp \
  --target-dir /user/hadoop/emp \
  -m 1
```

Common options:
- `--columns "id,name,sal"` — import selected columns.
- `--where "sal > 20000"` — import matching rows only.
- `--split-by id` — column used to split work (needed if no primary key).
- `--query "SELECT ... WHERE \$CONDITIONS"` — free-form query (needs `--split-by` + `--target-dir`).
- `--hive-import` — load directly into Hive.
- `--as-textfile` / `--as-avrodatafile` / `--as-parquetfile` — output format.

### Incremental import (imp)
- `--incremental append --check-column id --last-value 100` -> only rows with id > 100.
- `--incremental lastmodified --check-column updated_at --last-value '2020-01-01'` -> changed rows.

## Export (Hadoop -> RDBMS)
- Reads files from HDFS and INSERTs rows into an existing table.
- Target table must already exist in the database (Sqoop does not create it).
- Map-only job; each mapper reads a slice of the HDFS files and writes batches.

Basic:
```
sqoop export \
  --connect jdbc:mysql://localhost/testdb \
  --username root --password root \
  --table emp_out \
  --export-dir /user/hadoop/emp \
  -m 1
```

Options:
- `--input-fields-terminated-by ','` — delimiter of the HDFS files.
- `--update-key id` — do UPDATE instead of INSERT on matching key.
- `--update-mode allowinsert` — update if exists else insert (upsert).

## Import vs Export

| Point | Import | Export |
|-------|--------|--------|
| Direction | RDBMS -> HDFS/Hive | HDFS -> RDBMS |
| Target | Created in HDFS | Must pre-exist in DB |
| Job type | Map-only | Map-only |
| Key option | `--target-dir` | `--export-dir` |

(asked prev year) Both are map-only jobs; import pulls data in, export pushes data out.
