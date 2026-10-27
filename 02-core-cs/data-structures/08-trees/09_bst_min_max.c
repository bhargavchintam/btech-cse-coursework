// find minimum and maximum in a BST
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int val) {
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node *root, int val) {
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int findmin(struct node *root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findmax(struct node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    int a[] = {45, 15, 79, 90, 10, 55, 12, 20};
    int n = 8, i;
    struct node *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Minimum = %d\n", findmin(root));
    printf("Maximum = %d\n", findmax(root));
    return 0;
}
