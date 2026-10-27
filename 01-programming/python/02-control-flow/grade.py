marks = int(input("Enter marks: "))

if marks >= 90:
    g = "A"
elif marks >= 75:
    g = "B"
elif marks >= 60:
    g = "C"
elif marks >= 40:
    g = "D"
else:
    g = "Fail"

print("Grade:", g)
