// spiral / zigzag level order traversal using two stacks
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

struct node {
    int data;
    struct node *left, *right;
};

struct node* newnode(int val) {
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void spiral(struct node *root) {
    if (root == NULL)
        return;
    struct node *s1[SIZE];
    struct node *s2[SIZE];
    int t1 = -1, t2 = -1;
    s1[++t1] = root;
    while (t1 != -1 || t2 != -1) {
        while (t1 != -1) {
            struct node *curr = s1[t1--];
            printf("%d ", curr->data);
            if (curr->left != NULL)
                s2[++t2] = curr->left;
            if (curr->right != NULL)
                s2[++t2] = curr->right;
        }
        while (t2 != -1) {
            struct node *curr = s2[t2--];
            printf("%d ", curr->data);
            if (curr->right != NULL)
                s1[++t1] = curr->right;
            if (curr->left != NULL)
                s1[++t1] = curr->left;
        }
    }
}

int main() {
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    printf("Spiral order: ");
    spiral(root);
    printf("\n");
    return 0;
}
