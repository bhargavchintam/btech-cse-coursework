# a small quiz game
questions = [
    ("What is the capital of France?", "paris"),
    ("2 + 2 * 2 = ?", "6"),
    ("Which keyword defines a function in Python?", "def"),
    ("What does len() return for 'abc'?", "3"),
    ("Is Python case sensitive? (yes/no)", "yes"),
]

score = 0
print("Answer these", len(questions), "questions.\n")

for q, ans in questions:
    print(q)
    reply = input("your answer: ")
    if reply.strip().lower() == ans:
        print("correct!\n")
        score += 1
    else:
        print("wrong, answer is:", ans, "\n")

print("you scored", score, "out of", len(questions))
if score == len(questions):
    print("perfect score!")
elif score >= len(questions) / 2:
    print("good job")
else:
    print("better luck next time")
