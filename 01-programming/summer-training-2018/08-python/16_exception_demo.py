try:
    num = int(input("enter a number: "))
    print(f"square is {num * num}")
except ValueError:
    print("that was not a number")

print("program over")
