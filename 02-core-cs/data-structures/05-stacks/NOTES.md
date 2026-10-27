# Stacks

A stack is a linear list where insertion and deletion both happen at the same end,
called the **top**. So the last element pushed is the first one to come out. That is
**LIFO** - Last In First Out. Like a pile of plates, you take the top one first.

> "A stack only ever gives you back the thing you put in most recently." - said this in
> the first class and it stuck.

## Operations
- **push(x)** - put x on top
- **pop()** - remove and return the top element
- **peek()** / **top()** - look at the top without removing it
- **isEmpty()** / **isFull()** - status checks

Two error conditions to always handle:
- **Overflow** - push when the stack is already full (only in the array version, fixed size)
- **Underflow** - pop or peek when the stack is empty

## Array vs Linked implementation

**Array** - keep an array and an integer `top` (starts at -1). push does `top++` then
store, pop returns `stack[top]` then `top--`. Simple and fast but the size is fixed, so
overflow is possible.

**Linked list** - each push creates a node and adds it at the head, pop removes the head.
No fixed size (grows till memory runs out) so no real overflow, but every node needs a
malloc and you must free on pop. A bit more memory per element because of the pointer.

Got underflow wrong once in the lab - popped without checking `top == -1` and it printed
garbage. Always check first.

## Complexity

| Operation | Array | Linked list |
|-----------|-------|-------------|
| push      | O(1)  | O(1)        |
| pop       | O(1)  | O(1)        |
| peek      | O(1)  | O(1)        |
| search    | O(n)  | O(n)        |
| space     | O(n)  | O(n)        |

All the main operations are constant time because we only ever touch the top.

## Applications
- **Expression conversion** - infix to postfix / prefix (files 04, 06)
- **Expression evaluation** - postfix and prefix evaluation (files 05, 07)
- **Balanced parentheses** checking (file 03)
- **Reversing** a string or a number (files 09, 08)
- **Recursion** - the function call stack is a stack, each call pushes a frame
- **Backtracking** - maze solving, N-queens, undo the last move by popping
- **Undo / redo** in editors

## Notes on the expression programs
- Precedence used: `^` = 3, `* /` = 2, `+ -` = 1, `(` = 0.
- Infix to postfix: operands go straight to output, operators wait on the stack, pop when
  a lower or equal precedence operator arrives, `(` waits and `)` pops till the `(`.
- Infix to prefix: reverse the expression (swapping `(` and `)`), do the postfix logic but
  pop only on strictly higher precedence, then reverse the result.
- Evaluation programs here assume single digit operands so `ch - '0'` gives the number.
