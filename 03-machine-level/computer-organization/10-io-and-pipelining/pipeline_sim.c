/* space-time diagram for a 5-stage pipeline, with and without a RAW stall */
#include<stdio.h>

#define K 5
#define MAXN 20

const char *stg[K] = {"IF", "ID", "EX", "MEM", "WB"};

/* stall[i] = bubbles inserted before instruction i's ID stage.
   returns the cycle in which the last instruction leaves WB. */
int diagram(int n, int stall[])
{
    int i, j, c, s, start, shift, last = 0;
    char cell[MAXN + 1][2 * MAXN + K][4];

    for (i = 1; i <= n; i++)
        for (c = 0; c < 2 * MAXN + K; c++)
            cell[i][c][0] = '\0';

    shift = 0;    /* stalls accumulated by earlier instructions */
    for (i = 1; i <= n; i++) {
        start = i + shift;              /* IF happens before the stall is seen */
        sprintf(cell[i][start], "%s", stg[0]);
        for (j = 1; j <= stall[i]; j++)
            sprintf(cell[i][start + j], "%s", "--");
        for (s = 1; s < K; s++)
            sprintf(cell[i][start + stall[i] + s], "%s", stg[s]);
        shift += stall[i];
        if (start + stall[i] + K - 1 > last)
            last = start + stall[i] + K - 1;
    }

    printf("cycle ");
    for (c = 1; c <= last; c++)
        printf("%4d", c);
    printf("\n");
    for (i = 1; i <= n; i++) {
        printf("I%-5d", i);
        for (c = 1; c <= last; c++)
            printf("%4s", cell[i][c][0] ? cell[i][c] : ".");
        printf("\n");
    }
    return last;
}

int main()
{
    int n, total, stalls;
    int stall[MAXN + 1] = {0};

    printf("number of instructions (max %d): ", MAXN);
    scanf("%d", &n);

    printf("\n--- ideal pipeline, no hazards ---\n");
    total = diagram(n, stall);
    printf("total cycles = %d, formula k+n-1 = %d %s\n",
           total, K + n - 1, total == K + n - 1 ? "(matches)" : "(MISMATCH!)");
    printf("non-pipelined = n*k = %d cycles\n", n * K);
    printf("speedup = %d/%d = %.2f\n", n * K, total, (float)(n * K) / total);

    if (n >= 3) {
        /* I3 reads a register that I2 writes; without forwarding I2 writes it
           in WB (reg file writes first half, reads second half) so I3's ID
           must wait 2 cycles */
        stall[3] = 2;
        stalls = 2;
        printf("\n--- I3 RAW-dependent on I2, no forwarding ---\n");
        total = diagram(n, stall);
        printf("total cycles = %d, formula k+n-1+stalls = %d %s\n",
               total, K + n - 1 + stalls,
               total == K + n - 1 + stalls ? "(matches)" : "(MISMATCH!)");
        printf("speedup drops to %d/%d = %.2f\n",
               n * K, total, (float)(n * K) / total);
    }
    return 0;
}
