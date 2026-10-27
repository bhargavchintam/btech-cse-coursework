# word count in spark - flatMap -> map -> reduceByKey
from pyspark import SparkContext

sc = SparkContext(appName="word_count")
sc.setLogLevel("ERROR")

lines = sc.parallelize([
    "big data hadoop",
    "hadoop spark big data",
    "spark spark rdd",
])

counts = (lines
          .flatMap(lambda line: line.split(" "))
          .map(lambda word: (word, 1))
          .reduceByKey(lambda a, b: a + b))

for word, c in sorted(counts.collect()):
    print(word, c)

sc.stop()
