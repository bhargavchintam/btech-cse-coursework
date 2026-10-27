# write to a text file then read it back
with open("sample.txt", "w") as f:
    f.write("hello file\n")
    f.write("second line\n")

with open("sample.txt") as f:
    data = f.read()

print(data)
print("chars read:", len(data))
