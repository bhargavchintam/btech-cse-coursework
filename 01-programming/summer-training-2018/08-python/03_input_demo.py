# input always gives string
name = input("enter your name: ")
age = int(input("enter your age: "))

print("hello " + name)
if age >= 18:
    print("you can vote")
else:
    print("you cannot vote yet")
