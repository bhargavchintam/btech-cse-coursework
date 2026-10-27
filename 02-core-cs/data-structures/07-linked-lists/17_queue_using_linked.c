// queue using linked list - front and rear pointers, enqueue is O(1)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(rear == NULL)
    {
        front = rear = p;
        return;
    }
    rear->next = p;
    rear = p;
}

void dequeue()
{
    if(front == NULL)
    {
        printf("queue empty\n");
        return;
    }
    struct node *t = front;
    printf("removed %d\n", t->data);
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(t);
}

void display()
{
    if(front == NULL)
    {
        printf("queue empty\n");
        return;
    }
    struct node *t = front;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int ch, x;
    while(1)
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
