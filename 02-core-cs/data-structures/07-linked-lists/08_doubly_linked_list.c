/* Bindu Bhargava   18-09-18 */
// doubly linked list - insert/delete both ends, forward and backward display
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} NODE;

NODE *head = NULL;

NODE* create(int x) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertFront(int x) {
    NODE *p = create(x);
    if(head == NULL) {
        head = p;
        return;
    }
    p->next = head;
    head->prev = p;
    head = p;
}

void insertEnd(int x) {
    NODE *p = create(x);
    if(head == NULL) {
        head = p;
        return;
    }
    NODE *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    p->prev = t;
}

void deleteFront() {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    NODE *t = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(t);
}

void deleteEnd() {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    if(head->next == NULL) {        // only one node
        free(head);
        head = NULL;
        return;
    }
    NODE *t = head;
    while(t->next != NULL)
        t = t->next;
    t->prev->next = NULL;
    free(t);
}

void displayForward() {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    NODE *t = head;
    printf("forward : ");
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void displayBackward() {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    NODE *t = head;
    while(t->next != NULL)
        t = t->next;
    printf("backward: ");
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1.Insert Front  2.Insert End  3.Delete Front  4.Delete End  5.Display Forward  6.Display Backward  7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
