# Mini projects

Small menu-driven programs that put everything together. Most run a
`while True:` loop, print a menu, read a choice and act on it until you quit.

## Programs
- **calculator.py** - add / subtract / multiply / divide from a menu
- **number_guessing.py** - guess a random 1-100 number in 7 tries
- **todo_list.py** - add, show, mark done, delete tasks
- **bank_account.py** - deposit / withdraw / balance using an `Account` class
- **quiz_game.py** - answer questions and get a score
- **contact_book.py** - add / search / delete names and numbers (dict)

## The menu loop pattern
```python
while True:
    menu()
    ch = input("choice: ")
    if ch == "1":
        ...
    elif ch == "5":
        break
    else:
        print("wrong choice")
```

Wrapping the main part in `if __name__ == "__main__":` keeps it from running
if the file ever gets imported.

> to run: `python3 calculator.py` and type the menu numbers.
> the data is only kept in memory, it is gone when the program stops.
