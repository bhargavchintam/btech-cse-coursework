// dynamic 2d matrix using double pointer
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **m;
    int i, j, r, c;

    printf("Enter rows and columns : ");
    scanf("%d %d", &r, &c);

    m = (int **)malloc(r * sizeof(int *));
    for(i = 0; i < r; i++)
        m[i] = (int *)malloc(c * sizeof(int));

    printf("Enter the elements :\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &m[i][j]);

    printf("Matrix :\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    for(i = 0; i < r; i++)
        free(m[i]);
    free(m);

    return 0;
}
