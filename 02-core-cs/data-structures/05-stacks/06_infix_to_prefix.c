// infix to prefix - reverse the string, convert like postfix, reverse again
#include<stdio.h>
#include<ctype.h>
#include<string.h>
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

int prec(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[SIZE], rev[SIZE], prefix[SIZE];
    int i, k = 0, n;
    char c;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    n = strlen(infix);

    // reverse and swap the brackets
    for(i = 0; i < n; i++)
    {
        c = infix[n - 1 - i];
        if(c == '(')
            c = ')';
        else if(c == ')')
            c = '(';
        rev[i] = c;
    }
    rev[n] = '\0';

    for(i = 0; rev[i] != '\0'; i++)
    {
        c = rev[i];
        if(isalnum(c))
            prefix[k++] = c;
        else if(c == '(')
            push(c);
        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                prefix[k++] = pop();
            pop();
        }
        else
        {
            while(top != -1 && prec(stack[top]) > prec(c))
                prefix[k++] = pop();
            push(c);
        }
    }
    while(top != -1)
        prefix[k++] = pop();
    prefix[k] = '\0';

    printf("Prefix: ");
    for(i = k - 1; i >= 0; i--)
        printf("%c", prefix[i]);
    printf("\n");
    return 0;
}
