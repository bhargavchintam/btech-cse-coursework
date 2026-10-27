// 4-bit ripple up counter, prints the count sequence
#include<stdio.h>

int main()
{
    int i, b;
    printf("4-bit up count:\n");
    for(i = 0; i < 16; i++)
    {
        for(b = 3; b >= 0; b--)
            printf("%d", (i >> b) & 1);
        printf("  = %2d\n", i);
    }
    return 0;
}
