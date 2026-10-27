// 4-bit johnson counter sequence
#include<stdio.h>

int main()
{
    int q[4] = {0,0,0,0};
    int i, k, in;
    printf("Johnson counter (4-bit):\n");
    for(i = 0; i < 8; i++)
    {
        for(k = 0; k < 4; k++)
            printf("%d", q[k]);
        printf("\n");
        in = !q[3];              // inverted last bit feeds back
        for(k = 3; k > 0; k--)
            q[k] = q[k-1];
        q[0] = in;
    }
    return 0;
}
