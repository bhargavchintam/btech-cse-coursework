// even and odd parity bit for a binary string
#include<stdio.h>
#include<string.h>

int main()
{
    char b[33];
    int i, ones = 0;
    printf("Enter a binary number: ");
    scanf("%32s", b);
    for(i = 0; i < (int)strlen(b); i++)
        if(b[i] == '1')
            ones++;
    printf("Even parity bit = %d\n", ones % 2);
    printf("Odd parity bit  = %d\n", (ones % 2) ? 0 : 1);
    return 0;
}
