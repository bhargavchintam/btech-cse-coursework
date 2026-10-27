#include<stdio.h>

int square(int n);

int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    printf("Square = %d\n", square(n));
    return 0;
}

int square(int n)
{
    return n * n;
}
