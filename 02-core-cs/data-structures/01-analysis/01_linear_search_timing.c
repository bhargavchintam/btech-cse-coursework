// linear search - comparisons grow with n
#include<stdio.h>
#include<time.h>

#define MAX 10000
#define REP 20000

int main()
{
    int n, i, r, key, comp;
    int a[MAX];
    clock_t t1, t2;

    printf("   n    comparisons    time(sec)\n");
    for (n = 1000; n <= MAX; n += 1000) {
        for (i = 0; i < n; i++)
            a[i] = i + 1;              // values 1..n so 0 is absent

        key = 0;                       // absent -> worst case, scans everything
        comp = 0;
        for (i = 0; i < n; i++) {
            comp++;
            if (a[i] == key)
                break;
        }

        t1 = clock();
        for (r = 0; r < REP; r++) {
            int j;
            for (j = 0; j < n; j++)
                if (a[j] == key)
                    break;
        }
        t2 = clock();

        printf("%6d   %8d    %.4f\n", n, comp, (double)(t2 - t1) / CLOCKS_PER_SEC);
    }
    return 0;
}
