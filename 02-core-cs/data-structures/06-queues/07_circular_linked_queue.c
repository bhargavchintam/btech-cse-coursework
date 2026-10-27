// circular linked queue - keep only rear, rear->next is the front
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *rear = NULL;

void enqueue(int x)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = x;
    if (rear == NULL)
    {
        rear = temp;
        rear->next = rear;
    }
    else
    {
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
    printf("%d inserted\n", x);
}

void dequeue()
{
    NODE *front;
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    front = rear->next;
    printf("%d deleted\n", front->data);
    if (front == rear)
        rear = NULL;
    else
        rear->next = front->next;
    free(front);
}

void display()
{
    NODE *ptr;
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    ptr = rear->next;
    printf("Queue : ");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != rear->next);
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter element: ");
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
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
