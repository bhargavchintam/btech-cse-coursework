# simple menu calculator
def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mul(a, b):
    return a * b

def div(a, b):
    if b == 0:
        print("can't divide by zero")
        return None
    return a / b

def menu():
    print("\n--- Calculator ---")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("5. Quit")

if __name__ == "__main__":
    while True:
        menu()
        ch = input("choice: ")
        if ch == "5":
            print("bye")
            break
        if ch not in ("1", "2", "3", "4"):
            print("wrong choice")
            continue
        a = float(input("first number: "))
        b = float(input("second number: "))
        if ch == "1":
            print("result =", add(a, b))
        elif ch == "2":
            print("result =", sub(a, b))
        elif ch == "3":
            print("result =", mul(a, b))
        else:
            r = div(a, b)
            if r is not None:
                print("result =", r)
