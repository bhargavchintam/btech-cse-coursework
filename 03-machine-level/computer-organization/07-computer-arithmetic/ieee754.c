/* ieee 754 single precision - pull a float apart and put it back together */
#include<stdio.h>

union fbits {
    float f;
    unsigned int u;
};

void bin(unsigned int v, int w)
{
    int i;
    for (i = w - 1; i >= 0; i--)
        putchar('0' + ((v >> i) & 1));
}

void show(float x)
{
    union fbits b;
    unsigned int s, e, m;
    int i;
    double val;

    b.f = x;
    s = b.u >> 31;
    e = (b.u >> 23) & 0xFF;
    m = b.u & 0x7FFFFF;

    printf("value    : %g\n", x);
    printf("hex      : %08X\n", b.u);
    printf("sign     : %u\n", s);
    printf("exponent : ");
    bin(e, 8);
    printf(" = %u, E - 127 = %d\n", e, (int)e - 127);
    printf("mantissa : ");
    bin(m, 23);
    printf(" (hex %06X)\n", m);

    /* rebuild (-1)^s * 1.m * 2^(e-127), normalised numbers only */
    val = 1.0 + (double)m / 8388608.0;
    for (i = 127; i < (int)e; i++)
        val = val * 2.0;
    for (i = (int)e; i < 127; i++)
        val = val / 2.0;
    if (s)
        val = -val;
    printf("rebuilt  : %g\n\n", val);
}

int main()
{
    union fbits b;
    float x;

    printf("enter a float: ");
    scanf("%f", &x);
    printf("\n");
    show(x);

    b.f = -12.625f;
    printf("-12.625 packs to %08X, notes say C14A0000\n\n", b.u);

    x = 0.1f;
    printf("0.1 is actually stored as %.20f\n", (double)x);
    return 0;
}
