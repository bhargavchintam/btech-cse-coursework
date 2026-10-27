# os and os.path basics
import os

print("current dir:", os.getcwd())
print("this file:", os.path.basename(__file__))

# path joining and splitting
p = os.path.join("folder", "sub", "file.txt")
print("joined:", p)
print("dirname:", os.path.dirname(p))
print("basename:", os.path.basename(p))
print("split ext:", os.path.splitext("notes.md"))

# does it exist
print("exists?", os.path.exists(__file__))
print("is file?", os.path.isfile(__file__))
print("is dir?", os.path.isdir(os.getcwd()))

# list the files in this folder
print("\nfiles here:")
for name in sorted(os.listdir(".")):
    print(" ", name)

# an environment variable
print("\nPATH is set:", "PATH" in os.environ)
