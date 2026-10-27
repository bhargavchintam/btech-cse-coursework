/* Bindu Bhargava   20-09-18 */
/* binary search tree - menu driven */
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int val)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node *root, int val)
{
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

struct node* findmin(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* findmax(struct node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node* delete(struct node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val < root->data)
        root->left = delete(root->left, val);
    else if (val > root->data)
        root->right = delete(root->right, val);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // two children - copy inorder successor then delete it
        struct node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int search(struct node *root, int val)
{
    if (root == NULL)
        return 0;
    if (val == root->data)
        return 1;
    if (val < root->data)
        return search(root->left, val);
    return search(root->right, val);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;
    int ch, val;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Search  4.Inorder  5.Preorder  6.Postorder  7.Min  8.Max  9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("%d found\n", val);
                else
                    printf("%d not found\n", val);
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                    printf("Minimum = %d\n", findmin(root)->data);
                break;
            case 8:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                    printf("Maximum = %d\n", findmax(root)->data);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
