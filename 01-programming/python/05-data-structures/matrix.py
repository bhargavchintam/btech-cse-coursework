# matrix addition and transpose
a = [[1, 2, 3], [4, 5, 6]]
b = [[7, 8, 9], [1, 2, 3]]

rows = len(a)
cols = len(a[0])

c = [[0]*cols for _ in range(rows)]
for i in range(rows):
    for j in range(cols):
        c[i][j] = a[i][j] + b[i][j]

print("sum:")
for row in c:
    print(row)

# transpose of a
t = [[0]*rows for _ in range(cols)]
for i in range(rows):
    for j in range(cols):
        t[j][i] = a[i][j]

print("transpose of a:")
for row in t:
    print(row)
