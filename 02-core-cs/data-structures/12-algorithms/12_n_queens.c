// n-queens by backtracking - prints one valid placement
#include<stdio.h>

int board[20][20];
int n;

int safe(int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
        if(board[i][col])
            return 0;
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;
    for(i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j])
            return 0;
    return 1;
}

int solve(int row)
{
    if(row == n)
        return 1;
    int col;
    for(col = 0; col < n; col++)
    {
        if(safe(row, col))
        {
            board[row][col] = 1;
            if(solve(row + 1))
                return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int i, j;
    printf("Enter n: ");
    scanf("%d", &n);

    if(solve(0))
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                printf("%c ", board[i][j] ? 'Q' : '.');
            printf("\n");
        }
    }
    else
        printf("No solution\n");
    return 0;
}
