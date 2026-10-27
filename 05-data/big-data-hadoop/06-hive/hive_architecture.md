# Hive Architecture

Main components a HiveQL query passes through. (imp - draw the diagram in exam)

```
   CLI / Beeline / JDBC-ODBC
             |
          Driver  -----> Metastore (schema, RDBMS)
             |
         Compiler
             |
         Optimizer
             |
     Execution Engine
             |
      Hadoop (MapReduce / Tez)  ---> HDFS
```

## Components

**1. Hive Clients / UI**
- CLI (`hive` shell), **Beeline** (JDBC client over HiveServer2), Web UI, JDBC/ODBC.
- User submits the HiveQL query from here.

**2. Driver**
- Receives the query, acts like a controller.
- Manages the full lifecycle of a statement — opens a session, passes the query for compilation, fetches results back.

**3. Compiler**
- Parses the query, does **semantic analysis**, checks tables/columns against the metastore.
- Builds a logical **execution plan** (a DAG of stages / MR jobs).

**4. Optimizer**
- Rewrites the plan to make it efficient — filter push-down, join re-ordering, splitting tasks.

**5. Execution Engine**
- Runs the plan on Hadoop. Submits the MapReduce (or Tez/Spark) jobs in dependency order and collects output.

**6. Metastore** (imp - 2 marks)
- Stores **metadata** — table names, column names + types, partitions, and the HDFS location of the data.
- Backed by an RDBMS (**Derby** by default for single user, **MySQL** in production for multi-user).
- Stores only the schema, **not** the actual data (data is in HDFS).

## Query execution flow (asked prev year)
1. User submits query through CLI / Beeline.
2. Driver receives it and asks the Compiler for a plan.
3. Compiler fetches metadata from the Metastore and builds the execution plan.
4. Optimizer refines the plan.
5. Execution engine runs the MR/Tez jobs on the Hadoop cluster, reading data from HDFS.
6. Results are returned to the user via the Driver.
