// transitive closure using warshall's algorithm
#include<stdio.h>

int main()
{
    int r[20][20], n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (directed)\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &r[i][j]);

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (r[i][k] && r[k][j])
                    r[i][j] = 1;

    printf("Transitive closure\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", r[i][j]);
        printf("\n");
    }
    return 0;
}
