# a simple class
class Student:
    def set_name(self, name):
        self.name = name

    def show(self):
        print("Student:", self.name)


s = Student()
s.set_name("Ravi")
s.show()

s2 = Student()
s2.set_name("Anita")
s2.show()

print(type(s))
