// reverse a doubly linked list by swapping prev and next of each node
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* insertEnd(struct node *head, int x)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    if(head == NULL)
        return p;
    struct node *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    p->prev = t;
    return head;
}

struct node* reverse(struct node *head)
{
    struct node *curr = head, *temp = NULL;
    while(curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp != NULL)
        head = temp->prev;
    return head;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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
