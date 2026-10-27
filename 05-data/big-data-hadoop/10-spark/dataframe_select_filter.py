# dataframe select and filter
from pyspark.sql import SparkSession

spark = SparkSession.builder.appName("dataframe_select_filter").getOrCreate()
spark.sparkContext.setLogLevel("ERROR")

data = [
    (1, "raj", "cse", 5000),
    (2, "asha", "ece", 7000),
    (3, "kiran", "cse", 8000),
    (4, "meena", "civil", 6500),
    (5, "suresh", "ece", 9500),
]
df = spark.createDataFrame(data, ["id", "name", "dept", "sal"])

# select a few columns
df.select("name", "sal").show()

# filter rows
df.filter(df.sal > 7000).show()

# combine
df.filter(df.dept == "ece").select("name", "sal").show()

spark.stop()
