// Josephus problem using a circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, k, i;
    printf("Enter number of people: ");
    scanf("%d", &n);
    printf("Enter k (every k-th is eliminated): ");
    scanf("%d", &k);

    struct node *head = NULL, *last = NULL;
    for(i = 1; i <= n; i++)
    {
        struct node *p = malloc(sizeof(struct node));
        p->data = i;
        p->next = NULL;
        if(head == NULL)
            head = last = p;
        else
        {
            last->next = p;
            last = p;
        }
    }
    last->next = head;          // close the circle

    struct node *curr = head, *prev = last;
    while(curr->next != curr)
    {
        for(i = 1; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        printf("eliminated %d\n", curr->data);
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    printf("survivor is %d\n", curr->data);
    free(curr);
    return 0;
}
