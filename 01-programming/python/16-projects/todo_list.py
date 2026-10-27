# a little to-do list
tasks = []

def show():
    if not tasks:
        print("no tasks yet")
        return
    for i, t in enumerate(tasks, 1):
        mark = "x" if t["done"] else " "
        print(f"{i}. [{mark}] {t['task']}")

def menu():
    print("\n--- To Do ---")
    print("1. Add task")
    print("2. Show tasks")
    print("3. Mark done")
    print("4. Delete task")
    print("5. Quit")

if __name__ == "__main__":
    while True:
        menu()
        ch = input("choice: ")
        if ch == "1":
            t = input("task: ")
            tasks.append({"task": t, "done": False})
            print("added")
        elif ch == "2":
            show()
        elif ch == "3":
            show()
            n = int(input("which number is done? "))
            if 1 <= n <= len(tasks):
                tasks[n - 1]["done"] = True
                print("marked done")
            else:
                print("no such task")
        elif ch == "4":
            show()
            n = int(input("which number to delete? "))
            if 1 <= n <= len(tasks):
                removed = tasks.pop(n - 1)
                print("deleted:", removed["task"])
            else:
                print("no such task")
        elif ch == "5":
            print("bye")
            break
        else:
            print("wrong choice")
