/* Lab Program 10
   Construct a binary search tree and display its inorder, preorder, postorder
   and level order traversals. */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *insert(NODE *root, int x)
{
    if (root == NULL) {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = x;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void inorder(NODE *root)
{
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelorder(NODE *root)
{
    NODE *queue[100];
    int front = 0, rear = 0;
    if (root == NULL)
        return;
    queue[rear++] = root;
    while (front < rear) {
        NODE *ptr = queue[front++];
        printf("%d ", ptr->data);
        if (ptr->left)
            queue[rear++] = ptr->left;
        if (ptr->right)
            queue[rear++] = ptr->right;
    }
}

int main()
{
    NODE *root = NULL;
    int n, i, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nLevel order: ");
    levelorder(root);
    printf("\n");
    return 0;
}
