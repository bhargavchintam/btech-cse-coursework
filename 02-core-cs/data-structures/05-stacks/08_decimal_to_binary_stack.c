// decimal to binary using a stack of remainders
#include<stdio.h>
#define SIZE 32

int stack[SIZE];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if(n == 0)
    {
        printf("Binary: 0\n");
        return 0;
    }
    while(n > 0)
    {
        push(n % 2);
        n = n / 2;
    }
    printf("Binary: ");
    while(top != -1)
        printf("%d", pop());
    printf("\n");
    return 0;
}
