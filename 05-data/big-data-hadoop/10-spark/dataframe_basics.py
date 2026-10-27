# dataframe basics - SparkSession, createDataFrame, show, printSchema
from pyspark.sql import SparkSession

spark = SparkSession.builder.appName("dataframe_basics").getOrCreate()
spark.sparkContext.setLogLevel("ERROR")

data = [
    (1, "raj", "cse", 5000),
    (2, "asha", "ece", 7000),
    (3, "kiran", "cse", 8000),
    (4, "meena", "civil", 6500),
]
cols = ["id", "name", "dept", "sal"]

df = spark.createDataFrame(data, cols)

df.printSchema()
df.show()
print("total rows:", df.count())
print("columns:", df.columns)

spark.stop()
