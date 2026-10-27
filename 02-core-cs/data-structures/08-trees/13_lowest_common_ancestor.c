// lowest common ancestor in a BST
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

struct node* lca(struct node *root, int a, int b) {
    while (root != NULL) {
        if (a < root->data && b < root->data)
            root = root->left;
        else if (a > root->data && b > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7, i;
    struct node *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("LCA of 20 and 40 = %d\n", lca(root, 20, 40)->data);
    printf("LCA of 20 and 80 = %d\n", lca(root, 20, 80)->data);
    printf("LCA of 60 and 80 = %d\n", lca(root, 60, 80)->data);
    return 0;
}
