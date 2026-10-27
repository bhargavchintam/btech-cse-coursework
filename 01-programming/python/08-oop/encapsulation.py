# encapsulation with a private balance
class Account:
    def __init__(self, bal):
        self.__balance = bal

    def deposit(self, amt):
        self.__balance += amt

    def withdraw(self, amt):
        if amt <= self.__balance:
            self.__balance -= amt
        else:
            print('not enough money')

    def balance(self):
        return self.__balance


a = Account(1000)
a.deposit(500)
a.withdraw(300)
print('balance:', a.balance())

# print(a.__balance)  # error, __balance is private
