// binary to gray code
#include<stdio.h>
#include<string.h>

int main()
{
    char b[33], g[33];
    int i, n;
    printf("Enter a binary number: ");
    scanf("%32s", b);
    n = strlen(b);
    g[0] = b[0];   // MSB same
    for(i = 1; i < n; i++)
        g[i] = ((b[i-1] - '0') ^ (b[i] - '0')) + '0';
    g[n] = '\0';
    printf("Gray = %s\n", g);
    return 0;
}
