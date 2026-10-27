# Trees

A tree is a set of nodes with one root and no cycles. Each node points to its children.
Binary tree = at most two children per node (left and right).

## Binary tree vs BST
Plain binary tree has no ordering rule. A **binary search tree** keeps, for every node:
left subtree < node < right subtree. That ordering is what makes search O(height).

## Traversals
Depth first (recursive, one line each):
- inorder   = left, root, right   → for a BST this prints the keys in sorted order
- preorder  = root, left, right   → used to copy/serialize a tree
- postorder = left, right, root   → used to delete/free a tree, and to evaluate expression trees

Breadth first:
- level order = visit level by level, uses a queue

> Inorder of a BST comes out sorted. If it doesn't, it isn't a BST — that's how `check_bst` works.

## Height
Height of a node = longest path down to a leaf. Empty tree height = -1 (or 0 if you count nodes,
be consistent). `height(node) = 1 + max(height(left), height(right))`.

## BST insertion
Go left if the key is smaller, right if larger, insert at the NULL spot. O(h).

## BST deletion — the three cases
This is the one everyone gets wrong. To delete a node:
1. leaf → just free it, set parent's link to NULL
2. one child → link the parent straight to that child, free the node
3. two children → find the **inorder successor** (smallest key in the right subtree),
   copy its value into this node, then delete the successor (which has at most one child)

Missing case 3 is the classic bug — the tree loses half its nodes. Tested mine on deleting the root.

## AVL tree
A BST that keeps itself balanced. Balance factor = height(left) - height(right), must stay in
{-1, 0, +1}. When an insert breaks it, one of four rotations fixes it:
- LL → single right rotation
- RR → single left rotation
- LR → left then right
- RL → right then left

Balanced height stays O(log n), so search/insert/delete stay O(log n) worst case.

## Expression tree
Leaves are operands, internal nodes are operators. Build it from a postfix expression using a stack
of subtrees. Inorder gives the infix form, postorder evaluates it.

## Complexity

| Operation | BST (avg) | BST (worst, skewed) | AVL |
|---|---|---|---|
| search | O(log n) | O(n) | O(log n) |
| insert | O(log n) | O(n) | O(log n) |
| delete | O(log n) | O(n) | O(log n) |
| traversal | O(n) | O(n) | O(n) |

A skewed BST (inserting already-sorted data) degrades to a linked list — that's the whole reason AVL exists.
