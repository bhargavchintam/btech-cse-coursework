/* splits addresses into tag / index / offset for a given cache.
   assoc = 1 is direct mapped, k > 1 is k-way set associative. */

#include<stdio.h>

int lg2(unsigned x)
{
    int n = 0;
    while(x > 1) { x >>= 1; n++; }
    return n;
}

void bits(unsigned v, int n)
{
    int i;
    for(i = n - 1; i >= 0; i--)
        printf("%d", (v >> i) & 1);
}

int main()
{
    unsigned cache, block, assoc, lines, sets;
    unsigned mask, a, t, s, o;
    unsigned ex[3] = {0x2A57, 0x1234, 0x0FF8};
    int abits, off, idx, tag, i;
    const char *mid;

    printf("cache size (bytes): ");
    scanf("%u", &cache);
    printf("block size (bytes): ");
    scanf("%u", &block);
    printf("address width (bits): ");
    scanf("%d", &abits);
    printf("associativity (1=direct): ");
    scanf("%u", &assoc);

    lines = cache / block;
    sets = lines / assoc;
    off = lg2(block);
    idx = lg2(sets);
    tag = abits - idx - off;
    mid = (assoc == 1) ? "index" : "set";

    printf("\nlines = %u, sets = %u\n", lines, sets);
    printf("tag = %d bits, %s = %d bits, offset = %d bits\n", tag, mid, idx, off);

    mask = (abits == 32) ? 0xFFFFFFFFu : (1u << abits) - 1;
    printf("\n");
    for(i = 0; i < 3; i++) {
        a = ex[i] & mask;
        o = a & ((1u << off) - 1);
        s = (a >> off) & ((1u << idx) - 1);
        t = a >> (off + idx);
        printf("addr 0x%04X = ", a);
        bits(t, tag); printf(" "); bits(s, idx); printf(" "); bits(o, off);
        printf("   tag=%u %s=%u offset=%u\n", t, mid, s, o);
    }
    return 0;
}
