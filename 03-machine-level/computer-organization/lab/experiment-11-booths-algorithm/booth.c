/* booth's multiplication, 4 bit - lab version.
   traces one product fully, then pushes a few more pairs
   through the same routine to check it */
#include<stdio.h>

#define N 4
#define MASK 0xF

void bits(int v, char *s)
{
    int i;
    for (i = N - 1; i >= 0; i--)
        s[N - 1 - i] = ((v >> i) & 1) ? '1' : '0';
    s[N] = '\0';
}

int booth(int m, int q, int show)
{
    int acc, qr, qm1, q0, i, prod;
    char sa[N + 1], sq[N + 1];

    acc = 0;
    qr = q & MASK;
    qm1 = 0;

    bits(acc, sa);
    bits(qr, sq);
    if (show) {
        bits(m & MASK, sa);
        printf("M = %s, ", sa);
        bits((0 - m) & MASK, sa);
        printf("-M = %s\n\n", sa);
        bits(acc, sa);
        printf("step   A     Q    Q-1  operation\n");
        printf("  0   %s  %s   %d   initial values\n", sa, sq, qm1);
    }

    for (i = 1; i <= N; i++) {
        q0 = qr & 1;
        if (q0 == 1 && qm1 == 0) {
            acc = (acc - m) & MASK;
            bits(acc, sa);
            if (show)
                printf("  %d   %s  %s   %d   Q0 Q-1 = 10 : A = A - M\n", i, sa, sq, qm1);
        } else if (q0 == 0 && qm1 == 1) {
            acc = (acc + m) & MASK;
            bits(acc, sa);
            if (show)
                printf("  %d   %s  %s   %d   Q0 Q-1 = 01 : A = A + M\n", i, sa, sq, qm1);
        }
        /* arithmetic right shift of A:Q:Q-1, sign of A copied in */
        qm1 = q0;
        qr = (qr >> 1) | ((acc & 1) << (N - 1));
        acc = (acc >> 1) | (acc & (1 << (N - 1)));
        bits(acc, sa);
        bits(qr, sq);
        if (show)
            printf("  %d   %s  %s   %d   ASR\n", i, sa, sq, qm1);
    }

    prod = (acc << N) | qr;
    if (prod & (1 << (2 * N - 1)))
        prod = prod - (1 << (2 * N));
    return prod;
}

int main()
{
    int pairs[4][2] = {{5, -3}, {-7, -8}, {-4, 6}, {7, 7}};
    int i, p;

    printf("trace of -6 x 7:\n\n");
    p = booth(-6, 7, 1);
    printf("\nproduct A:Q = %d   check: -6 x 7 = %d\n", p, -6 * 7);

    printf("\nmore products through the same routine:\n");
    printf("   m    q   booth   m*q\n");
    for (i = 0; i < 4; i++) {
        p = booth(pairs[i][0], pairs[i][1], 0);
        printf("  %2d  %3d   %4d  %4d\n", pairs[i][0], pairs[i][1], p, pairs[i][0] * pairs[i][1]);
    }
    return 0;
}
