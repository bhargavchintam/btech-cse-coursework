// smallest element in array
#include<stdio.h>
int main()
{
    int a[50], n, i, small;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    i = 0;
    while(i < n)
    {
        scanf("%d", &a[i]);
        i++;
    }
    small = a[0];
    i = 1;
    while(i < n)
    {
        if(a[i] < small)
            small = a[i];
        i++;
    }
    printf("Smallest = %d\n", small);
    return 0;
}
