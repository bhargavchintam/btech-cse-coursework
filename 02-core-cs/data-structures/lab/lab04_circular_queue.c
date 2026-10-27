/* Lab Program 4
   Implement a circular queue using arrays. Support insert, delete and display
   with proper full and empty checks. */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = -1, count = 0;

void insert(int x)
{
    if (count == SIZE)
    {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    count++;
    printf("%d inserted\n", x);
}

void delete()
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

void display()
{
    int i, idx;
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    idx = front;
    for (i = 0; i < count; i++)
    {
        printf("%d ", queue[idx]);
        idx = (idx + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
