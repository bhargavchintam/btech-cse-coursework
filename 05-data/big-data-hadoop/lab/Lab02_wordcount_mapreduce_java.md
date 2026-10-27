# Lab 2 - Word Count using MapReduce (Java)

## Aim
Write a MapReduce program in Java to count the number of occurrences of each word in an input text file.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- JDK 8, `javac` on PATH
- Program compiled against `hadoop classpath`

## Procedure
1. Save the program as `Lab02_WordCount.java` (public class name must match the file name).
2. Compile against the Hadoop jars and build a jar:
   ```
   javac -cp $(hadoop classpath) -d wc_classes Lab02_WordCount.java
   jar -cvf wc.jar -C wc_classes/ .
   ```
3. Put the input into HDFS:
   ```
   hdfs dfs -mkdir -p /user/hadoop/wc_in
   hdfs dfs -put input.txt /user/hadoop/wc_in
   ```
4. Run the job (output dir must not exist):
   ```
   hadoop jar wc.jar Lab02_WordCount /user/hadoop/wc_in /user/hadoop/wc_out
   ```
5. See the result:
   ```
   hdfs dfs -cat /user/hadoop/wc_out/part-r-00000
   ```

## Program
See `Lab02_WordCount.java`. Mapper tokenizes each line and emits `(word, 1)`; the combiner and reducer are the same `IntSumReducer` which sums the counts per word.

## Output
input.txt:
```
big data hadoop
hadoop spark
big data spark spark
```
part-r-00000:
```
big     2
data    2
hadoop  2
spark   3
```

## Result
The MapReduce word count program compiled and ran on Hadoop, producing the count of each word in the input.
