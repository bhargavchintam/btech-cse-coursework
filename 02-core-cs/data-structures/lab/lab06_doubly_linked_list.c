/* Lab Program 6
   Implement a doubly linked list. Support insertion, deletion and display in
   both forward and reverse directions. */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;

NODE *head = NULL;

void insert_begin(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    head = temp;
}

void insert_end(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = head;
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
}

void delete(int x)
{
    NODE *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL && ptr->data != x)
        ptr = ptr->next;
    if (ptr == NULL) {
        printf("%d not found\n", x);
        return;
    }
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        head = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    free(ptr);
    printf("%d deleted\n", x);
}

void display_forward()
{
    NODE *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Forward: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void display_reverse()
{
    NODE *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr->next != NULL)
        ptr = ptr->next;
    printf("Reverse: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1) {
        printf("\n1.Insert Begin  2.Insert End  3.Delete  4.Display Forward  5.Display Reverse  6.Exit\n");
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
                display_forward();
                break;
            case 5:
                display_reverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
