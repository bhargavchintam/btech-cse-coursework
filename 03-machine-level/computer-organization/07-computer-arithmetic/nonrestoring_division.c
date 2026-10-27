/* non-restoring division, 4 bit - one add or subtract per cycle */
#include<stdio.h>

#define N 4

void bits(int v, int w, char *s)
{
    int i;
    for (i = w - 1; i >= 0; i--)
        s[w - 1 - i] = ((v >> i) & 1) ? '1' : '0';
    s[w] = '\0';
}

int main()
{
    int dd, dv, a, q, m, neg, i;
    char sa[8], sq[8];

    printf("dividend (0 to 15): ");
    scanf("%d", &dd);
    printf("divisor (1 to 7): ");
    scanf("%d", &dv);

    a = 0;
    q = dd & 0xF;
    m = dv;

    bits(m, N + 1, sa);
    printf("\nM = %s\n\n", sa);
    printf("step    A      Q     operation\n");
    bits(a, N + 1, sa);
    bits(q, N, sq);
    printf("  0   %s  %s  initial values\n", sa, sq);

    for (i = 1; i <= N; i++) {
        neg = (a >> N) & 1;
        a = ((a << 1) | ((q >> (N - 1)) & 1)) & 0x1F;
        q = (q << 1) & 0xF;
        bits(a, N + 1, sa);
        bits(q, N, sq);
        printf("  %d   %s  %s  %s : shift left AQ\n", i, sa, sq,
               neg ? "A < 0" : "A >= 0");
        if (neg)
            a = (a + m) & 0x1F;
        else
            a = (a - m) & 0x1F;
        /* printf("dbg a=%d q=%d\n", a, q); */
        bits(a, N + 1, sa);
        if (a & 0x10) {
            printf("  %d   %s  %s  A = A %c M ; A < 0 so Q0 = 0\n", i, sa, sq,
                   neg ? '+' : '-');
        } else {
            q = q | 1;
            bits(q, N, sq);
            printf("  %d   %s  %s  A = A %c M ; A >= 0 so Q0 = 1\n", i, sa, sq,
                   neg ? '+' : '-');
        }
    }

    if (a & 0x10) {
        a = (a + m) & 0x1F;
        bits(a, N + 1, sa);
        printf(" end  %s  %s  A < 0 : A = A + M, final restore\n", sa, sq);
    }

    printf("\nquotient Q = %d, remainder R = %d\n", q, a);
    printf("check: %d / %d = %d rem %d\n", dd, dv, dd / dv, dd % dv);
    return 0;
}
