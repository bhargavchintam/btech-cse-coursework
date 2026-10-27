# nested comprehension
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

# flatten
flat = [x for row in matrix for x in row]
print("flat:", flat)

# transpose
t = [[row[i] for row in matrix] for i in range(3)]
print("transpose:")
for row in t:
    print(row)

# multiplication table
table = [[i*j for j in range(1, 6)] for i in range(1, 6)]
for row in table:
    print(row)
