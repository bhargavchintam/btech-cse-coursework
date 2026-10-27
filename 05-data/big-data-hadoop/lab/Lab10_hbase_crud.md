# Lab 10 - HBase CRUD Operations

## Aim
Create an HBase table with column families and perform CRUD operations - create (put), read (get/scan), update (put) and delete (delete/deleteall), then drop the table.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache HBase 2.x in standalone/pseudo mode
- HBase shell

## Procedure
1. Start HBase and open the shell:
   ```
   start-hbase.sh
   hbase shell
   ```
2. Run the commands from `Lab10_hbase.txt` inside the shell. Table `emp` has two column families: `personal` and `professional`.
3. The row key is the first argument to `put`; a `put` on an existing rowkey+column overwrites the old value (that is the update).

## Program
See `Lab10_hbase.txt`.

## Output
```
hbase> get 'emp', '1'
COLUMN                     CELL
 personal:city             timestamp=..., value=bangalore
 personal:name             timestamp=..., value=raj
 professional:dept         timestamp=..., value=cse
 professional:sal          timestamp=..., value=9500     <- after update
4 row(s)

hbase> scan 'emp'
ROW    COLUMN+CELL
 1     column=personal:name, value=raj
 ...
```
After `deleteall 'emp','2'` the scan shows only row 1; `count 'emp'` returns 1.

## Result
HBase table was created and all CRUD operations were performed successfully from the HBase shell.
