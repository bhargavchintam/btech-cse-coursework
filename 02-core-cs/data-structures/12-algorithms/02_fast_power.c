// x^n by divide and conquer
// O(log n)
#include<stdio.h>

long long power(long long x, int n)
{
    if(n == 0)
        return 1;
    long long half = power(x, n / 2);
    if(n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

int main()
{
    long long x;
    int n;
    printf("Enter base and exponent: ");
    scanf("%lld %d", &x, &n);
    printf("%lld^%d = %lld\n", x, n, power(x, n));
    return 0;
}
