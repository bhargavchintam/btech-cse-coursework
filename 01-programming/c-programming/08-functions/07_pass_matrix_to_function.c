#include<stdio.h>

void display(int m[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main()
{
    int m[10][10], r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &m[i][j]);
    display(m, r, c);
    return 0;
}
