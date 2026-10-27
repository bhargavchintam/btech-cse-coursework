// check whether an array satisfies the max heap property
#include<stdio.h>
#define SIZE 100

int main()
{
    int a[SIZE], n, i, ok = 1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    // check every internal node against its children
    for(i = 0; i <= n/2 - 1; i++)
    {
        int l = 2*i + 1, r = 2*i + 2;
        if(l < n && a[i] < a[l])
            ok = 0;
        if(r < n && a[i] < a[r])
            ok = 0;
    }
    if(ok)
        printf("Yes, it is a max heap\n");
    else
        printf("No, it is not a max heap\n");
    return 0;
}
