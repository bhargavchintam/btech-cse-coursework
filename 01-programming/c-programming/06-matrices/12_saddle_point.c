// find saddle point in a matrix
#include<stdio.h>
int main()
{
    int a[10][10], m, n, i, j, k;
    int min, max, col, found=0;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(i=0;i<m;i++)
    {
        min = a[i][0];
        col = 0;
        for(j=1;j<n;j++)
        {
            if(a[i][j] < min)
            {
                min = a[i][j];
                col = j;
            }
        }
        max = a[0][col];
        for(k=1;k<m;k++)
        {
            if(a[k][col] > max)
                max = a[k][col];
        }
        if(min == max)
        {
            printf("Saddle point = %d at row %d column %d\n", min, i+1, col+1);
            found = 1;
        }
    }
    if(found == 0)
        printf("No saddle point\n");
    return 0;
}
