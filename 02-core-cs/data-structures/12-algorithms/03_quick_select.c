// kth smallest element using quickselect (partition based)
#include<stdio.h>

int arr[100];

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for(j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    //printf("pivot placed at %d\n", i + 1);
    return i + 1;
}

int quickselect(int low, int high, int k)
{
    int p = partition(low, high);
    if(p == k)
        return arr[p];
    else if(p > k)
        return quickselect(low, p - 1, k);
    else
        return quickselect(p + 1, high, k);
}

int main()
{
    int n, i, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);

    // kth smallest sits at index k-1 once partitioned
    printf("%d smallest element = %d\n", k, quickselect(0, n - 1, k - 1));
    return 0;
}
