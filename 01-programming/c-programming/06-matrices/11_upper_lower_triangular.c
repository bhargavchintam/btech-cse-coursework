// check if a square matrix is upper or lower triangular
#include<stdio.h>
int main() {
    int a[10][10], n, i, j, upper=1, lower=1;
    printf("Enter order of matrix: ");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(i>j && a[i][j]!=0)
                upper = 0;
            if(i<j && a[i][j]!=0)
                lower = 0;
        }
    }
    if(upper == 1)
        printf("Matrix is upper triangular\n");
    if(lower == 1)
        printf("Matrix is lower triangular\n");
    if(upper==0 && lower==0)
        printf("Matrix is neither\n");
    return 0;
}
