// two stacks in one array growing toward each other
#include<stdio.h>
#define SIZE 10

int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int x)
{
    if(top1 + 1 == top2)
    {
        printf("Stack Full\n");
        return;
    }
    arr[++top1] = x;
}

void push2(int x)
{
    if(top1 + 1 == top2)
    {
        printf("Stack Full\n");
        return;
    }
    arr[--top2] = x;
}

void pop1()
{
    if(top1 == -1)
    {
        printf("Stack1 Empty\n");
        return;
    }
    printf("Popped from stack1: %d\n", arr[top1--]);
}

void pop2()
{
    if(top2 == SIZE)
    {
        printf("Stack2 Empty\n");
        return;
    }
    printf("Popped from stack2: %d\n", arr[top2++]);
}

void display()
{
    int i;
    printf("Stack1: ");
    for(i = 0; i <= top1; i++)
        printf("%d ", arr[i]);
    printf("\nStack2: ");
    for(i = SIZE - 1; i >= top2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int ch, x;
    while(1)
    {
        printf("\n1.Push1  2.Push2  3.Pop1  4.Pop2  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push1(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                push2(x);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
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
