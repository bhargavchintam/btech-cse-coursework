marks = {"maths": 82, "physics": 74, "chemistry": 68, "english": 90}

print(marks)
print(marks["maths"])

marks["computer"] = 95
print(marks)

for sub in marks:
    print(sub, marks[sub])

print("total =", sum(marks.values()))
print(marks.keys())
print(marks.values())
