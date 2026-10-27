/* Lab Program 6
   Check whether a number is prime, and whether it is a palindrome.
   gcc lab06_prime_and_palindrome.c -o lab06  */

#include<stdio.h>

int main()
{
    int n, i, temp, rev = 0, r, flag = 1;
    printf("Enter a number : ");
    scanf("%d", &n);

    for(i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1 && n > 1)      // flag stays 1 if prime
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);

    temp = n;
    while(temp > 0)
    {
        r = temp % 10;
        rev = rev * 10 + r;
        temp = temp / 10;
    }
    if(rev == n)
        printf("%d is a palindrome\n", n);
    else
        printf("%d is not a palindrome\n", n);
    return 0;
}
