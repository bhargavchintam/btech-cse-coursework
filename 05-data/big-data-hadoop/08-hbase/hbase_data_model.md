# HBase Data Model

Data stored in **tables**. A table = rows; each row identified by a **row key**. Columns grouped into **column families**.

## Terms

**Row key**
- Unique identifier of a row (byte array).
- Rows stored sorted by row key (lexicographic / byte order).
- All access is by row key -> row key design decides performance. (imp)
- No secondary index by default.

**Column family (CF)**
- Group of related columns. Defined at table creation, changing it is costly.
- Stored together on disk (own HFile) -> physical unit.
- e.g. table `student` with CF `personal`, `academic`.
- Keep CF count small (1-3 recommended).

**Column qualifier**
- The actual column name inside a family. Written as `family:qualifier`.
- e.g. `personal:name`, `personal:age`, `academic:cgpa`.
- Added dynamically, no need to predefine. Different rows can have different qualifiers.

**Cell**
- **Definition:** intersection of {row key, column family, column qualifier, timestamp}. Holds the actual value (byte array).
- Cell = the smallest unit of data.

**Timestamp / version**
- Each cell value tagged with a timestamp (default = insert time, ms).
- Multiple **versions** of a cell kept, sorted newest first.
- `get` returns latest version unless a version count / range given.
- VERSIONS set per column family (e.g. `VERSIONS => 3`).

## Coordinates of a value (imp)
A single value is located by:
`(row key) -> (column family) -> (column qualifier) -> (timestamp) -> value`

## Sparse
- If a row has no value for a column, nothing is stored (no NULL cell). Saves space.

## Example (logical view)

| Row key | personal:name | personal:age | academic:cgpa |
|---------|---------------|--------------|---------------|
| 101     | raj           | 20           | 8.5           |
| 102     | anu           |              | 9.1           |

Row 102 has no `personal:age` -> that cell simply does not exist.

## Physical view
- Stored per column family, as sorted key-value:
  `rowkey, cf:qualifier, timestamp -> value`
- Sorted by row key, then CF, then qualifier, then timestamp (desc).

(2 marks) Cell = row key + column family + qualifier + timestamp -> value.
