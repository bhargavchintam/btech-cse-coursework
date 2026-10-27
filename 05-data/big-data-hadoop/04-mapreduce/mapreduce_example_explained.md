# Word Count - Worked Example

The standard first MapReduce program. Trace the counts by hand for the exam. (imp)

## Input
Two lines in the input file:
```
Dear Bear River
Car Car River
```

## Splitting
Assume the file is split into 2 splits (one per line here for the trace), so 2 map tasks.

## Map phase
Each line goes to `map()` as (offset, line). `map()` tokenises the line and emits `(word, 1)` for every word.

Map task 1 on "Dear Bear River":
```
(Dear, 1)
(Bear, 1)
(River, 1)
```
Map task 2 on "Car Car River":
```
(Car, 1)
(Car, 1)
(River, 1)
```

## Combiner (if set) - local pre-aggregation
Runs per map task. Sums the 1's locally.

Map 1 combined: `(Dear,1) (Bear,1) (River,1)` (no change, all unique here)
Map 2 combined: `(Car,2) (River,1)`  <- the two Cars merged locally

So "Car,1 Car,1" becomes a single "Car,2" before it crosses the network. That is the whole point of the combiner.

## Shuffle and Sort
Framework groups all pairs by key and sorts them, sending each key to one reducer:
```
(Bear,  [1])
(Car,   [2])
(Dear,  [1])
(River, [1, 1])
```
Note `River` came from both map tasks (1 from map 1, 1 from map 2) so its value list is [1, 1].

## Reduce phase
`reduce()` runs once per key, summing the value list:
```
Bear   -> 1
Car    -> 2
Dear   -> 1
River  -> 2
```

## Final output (part-r-00000)
```
Bear   1
Car    2
Dear   1
River  2
```

## Counting check
- Bear: appears once -> 1
- Car: appears twice -> 2
- Dear: once -> 1
- River: once in each line -> 2

Total words in = 6 (3 + 3). Sum of counts out = 1+2+1+2 = 6. Balances. (good sanity check for viva)

## Mapping to the Java code (WordCount.java)
- `TokenizerMapper.map()` -> the (word,1) emit, using `StringTokenizer`.
- `IntSumReducer.reduce()` -> the sum over the value list.
- `job.setCombinerClass(IntSumReducer.class)` -> the local combine step above (reuses the reducer because sum is associative).
- output key = Text (the word), output value = IntWritable (the count).
