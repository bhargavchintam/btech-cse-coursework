// linear queue using an array
#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
    printf("%d inserted\n", x);
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    front++;
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue : ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int ch, x;
    while (1)
    {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
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
