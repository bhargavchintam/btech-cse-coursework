# capture groups in regex
import re

date = "today is 11-07-2019"

m = re.search(r'(\d{2})-(\d{2})-(\d{4})', date)
print("whole match:", m.group(0))
print("day:", m.group(1))
print("month:", m.group(2))
print("year:", m.group(3))
print("all groups:", m.groups())

# named groups are easier to read
m2 = re.search(r'(?P<d>\d{2})-(?P<m>\d{2})-(?P<y>\d{4})', date)
print(m2.group('d'), m2.group('m'), m2.group('y'))
print(m2.groupdict())

# finditer gives match objects so you keep group info
log = "user=ravi id=12 | user=john id=45"
for m in re.finditer(r'user=(\w+) id=(\d+)', log):
    print(m.group(1), "has id", m.group(2))
