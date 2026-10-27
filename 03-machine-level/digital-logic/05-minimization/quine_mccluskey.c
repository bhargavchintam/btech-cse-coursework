// quine-mccluskey minimizer. reads number of variables and a minterm list,
// prints the prime implicants and a minimized SOP expression
#include<stdio.h>

#define MAX 64

int nvar, nm;
int mt[MAX];

int popcount(int x){ int c=0; while(x){ c+=x&1; x>>=1; } return c; }

// an implicant is a value with a dash-mask (1 bit = position is a dash)
typedef struct { int val, mask, used; } imp;

imp all[512]; int nall = 0;

int same(imp a, imp b){ return a.val==b.val && a.mask==b.mask; }

void add_imp(int val, int mask)
{
    int i;
    val = val & ~mask;           // canonical: dashed bits are 0
    for(i = 0; i < nall; i++)
        if(all[i].val==val && all[i].mask==mask) return;
    all[nall].val=val; all[nall].mask=mask; all[nall].used=0; nall++;
}

// does implicant cover original minterm x?
int covers(imp a, int x){ return (x & ~a.mask) == (a.val & ~a.mask); }

int main()
{
    int i, j, changed, level_start, prime[512], np = 0;
    printf("Enter number of variables: ");
    scanf("%d", &nvar);
    printf("How many minterms: ");
    scanf("%d", &nm);
    printf("Enter the minterms: ");
    for(i = 0; i < nm; i++){ scanf("%d", &mt[i]); add_imp(mt[i], 0); }

    // combine repeatedly
    level_start = 0;
    do {
        int end = nall;
        changed = 0;
        for(i = level_start; i < end; i++)
            for(j = i+1; j < end; j++)
                if(all[i].mask == all[j].mask)
                {
                    int diff = all[i].val ^ all[j].val;
                    if(popcount(diff) == 1)
                    {
                        all[i].used = 1; all[j].used = 1;
                        add_imp(all[i].val, all[i].mask | diff);
                        changed = 1;
                    }
                }
        level_start = end;
    } while(changed);

    // prime implicants = never used
    for(i = 0; i < nall; i++)
        if(!all[i].used)
            prime[np++] = i;

    // essential prime implicants + greedy cover
    int chosen[512], nc = 0, covered[MAX] = {0};
    // essentials
    for(i = 0; i < nm; i++)
    {
        int cnt = 0, last = -1;
        for(j = 0; j < np; j++)
            if(covers(all[prime[j]], mt[i])){ cnt++; last = prime[j]; }
        if(cnt == 1)
        {
            int seen = 0, t;
            for(t = 0; t < nc; t++) if(chosen[t]==last) seen=1;
            if(!seen) chosen[nc++] = last;
        }
    }
    // mark covered
    for(i = 0; i < nm; i++)
        for(j = 0; j < nc; j++)
            if(covers(all[chosen[j]], mt[i])) covered[i] = 1;
    // greedy for the rest
    int done = 0;
    while(!done)
    {
        int best = -1, bestcov = 0, k;
        for(j = 0; j < np; j++)
        {
            int c = 0, already = 0, t;
            for(t = 0; t < nc; t++) if(chosen[t]==prime[j]) already=1;
            if(already) continue;
            for(k = 0; k < nm; k++)
                if(!covered[k] && covers(all[prime[j]], mt[k])) c++;
            if(c > bestcov){ bestcov = c; best = prime[j]; }
        }
        if(best < 0) break;
        chosen[nc++] = best;
        for(k = 0; k < nm; k++)
            if(covers(all[best], mt[k])) covered[k] = 1;
        done = 1;
        for(k = 0; k < nm; k++) if(!covered[k]) done = 0;
    }

    // print prime implicants
    printf("\nPrime implicants: %d\n", np);

    // print the expression
    printf("F = ");
    for(j = 0; j < nc; j++)
    {
        int b, alldash = 1;
        for(b = nvar-1; b >= 0; b--)
            if(!((all[chosen[j]].mask >> b) & 1))
            {
                alldash = 0;
                printf("%c%s", 'A' + (nvar-1-b), ((all[chosen[j]].val >> b) & 1) ? "" : "'");
            }
        if(alldash) printf("1");
        if(j < nc-1) printf(" + ");
    }
    printf("\n");

    // self-check: expand chosen implicants back to minterms
    int got[MAX], ng = 0, x;
    for(x = 0; x < (1 << nvar); x++)
        for(j = 0; j < nc; j++)
            if(covers(all[chosen[j]], x)){ got[ng++] = x; break; }
    printf("covers:");
    for(i = 0; i < ng; i++) printf(" %d", got[i]);
    printf("\n");
    return 0;
}
