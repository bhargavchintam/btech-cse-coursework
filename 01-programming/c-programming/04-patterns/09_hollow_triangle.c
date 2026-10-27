// hollow right triangle
#include<stdio.h>

int main()
{
    int i, j, n;
    printf("Enter n : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(j==1 || j==i || i==n)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
