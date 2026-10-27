/* Bindu Bhargava  05-11-18 */
/* booth's multiplication, 4 bit - prints the A/Q/Q-1 table from the notes */
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

int main()
{
    int m, mult, a, qr, q1, q0, i, prod;
    char sa[N + 1], sq[N + 1];

    printf("multiplicand (-7 to 7): ");
    scanf("%d", &m);
    printf("multiplier (-8 to 7): ");
    scanf("%d", &mult);

    a = 0;
    qr = mult & MASK;
    q1 = 0;

    bits(m & MASK, sa);
    printf("\nM = %s, ", sa);
    bits((0 - m) & MASK, sa);
    printf("-M = %s\n\n", sa);

    printf("step   A     Q    Q-1  operation\n");
    bits(a, sa);
    bits(qr, sq);
    printf("  0   %s  %s   %d   initial values\n", sa, sq, q1);

    for (i = 1; i <= N; i++) {
        q0 = qr & 1;
        if (q0 == 1 && q1 == 0) {
            a = (a - m) & MASK;
            bits(a, sa);
            printf("  %d   %s  %s   %d   Q0 Q-1 = 10 : A = A - M\n", i, sa, sq, q1);
        } else if (q0 == 0 && q1 == 1) {
            a = (a + m) & MASK;
            bits(a, sa);
            printf("  %d   %s  %s   %d   Q0 Q-1 = 01 : A = A + M\n", i, sa, sq, q1);
        }
        /* arithmetic right shift of A:Q:Q-1, sign bit of A is copied */
        q1 = q0;
        qr = (qr >> 1) | ((a & 1) << (N - 1));
        a = (a >> 1) | (a & (1 << (N - 1)));
        bits(a, sa);
        bits(qr, sq);
        printf("  %d   %s  %s   %d   ASR\n", i, sa, sq, q1);
    }

    prod = (a << N) | qr;
    if (prod & (1 << (2 * N - 1)))
        prod = prod - (1 << (2 * N));
    printf("\nproduct A:Q = %s %s = %d\n", sa, sq, prod);
    printf("check: %d x %d = %d\n", m, mult, m * mult);
    return 0;
}
