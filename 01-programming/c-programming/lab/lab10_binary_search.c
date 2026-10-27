/* Lab Program 10
   Search for an element in a sorted array using binary search.
   gcc lab10_binary_search.c -o lab10  */

#include<stdio.h>

int main()
{
    int i, n, key, low, high, mid, found = 0;
    int arr[50];

    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search : ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    mid = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            found = 1;
            break;
        }
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found)
        printf("Element found at position %d\n", mid + 1);
    else
        printf("Element not found\n");
    return 0;
}
