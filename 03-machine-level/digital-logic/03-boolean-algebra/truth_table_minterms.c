// print the truth table of a function given by its minterm list
#include<stdio.h>

int main()
{
    int n, m, i, j, k, rows;
    int mt[64];
    printf("Enter number of variables: ");
    scanf("%d", &n);
    printf("How many minterms: ");
    scanf("%d", &m);
    printf("Enter the minterms: ");
    for(i = 0; i < m; i++)
        scanf("%d", &mt[i]);
    rows = 1 << n;
    for(k = n - 1; k >= 0; k--)
        printf("%c ", 'A' + (n - 1 - k));
    printf("| F\n");
    for(i = 0; i < rows; i++)
    {
        for(k = n - 1; k >= 0; k--)
            printf("%d ", (i >> k) & 1);
        int f = 0;
        for(j = 0; j < m; j++)
            if(mt[j] == i) f = 1;
        printf("| %d\n", f);
    }
    return 0;
}
