#include<stdio.h>

int width;

void pbin(unsigned v)
{
    int i;
    for(i = width - 1; i >= 0; i--)
        printf("%d", (v >> i) & 1);
}

int main()
{
    int a, b, mag;
    unsigned mask, sm, ones, twos, s, carry;

    printf("enter bit width: ");
    scanf("%d", &width);
    mask = (1u << width) - 1;

    printf("enter a number: ");
    scanf("%d", &a);
    mag = a < 0 ? -a : a;

    if(a < 0)
    {
        sm = (1u << (width - 1)) | (unsigned)mag;
        ones = ~(unsigned)mag & mask;
        twos = (ones + 1) & mask;
    }
    else
        sm = ones = twos = (unsigned)mag;

    /* printf("mask = %u\n", mask); */
    printf("sign-magnitude : "); pbin(sm); printf("\n");
    printf("1's complement : "); pbin(ones); printf("\n");
    printf("2's complement : "); pbin(twos); printf("\n");

    printf("enter b to compute a - b: ");
    scanf("%d", &b);

    printf("\n  a          = "); pbin((unsigned)a & mask); printf("  (%d)\n", a);
    printf("  b          = "); pbin((unsigned)b & mask); printf("  (%d)\n", b);
    printf("  2's comp b = "); pbin((unsigned)(-b) & mask); printf("\n");

    s = ((unsigned)a & mask) + ((unsigned)(-b) & mask);
    carry = s >> width;
    s = s & mask;

    printf("  sum        = "); pbin(s); printf("  carry out = %u (discarded)\n", carry);
    /* sign bit of the sum decides, carry alone lies for negative a */
    if((s >> (width - 1)) & 1)
        printf("sign bit 1, result is negative: -%u\n", ((~s) + 1) & mask);
    else
        printf("sign bit 0, result = %u\n", s);

    return 0;
}
