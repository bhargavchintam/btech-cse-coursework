# aggregation with reduce and reduceByKey
from pyspark import SparkContext

sc = SparkContext(appName="reduce_aggregate")
sc.setLogLevel("ERROR")

nums = sc.parallelize([4, 8, 15, 16, 23, 42])

total = nums.reduce(lambda a, b: a + b)
print("total:", total)
print("count:", nums.count())
print("average:", total / nums.count())

# sales per city, sum with reduceByKey
sales = sc.parallelize([
    ("blr", 100), ("hyd", 200), ("blr", 150),
    ("hyd", 50), ("blr", 300), ("mysore", 80),
])
city_total = sales.reduceByKey(lambda a, b: a + b)
for city, amt in sorted(city_total.collect()):
    print(city, amt)

sc.stop()
