# polymorphism - same method name, different classes
class Circle:
    def __init__(self, r):
        self.r = r

    def area(self):
        return 3.14 * self.r * self.r


class Square:
    def __init__(self, s):
        self.s = s

    def area(self):
        return self.s * self.s


shapes = [Circle(5), Square(4), Circle(2)]
for sh in shapes:
    print(round(sh.area(), 2))
