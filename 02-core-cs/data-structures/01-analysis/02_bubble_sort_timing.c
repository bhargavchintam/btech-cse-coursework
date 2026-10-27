// bubble sort - comparisons grow like n^2
#include<stdio.h>
#include<time.h>

#define MAX 10000

int main()
{
    int n, i, j, tmp;
    int a[MAX];
    long comp;
    clock_t t1, t2;

    printf("   n     comparisons     time(sec)\n");
    for (n = 1000; n <= MAX; n += 1000) {
        for (i = 0; i < n; i++)
            a[i] = n - i;              // reverse sorted -> worst case

        comp = 0;
        t1 = clock();
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - 1 - i; j++) {
                comp++;
                if (a[j] > a[j + 1]) {
                    tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }
        }
        t2 = clock();

        printf("%6d   %11ld    %.4f\n", n, comp, (double)(t2 - t1) / CLOCKS_PER_SEC);
    }
    return 0;
}
