// largest element in a matrix
#include<stdio.h>
int main()
{
    int a[10][10], m, n, i, j, big;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    big = a[0][0];
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(a[i][j] > big)
                big = a[i][j];
    printf("Largest element = %d\n", big);
    return 0;
}
