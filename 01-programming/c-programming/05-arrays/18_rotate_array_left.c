// rotate an array to the left
#include<stdio.h>
int main()
{
    int a[50], n, i, j, d, temp;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    temp = a[0];      // rotate left by one
    for(i=0;i<n-1;i++)
        a[i] = a[i+1];
    a[n-1] = temp;
    printf("After rotating left by 1\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Enter d: ");
    scanf("%d", &d);
    for(j=0;j<d;j++)
    {
        temp = a[0];
        for(i=0;i<n-1;i++)
            a[i] = a[i+1];
        a[n-1] = temp;
    }
    printf("After rotating left by %d\n", d);
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
