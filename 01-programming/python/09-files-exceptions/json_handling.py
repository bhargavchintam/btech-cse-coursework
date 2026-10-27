import json

student = {"name": "Ravi", "age": 19, "marks": [78, 91, 85]}

with open("student.json", "w") as f:
    json.dump(student, f)

with open("student.json") as f:
    data = json.load(f)

print(data)
print("name:", data["name"])
print("first mark:", data["marks"][0])

# turn a dict into a json string directly
print(json.dumps(student))
