// circular queue using an array
#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue : ");
    i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
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
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
