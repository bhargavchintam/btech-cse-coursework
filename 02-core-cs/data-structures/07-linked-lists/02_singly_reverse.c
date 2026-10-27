// reverse a singly linked list - iterative
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* insertEnd(struct node *head, int x)
{
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

struct node* reverse(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    int n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }
    printf("original: ");
    display(head);
    head = reverse(head);
    printf("reversed: ");
    display(head);
    return 0;
}
