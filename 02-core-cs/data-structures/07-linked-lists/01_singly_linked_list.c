// singly linked list - insert, delete, search, display, count
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    return p;
}

void insertFront(int x) {
    struct node *p = create(x);
    p->next = head;
    head = p;
}

void insertEnd(int x) {
    struct node *p = create(x);
    if(head == NULL) {
        head = p;
        return;
    }
    struct node *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
}

void insertPos(int x, int pos) {
    if(pos <= 1) {
        insertFront(x);
        return;
    }
    struct node *t = head;
    int i;
    for(i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;
    if(t == NULL) {
        printf("position not valid\n");
        return;
    }
    struct node *p = create(x);
    p->next = t->next;
    t->next = p;
}

void deleteVal(int x) {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    struct node *t = head, *prev = NULL;
    if(head->data == x) {           // deleting head
        head = head->next;
        free(t);
        return;
    }
    while(t != NULL && t->data != x) {
        prev = t;
        t = t->next;
    }
    if(t == NULL) {
        printf("%d not found\n", x);
        return;
    }
    prev->next = t->next;
    free(t);
}

int search(int x) {
    struct node *t = head;
    int pos = 1;
    while(t != NULL) {
        if(t->data == x)
            return pos;
        t = t->next;
        pos++;
    }
    return 0;
}

int count() {
    int c = 0;
    struct node *t = head;
    while(t != NULL) {
        c++;
        t = t->next;
    }
    return c;
}

void display() {
    if(head == NULL) {
        printf("list empty\n");
        return;
    }
    struct node *t = head;
    while(t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, x, pos;
    while(1) {
        printf("\n1.Insert Front  2.Insert End  3.Insert at Pos  4.Delete  5.Search  6.Display  7.Count  8.Exit\n");
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
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                insertPos(x, pos);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                deleteVal(x);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &x);
                pos = search(x);
                if(pos)
                    printf("found at position %d\n", pos);
                else
                    printf("not found\n");
                break;
            case 6:
                display();
                break;
            case 7:
                printf("count = %d\n", count());
                break;
            case 8:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
