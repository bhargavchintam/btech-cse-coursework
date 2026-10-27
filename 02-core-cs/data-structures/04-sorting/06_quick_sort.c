// quick sort - Lomuto partition, pivot = last element   O(n log n) avg
#include<stdio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j;
    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    int p;
    if (low < high)
    {
        p = partition(a, low, high);
        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int main()
{
    int a[100], n, i;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
