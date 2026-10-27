// sum of each row and each column of a matrix
#include<stdio.h>
int main()
{
    int a[10][10], m, n, i, j, sum;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(i=0;i<m;i++)
    {
        sum = 0;
        for(j=0;j<n;j++)
            sum = sum + a[i][j];
        printf("Sum of row %d = %d\n", i+1, sum);
    }
    for(j=0;j<n;j++)
    {
        sum = 0;
        for(i=0;i<m;i++)
            sum = sum + a[i][j];
        printf("Sum of column %d = %d\n", j+1, sum);
    }
    return 0;
}
