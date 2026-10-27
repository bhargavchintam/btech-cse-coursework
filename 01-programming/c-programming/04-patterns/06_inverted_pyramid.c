// inverted pyramid
#include<stdio.h>

int main()
{
    int i, j, n;
    printf("Enter rows : ");
    scanf("%d", &n);
    i = n;
    while(i >= 1)
    {
        for(j=1; j<=n-i; j++)
            printf(" ");
        for(j=1; j<=2*i-1; j++)
            printf("*");
        printf("\n");
        i--;
    }
    return 0;
}
