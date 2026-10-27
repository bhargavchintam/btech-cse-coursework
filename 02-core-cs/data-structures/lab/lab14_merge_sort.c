/* Lab Program 14
   Sort a set of n integers using merge sort and display the sorted array. */
// O(n log n)

#include<stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergesort(int arr[], int low, int high)
{
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergesort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
