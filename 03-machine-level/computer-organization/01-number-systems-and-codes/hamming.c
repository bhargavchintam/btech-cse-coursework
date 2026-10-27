#include<stdio.h>

const char *name[8] = {"", "p1", "p2", "d1", "p4", "d2", "d3", "d4"};

void ptable(int c[])
{
    int i;
    printf("pos :");
    for(i = 1; i <= 7; i++) printf("  %2d", i);
    printf("\nname:");
    for(i = 1; i <= 7; i++) printf("  %s", name[i]);
    printf("\nbit :");
    for(i = 1; i <= 7; i++) printf("  %2d", c[i]);
    printf("\n");
}

int main()
{
    int d1, d2, d3, d4, c[8], f, i;
    int s1, s2, s4, syn;

    printf("enter 4 data bits (d1 d2 d3 d4): ");
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

    /* even parity, p1 covers 1,3,5,7  p2 covers 2,3,6,7  p4 covers 4,5,6,7 */
    c[3] = d1; c[5] = d2; c[6] = d3; c[7] = d4;
    c[1] = d1 ^ d2 ^ d4;
    c[2] = d1 ^ d3 ^ d4;
    c[4] = d2 ^ d3 ^ d4;

    printf("\ncodeword:\n");
    ptable(c);
    printf("transmitted: ");
    for(i = 1; i <= 7; i++) printf("%d", c[i]);
    printf("\n");

    printf("\nposition to flip (1-7): ");
    scanf("%d", &f);
    c[f] = c[f] ^ 1;

    printf("\nreceived:\n");
    ptable(c);

    s1 = c[1] ^ c[3] ^ c[5] ^ c[7];
    s2 = c[2] ^ c[3] ^ c[6] ^ c[7];
    s4 = c[4] ^ c[5] ^ c[6] ^ c[7];
    syn = s4 * 4 + s2 * 2 + s1;

    printf("\nsyndrome s4 s2 s1 = %d%d%d = %d\n", s4, s2, s1, syn);
    if(syn == 0)
        printf("no error\n");
    else
    {
        printf("error at position %d, flipping it back\n", syn);
        c[syn] = c[syn] ^ 1;
        printf("corrected: ");
        for(i = 1; i <= 7; i++) printf("%d", c[i]);
        printf("\ndata bits: %d%d%d%d\n", c[3], c[5], c[6], c[7]);
    }

    return 0;
}
