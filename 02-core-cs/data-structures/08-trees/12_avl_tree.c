/* Bindu Bhargava   04-10-18 */
// AVL tree - self balancing bst with LL, RR, LR, RL rotations
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int height;
    struct node *left, *right;
};

int height(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

struct node* create(int val)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}

struct node* rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct node* leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int balance(struct node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct node* insert(struct node *root, int val)
{
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int b = balance(root);

    if (b > 1 && val < root->left->data)          // LL
        return rightrotate(root);
    if (b < -1 && val > root->right->data)         // RR
        return leftrotate(root);
    if (b > 1 && val > root->left->data) {         // LR
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (b < -1 && val < root->right->data) {       // RL
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 25};
    int n = 6, i;
    struct node *root = NULL;
    for (i = 0; i < n; i++) {
        root = insert(root, a[i]);
        printf("Inserted %d -> root %d | inorder: ", a[i], root->data);
        inorder(root);
        printf("\n");
    }
    return 0;
}
