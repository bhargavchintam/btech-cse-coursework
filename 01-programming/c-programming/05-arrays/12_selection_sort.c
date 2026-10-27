// selection sort
#include<stdio.h>
int main()
{
    int a[50], n, i, j, min, temp;
    printf("enter n\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];      // swap
        a[i] = a[min];
        a[min] = temp;
    }
    printf("sorted array\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
