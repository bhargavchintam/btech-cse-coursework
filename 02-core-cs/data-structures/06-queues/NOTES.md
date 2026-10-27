# Queues

A queue is a linear list where you insert at one end (the rear) and delete from
the other end (the front). FIFO — First In First Out. The first one to join the
line is the first one served. Opposite of a stack.

> "A stack is unfair, a queue is fair" — is how the lecturer explained it.

Two main operations:
- enqueue(x) — add x at the rear
- dequeue()  — remove the element at the front

Plus peek/front (look at the front without removing), isEmpty, isFull.

## The problem with a linear array queue
Take an array of SIZE and two indices, front and rear. enqueue does rear++,
dequeue does front++. Looks fine, but after a few inserts and deletes rear
reaches SIZE-1 and enqueue says "queue full" — even though the slots before
front are now empty. The space is there but we can't reach it. This is the
false-full (false overflow) problem. A linear queue throws away the freed slots.

## Circular queue — the fix
Treat the array as a ring: after the last index, wrap back to 0.

    rear = (rear + 1) % SIZE;
    front = (front + 1) % SIZE;

Now the freed front slots get reused. Full is tested as

    if ((rear + 1) % SIZE == front)

i.e. rear has come right behind front. I keep front = rear = -1 to mean empty,
and reset both to -1 after removing the last element so empty and full never
look the same. Got this wrong in the lab first time — used rear == SIZE-1 for
full and wasted half the array.

## Deque (double ended queue)
Insertion and deletion allowed at BOTH ends: insertFront, insertRear,
deleteFront, deleteRear. A plain queue and a stack are both special cases of a
deque. Built on a circular array so both ends wrap.

## Priority queue
Every element carries a priority. dequeue does NOT return the oldest element, it
returns the one with the highest priority. Two ways to do it: keep the array
unsorted and scan for the max when deleting, or keep the list sorted on insert
so the front is always the highest priority (the linked version).

## Complexity

| Operation         | Linear / Circular queue | Priority (unsorted) | Priority (sorted list) |
|-------------------|-------------------------|---------------------|------------------------|
| enqueue / insert  | O(1)                    | O(1)                | O(n)                   |
| dequeue / delete  | O(1)                    | O(n)                | O(1)                   |
| peek front        | O(1)                    | O(n)                | O(1)                   |
| search            | O(n)                    | O(n)                | O(n)                   |

Linked queue keeps both front and rear pointers, so enqueue and dequeue stay
O(1). Space is O(n) either way.

## Applications
- CPU and printer job scheduling
- BFS on a graph uses a queue
- Circular buffers (keyboard buffer, streaming data)
- Josephus problem — n people in a circle, every k-th eliminated (see 09)
