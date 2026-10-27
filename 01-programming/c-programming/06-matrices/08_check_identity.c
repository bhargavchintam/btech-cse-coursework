// check whether a matrix is an identity matrix
#include<stdio.h>
int main() {
    int a[10][10], n, i, j, flag=1;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(i==j && a[i][j]!=1)
                flag = 0;
            if(i!=j && a[i][j]!=0)
                flag = 0;
        }
    }
    if(flag == 1)
        printf("It is an identity matrix\n");
    else
        printf("It is not an identity matrix\n");
    return 0;
}
