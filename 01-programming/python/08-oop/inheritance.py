# single inheritance
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print(self.name, self.age)


class Student(Person):
    def __init__(self, name, age, roll):
        super().__init__(name, age)
        self.roll = roll

    def show_roll(self):
        print("Roll:", self.roll)


s = Student("Ravi", 19, 101)
s.show()
s.show_roll()
