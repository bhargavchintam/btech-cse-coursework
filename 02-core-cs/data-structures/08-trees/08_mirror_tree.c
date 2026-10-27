// mirror a binary tree - swap left and right at every node
#include<stdio.h>
#include<stdlib.h>

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

void mirror(struct node *root)
{
    if (root == NULL)
        return;
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
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
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printf("Inorder before mirror: ");
    inorder(root);
    mirror(root);
    printf("\nInorder after mirror : ");
    inorder(root);
    printf("\n");
    return 0;
}
