// realize NOT, AND, OR using only NAND
#include<stdio.h>

int nand(int a, int b){ return !(a & b); }

int main()
{
    int a, b;
    printf("a b | NOT(a) AND OR\n");
    for(a = 0; a <= 1; a++)
        for(b = 0; b <= 1; b++)
        {
            int n_a  = nand(a, a);            // NOT
            int and  = nand(nand(a,b), nand(a,b));  // AND = NOT(NAND)
            int or   = nand(nand(a,a), nand(b,b));  // OR  = NAND of the complements
            printf("%d %d |   %d     %d  %d\n", a, b, n_a, and, or);
        }
    return 0;
}
