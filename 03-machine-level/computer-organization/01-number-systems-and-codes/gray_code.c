#include<stdio.h>
#include<string.h>

void pbin(unsigned v, int n)
{
    int i;
    for(i = n - 1; i >= 0; i--)
        printf("%d", (v >> i) & 1);
}

int main()
{
    int n, i;
    unsigned g;
    char s[40];

    printf("enter number of bits: ");
    scanf("%d", &n);

    printf("dec  binary  gray\n");
    for(i = 0; i < (1 << n); i++)
    {
        g = i ^ (i >> 1);    /* binary to gray is one xor */
        printf("%3d  ", i);
        pbin(i, n);
        printf("    ");
        pbin(g, n);
        printf("\n");
    }

    printf("enter a gray code to convert: ");
    scanf("%s", s);
    /* msb copies, then b(i) = b(i-1) xor g(i) */
    for(i = 1; s[i] != '\0'; i++)
        s[i] = ((s[i-1] - '0') ^ (s[i] - '0')) + '0';
    g = 0;
    for(i = 0; s[i] != '\0'; i++)
        g = g * 2 + (s[i] - '0');
    printf("binary = %s = %u\n", s, g);

    return 0;
}
