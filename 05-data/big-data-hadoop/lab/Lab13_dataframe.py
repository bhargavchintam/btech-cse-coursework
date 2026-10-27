# spark dataframe basics

from pyspark.sql import SparkSession
from pyspark.sql.functions import avg

spark = SparkSession.builder.appName("dataframe").getOrCreate()
spark.sparkContext.setLogLevel("ERROR")

data = [(1, "raj",   "cse", 8000),
        (2, "anil",  "ece", 6000),
        (3, "sunil", "cse", 9000),
        (4, "kiran", "ece", 7500)]

cols = ["id", "name", "dept", "sal"]
df = spark.createDataFrame(data, cols)

df.show()
df.printSchema()

df.select("name", "sal").filter(df.sal > 7000).show()

df.groupBy("dept").agg(avg("sal").alias("avg_sal")).show()

spark.stop()
