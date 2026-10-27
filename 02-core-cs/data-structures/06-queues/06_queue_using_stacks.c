// queue implemented with two stacks
#include<stdio.h>
#define SIZE 100

int s1[SIZE], s2[SIZE];
int top1 = -1, top2 = -1;

void push1(int x) { s1[++top1] = x; }
void push2(int x) { s2[++top2] = x; }
int pop1() { return s1[top1--]; }
int pop2() { return s2[top2--]; }

void enqueue(int x)
{
    push1(x);
    printf("%d inserted\n", x);
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    if (top2 == -1)
    {
        while (top1 != -1)
            push2(pop1());
        //printf("moved s1 to s2\n");
    }
    printf("%d deleted\n", pop2());
}

void display()
{
    int i;
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue : ");
    for (i = top2; i >= 0; i--)
        printf("%d ", s2[i]);
    for (i = 0; i <= top1; i++)
        printf("%d ", s1[i]);
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
