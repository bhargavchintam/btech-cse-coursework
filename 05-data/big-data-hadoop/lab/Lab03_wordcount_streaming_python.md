# Lab 3 - Word Count using Hadoop Streaming (Python)

## Aim
Implement word count using Hadoop Streaming with a Python mapper and reducer, so the MapReduce logic is written in Python instead of Java.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Python 3, `hadoop-streaming-3.1.x.jar` in `$HADOOP_HOME/share/hadoop/tools/lib`

## Procedure
1. Make the two scripts executable:
   ```
   chmod +x Lab03_mapper.py Lab03_reducer.py
   ```
2. Test the pipeline locally first (mapper | sort | reducer):
   ```
   cat input.txt | python3 Lab03_mapper.py | sort | python3 Lab03_reducer.py
   ```
3. Put input into HDFS and run the streaming job:
   ```
   hdfs dfs -put input.txt /user/hadoop/wc_in
   hadoop jar $HADOOP_HOME/share/hadoop/tools/lib/hadoop-streaming-3.1.*.jar \
     -input /user/hadoop/wc_in \
     -output /user/hadoop/wc_out \
     -mapper Lab03_mapper.py \
     -reducer Lab03_reducer.py \
     -file Lab03_mapper.py -file Lab03_reducer.py
   ```
4. Read the output:
   ```
   hdfs dfs -cat /user/hadoop/wc_out/part-00000
   ```

## Program
See `Lab03_mapper.py` (emits `word\t1`) and `Lab03_reducer.py` (reads the sorted stream and keeps a running total per current word).

## Output
For input `big data hadoop / hadoop spark spark / big data a a a`:
```
a       3
big     2
data    2
hadoop  2
spark   2
```

## Result
Word count was implemented with Hadoop Streaming in Python and gave the correct counts when run through the mapper-sort-reducer pipeline.
