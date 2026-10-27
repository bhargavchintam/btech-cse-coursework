// triangle of alternating 0 and 1
#include<stdio.h>

int main()
{
    int i, j, n, flag = 1;
    printf("Enter n : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%d ", flag);
            flag = !flag;   // flip
        }
        printf("\n");
    }
    return 0;
}
