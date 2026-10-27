#include<stdio.h>

int main()
{
    int n, rev = 0, rem;
    printf("Enter the number : ");
    scanf("%d", &n);
    while(n != 0)
    {
        rem = n % 10;   // n%10 gives last digit
        rev = rev * 10 + rem;
        n = n / 10;
    }
    printf("Reverse = %d\n", rev);
    return 0;
}
