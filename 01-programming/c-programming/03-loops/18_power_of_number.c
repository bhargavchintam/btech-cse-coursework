#include<stdio.h>

// a raised to power b without using pow
int main()
{
    int a, b, i;
    long int result = 1;
    printf("Enter base and exponent: ");
    scanf("%d %d", &a, &b);
    for(i = 1; i <= b; i++)
    {
        result = result * a;
    }
    printf("%d ^ %d = %ld\n", a, b, result);
    return 0;
}
