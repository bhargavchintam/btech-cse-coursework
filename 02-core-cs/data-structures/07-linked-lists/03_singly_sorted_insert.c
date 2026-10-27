// keep a singly linked list sorted while inserting
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* sortedInsert(struct node *head, int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(head == NULL || x < head->data) {
        p->next = head;
        return p;
    }
    struct node *t = head;
    while(t->next != NULL && t->next->data < x)
        t = t->next;
    p->next = t->next;
    t->next = p;
    return head;
}

void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements in any order\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        head = sortedInsert(head, x);
    }
    printf("sorted list: ");
    display(head);
    return 0;
}
