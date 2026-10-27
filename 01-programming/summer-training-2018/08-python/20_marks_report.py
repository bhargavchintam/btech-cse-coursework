# mini project - marks report
students = {
    "bhargav": [82, 74, 91],
    "ravi": [65, 70, 58],
    "priya": [90, 88, 95],
    "arjun": [45, 52, 60]
}

topper = ""
best = 0

for name in students:
    marks = students[name]
    total = sum(marks)
    avg = total / len(marks)
    print(f"{name}: total = {total}, average = {avg:.2f}")
    if avg > best:
        best = avg
        topper = name

print(f"topper is {topper} with average {best:.2f}")
