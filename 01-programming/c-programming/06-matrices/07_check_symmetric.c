// check whether a matrix is symmetric
#include<stdio.h>
int main()
{
    int a[10][10], n, i, j, flag=1;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j] != a[j][i])
                flag = 0;
        }
    }
    if(flag == 1)
        printf("Matrix is symmetric\n");
    else
        printf("Matrix is not symmetric\n");
    return 0;
}
