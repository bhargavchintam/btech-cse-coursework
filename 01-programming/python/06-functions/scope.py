# local and global scope
x = 10

def show():
    x = 5
    print("inside:", x)

def change():
    global x
    x = 99

show()
print("outside:", x)
change()
print("after change:", x)
