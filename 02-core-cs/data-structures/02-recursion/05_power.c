#include<stdio.h>

long power(int x, int n)
{
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main()
{
    int x, n;
    printf("Enter base and exponent: ");
    scanf("%d %d", &x, &n);
    printf("%d^%d = %ld\n", x, n, power(x, n));
    return 0;
}
