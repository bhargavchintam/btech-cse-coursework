# multiple inheritance
class Father:
    def skills(self):
        print('driving, cooking')


class Mother:
    def hobbies(self):
        print('painting, music')


class Child(Father, Mother):
    def show(self):
        print('child has:')


c = Child()
c.show()
c.skills()
c.hobbies()

# order it looks up methods
print(Child.__mro__)
