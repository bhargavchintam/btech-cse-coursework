# rdd basics - parallelize, collect, count
from pyspark import SparkContext

sc = SparkContext(appName="rdd_basics")
sc.setLogLevel("ERROR")

nums = sc.parallelize([10, 20, 30, 40, 50])

print("all elements:", nums.collect())
print("count:", nums.count())
print("first:", nums.first())
print("num partitions:", nums.getNumPartitions())

sc.stop()
