#include<stdio.h>

int sumdig(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumdig(n / 10);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of digits = %d\n", sumdig(n));
    return 0;
}
