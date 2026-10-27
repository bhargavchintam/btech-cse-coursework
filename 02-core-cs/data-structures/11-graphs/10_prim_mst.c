// prim's minimum spanning tree
#include<stdio.h>
#define INF 9999

int main()
{
    int cost[20][20], n, i, j, u, v, min, total = 0, count;
    int selected[20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (0 for no edge)\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }

    selected[0] = 1;                 // start from vertex 0
    printf("Edges in MST\n");
    for (count = 0; count < n - 1; count++)
    {
        min = INF;
        u = v = -1;
        for (i = 0; i < n; i++)
            if (selected[i])
                for (j = 0; j < n; j++)
                    if (!selected[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
        if (v == -1)
            break;
        printf("%d - %d  weight %d\n", u, v, min);
        total += min;
        selected[v] = 1;
    }

    printf("Total weight = %d\n", total);
    return 0;
}
