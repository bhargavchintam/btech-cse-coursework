// recursive inorder, preorder, postorder
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

// left, root, right
void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// root, left, right
void preorder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// left, right, root
void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7, i;
    struct node *root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, a[i]);

    printf("Inorder   : ");
    inorder(root);
    printf("\nPreorder  : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
    printf("\n");
    return 0;
}
