// evaluate a postfix expression, operands are single digits
#include<stdio.h>
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
    int i, a, b;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] >= '0' && exp[i] <= '9')
            push(exp[i] - '0');
        else
        {
            b = pop();
            a = pop();
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
