# spark rdd operations

from pyspark import SparkContext

sc = SparkContext(appName="rddops")
sc.setLogLevel("ERROR")

nums = sc.parallelize([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

print("count:", nums.count())
print("sum:", nums.reduce(lambda a, b: a + b))
print("max:", nums.max())

evens = nums.filter(lambda x: x % 2 == 0)
print("evens:", evens.collect())

squares = nums.map(lambda x: x * x)
print("squares:", squares.collect())

words = sc.parallelize(["hadoop", "spark", "hadoop", "hive", "spark", "spark"])
freq = words.map(lambda w: (w, 1)).reduceByKey(lambda a, b: a + b)
print("wordfreq:", sorted(freq.collect()))

sc.stop()
