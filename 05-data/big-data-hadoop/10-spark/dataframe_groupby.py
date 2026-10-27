# dataframe groupBy and aggregation
from pyspark.sql import SparkSession
from pyspark.sql.functions import avg, count, sum

spark = SparkSession.builder.appName("dataframe_groupby").getOrCreate()
spark.sparkContext.setLogLevel("ERROR")

data = [
    (1, "raj", "cse", 5000),
    (2, "asha", "ece", 7000),
    (3, "kiran", "cse", 8000),
    (4, "meena", "civil", 6500),
    (5, "suresh", "ece", 9500),
    (6, "divya", "cse", 6000),
]
df = spark.createDataFrame(data, ["id", "name", "dept", "sal"])

# count per dept
df.groupBy("dept").agg(count("id").alias("emp_count")).show()

# avg and total salary per dept
df.groupBy("dept").agg(
    avg("sal").alias("avg_sal"),
    sum("sal").alias("total_sal"),
).orderBy("dept").show()

spark.stop()
