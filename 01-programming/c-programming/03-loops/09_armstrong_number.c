#include<stdio.h>

/* armstrong number check */
int main()
{
    int n, temp, rem, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while(temp > 0)
    {
        rem = temp % 10;
        sum = sum + rem * rem * rem;
        temp = temp / 10;
    }
    if(sum == n)
        printf("%d is an armstrong number\n", n);
    else
        printf("%d is not an armstrong number\n", n);
    return 0;
}
