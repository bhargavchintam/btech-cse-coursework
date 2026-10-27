/* Bindu Bhargava   14-08-18 */
/* Lab Program 1
   Implement a stack of integers using an array. Support push, pop, peek and
   display operations with overflow and underflow checks. */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int x)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed\n", x);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped\n", stack[top--]);
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element = %d\n", stack[top]);
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter element: ");
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
