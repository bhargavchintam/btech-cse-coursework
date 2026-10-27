// 4 to 1 multiplexer
#include<stdio.h>

int main()
{
    int d[4], s0, s1, sel, y;
    printf("Enter 4 inputs I0 I1 I2 I3: ");
    scanf("%d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
    printf("Enter select lines s1 s0: ");
    scanf("%d %d", &s1, &s0);
    sel = s1 * 2 + s0;
    y = d[sel];
    printf("Y = %d\n", y);
    return 0;
}
