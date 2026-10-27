# todo list program
todos = []

while True:
    print("1. add  2. view  3. remove  4. quit")
    choice = input("enter choice: ")
    if choice == "1":
        task = input("enter task: ")
        todos.append(task)
        print("added")
    elif choice == "2":
        if len(todos) == 0:
            print("nothing to do")
        for i in range(len(todos)):
            print(f"{i + 1}. {todos[i]}")
    elif choice == "3":
        task = input("enter task to remove: ")
        if task in todos:
            todos.remove(task)
            print("removed")
        else:
            print("not found")
    elif choice == "4":
        print("bye")
        break
    else:
        print("wrong choice")
