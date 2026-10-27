#include<stdio.h>

/* count number of digits in a number */
int main()
{
    int n, count = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    do
    {
        count++;
        n = n / 10;
    } while(n != 0);
    printf("Number of digits = %d\n", count);
    return 0;
}
