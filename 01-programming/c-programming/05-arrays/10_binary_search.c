// binary search on a sorted array
#include<stdio.h>
int main()
{
    int a[50], n, i, key, low, high, mid, pos=-1;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order\n", n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low+high)/2;
        //printf("mid=%d\n", mid);
        if(a[mid] == key)
        {
            pos = mid;
            break;
        }
        else if(key < a[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    if(pos == -1)
        printf("Element not found\n");
    else
        printf("Found at position %d\n", pos+1);
    return 0;
}
