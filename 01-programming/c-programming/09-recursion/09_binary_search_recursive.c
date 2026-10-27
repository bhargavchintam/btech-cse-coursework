#include<stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    int mid;
    if(low > high)
        return -1;
    mid = (low + high) / 2;
    if(arr[mid] == key)
        return mid;
    else if(key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[50], n, i, key, pos;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter %d sorted elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter key : ");
    scanf("%d", &key);
    pos = binarySearch(arr, 0, n - 1, key);   // TODO duplicates
    if(pos == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", pos);
    return 0;
}
