// evaluate a prefix expression, scan right to left, single digit operands
#include<stdio.h>
#include<string.h>
#define SIZE 100

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
    char exp[SIZE];
    int i, a, b, n;
    printf("Enter prefix expression: ");
    scanf("%s", exp);
    n = strlen(exp);
    for(i = n - 1; i >= 0; i--)
    {
        if(exp[i] >= '0' && exp[i] <= '9')
            push(exp[i] - '0');
        else
        {
            a = pop();
            b = pop();
            switch(exp[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
