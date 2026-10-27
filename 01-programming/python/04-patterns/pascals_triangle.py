n = int(input("Rows: "))

row = [1]
for i in range(n):
    print(row)
    # build next row
    nxt = [1]
    for j in range(len(row) - 1):
        nxt.append(row[j] + row[j + 1])
    nxt.append(1)
    row = nxt
