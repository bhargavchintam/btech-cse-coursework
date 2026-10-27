# contact book - store names and numbers
contacts = {}

def show_all():
    if not contacts:
        print("no contacts")
        return
    for name in sorted(contacts):
        print(f"  {name} : {contacts[name]}")

def menu():
    print("\n--- Contact Book ---")
    print("1. Add contact")
    print("2. Show all")
    print("3. Search")
    print("4. Delete")
    print("5. Quit")

if __name__ == "__main__":
    while True:
        menu()
        ch = input("choice: ")
        if ch == "1":
            name = input("name: ")
            num = input("number: ")
            contacts[name] = num
            print("saved")
        elif ch == "2":
            show_all()
        elif ch == "3":
            name = input("search name: ")
            if name in contacts:
                print(name, "->", contacts[name])
            else:
                print("not found")
        elif ch == "4":
            name = input("delete name: ")
            if name in contacts:
                del contacts[name]
                print("deleted")
            else:
                print("not found")
        elif ch == "5":
            print("bye")
            break
        else:
            print("wrong choice")
