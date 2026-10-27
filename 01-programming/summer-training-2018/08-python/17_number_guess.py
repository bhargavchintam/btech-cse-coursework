# number guessing game
import random

secret = random.randint(1, 100)
tries = 0

print("guess a number between 1 and 100")

while True:
    guess = int(input("enter your guess: "))
    tries = tries + 1
    if guess < secret:
        print("go higher")
    elif guess > secret:
        print("go lower")
    else:
        print(f"correct! you took {tries} tries")
        break
