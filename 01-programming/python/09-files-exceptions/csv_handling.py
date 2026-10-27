import csv

rows = [
    ["name", "age", "city"],
    ["Ravi", 19, "Delhi"],
    ["Anita", 20, "Pune"],
]

with open("people.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerows(rows)

with open("people.csv") as f:
    r = csv.reader(f)
    for row in r:
        print(row)
