// reverse a string using a stack
#include<stdio.h>
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

int main()
{
    char str[SIZE];
    int i, n;
    printf("Enter a string: ");
    scanf("%s", str);
    n = strlen(str);
    for(i = 0; i < n; i++)
        push(str[i]);
    printf("Reversed: ");
    while(top != -1)
        printf("%c", pop());
    printf("\n");
    return 0;
}
