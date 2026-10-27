# append mode adds to the end instead of overwriting
with open("log.txt", "w") as f:
    f.write("line 1\n")

with open("log.txt", "a") as f:
    f.write("line 2\n")
    f.write("line 3\n")

# read it line by line
with open("log.txt") as f:
    for line in f:
        print(line.strip())
