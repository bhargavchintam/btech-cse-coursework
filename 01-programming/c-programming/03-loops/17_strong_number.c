#include<stdio.h>

/* strong number - sum of factorial of digits */
int main()
{
    int n, temp, rem, i, sum = 0;
    long int fact;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while(temp > 0)
    {
        rem = temp % 10;
        fact = 1;
        for(i = 1; i <= rem; i++)
            fact = fact * i;
        sum = sum + fact;
        temp = temp / 10;
    }
    if(sum == n)
        printf("%d is a strong number\n", n);
    else
        printf("%d is not a strong number\n", n);
    return 0;
}
