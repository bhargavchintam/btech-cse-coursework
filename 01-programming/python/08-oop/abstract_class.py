# abstract base class using abc
from abc import ABC, abstractmethod


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass


class Rectangle(Shape):
    def __init__(self, w, h):
        self.w = w
        self.h = h

    def area(self):
        return self.w * self.h


class Triangle(Shape):
    def __init__(self, b, h):
        self.b = b
        self.h = h

    def area(self):
        return 0.5 * self.b * self.h


r = Rectangle(4, 5)
t = Triangle(6, 8)
print("rect area:", r.area())
print("tri area:", t.area())

# s = Shape()  # TypeError, Shape is abstract
