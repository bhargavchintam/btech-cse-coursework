/* Lab Program 3
   Evaluate a postfix expression using a stack. Operands are single digits. */

#include<stdio.h>
#include<ctype.h>

int stack[100];
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
    char exp[100], c;
    int i, a, b, k, r;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        c = exp[i];
        if (isdigit(c)) {
            push(c - '0');
        }
        else {
            b = pop();
            a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^':
                    r = 1;
                    for (k = 0; k < b; k++)
                        r *= a;
                    push(r);
                    break;
            }
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
