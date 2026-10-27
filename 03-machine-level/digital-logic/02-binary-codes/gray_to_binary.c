// gray code to binary
#include<stdio.h>
#include<string.h>

int main()
{
    char g[33], b[33];
    int i, n;
    printf("Enter a gray code: ");
    scanf("%32s", g);
    n = strlen(g);
    b[0] = g[0];
    for(i = 1; i < n; i++)
        b[i] = ((b[i-1] - '0') ^ (g[i] - '0')) + '0';
    b[n] = '\0';
    printf("Binary = %s\n", b);
    return 0;
}
