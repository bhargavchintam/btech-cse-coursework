// second largest element in an array
#include<stdio.h>
#include<limits.h>
int main()
{
    int a[50], n, i, big, second;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    big = INT_MIN;
    second = INT_MIN;
    for(i=0;i<n;i++)
    {
        if(a[i] > big)
        {
            second = big;
            big = a[i];
        }
        else if(a[i] > second && a[i] != big)
            second = a[i];
    }
    printf("Second largest = %d\n", second);
    return 0;
}
