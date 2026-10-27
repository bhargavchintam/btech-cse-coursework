// linear search in an array
#include<stdio.h>
int main()
{
    int a[50], n, i, key, pos=-1;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i=0;i<n;i++)
    {
        if(a[i] == key)
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", pos+1);
    return 0;
}
