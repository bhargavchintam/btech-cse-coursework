// gcc 05_matrix_calculator.c -o matrix
#include<stdio.h>

void readmat(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void printmat(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10], res[10][10];
    int r, c, i, j, k, choice;

    while(1)
    {
        printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Transpose\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 5)
            break;

        if(choice == 4)
        {
            printf("Enter rows and cols: ");
            scanf("%d %d", &r, &c);
            printf("Enter matrix:\n");
            readmat(a, r, c);
            for(i = 0; i < r; i++)
                for(j = 0; j < c; j++)
                    res[j][i] = a[i][j];
            printf("Transpose:\n");
            printmat(res, c, r);
            continue;
        }

        if(choice == 3)
        {
            int r2, c2;
            printf("Enter rows and cols of A: ");
            scanf("%d %d", &r, &c);
            printf("Enter rows and cols of B: ");
            scanf("%d %d", &r2, &c2);
            if(c != r2)
            {
                printf("Cannot multiply\n");
                continue;
            }
            printf("Enter matrix A:\n");
            readmat(a, r, c);
            printf("Enter matrix B:\n");
            readmat(b, r2, c2);
            for(i = 0; i < r; i++)
            {
                for(j = 0; j < c2; j++)
                {
                    res[i][j] = 0;
                    for(k = 0; k < c; k++)
                        res[i][j] += a[i][k] * b[k][j];
                }
            }
            printf("Result:\n");
            printmat(res, r, c2);
            continue;
        }

        // add or subtract
        printf("Enter rows and cols: ");
        scanf("%d %d", &r, &c);
        printf("Enter matrix A:\n");
        readmat(a, r, c);
        printf("Enter matrix B:\n");
        readmat(b, r, c);
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(choice == 1)
                    res[i][j] = a[i][j] + b[i][j];
                else
                    res[i][j] = a[i][j] - b[i][j];
            }
        }
        printf("Result:\n");
        printmat(res, r, c);
    }
    return 0;
}
