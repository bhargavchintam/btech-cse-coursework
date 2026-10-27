# a class that is its own iterator

class Countdown:
    def __init__(self, start):
        self.n = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.n <= 0:
            raise StopIteration
        val = self.n
        self.n -= 1
        return val

for x in Countdown(5):
    print(x, end=" ")
print()
