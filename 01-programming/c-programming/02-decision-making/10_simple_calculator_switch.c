#include<stdio.h>
int main()
{
    char op;
    float a, b;
    printf("Enter an operator (+ - * /): ");
    scanf("%c", &op);
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);
    switch(op)
    {
        case '+':
            printf("%f\n", a + b);
            break;
        case '-':
            printf("%f\n", a - b);
            break;
        case '*':
            printf("%f\n", a * b);
            break;
        case '/':
            printf("%f\n", a / b);
            break;
        default:
            printf("Invalid operator\n");
    }
    return 0;
}
