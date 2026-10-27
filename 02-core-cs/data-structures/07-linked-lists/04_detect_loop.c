// Floyd's cycle detection, slow and fast pointer
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int x)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    return p;
}

int detectLoop(struct node *head)
{
    struct node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}

int main()
{
    struct node *head = create(1);
    head->next = create(2);
    head->next->next = create(3);
    head->next->next->next = create(4);
    head->next->next->next->next = create(5);

    printf("list 1-2-3-4-5 : ");
    if(detectLoop(head))
        printf("loop found\n");
    else
        printf("no loop\n");

    // now link the last node (5) back to node 3 to make a loop
    head->next->next->next->next->next = head->next->next;

    printf("after linking 5 back to 3 : ");
    if(detectLoop(head))
        printf("loop found\n");
    else
        printf("no loop\n");

    return 0;
}
