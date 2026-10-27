// truth tables of the basic gates
#include<stdio.h>

int main()
{
    int a, b;
    printf("a b | AND OR NAND NOR XOR XNOR\n");
    for(a = 0; a <= 1; a++)
        for(b = 0; b <= 1; b++)
            printf("%d %d |  %d  %d   %d    %d   %d    %d\n",
                   a, b, a&b, a|b, !(a&b), !(a|b), a^b, !(a^b));
    printf("\nNOT: a=0 -> %d , a=1 -> %d\n", !0, !1);
    return 0;
}
