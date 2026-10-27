# Lab 9 - Word Count using Pig

## Aim
Count the occurrences of each word in a text file using Apache Pig with TOKENIZE and FLATTEN.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- Apache Pig 0.17

## Procedure
1. Put the input into HDFS:
   ```
   hdfs dfs -put input.txt /user/hadoop/input.txt
   ```
   `input.txt`
   ```
   big data hadoop
   hadoop pig
   big data pig pig
   ```
2. Run:
   ```
   pig -x mapreduce Lab09_wordcount.pig
   ```

## Program
See `Lab09_wordcount.pig`. LOAD each line as a chararray -> `FLATTEN(TOKENIZE(line))` splits lines into words -> GROUP BY word -> `COUNT(words)` per group -> ORDER BY count DESC -> DUMP.

## Output
```
(pig,3)
(big,2)
(data,2)
(hadoop,2)
```

## Result
Word count was implemented in Pig Latin using TOKENIZE and FLATTEN, giving the correct frequency of each word.
