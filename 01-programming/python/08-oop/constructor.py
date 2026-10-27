# using the __init__ constructor
class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks

    def show(self):
        print(self.name, "got", self.marks)


s1 = Student("Ravi", 78)
s2 = Student("Anita", 91)
s1.show()
s2.show()
