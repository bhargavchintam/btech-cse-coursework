#include<stdio.h>

// print all prime numbers upto n
int main()
{
    int i, j, n, flag;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        flag = 1;
        for(j = 2; j <= i / 2; j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
