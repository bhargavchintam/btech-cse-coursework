# dictionary operations
d = {'a': 1, 'b': 2, 'c': 3}
print(d)
print("keys:", list(d.keys()))
print("values:", list(d.values()))
print("items:", list(d.items()))

d['d'] = 4
print("after add:", d)

d['a'] = 100
print("after update:", d)

print("get b:", d.get('b'))
print("get z:", d.get('z', 'not found'))

del d['c']
print("after delete c:", d)

for k, v in d.items():
    print(k, "->", v)
