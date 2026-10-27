# rdd actions - reduce, count, take, collect
from pyspark import SparkContext

sc = SparkContext(appName="rdd_actions")
sc.setLogLevel("ERROR")

nums = sc.parallelize([5, 3, 8, 1, 9, 2, 7])

print("collect:", nums.collect())
print("count:", nums.count())
print("take 3:", nums.take(3))
print("sum (reduce):", nums.reduce(lambda a, b: a + b))
print("max (reduce):", nums.reduce(lambda a, b: a if a > b else b))

sc.stop()
