// circular singly linked list - insert, delete, display
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertFront(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    if(head == NULL) {
        p->next = p;
        head = p;
        return;
    }
    struct node *t = head;
    while(t->next != head)
        t = t->next;
    p->next = head;
    t->next = p;
    head = p;
}

void insertEnd(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    if(head == NULL) {
        p->next = p;
        head = p;
        return;
    }
    struct node *t = head;
    while(t->next != head)
        t = t->next;
    t->next = p;
    p->next = head;
}

void deleteVal(int x) {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    if(head->next == head) {            // single node
        if(head->data == x) {
            free(head);
            head = NULL;
        }
        else
            printf("%d not found\n", x);
        return;
    }
    if(head->data == x) {              // deleting head
        struct node *last = head;
        while(last->next != head)
            last = last->next;
        struct node *tmp = head;
        head = head->next;
        last->next = head;
        free(tmp);
        return;
    }
    struct node *prev = head, *t = head->next;
    while(t != head && t->data != x) {
        prev = t;
        t = t->next;
    }
    if(t == head) {
        printf("%d not found\n", x);
        return;
    }
    prev->next = t->next;
    free(t);
}

void display() {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    struct node *t = head;
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while(t != head);
    printf("(back to head)\n");
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1.Insert Front  2.Insert End  3.Delete  4.Display  5.Exit\n");
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
                printf("Enter value to delete: ");
                scanf("%d", &x);
                deleteVal(x);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
