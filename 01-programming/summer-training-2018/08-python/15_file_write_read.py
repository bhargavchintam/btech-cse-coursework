f = open("notes.txt", "w")
f.write("python class notes\n")
f.write("files are easy\n")
f.write("bhargav\n")
f.close()

f = open("notes.txt", "r")
data = f.read()
f.close()

print(data)
