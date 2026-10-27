# map and filter on employee salaries
from pyspark import SparkContext

sc = SparkContext(appName="map_filter")
sc.setLogLevel("ERROR")

emp = sc.parallelize([
    ("raj", 5000),
    ("asha", 12000),
    ("kiran", 8000),
    ("meena", 15000),
    ("suresh", 9500),
])

# give everyone a 10% hike
hike = emp.map(lambda e: (e[0], int(e[1] * 1.10)))
print("after 10% hike:", hike.collect())

# high earners (sal > 9000)
high = emp.filter(lambda e: e[1] > 9000)
print("sal > 9000:", high.collect())

names = high.map(lambda e: e[0])
print("names only:", names.collect())

sc.stop()
