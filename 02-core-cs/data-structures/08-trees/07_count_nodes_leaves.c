// count total nodes, leaf nodes and internal nodes
#include<stdio.h>
#include<stdlib.h>

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

int countnodes(NODE *root) {
    if (root == NULL)
        return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}

int countleaves(NODE *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countleaves(root->left) + countleaves(root->right);
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7, i;
    NODE *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    int total = countnodes(root);
    int leaves = countleaves(root);
    printf("Total nodes    = %d\n", total);
    printf("Leaf nodes     = %d\n", leaves);
    printf("Internal nodes = %d\n", total - leaves);
    return 0;
}
