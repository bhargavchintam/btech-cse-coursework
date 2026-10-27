# class methods and static methods
class Circle:
    pi = 3.14159

    def __init__(self, r):
        self.r = r

    def area(self):
        return Circle.pi * self.r * self.r

    @classmethod
    def unit(cls):
        return cls(1)

    @staticmethod
    def info():
        print("a circle just needs a radius")


c = Circle(5)
print(round(c.area(), 2))

u = Circle.unit()
print("unit circle area:", round(u.area(), 5))

Circle.info()
