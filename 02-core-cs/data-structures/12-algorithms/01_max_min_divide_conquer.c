// find max and min of an array using divide and conquer
#include<stdio.h>

int arr[100];

void maxmin(int low, int high, int *max, int *min)
{
    if(low == high)
    {
        *max = *min = arr[low];
    }
    else if(high == low + 1)
    {
        if(arr[low] > arr[high])
        {
            *max = arr[low];
            *min = arr[high];
        }
        else
        {
            *max = arr[high];
            *min = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;
        maxmin(low, mid, &max1, &min1);
        maxmin(mid + 1, high, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main()
{
    int n, i, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    maxmin(0, n - 1, &max, &min);
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);
    return 0;
}
