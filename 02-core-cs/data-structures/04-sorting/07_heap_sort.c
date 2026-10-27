// heap sort - build a max heap, swap root to end, re-heapify   O(n log n)
#include<stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2, temp;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n)
{
    int i, temp;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
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

    heapsort(a, n);

    printf("Sorted array\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
