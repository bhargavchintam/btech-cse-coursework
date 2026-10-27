// iterative inorder and preorder using an explicit stack
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;

NODE* create(int val) {
    NODE *n = malloc(sizeof(NODE));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

NODE* insert(NODE *root, int val) {
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(NODE *root) {
    NODE *stack[SIZE];
    int top = -1;
    NODE *curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorder(NODE *root) {
    if (root == NULL)
        return;
    NODE *stack[SIZE];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        NODE *curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->right != NULL)
            stack[++top] = curr->right;
        if (curr->left != NULL)
            stack[++top] = curr->left;
    }
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7, i;
    NODE *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Inorder (iterative)  : ");
    inorder(root);
    printf("\nPreorder (iterative) : ");
    preorder(root);
    printf("\n");
    return 0;
}
