# nested lists
students = [['ram', 85], ['sita', 92], ['john', 78]]
for s in students:
    print(s[0], "got", s[1])

# list of lists
grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print("element at 1,2:", grid[1][2])

# flatten it
flat = []
for row in grid:
    for x in row:
        flat.append(x)
print("flat:", flat)
