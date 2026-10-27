# Linked Lists

A linked list is a chain of nodes. Each node holds some data and a pointer to the
next node. Unlike an array the nodes are not stored together in memory - they can
be anywhere, the `next` pointer is what keeps them in order. The list is reached
through one pointer called `head`. Last node's next is NULL.

> "An array is a shelf of fixed size, a linked list grows as you add books." - said
> in class, stuck with me.

## Node structure

Singly:
```
struct node {
    int data;
    struct node *next;
};
```
Doubly has an extra `prev` pointer so you can go both ways. Circular list's last
node points back to head instead of NULL.

## Types
- Singly - one direction, next only.
- Doubly - next and prev, can traverse backward, delete is easier (you have prev).
- Circular - last node links to first, no NULL end. Good for round-robin things.

## Operations
- insert front - O(1), just point new node to head and move head.
- insert end - O(n) because you walk to the last node. O(1) if you keep a rear pointer.
- insert at position - walk to pos-1 then relink.
- delete by value - find the node AND its previous, then prev->next = node->next.
- search - linear scan O(n).
- display / count - walk the whole list O(n).

Two bugs that cost me marks in the lab:
- deleting the head node without updating head -> list gets corrupted.
- forgetting the empty list case, deref NULL and it segfaults.
So every delete checks `if(head == NULL)` first and handles the head separately.

## Advantages over arrays
- size is not fixed, grows/shrinks at runtime (no wasted space, no overflow).
- insert/delete at front is O(1), array needs to shift everything O(n).
- memory is allocated as needed with malloc.

## Disadvantages
- no random access, to reach the i-th node you walk from head - O(n).
- extra memory for the pointer in every node.
- not cache friendly, nodes scattered in memory.

## When to use
Use a linked list when the size keeps changing and you insert/delete a lot,
especially at the front. Use an array when you need fast index access a[i] or the
size is known and fixed.

## Complexity

| Operation            | Array | Singly LL | Doubly LL |
|----------------------|-------|-----------|-----------|
| Access i-th          | O(1)  | O(n)      | O(n)      |
| Search               | O(n)  | O(n)      | O(n)      |
| Insert at front      | O(n)  | O(1)      | O(1)      |
| Insert at end        | O(1)* | O(n)      | O(n)      |
| Delete at front      | O(n)  | O(1)      | O(1)      |
| Delete at end        | O(1)  | O(n)      | O(n)      |
| Delete given a node  | O(n)  | O(n)      | O(1)      |

\* array insert at end is O(1) only if there is spare capacity, else you reallocate.

Space is O(n) for all of them. Insert/delete at end becomes O(1) if a tail/rear
pointer is maintained (see the queue-using-linked-list program).
