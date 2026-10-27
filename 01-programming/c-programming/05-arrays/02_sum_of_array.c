// sum of all elements in an array
#include<stdio.h>
int main()
{
    int a[50], n, i, sum=0;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
        sum = sum + a[i];
    printf("Sum = %d\n", sum);
    return 0;
}
