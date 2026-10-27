/* Bindu Bhargava
   19-11-17 */
#include<stdio.h>

int main()
{
    int i, j, n, c = 1;
    printf("Enter the number of rows : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("%d ", c);
            c++;
        }
        printf("\n");
    }
    return 0;
}
