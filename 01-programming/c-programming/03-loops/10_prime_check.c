#include<stdio.h>

int main()
{
    int i, n, flag = 1;   // flag stays 1 if prime
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1 && n > 1)
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    return 0;
}
