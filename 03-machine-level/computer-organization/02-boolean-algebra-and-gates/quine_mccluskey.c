/* Bindu Bhargava  06-09-18 */

/* quine-mccluskey tabulation method, up to 4 variables.
   read the minterms, combine terms that differ in one bit round by
   round, the ones that never combine are the prime implicants, then
   pick a minimal cover off the pi chart. not in the syllabus, read
   about it in mano's simplification chapter, wanted to check my
   k-map answers with it. */

#include<stdio.h>

#define MAXT 128

int nv;                        /* number of variables */
int mt[16], nm;                /* minterms */
int pv[MAXT], pd[MAXT], np;    /* prime implicants: value, dash mask */

int ones(int x)
{
    int c = 0;
    while(x) { c += x & 1; x >>= 1; }
    return c;
}

/* does prime implicant p cover minterm m */
int covers(int p, int m)
{
    return (m & ~pd[p] & ((1 << nv) - 1)) == pv[p];
}

/* print a term in letters, A is the msb */
void pterm(int v, int d)
{
    int i, any = 0;
    for(i = nv - 1; i >= 0; i--)
    {
        if((d >> i) & 1) continue;
        printf("%c", 'A' + nv - 1 - i);
        if(!((v >> i) & 1)) printf("'");
        any = 1;
    }
    if(!any) printf("1");    /* every variable dashed out */
}

void pdash(int v, int d)
{
    int i;
    for(i = nv - 1; i >= 0; i--)
        putchar((d >> i) & 1 ? '-' : '0' + ((v >> i) & 1));
}

int main()
{
    int cv[MAXT], cd[MAXT], used[MAXT], nc;
    int xv[MAXT], xd[MAXT], nx;
    int i, j, k, diff, dup;
    int cnt, esspi, best, bestmask;
    unsigned s;

    printf("number of variables (2-4): ");
    scanf("%d", &nv);
    printf("number of minterms: ");
    scanf("%d", &nm);
    printf("minterms: ");
    for(i = 0; i < nm; i++)
        scanf("%d", &mt[i]);

    /* round 0 is the minterms themselves, no dashes */
    nc = nm;
    for(i = 0; i < nm; i++) { cv[i] = mt[i]; cd[i] = 0; }
    np = 0;

    while(nc > 0)
    {
        nx = 0;
        for(i = 0; i < nc; i++) used[i] = 0;
        for(i = 0; i < nc; i++)
            for(j = i + 1; j < nc; j++)
            {
                if(cd[i] != cd[j]) continue;
                diff = cv[i] ^ cv[j];
                if(ones(diff) != 1) continue;
                used[i] = used[j] = 1;
                dup = 0;    /* same pair reachable two ways, keep one */
                for(k = 0; k < nx; k++)
                    if(xv[k] == (cv[i] & cv[j]) && xd[k] == (cd[i] | diff))
                        dup = 1;
                if(!dup)
                {
                    xv[nx] = cv[i] & cv[j];
                    xd[nx] = cd[i] | diff;
                    nx++;
                }
            }
        for(i = 0; i < nc; i++)
            if(!used[i])
            {
                pv[np] = cv[i];
                pd[np] = cd[i];
                np++;
            }
        for(i = 0; i < nx; i++) { cv[i] = xv[i]; cd[i] = xd[i]; }
        nc = nx;
    }

    printf("\nprime implicants:\n");
    for(i = 0; i < np; i++)
    {
        printf("  ");
        pdash(pv[i], pd[i]);
        printf("  ");
        pterm(pv[i], pd[i]);
        printf("  covers");
        for(j = 0; j < nm; j++)
            if(covers(i, mt[j])) printf(" %d", mt[j]);
        /* essential if some minterm has no other cover */
        esspi = 0;
        for(j = 0; j < nm; j++)
        {
            cnt = 0;
            for(k = 0; k < np; k++)
                if(covers(k, mt[j])) cnt++;
            if(cnt == 1 && covers(i, mt[j])) esspi = 1;
        }
        if(esspi) printf("   *essential");
        printf("\n");
    }

    /* pi chart: smallest set of pis covering every minterm.
       np is small for 4 variables so brute force every subset */
    best = -1;
    bestmask = 0;
    for(s = 0; s < (1u << np); s++)
    {
        for(j = 0; j < nm; j++)
        {
            for(k = 0; k < np; k++)
                if((s >> k) & 1 && covers(k, mt[j])) break;
            if(k == np) break;    /* minterm j not covered */
        }
        if(j == nm && (best < 0 || ones(s) < best))
        {
            best = ones(s);
            bestmask = s;
        }
    }

    printf("\nminimal cover (%d terms):\n  F = ", best);
    k = 0;
    for(i = 0; i < np; i++)
        if((bestmask >> i) & 1)
        {
            if(k++) printf(" + ");
            pterm(pv[i], pd[i]);
        }
    printf("\n");

    return 0;
}
