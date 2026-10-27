players = ["kohli", "dhoni", "rohit", "bumrah"]

print(players)
print(players[0])
print(players[-1])
print(len(players))

players.append("dhawan")
print(players)

players.remove("rohit")
print(players)

players.sort()
print(players)

for p in players:
    print(p)
