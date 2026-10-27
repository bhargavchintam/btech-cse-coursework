# What is Pig

**Definition:** Apache Pig is a high-level platform for analysing large datasets on Hadoop. Programs are written in a data-flow language called **Pig Latin**, which Pig converts into MapReduce jobs. Developed at Yahoo. (imp)

- Pig Latin is a **data-flow / scripting language** — you describe a series of steps (load, filter, group, ...) and data flows through them.
- Pig internally **compiles the script into MapReduce jobs** and runs them on Hadoop. About 10 lines of Pig ≈ 200 lines of Java MapReduce.
- Best suited for **ETL** work — extract, transform, load — and for quick ad-hoc data processing.
- Works on **structured, semi-structured and unstructured** data.

## Why Pig
- Writing MapReduce in Java is long. Pig gives short scripts for the same work.
- No need to know Java; Pig Latin is simple to learn.
- Handles the details of parallel execution, so the programmer focuses on the logic.

## Execution modes (imp)
- **Local mode** — runs on a single JVM using the local file system. Used for testing. `pig -x local`
- **MapReduce mode** — runs on the Hadoop cluster, data in HDFS. Default mode. `pig -x mapreduce`

## Grunt shell
- The interactive shell of Pig where Pig Latin statements are typed one by one. (asked prev year)

## Features
- Rich set of operators (JOIN, FILTER, GROUP, ORDER, ...).
- Handles nested data types (bag, tuple, map).
- Extensible with **UDF** written in Java, Python etc.
- Optimizes the script automatically before running.

## Where Pig is used
- ETL pipelines, log processing, iterative data processing, quick data exploration.
