// sum of both diagonals of a square matrix
#include<stdio.h>
int main()
{
    int a[10][10], n, i, j, d1=0, d2=0;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(i=0;i<n;i++)
    {
        d1 = d1 + a[i][i];
        d2 = d2 + a[i][n-1-i];
    }
    printf("Principal diagonal sum = %d\n", d1);
    printf("Secondary diagonal sum = %d\n", d2);
    return 0;
}
