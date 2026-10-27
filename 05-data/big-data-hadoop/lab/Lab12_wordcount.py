# spark wordcount

from pyspark import SparkContext

sc = SparkContext(appName="wordcount")
sc.setLogLevel("ERROR")

data = ["big data hadoop",
        "hadoop mapreduce spark",
        "big data spark spark"]

lines = sc.parallelize(data)
counts = lines.flatMap(lambda line: line.split()) \
              .map(lambda word: (word, 1)) \
              .reduceByKey(lambda a, b: a + b)

for word, count in sorted(counts.collect()):
    print("%s\t%d" % (word, count))

sc.stop()
