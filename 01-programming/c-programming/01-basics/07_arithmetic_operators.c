#include<stdio.h>
int main()
{
    int a, b;
    printf("enter a and b\n");
    scanf("%d %d", &a, &b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);   // integer division
    printf("a %% b = %d\n", a % b);
    return 0;
}
