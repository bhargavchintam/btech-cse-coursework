// bst deletion - leaf, one child, two children (inorder successor)
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int val)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node *root, int val)
{
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

struct node* findmin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* delete(struct node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val < root->data)
        root->left = delete(root->left, val);
    else if (val > root->data)
        root->right = delete(root->right, val);
    else {
        // no child or one child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // two children - smallest node in right subtree replaces this one
        struct node *succ = findmin(root->right);
        root->data = succ->data;
        root->right = delete(root->right, succ->data);
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
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7, i;
    struct node *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Inorder            : ");
    inorder(root);

    root = delete(root, 20);
    printf("\nAfter deleting 20  : ");
    inorder(root);

    root = delete(root, 30);
    printf("\nAfter deleting 30  : ");
    inorder(root);

    root = delete(root, 50);
    printf("\nAfter deleting 50  : ");
    inorder(root);
    printf("\n");
    return 0;
}
