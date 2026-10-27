#include<stdio.h>

// program to print numbers from 1 to n
int main()
{
    int i, n;
    printf("Enter n : ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
