// level order traversal (BFS) using a queue
#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

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

void levelorder(struct node *root)
{
    if (root == NULL)
        return;
    struct node *queue[SIZE];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct node *curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left != NULL)
            queue[rear++] = curr->left;
        if (curr->right != NULL)
            queue[rear++] = curr->right;
    }
}

int main()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    printf("Level order: ");
    levelorder(root);
    printf("\n");
    return 0;
}
