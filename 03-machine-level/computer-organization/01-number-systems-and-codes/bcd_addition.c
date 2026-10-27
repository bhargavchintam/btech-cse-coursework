#include<stdio.h>

void pbin4(unsigned v)
{
    int i;
    for(i = 3; i >= 0; i--)
        printf("%d", (v >> i) & 1);
}

int main()
{
    unsigned a, b, s, carry;

    printf("enter two decimal digits: ");
    scanf("%u %u", &a, &b);

    printf("\n    "); pbin4(a); printf("      %u\n", a);
    printf("  + "); pbin4(b); printf("      %u\n", b);
    printf("  ------\n");

    s = a + b;
    if(s > 9)
    {
        printf("    "); pbin4(s & 0xF);
        if(s > 15) printf(" (carry 1)");
        printf("   = %u, needs correction\n", s);
        s = s + 6;
        printf("  + 0110      add 6\n");
        printf("  ------\n");
        carry = (s >> 4) & 1;
        printf("  %u ", carry); pbin4(s & 0xF); printf("\n");
        printf("\nresult: %u %u in BCD = %u\n", carry, s & 0xF, a + b);
    }
    else
    {
        printf("    "); pbin4(s); printf("   = %u, legal code, no correction\n", s);
        printf("\nresult: 0 %u in BCD = %u\n", s, s);
    }

    return 0;
}
