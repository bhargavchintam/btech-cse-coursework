// radix sort - LSD, base 10, non negative integers
#include<stdio.h>

int getmax(int a[], int n)
{
    int i, max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// stable counting sort on the digit at 'exp'
void countdigit(int a[], int n, int exp)
{
    int output[100], count[10] = {0}, i, d;
    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        d = (a[i] / exp) % 10;
        output[count[d] - 1] = a[i];
        count[d]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixsort(int a[], int n)
{
    int max = getmax(a, n), exp;
    for (exp = 1; max / exp > 0; exp *= 10)
        countdigit(a, n, exp);
}

int main()
{
    int a[100], n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements (>= 0)\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixsort(a, n);

    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
