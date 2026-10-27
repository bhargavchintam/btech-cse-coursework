// merge sort   O(n log n)
#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int *temp = malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
    free(temp);                 // dont forget to free
}

void merge_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
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

    merge_sort(a, 0, n - 1);

    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
