// reverse a number using recursion
#include<stdio.h>

int rev = 0;

int reverse(int n)
{
    if(n == 0)
        return rev;
    rev = rev * 10 + n % 10;
    return reverse(n / 10);
}

int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("Reverse = %d\n", reverse(n));
    return 0;
}
