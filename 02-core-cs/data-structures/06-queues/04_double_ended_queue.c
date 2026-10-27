// double ended queue (deque) on a circular array
#include<stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty()
{
    return front == -1;
}

void insertFront(int x)
{
    if (isFull())
    {
        printf("Deque is full\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = SIZE - 1;
    else
        front = front - 1;
    deque[front] = x;
    printf("%d inserted at front\n", x);
}

void insertRear(int x)
{
    if (isFull())
    {
        printf("Deque is full\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else if (rear == SIZE - 1)
        rear = 0;
    else
        rear = rear + 1;
    deque[rear] = x;
    printf("%d inserted at rear\n", x);
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("%d deleted from front\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else if (front == SIZE - 1)
        front = 0;
    else
        front = front + 1;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("%d deleted from rear\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = SIZE - 1;
    else
        rear = rear - 1;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque : ");
    i = front;
    while (1)
    {
        printf("%d ", deque[i]);
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
        printf("\n1.Insert front  2.Insert rear  3.Delete front  4.Delete rear  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
