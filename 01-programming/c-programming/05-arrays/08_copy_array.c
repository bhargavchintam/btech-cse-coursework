// copy elements of one array into another
#include<stdio.h>
int main()
{
    int a[50], b[50], n, i;
    printf("How many elements? ");
    scanf("%d", &n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(i=0;i<n;i++)
        b[i] = a[i];
    printf("Copied array\n");
    for(i=0;i<n;i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}
