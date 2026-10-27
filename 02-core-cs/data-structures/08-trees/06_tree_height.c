// height of a binary tree (number of levels)
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

int height(struct node *root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60};
    int n = 6, i;
    struct node *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Height of tree = %d\n", height(root));
    return 0;
}
