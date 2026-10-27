/* Bindu Bhargava  14-08-18 */
#include<stdio.h>
#include<string.h>

void convert(unsigned n, int base)
{
    int r[40], i = 0;
    if(n == 0)
    {
        printf("0");
        return;
    }
    while(n > 0)
    {
        r[i++] = n % base;
        n = n / base;
    }
    /* remainders come out in reverse order */
    for(i = i - 1; i >= 0; i--)
    {
        if(r[i] < 10)
            printf("%d", r[i]);
        else
            printf("%c", 'A' + r[i] - 10);
    }
}

int main()
{
    unsigned n, d;
    char s[40];
    int i;

    printf("enter a decimal number: ");
    scanf("%u", &n);

    printf("binary : ");
    convert(n, 2);
    printf("\noctal  : ");
    convert(n, 8);
    printf("\nhex    : ");
    convert(n, 16);
    printf("\ncross check with printf: %o %X\n", n, n);

    printf("enter a binary string: ");
    scanf("%s", s);
    d = 0;
    for(i = 0; s[i] != '\0'; i++)
        d = d * 2 + (s[i] - '0');
    printf("%s in decimal = %u\n", s, d);

    return 0;
}
