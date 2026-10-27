// floyd-warshall all pairs shortest path
#include<stdio.h>
#define INF 9999

int main()
{
    int d[20][20], n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (%d for no edge)\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("All pairs shortest distances\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] >= INF)
                printf("INF ");
            else
                printf("%3d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
