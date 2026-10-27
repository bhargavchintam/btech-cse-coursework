// gcc 07_tic_tac_toe.c -o ttt
#include<stdio.h>

char board[3][3];

void display()
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < 2)
                printf("|");
        }
        printf("\n");
        if(i < 2)
            printf("-----------\n");
    }
}

int checkwin()
{
    int i;
    for(i = 0; i < 3; i++)
    {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int main()
{
    int i, j, move, count = 0;
    char player = 'X';

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            board[i][j] = ' ';

    while(1)
    {
        display();
        printf("Player %c enter position (1-9): ", player);
        scanf("%d", &move);

        i = (move - 1) / 3;
        j = (move - 1) % 3;

        if(move < 1 || move > 9 || board[i][j] != ' ')
        {
            printf("Invalid move, try again\n");
            continue;
        }

        board[i][j] = player;
        count++;

        if(checkwin())
        {
            display();
            printf("Player %c wins!\n", player);
            break;
        }

        if(count == 9)
        {
            display();
            printf("Its a draw\n");
            break;
        }

        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }
    return 0;
}
