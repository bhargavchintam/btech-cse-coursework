#include<stdio.h>

int main()
{
    int i, j, n;
    printf("enter number of rows : ");
    scanf("%d", &n);
    i = n;
    while(i >= 1)
    {
        for(j=1; j<=i; j++)
            printf("%d ", j);
        printf("\n");
        i--;
    }
    return 0;
}
