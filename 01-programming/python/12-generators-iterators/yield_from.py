# yield from delegates to another iterable

def letters():
    yield from "abc"

def numbers():
    yield from range(1, 4)

def both():
    yield from letters()
    yield from numbers()

print(list(both()))

# flatten a list of lists
def flatten(lists):
    for sub in lists:
        yield from sub

print(list(flatten([[1, 2], [3, 4], [5]])))
