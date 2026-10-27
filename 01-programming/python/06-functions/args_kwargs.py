# *args and **kwargs
def total(*nums):
    s = 0
    for n in nums:
        s += n
    return s

def show(**info):
    for k, v in info.items():
        print(k, "=", v)

print("total:", total(1, 2, 3, 4))
print("total:", total(10, 20))
show(name="ravi", age=19, city="pune")
