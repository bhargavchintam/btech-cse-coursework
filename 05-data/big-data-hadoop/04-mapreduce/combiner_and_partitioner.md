# Combiner and Partitioner

Two optimisation/control points between map and reduce. Common exam question: "Differentiate combiner and partitioner". (asked prev year)

## Combiner
**Definition:** a **local mini-reducer** that runs on the map node, on the output of one map task, before the data is shuffled to the reducer. Purpose: cut down the volume of intermediate data sent over the network.

- Set with `job.setCombinerClass(...)`. Usually the **same class as the reducer**.
- Input and output types of the combiner must be the **same** (k2,v2 -> k2,v2), because its output feeds the reducer just like map output does.
- Framework decides **whether and how many times** to run the combiner (0, 1, or many times per map). So it must NOT change the final result.
- Only safe when the reduce operation is **commutative and associative** (e.g. sum, max, min, count).

### Where combiner helps
Word count: a map task emitting `("the",1)` a thousand times can be combined locally to `("the",1000)` — one pair over the wire instead of a thousand.

### Where combiner is WRONG (imp)
**Average** is not associative: avg(avg(a,b), c) != avg(a,b,c). If you combine partial averages the final answer is wrong. So `AverageSalary` sets **no combiner**. Fix would be to emit (sum,count) pairs.

## Partitioner
**Definition:** decides **which reducer** each intermediate key goes to. Guarantees all values for a given key reach the **same** reducer.

- Default is **HashPartitioner**:
  ```
  partition = (key.hashCode() & Integer.MAX_VALUE) % numReduceTasks
  ```
- Number of partitions = number of reduce tasks.
- `& Integer.MAX_VALUE` drops the sign bit so the partition is never negative.

### Custom partitioner
Extend `Partitioner<K,V>` and override `getPartition()`. Used when you want a specific grouping, e.g. send all "male" records to reducer 0 and "female" to reducer 1, or route data by year/state.

```java
public class DeptPartitioner extends Partitioner<Text, IntWritable> {
    public int getPartition(Text key, IntWritable value, int numReduceTasks) {
        if (key.toString().equals("HR"))   return 0;
        if (key.toString().equals("SALES")) return 1 % numReduceTasks;
        return 2 % numReduceTasks;
    }
}
```
Set with `job.setPartitionerClass(DeptPartitioner.class)` and `job.setNumReduceTasks(3)`.

Skewed keys -> uneven partitions -> some reducers slow. Custom partitioner helps balance.

## Comparison

| Point        | Combiner                          | Partitioner                          |
|--------------|-----------------------------------|--------------------------------------|
| Purpose      | reduce data volume before shuffle | route keys to the right reducer      |
| Runs         | on map side, after map            | on map side, during partitioning     |
| Also called  | mini-reducer / semi-reducer       | -                                    |
| Optional?    | yes (optimisation)                | default always present (HashPartitioner) |
| Base class   | Reducer                           | Partitioner                          |
| Affects result? | must NOT                       | decides distribution, not values     |
