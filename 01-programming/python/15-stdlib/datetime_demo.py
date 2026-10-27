# working with dates and times
from datetime import datetime, date, timedelta

today = date(2019, 7, 11)
print("today:", today)
print("year:", today.year, "month:", today.month, "day:", today.day)
print("weekday:", today.strftime("%A"))

# a specific datetime
dt = datetime(2019, 12, 25, 18, 30, 0)
print("formatted:", dt.strftime("%d-%m-%Y %H:%M"))

# arithmetic with timedelta
week_later = today + timedelta(days=7)
print("a week later:", week_later)

diff = date(2020, 1, 1) - today
print("days to new year:", diff.days)

# parse a string into a date
s = "2019-08-15"
d = datetime.strptime(s, "%Y-%m-%d")
print("parsed:", d.date(), "is a", d.strftime("%A"))
