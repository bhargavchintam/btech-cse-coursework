// diameter of a binary tree - longest path between two nodes (in nodes)
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;

NODE* newnode(int val) {
    NODE *n = malloc(sizeof(NODE));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int height(NODE *root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int diameter(NODE *root) {
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int through = lh + rh + 1;
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int best = ld > rd ? ld : rd;
    return through > best ? through : best;
}

int main() {
    NODE *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printf("Diameter = %d\n", diameter(root));
    return 0;
}
