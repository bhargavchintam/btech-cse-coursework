# Pig Architecture

A Pig Latin script goes through these stages before it runs on Hadoop. (imp - draw diagram)

```
   Pig Latin script (Grunt / .pig file)
             |
          Parser        -> checks syntax, builds logical plan (DAG)
             |
         Optimizer      -> improves the logical plan
             |
         Compiler       -> converts to a series of MapReduce jobs
             |
      Execution Engine  -> submits jobs to Hadoop
             |
         Hadoop / HDFS
```

## Components

**1. Parser**
- Takes the Pig Latin script, checks its **syntax** and does type checking.
- Output is a **logical plan** shown as a **DAG** (directed acyclic graph) where nodes are operators and edges are data flows. (imp)

**2. Optimizer**
- Works on the logical plan. Applies optimisations like **projection push-down** (drop unused columns early) and **filter push-down** to reduce the data moved.

**3. Compiler**
- Converts the optimised logical plan into a series of **MapReduce jobs**.

**4. Execution Engine**
- Submits the MapReduce jobs to Hadoop in order and returns the result.

## Note on lazy execution (asked prev year)
- Pig uses **lazy evaluation** — LOAD, FILTER, GROUP etc. only build the plan.
- The plan actually runs only when a **DUMP** or **STORE** is reached. That is why nothing executes till you dump/store.
