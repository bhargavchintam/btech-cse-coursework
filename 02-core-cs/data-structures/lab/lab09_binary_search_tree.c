/* Lab Program 9
   Implement a binary search tree. Support insert, delete (all three cases),
   search and inorder, preorder, postorder traversals using a menu. */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;

NODE *root = NULL;

NODE *create(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

NODE *insert(NODE *root, int x)
{
    if (root == NULL)
        return create(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

NODE *findmin(NODE *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

NODE *delete(NODE *root, int x)
{
    if (root == NULL)
    {
        printf("%d not found\n", x);
        return NULL;
    }
    if (x < root->data)
        root->left = delete(root->left, x);
    else if (x > root->data)
        root->right = delete(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        NODE *temp = findmin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void search(NODE *root, int x)
{
    while (root != NULL)
    {
        if (x == root->data)
        {
            printf("%d found\n", x);
            return;
        }
        if (x < root->data)
            root = root->left;
        else
            root = root->right;
    }
    printf("%d not found\n", x);
}

// inorder = left, root, right
void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Insert  2.Delete  3.Search  4.Inorder  5.Preorder  6.Postorder  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = delete(root, x);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search(root, x);
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            case 5:
                preorder(root);
                printf("\n");
                break;
            case 6:
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
