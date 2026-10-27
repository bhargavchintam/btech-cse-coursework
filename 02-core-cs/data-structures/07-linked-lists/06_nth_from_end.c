// find nth node from the end using two pointers
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
    int n, i, x, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }
    display(head);
    printf("Enter k: ");
    scanf("%d", &k);

    struct node *first = head, *second = head;
    for(i = 0; i < k; i++)
    {
        if(first == NULL)
        {
            printf("k is larger than the list\n");
            return 0;
        }
        first = first->next;
    }
    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    printf("%d node from end = %d\n", k, second->data);
    return 0;
}
