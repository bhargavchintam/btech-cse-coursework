// check whether a binary tree is a valid BST
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newnode(int val)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int isBST(struct node *root, int min, int max)
{
    if (root == NULL)
        return 1;
    if (root->data <= min || root->data >= max)
        return 0;
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main()
{
    // a proper BST
    struct node *t1 = newnode(50);
    t1->left = newnode(30);
    t1->right = newnode(70);
    t1->left->left = newnode(20);
    t1->left->right = newnode(40);

    // not a BST - 65 sits in the left subtree of 50
    struct node *t2 = newnode(50);
    t2->left = newnode(30);
    t2->right = newnode(70);
    t2->left->left = newnode(20);
    t2->left->right = newnode(65);

    if (isBST(t1, INT_MIN, INT_MAX))
        printf("Tree 1 is a BST\n");
    else
        printf("Tree 1 is not a BST\n");

    if (isBST(t2, INT_MIN, INT_MAX))
        printf("Tree 2 is a BST\n");
    else
        printf("Tree 2 is not a BST\n");
    return 0;
}
