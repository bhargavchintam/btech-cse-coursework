# Phases of MapReduce

A MapReduce job runs in three main phases: **Map -> Shuffle & Sort -> Reduce**. Shuffle & sort is done by the framework, not by the programmer.

## 1. Map phase
- Input file is broken into **input splits** (one split ~ one HDFS block, 128 MB default).
- One **map task per split**, run in parallel.
- **RecordReader** turns the split into (key, value) records and feeds them to `map()` one at a time.
  - For TextInputFormat: key = byte offset in file, value = the line.
- `map()` emits intermediate (k2, v2) pairs.
- Output is written to the **local disk** of the map node (a circular memory buffer, spilled to disk), NOT to HDFS. (imp)
- If a **combiner** is set, it runs here on the spilled data to shrink map output.

## 2. Shuffle and Sort phase
The heart of MapReduce — moves map output to the reducers.

- **Partitioning:** each (k2, v2) is assigned a partition = `HashPartitioner`, `(key.hashCode() & Integer.MAX_VALUE) % numReduceTasks`. All records with the same key go to the same reducer.
- **Shuffle:** reducers pull (copy) their partition from every map node over HTTP.
- **Sort:** the framework **merge-sorts** the copied data so each reducer sees keys in sorted order, and all values of one key are grouped together -> (k2, list(v2)).

Points:
- Shuffle starts as soon as some map outputs are ready (overlaps with map).
- This is the most network + disk heavy step; combiner and compression reduce the load.

## 3. Reduce phase
- `reduce()` is called **once per unique key**, with that key and the iterable of all its values.
- Produces final (k3, v3) pairs.
- Output written to **HDFS** as `part-r-00000`, one file per reduce task.
- No. of output files = no. of reducers (set by `job.setNumReduceTasks(n)`).

## Quick comparison

| Phase          | Runs on        | Reads from      | Writes to      | Who does it   |
|----------------|----------------|-----------------|----------------|---------------|
| Map            | mapper nodes   | HDFS (split)    | local disk     | programmer    |
| Shuffle & Sort | across cluster | mapper disks    | reducer memory/disk | framework |
| Reduce         | reducer nodes  | shuffled data   | HDFS           | programmer    |

## Notes
- **Map-only jobs:** set reducers = 0. Map output goes straight to HDFS, no shuffle. Used for pure transformations (e.g. format conversion, filtering).
- No. of maps is decided by the input size (splits); no. of reduces is set by the programmer.
- Sorting is by key using the key's `WritableComparable` / `compareTo`.
