/* Bindu Bhargava  07-12-18 */
/* direct mapped cache on a fixed address trace.
   cache 512 B, block 32 B -> 16 lines, 12-bit addresses
   offset = 5 bits, index = 4 bits, tag = 3 bits */
#include<stdio.h>

#define N 16
#define LINES 16

unsigned trace[N] = {
    0x040, 0x044, 0x240, 0x040, 0x100, 0x108, 0x24C, 0x100,
    0x3A0, 0x3BC, 0x1A0, 0x040, 0x048, 0x3A0, 0x108, 0x800
};

int main()
{
    int tag[LINES];
    int i, blk, line, t, hit, hits;

    for (i = 0; i < LINES; i++)
        tag[i] = -1;    /* empty line */

    hits = 0;
    printf("  #  addr   block  line  tag  result\n");
    for (i = 0; i < N; i++) {
        blk = trace[i] >> 5;
        line = blk % LINES;
        t = blk / LINES;
        hit = (tag[line] == t);
        if (hit)
            hits++;
        else
            tag[line] = t;
        printf(" %2d  0x%03X  %4d   %3d   %2d   %s\n",
               i + 1, trace[i], blk, line, t, hit ? "hit" : "miss");
    }

    printf("\nhits = %d / %d, hit ratio = %.2f\n", hits, N, (float)hits / N);
    return 0;
}
