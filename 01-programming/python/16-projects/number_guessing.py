# guess the number game
import random

secret = random.randint(1, 100)
tries = 7

print("I picked a number between 1 and 100.")
print(f"You have {tries} tries.")

won = False
for t in range(1, tries + 1):
    guess = int(input(f"try {t}: "))
    if guess == secret:
        print("You got it!")
        won = True
        break
    elif guess < secret:
        print("too low")
    else:
        print("too high")

if not won:
    print("out of tries. the number was", secret)
