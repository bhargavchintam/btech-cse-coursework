/* Lab Program 7
   Implement a circular linked list with insert, delete and display
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
    NODE *ptr = head;
    temp->data = x;
    if (head == NULL) {
        temp->next = temp;
        head = temp;
        return;
    }
    while (ptr->next != head)
        ptr = ptr->next;
    temp->next = head;
    ptr->next = temp;
    head = temp;
}

void insert_end(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = head;
    temp->data = x;
    if (head == NULL) {
        temp->next = temp;
        head = temp;
        return;
    }
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = temp;
    temp->next = head;
}

void delete(int x)
{
    NODE *ptr = head, *prev = NULL;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head && head->data == x) {
        free(head);
        head = NULL;
        printf("%d deleted\n", x);
        return;
    }
    while (ptr->data != x) {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == head) {
            printf("%d not found\n", x);
            return;
        }
    }
    if (ptr == head) {
        NODE *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
    } else {
        prev->next = ptr->next;
    }
    free(ptr);
    printf("%d deleted\n", x);
}

void display()
{
    NODE *ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

int main()
{
    int choice, x;
    while (1) {
        printf("\n1.Insert Begin  2.Insert End  3.Delete  4.Display  5.Exit\n");
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
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
