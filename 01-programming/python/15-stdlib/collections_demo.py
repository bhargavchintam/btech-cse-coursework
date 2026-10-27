# collections module - Counter, defaultdict, namedtuple, deque
from collections import Counter, defaultdict, namedtuple, deque

# Counter counts things
c = Counter("mississippi")
print(c)
print("most common:", c.most_common(2))
print("count of s:", c['s'])

# defaultdict gives a default value for missing keys
d = defaultdict(list)
pairs = [("fruit", "apple"), ("veg", "carrot"), ("fruit", "mango")]
for k, v in pairs:
    d[k].append(v)
print(dict(d))

# namedtuple is like a lightweight class
Point = namedtuple("Point", "x y")
p = Point(3, 4)
print(p, p.x, p.y)
print("distance sq:", p.x**2 + p.y**2)

# deque - fast appends and pops on both ends
q = deque([1, 2, 3])
q.appendleft(0)
q.append(4)
print(q)
q.popleft()
print(q)
q.rotate(1)
print("rotated:", q)
