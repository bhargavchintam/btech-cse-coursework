# bank account menu using a class
class Account:
    def __init__(self, name, balance=0):
        self.name = name
        self.balance = balance

    def deposit(self, amt):
        if amt <= 0:
            print("amount must be positive")
            return
        self.balance += amt
        print(f"deposited {amt}, balance is {self.balance}")

    def withdraw(self, amt):
        if amt > self.balance:
            print("not enough balance")
            return
        self.balance -= amt
        print(f"withdrew {amt}, balance is {self.balance}")

def menu():
    print("\n--- Bank ---")
    print("1. Deposit")
    print("2. Withdraw")
    print("3. Check balance")
    print("4. Quit")

if __name__ == "__main__":
    name = input("your name: ")
    acc = Account(name)
    print("account opened for", acc.name)
    while True:
        menu()
        ch = input("choice: ")
        if ch == "1":
            amt = float(input("amount: "))
            acc.deposit(amt)
        elif ch == "2":
            amt = float(input("amount: "))
            acc.withdraw(amt)
        elif ch == "3":
            print("balance =", acc.balance)
        elif ch == "4":
            print("thank you")
            break
        else:
            print("wrong choice")
