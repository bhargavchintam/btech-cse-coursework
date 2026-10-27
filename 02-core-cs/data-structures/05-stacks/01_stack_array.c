// stack using array - push, pop, peek, display
#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int x)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = x;
    printf("%d pushed\n", x);
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped\n", stack[top]);
    top--;
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element = %d\n", stack[top]);
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    //printf("top=%d\n", top);
    printf("Stack: ");
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int ch, x;
    while(1)
    {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
