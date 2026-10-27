/* restoring division, 4 bit - A is 5 bits so the sign of A - M shows */
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
    int dd, dv, a, q, m, t, i;
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
        a = ((a << 1) | ((q >> (N - 1)) & 1)) & 0x1F;
        q = (q << 1) & 0xF;
        bits(a, N + 1, sa);
        bits(q, N, sq);
        printf("  %d   %s  %s  shift left AQ\n", i, sa, sq);
        t = (a - m) & 0x1F;
        bits(t, N + 1, sa);
        printf("  %d   %s  %s  A = A - M\n", i, sa, sq);
        if (t & 0x10) {
            bits(a, N + 1, sa);
            printf("  %d   %s  %s  A < 0 : restore, Q0 = 0\n", i, sa, sq);
        } else {
            a = t;
            q = q | 1;
            bits(a, N + 1, sa);
            bits(q, N, sq);
            printf("  %d   %s  %s  A >= 0 : keep, Q0 = 1\n", i, sa, sq);
        }
    }

    printf("\nquotient Q = %d, remainder R = %d\n", q, a);
    printf("check: %d / %d = %d rem %d\n", dd, dv, dd / dv, dd % dv);
    return 0;
}
