// binary to decimal
#include<stdio.h>

int main()
{
    long bin;
    int dec = 0, rem, base = 1;
    printf("Enter a binary number: ");
    scanf("%ld", &bin);
    while(bin > 0)
    {
        rem = bin % 10;
        dec = dec + rem * base;
        base = base * 2;
        bin = bin / 10;
    }
    printf("Decimal = %d\n", dec);
    return 0;
}
