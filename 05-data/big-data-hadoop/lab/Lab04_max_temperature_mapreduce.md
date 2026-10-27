# Lab 4 - Maximum Temperature using MapReduce

## Aim
Write a MapReduce program to find the maximum temperature recorded in each year from the NCDC weather dataset.

## Software / Environment
- Hadoop 3.1 pseudo-distributed
- JDK 8, compiled against `hadoop classpath`
- Input: NCDC fixed-width weather records

## Procedure
1. Save as `Lab04_MaxTemperature.java`, compile and jar it:
   ```
   javac -cp $(hadoop classpath) -d mt_classes Lab04_MaxTemperature.java
   jar -cvf maxtemp.jar -C mt_classes/ .
   ```
2. Put the sample weather file into HDFS:
   ```
   hdfs dfs -mkdir -p /user/hadoop/ncdc
   hdfs dfs -put sample.txt /user/hadoop/ncdc
   ```
3. Run the job:
   ```
   hadoop jar maxtemp.jar Lab04_MaxTemperature /user/hadoop/ncdc /user/hadoop/mt_out
   ```
4. View the result:
   ```
   hdfs dfs -cat /user/hadoop/mt_out/part-r-00000
   ```

## Program
See `Lab04_MaxTemperature.java`. The mapper reads the year (chars 15-19) and air temperature (chars 87-92) from each record, skips missing (9999) and bad-quality readings, and emits `(year, temperature)`. The reducer keeps the maximum temperature per year.

## Output
```
1949    111
1950    22
```
(temperatures are in tenths of a degree C, so 111 = 11.1 C)

## Result
The MapReduce program parsed the weather records and correctly reported the maximum temperature for each year.
