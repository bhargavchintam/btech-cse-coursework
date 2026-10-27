// binary addition and subtraction (subtraction via 2's complement) on 8-bit values
#include<stdio.h>

int val(long b)
{
    int d = 0, base = 1, r;
    while(b > 0){ r = b % 10; d += r * base; base *= 2; b /= 10; }
    return d;
}

int main()
{
    long x, y;
    int a, b;
    printf("Enter two binary numbers: ");
    scanf("%ld %ld", &x, &y);
    a = val(x); b = val(y);
    printf("Sum = %d (decimal)\n", a + b);
    printf("Difference = %d (decimal)\n", a - b);
    return 0;
}
