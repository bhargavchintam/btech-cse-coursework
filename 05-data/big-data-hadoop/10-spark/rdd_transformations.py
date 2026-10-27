# rdd transformations - map, filter, flatMap
from pyspark import SparkContext

sc = SparkContext(appName="rdd_transformations")
sc.setLogLevel("ERROR")

nums = sc.parallelize([1, 2, 3, 4, 5, 6])

squares = nums.map(lambda x: x * x)
print("map (squares):", squares.collect())

evens = nums.filter(lambda x: x % 2 == 0)
print("filter (evens):", evens.collect())

lines = sc.parallelize(["big data", "hadoop spark", "hdfs"])
words = lines.flatMap(lambda line: line.split(" "))
print("flatMap (words):", words.collect())

sc.stop()
