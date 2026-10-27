# Pig Latin Basics

## Data model (imp)

| Term | Meaning | Example |
|------|---------|---------|
| Atom | single value (int, chararray, ...) | `raj`, `25` |
| Tuple | ordered set of fields (a row) | `(101, raj, 55000)` |
| Bag | collection of tuples | `{(101,raj),(102,anil)}` |
| Map | set of key-value pairs | `[name#raj]` |
| Relation | a bag (the outermost bag) | result of a LOAD |

## Data types
- **int, long, float, double, chararray** (string), **bytearray**, **boolean**.
- Complex: **tuple, bag, map**.

## Common operators (asked prev year)

| Operator | Use |
|----------|-----|
| LOAD | read data into a relation |
| STORE | write a relation to disk |
| DUMP | print a relation to screen |
| FILTER | keep rows matching a condition |
| FOREACH ... GENERATE | transform / project columns |
| GROUP | group rows by a key |
| JOIN | join two relations on a key |
| ORDER BY | sort rows |
| LIMIT | keep first n rows |
| DISTINCT | remove duplicate rows |
| DESCRIBE | show schema of a relation |
| EXPLAIN | show execution plan |

## Simple script
```pig
A = LOAD 'emp.txt' USING PigStorage(',') AS (id:int, name:chararray, sal:int);
B = FILTER A BY sal > 30000;
C = FOREACH B GENERATE name, sal;
DUMP C;
```

## Points
- Each statement, except DUMP/STORE, produces a **new relation**.
- Relation and field names are **case sensitive**; keywords are not.
- `PigStorage(',')` is the default load/store function; the arg is the field separator. (imp)
- Nothing runs until a **DUMP** or **STORE** (lazy evaluation).
