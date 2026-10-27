# InputFormat and OutputFormat

Control how a MapReduce job reads its input and writes its output.

## InputFormat
**Definition:** class that describes the input to a job. Two jobs:
1. Compute the **input splits** (how the data is divided among map tasks).
2. Provide a **RecordReader** that turns a split into (key, value) records.

### InputSplit
- A logical chunk of the input processed by one map task.
- Has a length (bytes) and a list of hosts where it lives (for data locality).
- Split != HDFS block. Split is logical (offsets), block is physical storage. By default one split ~ one block (128 MB), but a split can be tuned with `mapreduce.input.fileinputformat.split.minsize` / `maxsize`.

### RecordReader
- Reads the raw bytes of a split and produces (key, value) pairs for `map()`.
- e.g. `LineRecordReader` returns key = byte offset, value = line text.

### Common InputFormats

| InputFormat              | Key                | Value                  | Use |
|--------------------------|--------------------|------------------------|-----|
| **TextInputFormat** (default) | LongWritable (byte offset) | Text (line)      | plain text, line per record |
| **KeyValueTextInputFormat** | Text (before tab) | Text (after tab)       | tab-separated key\tvalue lines |
| **NLineInputFormat**     | LongWritable       | Text                   | fixed N lines per map (e.g. simulations) |
| **SequenceFileInputFormat** | user key         | user value             | binary Hadoop SequenceFiles |
| **DBInputFormat**        | LongWritable       | DBWritable row         | read from a relational DB |
| **FixedLengthInputFormat** | LongWritable     | BytesWritable          | fixed-width binary records |

- `FileInputFormat` is the base class for file-based formats; `addInputPath()` / `setInputPaths()` set the input.
- **Non-splittable** files (e.g. gzip) -> one map task for the whole file, no matter the size.

## OutputFormat
**Definition:** describes how the job writes its output. Provides a **RecordWriter** and checks the output spec (e.g. fails early if the output dir already exists).

### Common OutputFormats

| OutputFormat              | Output |
|---------------------------|--------|
| **TextOutputFormat** (default) | key and value as text, separated by a tab, one per line |
| **SequenceFileOutputFormat** | binary SequenceFile, good as input to another job |
| **MapFileOutputFormat**   | sorted output with an index for lookup |
| **MultipleOutputs**       | write to several named files from one job |
| **NullOutputFormat**      | discard output (when the job's side effects are elsewhere) |
| **DBOutputFormat**        | write rows back to a relational DB |

- Output files are named `part-r-00000`, `part-r-00001`, ... (r = reduce). Map-only jobs give `part-m-00000`.
- A `_SUCCESS` marker file is written when the job finishes cleanly.
- Output directory **must not already exist** — the job throws `FileAlreadyExistsException` (safety so you don't overwrite results).

## Setting them in the driver
```java
job.setInputFormatClass(KeyValueTextInputFormat.class);
job.setOutputFormatClass(TextOutputFormat.class);
```
If not set, defaults are TextInputFormat and TextOutputFormat.
