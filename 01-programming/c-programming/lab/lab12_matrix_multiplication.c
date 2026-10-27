/* Lab Program 12
   Multiply two matrices after checking them for conformability.
   gcc lab12_matrix_multiplication.c -o lab12  */

#include<stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int i, j, k, r1, c1, r2, c2;

    printf("Enter rows and columns of matrix A : ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of matrix B : ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2)
    {
        printf("Matrices cannot be multiplied\n");
        return 0;
    }

    printf("Enter elements of matrix A\n");
    for(i = 0; i < r1; i++)
        for(j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of matrix B\n");
    for(i = 0; i < r2; i++)
        for(j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < c1; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
        }
    }

    printf("Product matrix is\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}
