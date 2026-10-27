// remove duplicates from an unsorted linked list
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

void removeDup(struct node *head) {
    struct node *p = head;
    while(p != NULL) {
        struct node *q = p;
        while(q->next != NULL) {
            if(q->next->data == p->data) {
                struct node *dup = q->next;
                q->next = q->next->next;
                free(dup);
            }
            else
                q = q->next;
        }
        p = p->next;
    }
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
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }
    printf("before: ");
    display(head);
    removeDup(head);
    printf("after : ");
    display(head);
    return 0;
}
