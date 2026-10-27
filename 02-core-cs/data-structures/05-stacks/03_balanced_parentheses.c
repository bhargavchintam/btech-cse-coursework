// check whether brackets ()[]{} are balanced using stack
#include<stdio.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int match(char open, char close)
{
    if(open == '(' && close == ')')
        return 1;
    if(open == '[' && close == ']')
        return 1;
    if(open == '{' && close == '}')
        return 1;
    return 0;
}

int main()
{
    char exp[SIZE];
    int i;
    printf("Enter expression: ");
    scanf("%s", exp);
    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(top == -1 || !match(pop(), exp[i]))
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if(top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
