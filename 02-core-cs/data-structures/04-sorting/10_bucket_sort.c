// bucket sort for integers - scatter into n buckets by value range
#include<stdio.h>
#define SIZE 100

int bucket[SIZE][SIZE];
int cnt[SIZE];

int main()
{
    int a[SIZE], n, i, j, k, m, key, max, idx;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements (>= 0)\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    for (i = 0; i < n; i++)
    {
        idx = n * a[i] / (max + 1);
        bucket[idx][cnt[idx]++] = a[i];
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        // insertion sort this bucket
        for (j = 1; j < cnt[i]; j++)
        {
            key = bucket[i][j];
            m = j - 1;
            while (m >= 0 && bucket[i][m] > key)
            {
                bucket[i][m + 1] = bucket[i][m];
                m--;
            }
            bucket[i][m + 1] = key;
        }
        for (j = 0; j < cnt[i]; j++)
            a[k++] = bucket[i][j];
    }

    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
