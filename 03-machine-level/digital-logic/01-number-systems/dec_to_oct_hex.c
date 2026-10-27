// decimal to octal and hex using printf format specifiers
#include<stdio.h>

int main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Octal = %o\n", n);
    printf("Hex   = %X\n", n);
    return 0;
}
