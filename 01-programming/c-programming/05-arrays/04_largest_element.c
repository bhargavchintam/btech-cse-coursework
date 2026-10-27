// find largest element in an array
#include<stdio.h>
int main()
{
    int a[50], n, i, big;
    printf("enter n\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    big = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i] > big)
            big = a[i];
    }
    printf("Largest = %d\n", big);
    return 0;
}
