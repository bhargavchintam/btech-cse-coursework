/* Bindu Bhargava   18-09-18 */
// infix to postfix conversion
#include<stdio.h>
#include<ctype.h>
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
    char infix[SIZE], postfix[SIZE];
    int i, k = 0;
    char c;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    for(i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];
        if(isalnum(c))
            postfix[k++] = c;
        else if(c == '(')
            push(c);
        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();   // remove the (
        }
        else
        {
            while(top != -1 && prec(stack[top]) >= prec(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while(top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
    return 0;
}
