// rat in a maze - backtracking to find a path from top-left to bottom-right
#include<stdio.h>

#define N 4

int maze[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int sol[N][N];

int solve(int x, int y)
{
    if(x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return 1;
    }
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0)
    {
        sol[x][y] = 1;
        if(solve(x + 1, y))     // move down
            return 1;
        if(solve(x, y + 1))     // move right
            return 1;
        sol[x][y] = 0;          // backtrack
        return 0;
    }
    return 0;
}

int main()
{
    int i, j;
    if(solve(0, 0))
    {
        printf("Path found:\n");
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
                printf("%d ", sol[i][j]);
            printf("\n");
        }
    }
    else
        printf("No path exists\n");
    return 0;
}
