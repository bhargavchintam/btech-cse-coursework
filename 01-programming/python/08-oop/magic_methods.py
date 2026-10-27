# magic / dunder methods
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x}, {self.y})"

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


p = Point(1, 2)
q = Point(3, 4)
print(p)
print(p + q)
print(p == q)
print(p == Point(1, 2))
