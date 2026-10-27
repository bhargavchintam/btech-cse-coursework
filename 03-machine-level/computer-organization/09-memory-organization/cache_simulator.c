/* direct mapped vs 2-way LRU cache on the same address trace.
   cache 1 KB, block 16 B, 16-bit addresses (same setup as the unit 9 notes).
   direct: 64 lines, line = block % 64
   2-way : 32 sets,  set  = block % 32, LRU inside the set

   checked by hand first:
   direct MHMMMMHMMMMHHMHHMHHM =  8/20 = 0.40
   2-way  MHMHHMHHMMMHHMHHHHHH = 13/20 = 0.65 */

#include<stdio.h>

#define N 20

unsigned trace[N] = {
    0x0040, 0x0044, 0x0440, 0x0040, 0x0444,
    0x0100, 0x0104, 0x0040, 0x0840, 0x0440,
    0x0040, 0x0104, 0x0108, 0x0200, 0x0204,
    0x0040, 0x0440, 0x0100, 0x0204, 0x0044
};

int main()
{
    int dtag[64], wtag[32][2], lru[32];
    int i, j, blk, di, dt, ws, wt, dhit, whit, h1, h2;

    for(i = 0; i < 64; i++) dtag[i] = -1;
    for(i = 0; i < 32; i++) { wtag[i][0] = wtag[i][1] = -1; lru[i] = 0; }

    h1 = h2 = 0;
    printf("  #  addr    block  line tag direct   set tag 2-way\n");
    for(i = 0; i < N; i++) {
        blk = trace[i] >> 4;

        di = blk % 64; dt = blk / 64;
        dhit = (dtag[di] == dt);
        if(!dhit) dtag[di] = dt;

        /* lru[s] holds the way to evict next; a hit makes the other way LRU */
        ws = blk % 32; wt = blk / 32;
        whit = 0;
        for(j = 0; j < 2; j++)
            if(wtag[ws][j] == wt) { whit = 1; lru[ws] = 1 - j; }
        if(!whit) {
            wtag[ws][lru[ws]] = wt;
            lru[ws] = 1 - lru[ws];
        }
        /* printf("set %d: %d %d lru=%d\n", ws, wtag[ws][0], wtag[ws][1], lru[ws]); */

        if(dhit) h1++;
        if(whit) h2++;
        printf(" %2d  0x%04X  %4d   %3d %3d  %-4s    %3d %3d  %s\n",
               i + 1, trace[i], blk, di, dt, dhit ? "hit" : "miss",
               ws, wt, whit ? "hit" : "miss");
    }

    printf("\ndirect mapped: %d/%d hits, hit ratio %.2f\n", h1, N, (float)h1 / N);
    printf("2-way LRU    : %d/%d hits, hit ratio %.2f\n", h2, N, (float)h2 / N);
    return 0;
}
