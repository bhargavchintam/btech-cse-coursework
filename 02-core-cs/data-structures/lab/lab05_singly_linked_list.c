/* Lab Program 5
   Implement a singly linked list with insert, delete, search and display
   operations using a menu. */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *head = NULL;

void insert_begin(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insert_end(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = head;
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
}

void delete(int x)
{
    NODE *ptr = head, *prev = NULL;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL && ptr->data != x) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("%d not found\n", x);
        return;
    }
    if (prev == NULL)
        head = ptr->next;
    else
        prev->next = ptr->next;
    free(ptr);
    printf("%d deleted\n", x);
}

void search(int x)
{
    NODE *ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        if (ptr->data == x) {
            printf("%d found at position %d\n", x, pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("%d not found\n", x);
}

void display()
{
    NODE *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, x;
    while (1) {
        printf("\n1.Insert Begin  2.Insert End  3.Delete  4.Search  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert_begin(x);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insert_end(x);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                delete(x);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search(x);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
