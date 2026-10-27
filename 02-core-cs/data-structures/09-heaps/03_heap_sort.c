/* Bindu Bhargava   12-11-18 */
// heap sort   O(n log n)
#include<stdio.h>
#define SIZE 100

// sift down node i in a heap of size m (0-indexed)
void heapify(int a[], int m, int i)
{
    int large, l, r, t;
    large = i;
    l = 2*i + 1;
    r = 2*i + 2;
    if(l < m && a[l] > a[large])
        large = l;
    if(r < m && a[r] > a[large])
        large = r;
    if(large != i)
    {
        t = a[i];
        a[i] = a[large];
        a[large] = t;
        heapify(a, m, large);
    }
}

void heap_sort(int a[], int n)
{
    int i, t;
    for(i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for(i = n - 1; i > 0; i--)
    {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

int main()
{
    int a[SIZE], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    heap_sort(a, n);
    printf("Sorted : ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
