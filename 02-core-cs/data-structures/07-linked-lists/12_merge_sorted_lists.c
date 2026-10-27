// merge two sorted linked lists into one sorted list
// O(m+n)
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertEnd(struct node *head, int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(head == NULL)
        return p;
    struct node *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    return head;
}

struct node* merge(struct node *a, struct node *b) {
    struct node dummy;
    struct node *tail = &dummy;
    dummy.next = NULL;
    while(a != NULL && b != NULL) {
        if(a->data <= b->data) {
            tail->next = a;
            a = a->next;
        }
        else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if(a != NULL)
        tail->next = a;
    else
        tail->next = b;
    return dummy.next;
}

void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *a = NULL, *b = NULL;
    int n, m, i, x;
    printf("Enter size of first sorted list: ");
    scanf("%d", &n);
    printf("enter %d elements in sorted order\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        a = insertEnd(a, x);
    }
    printf("Enter size of second sorted list: ");
    scanf("%d", &m);
    printf("enter %d elements in sorted order\n", m);
    for(i = 0; i < m; i++) {
        scanf("%d", &x);
        b = insertEnd(b, x);
    }
    struct node *c = merge(a, b);
    printf("merged: ");
    display(c);
    return 0;
}
